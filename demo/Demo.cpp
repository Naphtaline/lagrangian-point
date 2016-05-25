//
//  Demo.cpp
//  LagrangianPoint
//
//  Created by Xiaxing SHI on 07/05/16.
//  Copyright © 2016 Dimgai. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <Vector.hpp>
#include <Engine.hpp>
#include <CircleCollider.hpp>
#include "PlanetDemo.hpp"
#include "PlayerDemo.hpp"

int main(int, char const**)
{
    // Create the main window
    auto modes = sf::VideoMode::getFullscreenModes();
    sf::VideoMode modeToUse;
    for (auto mode : modes) {
        if (modeToUse.width < mode.width) {
            modeToUse = mode;
        }
    }
    modeToUse.width = modeToUse.width / 2;
    modeToUse.height = modeToUse.height / 2;
    sf::RenderWindow window(modeToUse, "Lagrangian Point Engine");
    window.setVerticalSyncEnabled(true);
    
    auto unit = modeToUse.width / 100.0f;

    // Load sprites to display
    sf::Texture textureBackground;
    if (!textureBackground.loadFromFile("resources/Background.png")) {
        return EXIT_FAILURE;
    }
    sf::RectangleShape backgroud(sf::Vector2f(modeToUse.width, modeToUse.height));
    backgroud.setTexture(&textureBackground);

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile("resources/icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load sprites to display
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("resources/Player.png")) {
        return EXIT_FAILURE;
    }
    sf::Texture texturePlanet1;
    if (!texturePlanet1.loadFromFile("resources/Planet1.png")) {
        return EXIT_FAILURE;
    }
    sf::Texture texturePlanet2;
    if (!texturePlanet2.loadFromFile("resources/Planet2.png")) {
        return EXIT_FAILURE;
    }
    sf::Texture texturePlanet3;
    if (!texturePlanet3.loadFromFile("resources/Planet3.png")) {
        return EXIT_FAILURE;
    }
    // create a Rigidbody
    auto player = std::make_shared<PlayerDemo>(3.5f * unit, physics::Vector(2 * unit, 0));
    player->setPosition(modeToUse.width / 2, modeToUse.height / 2);
    player->setTexture(&texturePlayer);
    player->setForceValue(unit / 6);
    auto playerCollider = std::make_shared<physics::CircleCollider>(physics::Vector(), 3.5f * unit);
    playerCollider->setAttachedRigidbody(player);
    
    // create planet 1
    auto planet1 = std::make_shared<PlanetDemo>(20 * unit, 20 * unit, 6.6f * unit);
    planet1->setOrigin(10 * unit, 10.6f * unit);
    planet1->setPosition(18 * unit, 16 * unit);
    planet1->setTexture(&texturePlanet1);
    planet1->a = unit / 25;
    auto planet1Collider = std::make_shared<physics::CircleCollider>(planet1->getCenter(), planet1->getGravityRadius());

    // create planet 2
    auto planet2 = std::make_shared<PlanetDemo>(20 * unit, 20 * unit, 10 * unit);
    planet2->setPosition(80 * unit, 23 * unit);
    planet2->a = unit / 15;
    planet2->setTexture(&texturePlanet2);
    auto planet2Collider = std::make_shared<physics::CircleCollider>(planet2->getCenter(), planet2->getGravityRadius());

    // create planet 3
    auto planet3 = std::make_shared<PlanetDemo>(16 * unit, 20 * unit, 8 * unit);
    planet3->setPosition(36 * unit, modeToUse.height - 22 * unit);
    planet3->a = unit / 20;
    planet3->setTexture(&texturePlanet3);
    planet3->setOrigin(8 * unit, 8 * unit);
    auto planet3Collider = std::make_shared<physics::CircleCollider>(planet3->getCenter(), planet3->getGravityRadius());

    // setup movement area
    physics::Engine::get().setMovementArea(3.5f * unit, 3.5f * unit, window.getSize().x - 3.5f * unit, window.getSize().y - 3.5f * unit);

    // add player & planets
    physics::Engine::get().addRigidbody(player);
    physics::Engine::get().addGravity(planet1);
    physics::Engine::get().addGravity(planet2);
    physics::Engine::get().addGravity(planet3);
    physics::Engine::get().addCollider(playerCollider);
    physics::Engine::get().addCollider(planet1Collider);
    physics::Engine::get().addCollider(planet2Collider);
    physics::Engine::get().addCollider(planet3Collider);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // listen key pressed to do things
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Escape: // reset the demo
                        player->setPosition(modeToUse.width / 2, modeToUse.height / 2);
                        player->rbSetVelocity(physics::Vector(2 * unit, 0));
                        player->rbSetUseGravity(true);
                        break;
                    case sf::Keyboard::Space: // jump when landed
                        player->jump();
                        break;
                    case sf::Keyboard::W: // go up
                    case sf::Keyboard::Up: {
                        player->setForce(0, -1);
                        break;
                    }
                    case sf::Keyboard::S: // go down
                    case sf::Keyboard::Down: {
                        player->setForce(0, 1);
                        break;
                    }
                    case sf::Keyboard::D: // go right
                    case sf::Keyboard::Right: {
                        player->setForce(1, 0);
                        break;
                    }
                    case sf::Keyboard::A: // go left
                    case sf::Keyboard::Left: {
                        player->setForce(-1, 0);
                        break;
                    }
                    default:
                        break;
                }
            }

            if (event.type == sf::Event::KeyReleased) {
                player->setForce(0, 0);
            }
        }

        // recalculate player's position
        physics::Engine::get().update();

        // Clear screen
        window.clear();

        // redraw player & planets
        window.draw(backgroud);
        window.draw(*player);
        window.draw(*planet1);
        window.draw(*planet2);
        window.draw(*planet3);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
