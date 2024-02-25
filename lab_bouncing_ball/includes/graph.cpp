#include <iostream>
#include "graph.h"
#include "constants.h"

using namespace std;

void Graph::setInfo()
{
}
void Graph::update(graph_info *gi)
{
}

void Graph::Draw(sf::RenderWindow &window)
{
    window.clear();

    for (int i = 0; i < NUM_OF_POINTS; i++)
    {
        // y = x
        _screen_cords.push_back(sf::Vector2f(i, SCREEN_HEIGHT / 2));
    }

    // now draw
    for (int i = 0; i < _screen_cords.size(); i++)
    {
        sf::CircleShape point(RADIUS);
        point.setFillColor(sf::Color::Yellow);
        point.setPosition(_screen_cords[i]);
        window.draw(point);
    }
}