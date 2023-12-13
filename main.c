#include <emscripten/emscripten.h>

#include "raylib.h"

#define PLATFORM_WEB

const int screenWidth = 800;
const int screenHeight = 450;

void update_frame(void);

int main(void) {
  InitWindow(screenWidth, screenHeight, "My Game 3");

#if defined(PLATFORM_WEB)
  emscripten_set_main_loop(update_frame, 0, 1);
#else
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    UpdateDrawFrame();
  }
#endif

  CloseWindow();
  return 0;
}

void update_frame(void) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  DrawText("Hello, is tis thing on?", 190, 200, 20, LIGHTGRAY);
  EndDrawing();
}