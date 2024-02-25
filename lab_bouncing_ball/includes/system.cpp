#include "system.h"
#include "random.h"
#include "constants.h"
#include "graph_info.h"
#include "Graph.h"
#include <iostream>

System::System(graph_info *info) : G(info)
{
}

// System::System(graph_info *info)
// {
//     Graph g(info);
// }

//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command)
{
}
void System::Step(int command, graph_info *info)
{
}

void System::Draw(sf::RenderWindow &window)
{
    G.Draw(window);
}
