#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "plot.h"
#include "graph_info.h"

using namespace std;

class Graph
{
public:
    Graph(graph_info *gi) : _info(gi) {}
    void setInfo();
    void update(graph_info *gi);
    void Draw(sf::RenderWindow &window);

    // void Print() const;

private:
    graph_info *_info;
    plot _plotter;
    vector<sf::Vector2f> _screen_cords;
};

#endif