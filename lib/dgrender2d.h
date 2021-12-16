#ifndef DGRENDER3D_H
#define DGRENDER3D_H

#include <GL/glew.h>

#include "mesh.h"
#include "transformnode.h"
#include "meshnode.h"

#include "camera.h"
#include "freecamera.h"

class DgRender2D
{
public:
    DgRender2D() = delete;

    static void initialize()
    {
        glewInit();
        glEnable(GL_DEPTH_TEST);
    }

private:
};


#endif // DGRENDER3D_H
