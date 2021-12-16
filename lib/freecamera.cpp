#include "freecamera.h"

#include <glm/gtc/matrix_transform.hpp>

FreeCamera::FreeCamera(const glm::vec3& position)
    : position(position)
{

}

void FreeCamera::computeTransformationMatrix() const
{
    // TODO: Add rotation with up vector (third parameter)
    // TODO: Add zoom as z coordinate of position
    auto orthogonal = glm::ortho(-1.0F, 1.0F, -1.0F, 1.0F, 3.0F, -3.0F);
    cachedTransformation = orthogonal * glm::lookAt(position, glm::vec3{0.0F, 0.0F, -1.0F}, glm::vec3{0.0F, 1.0F, 0.0F});
}

void FreeCamera::move(const glm::vec3 &displacement)
{
    position += displacement;
    cachedTransformation.reset();
}
