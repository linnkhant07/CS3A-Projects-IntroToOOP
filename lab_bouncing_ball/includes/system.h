#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>

#include "graph_info.h"
#include "Graph.h"
#include "plot.h"

using namespace std;
class System
{
public:
    // System() {}
    System(graph_info *info); // new
    void Step(int command);
    void Step(int command, graph_info *info); // new
    void Draw(sf::RenderWindow &widnow);

private:
    Graph G;
};

#endif // SYSTEM_H
