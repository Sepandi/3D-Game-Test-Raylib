#include <raylib.h>
#include <iostream>

#include "Player.hpp"
#include "Cube.hpp"

int main()
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 600, "GAME");
    
    Camera3D camera;
    camera.position = (Vector3){ 45.0f, 45.0f, -45.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 20.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    Player player = Player(0,0.5,0);


    BoundingBox wallBlue  = (BoundingBox){Vector3{-17.0f, 0.0f, -16.0f}, Vector3{-16.0f, 10.0f, 16.0f}};
    Cube wallGold = Cube(Vector3{0.0f, 5.0f, 0.0f},32,-10,1);
    while (!WindowShouldClose())   
    {   
        camera.target = player.cube;
        player.update();

        if (IsKeyDown(KEY_SPACE)){
            camera.position.y += 1;
            camera.target.y -= 1;
        }
        if (IsKeyDown(KEY_LEFT_SHIFT)){
            camera.position.y -= 1;
            camera.target.y += 1;
        }

        float speed = 10*GetFrameTime();
        if (IsKeyDown(KEY_W)){
            camera.position.z += speed;
            camera.position.x -= speed;
        } 
        if (IsKeyDown(KEY_S)){
            camera.position.z -= speed;
            camera.position.x += speed;
        } 
        if (IsKeyDown(KEY_A)){
            camera.position.z += speed;
            camera.position.x += speed;
        } 
        if (IsKeyDown(KEY_D)){
            camera.position.z -= speed;
            camera.position.x -= speed;
        } 


        //if (CheckCollisionBoxes())
        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                


                DrawBoundingBox(wallBlue,BLACK);
                DrawBoundingBox(wallGold.boundingBox,BLACK);
                if (!IsKeyDown(KEY_R)){
                    DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);
                    DrawCube(Vector3{-16.5f, 5.0f, 0.0f},1,10,32,BLUE);
                    DrawCube(wallGold.pos, wallGold.width, wallGold.height, wallGold.depth, GOLD);                      
                    DrawCube(player.cube,1,1,1,LIME);
                }
                
                

            EndMode3D();
        DrawFPS(10,10);
        EndDrawing();
    }
    CloseWindow();      

    return 0;
}
