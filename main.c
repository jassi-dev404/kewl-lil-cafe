#include "raylib.h"
int main(void) {
  const int screenWidth = 1200;
  const int screenHeight = 700;
  InitWindow(screenWidth, screenHeight, "kewl lil cafe");
  Font silly = LoadFontEx("assets/augiepixel.ttf", 96, 0, 0);
  Image op_img = LoadImage("assets/open_img.png");
  Texture2D open_texture = LoadTextureFromImage(op_img);
  UnloadImage(op_img);
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexturePro(open_texture,
                   (Rectangle){0, 0, (float)open_texture.width,
                               (float)open_texture.height},
                   (Rectangle){0, 0, (float)screenWidth, (float)screenHeight},
                   (Vector2){0, 0}, 0.0f, WHITE);
    DrawTextEx(silly, "kewl lil cafe.", (Vector2){53.0f, 50.0f},
               (float)screenHeight / 7.0f, 1.0f, WHITE);
    DrawTextEx(silly, "kewl lil cafe.", (Vector2){50.0f, 53.0f},
               (float)screenHeight / 7.0f, 1.0f, WHITE);
    DrawTextEx(silly, "kewl lil cafe.", (Vector2){47.0f, 50.0f},
               (float)screenHeight / 7.0f, 1.0f, WHITE);    
    DrawTextEx(silly, "kewl lil cafe.", (Vector2){50.0f, 47.0f},
               (float)screenHeight / 7.0f, 1.0f, WHITE);
    DrawTextEx(silly, "kewl lil cafe.", (Vector2){50.0f, 50.0f},
               (float)screenHeight / 7.0f, 1.0f, BLACK);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
