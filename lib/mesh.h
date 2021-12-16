#ifndef MESH_H
#define MESH_H

#include <vector>

#include <glm/glm.hpp>

#include <SFML/Graphics/Shader.hpp>

class Mesh
{
public:
    struct Vertex
    {
        glm::vec3 position;
        // TODO: Remove normal, add texture
        glm::vec3 normal;
    };

public:
    Mesh(std::vector<Vertex>&& vertices, std::vector<unsigned int>&& indices);
    ~Mesh();

    void draw(sf::Shader* shader);

    static Mesh createPlane();

private:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;
};

#endif // MESH_H
