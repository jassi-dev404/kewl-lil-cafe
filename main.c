#include "raylib.h"
#include <stdio.h>

int main(void) {
    const int screenWidth = 1200;
    const int screenHeight = 700;
    int start_screen = 1;
    InitWindow(screenWidth, screenHeight, "kewl lil cafe");
    Font silly = LoadFontEx("assets/augiepixel.ttf", 96, 0, 0);
    Image op_img = LoadImage("assets/open_img.png");
    Texture2D open_texture = LoadTextureFromImage(op_img);
    Texture2D button = LoadTexture("assets/start.png");
    UnloadImage(op_img);
    int size_i = 0;
    int btnState = 0;
    bool btnAction = false;
    float baseWidth = (float)button.width * 0.7f;
    float baseHeight = (float)button.height * 0.7f;
    Rectangle sourceRec = {0, 0, (float)button.width, (float)button.height};
    Vector2 mousePoint = {0.0f, 0.0f};
    Rectangle btnBounds = {screenWidth - 530.0f, screenHeight - 130.0f, (float)baseWidth, (float)baseHeight};
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        mousePoint = GetMousePosition();

        if (start_screen == 1) {
            btnAction = false;
            if (CheckCollisionPointRec(mousePoint, btnBounds)) {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    btnState = 2;
                else
                    btnState = 1;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                    btnAction = true;
            } else
                btnState = 0;
            if (btnAction) {
                start_screen = 0;
            }
            if (btnState == 1 || btnState == 2) {
                if (size_i < 15) {
                    size_i = size_i + 2;
                }
            }
            if (btnState == 0) {
                if (size_i > 0) {
                    size_i = size_i - 2;
                }
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (start_screen == 1) {
            DrawTexturePro(open_texture, (Rectangle){0, 0, (float)open_texture.width, (float)open_texture.height},
                           (Rectangle){0, 0, (float)screenWidth, (float)screenHeight}, (Vector2){0, 0}, 0.0f, WHITE);
            DrawTextEx(silly, "kewl lil cafe.", (Vector2){55.0f, 50.0f}, (float)screenHeight / 5.0f, 1.0f, WHITE);
            DrawTextEx(silly, "kewl lil cafe.", (Vector2){50.0f, 55.0f}, (float)screenHeight / 5.0f, 1.0f, WHITE);
            DrawTextEx(silly, "kewl lil cafe.", (Vector2){45.0f, 50.0f}, (float)screenHeight / 5.0f, 1.0f, WHITE);
            DrawTextEx(silly, "kewl lil cafe.", (Vector2){50.0f, 45.0f}, (float)screenHeight / 5.0f, 1.0f, WHITE);
            DrawTextEx(silly, "kewl lil cafe.", (Vector2){50.0f, 50.0f}, (float)screenHeight / 5.0f, 1.0f, BLACK);

            Rectangle destRec = {btnBounds.x - ((float)size_i / 2.0f), btnBounds.y - ((float)size_i / 2.0f),
                                 (float)baseWidth + (float)size_i + (float)size_i * 0.5,
                                 (float)baseHeight + (float)size_i};
            DrawTexturePro(button, sourceRec, destRec, (Vector2){0, 0}, 0.0f, WHITE);
        }
        EndDrawing();
    }
    UnloadFont(silly);
    UnloadTexture(open_texture);
    UnloadTexture(button);
    CloseWindow();
    return 0;
}