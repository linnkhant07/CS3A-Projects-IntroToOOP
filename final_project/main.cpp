#include <iostream>
#include "includes/graphing/animate.h"
using namespace std;

int main()
{
    animate game;
    game.run();
    cout << endl
         << endl
         << "------ MAIN EXITING --------------------------" << endl;
    return 0;
}
