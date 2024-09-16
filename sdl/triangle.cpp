#include <SDL2/SDL.h>
#include <GL/gl.h> // For OpenGL functions
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 600;

// Function to draw a cycle (circle)
void drawCycle(float radius, int segments) {
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y); 
    }
    glEnd();
}

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Set OpenGL context version (optional but recommended)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Create SDL window
    SDL_Window* window = SDL_CreateWindow("SDL OpenGL Cycle",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT,
                                          SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create OpenGL context
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        SDL_Log("Failed to create OpenGL context: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main loop flag
    bool running = true;
    SDL_Event event;

    // Main loop
    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Set up the projection matrix
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1, 1, -1, 1, -1, 1);

        // Draw the cycle
        drawCycle(0.5f, 100); // Radius = 0.5, 100 segments

        // Swap buffers (show what we drew)
        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
