#include "mesh.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

Mesh::Mesh(std::vector<Vertex> &&vertices, std::vector<unsigned int> &&indices)
    : vertices(vertices), indices(indices)
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex),
                 &(this->vertices[0]), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(unsigned int),
                 &(this->indices[0]), GL_STATIC_DRAW);

    // Vertex.position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)nullptr);

    // Vertex.normal
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}

void Mesh::draw(sf::Shader* shader)
{
    sf::Shader::bind(shader);
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
}

Mesh Mesh::createPlane()
{
    std::vector<Vertex> vertices
    {
        {{-0.5F, -0.5F, 0.0F}, {0.0F, 0.0F, 1.0F}},
        {{0.5F, -0.5F, 0.0F}, {0.0F, 0.0F, 1.0F}},
        {{0.5F, 0.5F, 0.0F}, {0.0F, 0.0F, 1.0F}},
        {{-0.5F, 0.5F, 0.0F}, {0.0F, 0.0F, 1.0F}}
    };

    std::vector<unsigned int> indices{0, 1, 3, 1, 2, 3};

    return Mesh(std::move(vertices), std::move(indices));
}
