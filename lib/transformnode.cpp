#include "transformnode.h"

#include <glm/gtc/matrix_transform.hpp>

void TransformNode::setPosition(const glm::vec2 &translation)
{
    this->translation = translation;
    cachedTransformation.reset();
}

void TransformNode::setRotation(float rotation)
{
    this->rotation = rotation;
    cachedTransformation.reset();
}

void TransformNode::setScale(const glm::vec2 &scaling)
{
    this->scaling = scaling;
    cachedTransformation.reset();
}

void TransformNode::draw(const glm::mat4& camera, const glm::mat4 &transformation) const {}

void TransformNode::transform(glm::mat4 &transformation) const
{
    if(!cachedTransformation.has_value())
    {
        auto uncachedTransformation = glm::mat4(1.0F);

        uncachedTransformation = glm::translate(uncachedTransformation, glm::vec3(translation, 0.0F));
        uncachedTransformation = glm::rotate(uncachedTransformation, rotation, glm::vec3(0.0, 0.0, 1.0));
        uncachedTransformation = glm::scale(uncachedTransformation, glm::vec3(scaling, 0.0F));

        cachedTransformation = uncachedTransformation;
    }

    transformation *= cachedTransformation.value();
}

bool TransformNode::isDrawable() const
{
    return false;
}
