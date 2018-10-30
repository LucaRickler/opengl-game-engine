#include <cbg.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
    shader.Load("./shaders/test.vert","./shaders/test.frag");
  } catch(Exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
  }

  Vertex* v0 = new Vertex(new glm::vec4(1.0f, -1.0f, 0.0f, 1.0f), zero3, new glm::vec2(1.0f, 0.0f), zero3);
  Vertex* v1 = new Vertex(new glm::vec4(-1.0f, -1.0f, 0.0f, 1.0f), zero3, new glm::vec2(0.0f, 0.0f), zero3);
  Vertex* v2 = new Vertex(new glm::vec4(-1.0f,  1.0f, 0.0f, 1.0f), zero3, new glm::vec2(0.0f, 1.0f), zero3);
  Vertex* v3 = new Vertex(new glm::vec4(1.0f,  1.0f, 0.0f, 1.0f), zero3, new glm::vec2(1.0f, 1.0f), zero3);
  
  Vertex* v4 = new Vertex(new glm::vec4(0.5f, 0.5f, 0.0f, 1.0f), zero3, new glm::vec2(1.0f, 0.0f), zero3);
  Vertex* v5 = new Vertex(new glm::vec4(0.5f, -0.5f, 0.0f, 1.0f), zero3, new glm::vec2(0.0f, 0.0f), zero3);
  Vertex* v6 = new Vertex(new glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), zero3, new glm::vec2(0.0f, 1.0f), zero3);
  Vertex* v7 = new Vertex(new glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f), zero3, new glm::vec2(1.0f, 1.0f), zero3);

  Mesh m1;
  m1.AddTri(v4, v5, v7);

  m1.AddTri(v5, v6, v7);

  // glm::vec3 cameraTarget(0.0f, 0.0f, 0.0f);
  // glm::vec3 cameraPos(0.0f, 0.0f, 3.0f);
  // glm::vec3 up(0.0f, 1.0f, 0.0f);

  glm::mat4 view(1);
  view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), 
  		   glm::vec3(0.0f, 0.0f, 0.0f), 
  		   glm::vec3(0.0f, 1.0f, 0.0f));
  //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
  glm::mat4 projection;
  projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
  glm::mat4 model(1);
  //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

  

    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glEnable(GL_DEPTH_TEST);
  
  while (!window->ShouldClose())
  {
    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.Bind();
    shader.SetFloat("time", glfwGetTime());
    shader.SetMat4("projection", projection);
    shader.SetMat4("view", view);
    //auto m = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.SetMat4("model", model);
    
    m1.Draw();
    
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
