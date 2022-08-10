#include <raylib.h>

class Cube{
    public:
        Vector3 pos;
        float width;
        float height;
        float depth;
        BoundingBox boundingBox;
        Cube(Vector3 posIn,float widthIn,float heightIn,float depthIn){
            pos = posIn;
            width = widthIn;
            height = heightIn;
            depth = depthIn;
            boundingBox = (BoundingBox){(Vector3){pos.x,pos.y,pos.z},(Vector3){pos.x+width,pos.y+height,pos.z+depth}};

        }
};