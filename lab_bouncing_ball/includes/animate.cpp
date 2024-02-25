#include "animate.h"
#include "constants.h"
#include <iostream>
#include "system.h"
using namespace std;

animate::animate() : sidebar(WORK_PANEL, SIDE_BAR), system(info)

{
    cout << "animate CTOR: TOP" << endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");

    // GRAPH INFO
    // stubs for now
    string equation = "y=x";
    graph_info *info = new graph_info(equation, sf::Vector2f(SCREEN_HEIGHT, SCREEN_WIDTH), sf::Vector2f(SCREEN_HEIGHT / 2, SCREEN_HEIGHT / 2), sf::Vector2f(10, 10), sf::Vector2f(-5, 5));

    //------------------------------------------------------
    system = System(info);
    window.setFramerateLimit(60);

    mouseIn = true;

    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout << "Geme CTOR. preparing to load the font." << endl;
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "animate() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }

    myTextLabel = sf::Text("Initial String for myTextLabel", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setFillColor(sf::Color::Green);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT - myTextLabel.getLocalBounds().height - 5));
    cout << "animate instantiated successfully." << endl;
}

void animate::Step(int command)
{
    system.Step(command);
}

void animate::Draw()
{
    // Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn)
    {
        window.draw(mousePoint);
    }

    sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    // getPosition() gives you screen coords, getPosition(window) gives you window coords
    // cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    // drawing Test: . . . . . . . . . . . .
    // This is how you draw text:)
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}

void animate::update()
{
    // cause changes to the data for the next frame
    system.Step(command);
    command = 0;
    if (mouseIn)
    {
        // mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x - 5,
                               sf::Mouse::getPosition(window).y - 5);

        // mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
    }
}
void animate::render()
{
    window.clear();
    Draw();
    window.display();
}

void animate::processEvents()
{
    sf::Event event;
    float mouseX, mouseY;
    while (window.pollEvent(event)) // or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;

        // key pressed
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
                sidebar[SB_KEY_PRESSED] = "LEFT ARROW";
                command = 4;
                break;
            case sf::Keyboard::Right:
                sidebar[SB_KEY_PRESSED] = "RIGHT ARROW";
                command = 6;
                break;
            case sf::Keyboard::Escape:
                sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                window.close();
                break;
            }

            break;
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
            break;

        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            // Do something with it if you need to...
            break;
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                                            mouse_pos_string(window);
            }
            else
            {
                sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                                            mouse_pos_string(window);
            }
            break;

        default:
            break;
        }
    }
}
void animate::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render(); // clear/draw/display
    }
    cout << endl
         << "-------ANIMATE MAIN LOOP EXITING ------------" << endl;
}

string mouse_pos_string(sf::RenderWindow &window)
{
    return "(" +
           to_string(sf::Mouse::getPosition(window).x) +
           ", " +
           to_string(sf::Mouse::getPosition(window).y) +
           ")";
}
