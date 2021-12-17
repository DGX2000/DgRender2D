#include "dgrender2d.h"

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 3;
    settings.minorVersion = 3;

    unsigned int screenWidth = 800;
    unsigned int screenHeight = 600;

    sf::Window window(sf::VideoMode(screenWidth, screenHeight), "OpenGL", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    window.setActive(true);

    DgRender2D::initialize();

    sf::Shader shader;
    shader.loadFromFile("vertex_shader.glslv", "fragment_shader.glslf");
    shader.setUniform("lightPosition", sf::Glsl::Vec3(0.0F, 0.0F, 1.0F));

    Mesh plane = Mesh::createPlane();

    TransformNode sceneRoot;
    MeshNode planeNode(&plane, &shader);
    sceneRoot.addNode(&planeNode);

    FreeCamera freeCam(glm::vec2(0.0F, 0.0F));

    float rotation = 0.0F;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(event.type == sf::Event::Resized)
            {
                screenWidth = event.size.width;
                screenHeight = event.size.height;

                glViewport(0, 0, screenWidth, screenHeight);
            }
            else if(event.type == sf::Event::KeyPressed)
            {
                switch(event.key.code)
                {
                case sf::Keyboard::A:
                    freeCam.move(glm::vec2(-0.1F, 0.0F));
                    break;
                case sf::Keyboard::D:
                    freeCam.move(glm::vec2(0.1F, 0.0F));
                    break;
                case sf::Keyboard::W:
                    freeCam.move(glm::vec2(0.0F, 0.1F));
                    break;
                case sf::Keyboard::S:
                    freeCam.move(glm::vec2(0.0F, -0.1F));
                    break;
                default:
                    break;
                }
            }
        }

        // TODO: Pack into library (execute)
        glClearColor(0.2F, 0.3F, 0.3F, 1.0F);
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);

        freeCam.capture(&sceneRoot);
        sceneRoot.setRotation(rotation);
        rotation += 0.01F;

        window.display();
    }

    return 0;
}
