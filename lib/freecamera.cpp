#include "freecamera.h"

#include <glm/gtc/matrix_transform.hpp>

FreeCamera::FreeCamera(const glm::vec2& position)
    : position(position)
{

}

void FreeCamera::computeTransformationMatrix() const
{
    // TODO: Add rotation with up vector (third parameter)
    // TODO: Add zoom as z coordinate of position
    auto orthogonal = glm::ortho(-4.0F, 4.0F, -3.0F, 3.0F, -1.0F, 1.0F);
    cachedTransformation = orthogonal * glm::lookAt(glm::vec3(position, 0.5F),
                                                    glm::vec3{position.x, position.y, -1.0F},
                                                    glm::vec3{0.0F, 1.0F, 0.0F});
}

void FreeCamera::move(const glm::vec2 &displacement)
{
    position += displacement;
    cachedTransformation.reset();
}
