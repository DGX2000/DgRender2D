#ifndef FREECAMERA_H
#define FREECAMERA_H

#include "camera.h"

class FreeCamera : public Camera
{
public:
    FreeCamera(const glm::vec2& position);

    void computeTransformationMatrix() const override;

    void move(const glm::vec2& displacement);
    void rotate(float amount);

private:
    glm::vec2 position;
};

#endif // FREECAMERA_H
