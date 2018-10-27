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
  
  Mesh m1;
  m1.AddTri(
    new float[8]{1.0f, -1.0f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f},
    new float[8]{-1.0f, -1.0f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f},
    new float[8]{1.0f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f}
    );

  m1.AddTri(
    new float[8]{-1.0f, -1.0f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f},
    new float[8]{-1.0f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
    new float[8]{1.0f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f}
    );

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
