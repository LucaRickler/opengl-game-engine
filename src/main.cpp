#include <cbg.hpp>

#include <iostream>

void processInput(Window *window);

// settings
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
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
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
  // float vertices[] = {
  //     // positions         // colors
  //     1.0f, -1.0f, 0.0f,  1.0f, 0.0f, 0.0f,
  //     -1.0f, -1.0f, 0.0f,  0.0f, 1.0f, 0.0f,
  //     -1.0f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f,
  //     1.0f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f
  // };

  //   unsigned int indices[] = {  // note that we start from 0!
  //       0, 1, 3,
  //       1, 2, 3  // first Triangle
  //   };
  //   unsigned int VBO, VAO, EBO;
  //   glGenVertexArrays(1, &VAO);
  //   glGenBuffers(1, &VBO);
  //   glGenBuffers(1, &EBO);
  //   // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
  //   glBindVertexArray(VAO);

  //   glBindBuffer(GL_ARRAY_BUFFER, VBO);
  //   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  //   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  //   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  //   // position attribute
  //   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  //   glEnableVertexAttribArray(0);
  //   // color attribute
  //   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
  //   glEnableVertexAttribArray(1);

  //   // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
  //   glBindBuffer(GL_ARRAY_BUFFER, 0); 

  //   // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
  //   //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  //   // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
  //   // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
  //   glBindVertexArray(0); 


    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  float time = 0.0f;
    // render loop
    // -----------
    while (!window->ShouldClose())
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        shader.Use();
        time += 0.1f;
        shader.SetFloat("time", time);
        
        //glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        m1.Draw();
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        
        // glBindVertexArray(0); // no need to unbind it every time 
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        window->SwapBuffers();
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    //glDeleteVertexArrays(1, &VAO);
    //glDeleteBuffers(1, &VBO);
    //glDeleteBuffers(1, &EBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    
    delete window;
    //glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(Window *window) {
  if (window->GetKeyPressed(GLFW_KEY_ESCAPE))
    window->Close();
}
