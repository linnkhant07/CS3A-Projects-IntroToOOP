#ifndef PLOT_H
#define PLOT_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "graph_info.h"

using namespace std;

class plot
{
public:
    /*Plot(graph_info* gi): _info(gi){}
void update(graph_info* updated_gi);
vector2f set_info();
vector 2f operator();


private:
_info
Queue<Token*> _post_fix;*/
    plot(graph_info *gi) : _info(gi) {}

private:
    graph_info *_info;
};
#endif