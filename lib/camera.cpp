#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

#include "scenenode.h"

void Camera::capture(const SceneNode *node) const
{
    if(!cachedTransformation.has_value())
    {
        computeTransformationMatrix();
    }

    auto identity = glm::mat4(1.0F);
    node->traverse(cachedTransformation.value(), identity);
}
