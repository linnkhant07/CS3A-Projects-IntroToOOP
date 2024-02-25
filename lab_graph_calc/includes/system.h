#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
class System
{
public:
    System();
    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow &widnow);

private:
    //    vector<Particle> system;
    vector<sf::CircleShape *> shapes;
    vector<sf::Vector2f> vels;
};

#endif // SYSTEM_H
