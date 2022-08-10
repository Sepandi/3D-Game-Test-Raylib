#include <raylib.h>

class Player{
    public:
        Vector3 cube;
        Player(float x , float y ,float z){
            cube = (Vector3){x,y,z};
        }

        void update(){
            float speed = 10*GetFrameTime();
            if (IsKeyDown(KEY_W)){
                cube.z += speed;
                cube.x -= speed;
            } 
            if (IsKeyDown(KEY_S)){
                cube.z -= speed;
                cube.x += speed;
            } 
            if (IsKeyDown(KEY_A)){
                cube.x += speed;
                cube.z += speed;

            } 
            if (IsKeyDown(KEY_D)){
                cube.x -= speed;
                cube.z -= speed;
            } 
        }
};

