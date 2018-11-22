#include <moonbeam.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

void processInput(Window *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
  MoonBeamEngine engine;
  SystemManager* sm = engine.GetSystemManager();
  EntityManager* em = engine.GetEntityManager();
  ComponentManager* cm = engine.GetComponentManager();

  Window* window = engine.CreateWindow(SCR_WIDTH, SCR_HEIGHT);

  GraphicSystem* gs = sm->CreateSystem<GraphicSystem>();

  Entity* cameraEnt = em->CreateEntity<Entity>();
  Transform* cameraTransf = cameraEnt->AddComponent<Transform>();
  cameraTransf->SetPosition(glm::vec3(0.0f, 0.0f, 3.0f));
  Camera* cam = cameraEnt->AddComponent<Camera>();

  gs->SetMainCamera(cam);


  DrawShader shader;
  try {
    shader.Load("./shaders/test.vert","./shaders/test.frag");
  } catch(Exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
  }
  shader.BindUniformBlock("Matrices", 0);

  ComputeShader compute;
  try {
    compute.Load("./shaders/test.comp");
  } catch(Exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
  }

  Texture2D *tex = new Texture2D(512,512);

  ComputeMaterial* compMat = new ComputeMaterial();
  compMat->SetTexture(GL_TEXTURE0, tex);
  compMat->SetShader(&compute);
  compMat->SetWorkGroups(512,512,1);

  Material* drawMat = new Material();
  drawMat->SetTexture(GL_TEXTURE0, tex);
  drawMat->SetShader(&shader);

  Vertex v0 = Vertex::CreateVertex(glm::vec4(1.0f, -1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f), zero3);
  Vertex v1 = Vertex::CreateVertex(glm::vec4(-1.0f, -1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f), zero3);
  Vertex v2 = Vertex::CreateVertex(glm::vec4(-1.0f,  1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f), zero3);
  Vertex v3 = Vertex::CreateVertex(glm::vec4(1.0f,  1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f), zero3);
  
  Vertex v4 = Vertex::CreateVertex(glm::vec4(0.5f, 0.5f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f), zero3);
  Vertex v5 = Vertex::CreateVertex(glm::vec4(0.5f, -0.5f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f), zero3);
  Vertex v6 = Vertex::CreateVertex(glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f), zero3);
  Vertex v7 = Vertex::CreateVertex(glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f), zero3);

  Mesh *m1 = new Mesh();
  m1->AddTri(v4, v5, v7);
  m1->AddTri(v5, v6, v7);

  Model mod;
  mod.SetMaterial(drawMat);
  mod.SetMesh(m1);
  
    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glEnable(GL_DEPTH_TEST);

  auto matrix = mod.GetMatrix();
  
  while (!window->ShouldClose()) {
    sm->Update();

    compMat->Bind();
    compute.SetFloat("time", (float)glfwGetTime());
    compMat->Dispatch();

    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    auto m2 = glm::rotate(matrix, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
    mod.SetMatrix(m2);
    mod.Draw();
    
    
    window->SwapBuffers();
    glfwPollEvents();
  }
    
  //delete window;
  //glfwTerminate();
  return 0;
}

void processInput(Window *window) {
  if (window->GetKeyPressed(GLFW_KEY_ESCAPE))
    window->Close();
}
