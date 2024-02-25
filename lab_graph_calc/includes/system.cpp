#include "system.h"
#include "random.h"
#include "constants.h"
#include <iostream>

System::System()
{
    Random r;
    // int xpos = 100;
    // int ypos = 100;
    // the shape of the object, along with its velocity, acceleration,
    // position, etc. should be part of the individual object.
    for (int i = 0; i < 30; i++)
    {
        sf::CircleShape *ptr = new sf::CircleShape(r.Next(5, 50));
        ptr->setPosition(sf::Vector2f(r.Next(0, 1352), r.Next(0, 752)));
        vels.push_back(sf::Vector2f(r.Next(-5, 5), r.Next(1, 5)));
        int r_ = r.Next(0, 255);
        int g_ = r.Next(0, 255);
        int b_ = r.Next(0, 255);
        ptr->setFillColor(sf::Color(r_, g_, b_));
        shapes.push_back(ptr);
    }
}

//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command)
{

    // all this is the responsibility of the
    //  individual object:
    for (int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->move(vels[i]);
        sf::Vector2f pos = shapes[i]->getPosition();
        if ((pos.x) >= WORK_PANEL - 20)
            vels[i] = sf::Vector2f(-1 * vels[i].x, 1 * vels[i].y);
        if (pos.x <= 0)
            vels[i] = sf::Vector2f(-1 * vels[i].x, 1 * vels[i].y);
        if ((pos.y) >= SCREEN_HEIGHT - 20)
            vels[i] = sf::Vector2f(1 * vels[i].x, -1 * vels[i].y);
        if (pos.y <= 0)
            vels[i] = sf::Vector2f(1 * vels[i].x, -1 * vels[i].y);
    }
}

void System::Draw(sf::RenderWindow &window)
{
    window.clear();
    for (sf::CircleShape *ptr : shapes)
    {
        window.draw(*ptr);
    }
}
