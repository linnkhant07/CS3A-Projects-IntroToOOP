#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include <iostream>
#include <string.h>
#include "plot.h"

using namespace std;

class graph_info
{
public:
    graph_info(string eq, sf::Vector2f wd, sf::Vector2f origin, sf::Vector2f scale, sf::Vector2f domain) : _equation(eq), _window_dimensions(wd), _origin(origin), _scale(scale), _domain(domain) {}

private:
    string _equation;
    sf::Vector2f _window_dimensions;
    sf::Vector2f _origin;
    sf::Vector2f _scale;
    sf::Vector2f _domain;
    int points;
};

#endif