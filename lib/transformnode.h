#ifndef TRANSFORMNODE_H
#define TRANSFORMNODE_H

#include "scenenode.h"

#include <optional>

#include <glm/glm.hpp>

class TransformNode : public SceneNode
{
public:
    TransformNode() = default;

    void setPosition(const glm::vec2& position);
    void setRotation(float rotation);
    void setScale(const glm::vec2& scaling);

protected:
    virtual void draw(const glm::mat4& camera, const glm::mat4& transformation) const;
    virtual void transform(glm::mat4& transformation) const;
    virtual bool isDrawable() const;

private:
    mutable std::optional<glm::mat4> cachedTransformation;

    glm::vec2 translation{0.0F, 0.0F};
    glm::vec2 scaling{1.0F, 1.0F};
    float rotation;
};

#endif // TRANSFORMNODE_H
