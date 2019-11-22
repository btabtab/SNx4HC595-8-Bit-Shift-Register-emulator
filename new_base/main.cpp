#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */

#include "sfml_variables_header.h"
#include "class_mouse.h"


using namespace std;

sf::VertexArray cameraline(sf::Lines, 4);// the line from the current point to the camera

sf::Clock time_elapsed; //main_clock

sf::RectangleShape background;

void draw()
{

    window.clear();

    window.draw(background);
    window.draw(X_hair.body);

    window.display();
    window.setView(camera);

}



int main()
{
//camera.zoom(0.02);

background.setFillColor(sf::Color::White);
background.setSize(sf::Vector2f(window.getSize()));

window.setMouseCursorVisible(false);
X_hair.sprite_load_apply();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /// ////////////////////////////////////////////



        X_hair.pos_apply();
        draw();


        /// ////////////////////////////////////////////
    }

    return 0;
}
