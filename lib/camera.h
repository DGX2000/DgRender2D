#ifndef CAMERA_H
#define CAMERA_H

#include <optional>

#include <glm/glm.hpp>

class Camera
{
public:
    void capture(const class SceneNode* node) const;
    virtual void computeTransformationMatrix() const = 0;

protected:
    mutable std::optional<glm::mat4> cachedTransformation;
};

#endif // CAMERA_H
