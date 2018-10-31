#include <cbg.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

void processInput(Window *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
  Window* window = new Window(SCR_WIDTH, SCR_HEIGHT);
  try {
    window->Open();
  } catch (Exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
  }

  DrawShader shader;
  try {
    shader.Load("./shaders/test.vert","./shaders/test.2.frag");
  } catch(Exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
  }


  ComputeShader compute;
  try {
    compute.Load("./shaders/test.comp");
  } catch(Exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
  }

  Texture2D *tex = new Texture2D(512,512);

  Material* compMat = new Material();
  compMat->SetTexture(GL_TEXTURE0, tex);
  compMat->SetShader(&compute);

  Material* drawMat = new Material();
  drawMat->SetTexture(GL_TEXTURE0, tex);
  drawMat->SetShader(&shader);

  Vertex* v0 = new Vertex(new glm::vec4(1.0f, -1.0f, 0.0f, 1.0f), zero3, new glm::vec2(1.0f, 0.0f), zero3);
  Vertex* v1 = new Vertex(new glm::vec4(-1.0f, -1.0f, 0.0f, 1.0f), zero3, new glm::vec2(0.0f, 0.0f), zero3);
  Vertex* v2 = new Vertex(new glm::vec4(-1.0f,  1.0f, 0.0f, 1.0f), zero3, new glm::vec2(0.0f, 1.0f), zero3);
  Vertex* v3 = new Vertex(new glm::vec4(1.0f,  1.0f, 0.0f, 1.0f), zero3, new glm::vec2(1.0f, 1.0f), zero3);
  
  Vertex* v4 = new Vertex(new glm::vec4(0.5f, 0.5f, 0.0f, 1.0f), zero3, new glm::vec2(1.0f, 1.0f), zero3);
  Vertex* v5 = new Vertex(new glm::vec4(0.5f, -0.5f, 0.0f, 1.0f), zero3, new glm::vec2(1.0f, 0.0f), zero3);
  Vertex* v6 = new Vertex(new glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), zero3, new glm::vec2(0.0f, 0.0f), zero3);
  Vertex* v7 = new Vertex(new glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f), zero3, new glm::vec2(0.0f, 1.0f), zero3);

  Mesh *m1 = new Mesh();
  m1->AddTri(v4, v5, v7);
  m1->AddTri(v5, v6, v7);

  Model mod;
  mod.SetMaterial(drawMat);
  mod.SetMesh(m1);

  // glm::vec3 cameraTarget(0.0f, 0.0f, 0.0f);
  // glm::vec3 cameraPos(0.0f, 0.0f, 3.0f);
  // glm::vec3 up(0.0f, 1.0f, 0.0f);

  glm::mat4 view(1);
  view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), 
  		   glm::vec3(0.0f, 0.0f, 0.0f), 
  		   glm::vec3(0.0f, 1.0f, 0.0f));
  glm::mat4 projection;
  projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
  glm::mat4 model(1);
  
  

    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glEnable(GL_DEPTH_TEST);

  auto matrix = mod.GetMatrix();
  
  while (!window->ShouldClose()) {
    compMat->Bind();
    compute.SetFloat("time", (float)glfwGetTime());
    glDispatchCompute(512,512,1);

    glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    auto m2 = glm::rotate(matrix, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
    auto transform = projection * view;
    mod.SetMatrix(m2);
    mod.Draw(transform);
    
    
    window->SwapBuffers();
    glfwPollEvents();
  }
    
  delete window;
  //glfwTerminate();
  return 0;
}

void processInput(Window *window) {
  if (window->GetKeyPressed(GLFW_KEY_ESCAPE))
    window->Close();
}
