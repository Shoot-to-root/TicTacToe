#include <iostream>
#include "com.h"
#include "player.h"
using namespace std;

int main()
{
    cout << "//////////////////////////////////////////////////////////////////////////\n"
         << "///                                                                    ///\n"
         << "///                    Welcome to my Tic Tac Toe Project!              ///\n"
         << "///           Press (1) for single player, (2) for multiplayers.       ///\n"
         << "///                                                                    ///\n"
         << "//////////////////////////////////////////////////////////////////////////\n\n";
    int n;
    cout << "Single player or multiple players?: ";
    cin >> n;

    if(n == 1)
        result();

    if(n == 2)
        secondResult();

    return 0;

}
