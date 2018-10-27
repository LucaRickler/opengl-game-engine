#include <cbg.hpp>

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

  Shader shader;
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
  
  Mesh m1;
  m1.AddTri(v0, v1, v3);

  m1.AddTri(v1, v2, v3);

    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  float time = 0.0f;
  while (!window->ShouldClose())
  {
    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shader.Use();
    time += 0.1f;
    shader.SetFloat("time", time);
    
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
