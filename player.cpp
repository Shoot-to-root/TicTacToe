#include <iostream>
#include "player.h"
using namespace std;

char grid[ROW][COLUMN]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char p1, p2;

void draw()
{
    system("cls");
    cout << "Tic Tac Toe\n" << endl;

    for(int i=0; i<ROW; i++){
        for(int j=0; j<COLUMN; j++){
            cout <<" " << grid[i][j];
            if(j < COLUMN-1)
                cout << " |";
        }
        cout << endl;
        if(i < ROW-1)
            cout << "-----------" << endl;
    }

    cout << endl;
}

int checkWin()
{   //p1
    if(grid[0][0]==p1 && grid[0][1]==p1 && grid[0][2]==p1)
        return 1;
    else if(grid[1][0]==p1 && grid[1][1]==p1 && grid[1][2]==p1)
        return 1;
    else if(grid[2][0]==p1 && grid[2][1]==p1 && grid[2][2]==p1)
        return 1;
    else if(grid[0][0]==p1 && grid[1][0]==p1 && grid[2][0]==p1)
        return 1;
    else if(grid[0][1]==p1 && grid[1][1]==p1 && grid[2][1]==p1)
        return 1;
    else if(grid[0][2]==p1 && grid[1][2]==p1 && grid[2][2]==p1)
        return 1;
    else if(grid[0][0]==p1 && grid[1][1]==p1 && grid[2][2]==p1)
        return 1;
    else if(grid[0][2]==p1 && grid[1][1]==p1 && grid[2][0]==p1)
        return 1;
    //p2
    if(grid[0][0]==p2 && grid[0][1]==p2 && grid[0][2]==p2)
        return 1;
    else if(grid[1][0]==p2 && grid[1][1]==p2 && grid[1][2]==p2)
        return 1;
    else if(grid[2][0]==p2 && grid[2][1]==p2 && grid[2][2]==p2)
        return 1;
    else if(grid[0][0]==p2 && grid[1][0]==p2 && grid[2][0]==p2)
        return 1;
    else if(grid[0][1]==p2 && grid[1][1]==p2 && grid[2][1]==p2)
        return 1;
    else if(grid[0][2]==p2 && grid[1][2]==p2 && grid[2][2]==p2)
        return 1;
    else if(grid[0][0]==p2 && grid[1][1]==p2 && grid[2][2]==p2)
        return 1;
    else if(grid[0][2]==p2 && grid[1][1]==p2 && grid[2][0]==p2)
        return 1;
    //draw
    else if(grid[0][0] != '1' && grid[0][1] != '2' && grid[0][2] != '3' && grid[1][0] != '4' && grid[1][1] != '5' && grid[1][2] != '6' && grid[2][0] != '7' && grid[2][1] != '8' && grid[2][2] != '9')
        return 2;
    else return 0;
}

void secondResult()
{
    cout << "Choose 'X' or 'O' to start the game." << endl;
    cout << "Player 1: " ;
    cin >> p1;

    if(p1 == 'X')
        p2='O';
    else
        p2='X';

    int choice;
    int player=0;
    int win=0;
    char mark;

    while(win == 0){
        draw(); //display game grid

        //player alternate
        if(player%2 == 0)
            cout << "Player 1 enter a number: ";
        else
            cout << "Player 2 enter a number: ";
        cin >> choice;

        //player's marker alternate
        if(player%2 == 0)
            mark=p1;
        else
            mark=p2;

        //mark on grid
        if (choice == 1 && grid[0][0] == '1')
            grid[0][0]=mark;
        else if(choice == 2 && grid[0][1] == '2')
            grid[0][1]=mark;
        else if(choice == 3 && grid[0][2] == '3')
            grid[0][2]=mark;
        else if (choice == 4 && grid[1][0] == '4')
            grid[1][0]=mark;
        else if(choice == 5 && grid[1][1] == '5')
            grid[1][1]=mark;
        else if(choice == 6 && grid[1][2] == '6')
            grid[1][2]=mark;
        else if (choice == 7 && grid[2][0] == '7')
            grid[2][0]=mark;
        else if(choice == 8 && grid[2][1] == '8')
            grid[2][1]=mark;
        else if(choice == 9 && grid[2][2] == '9')
            grid[2][2]=mark;
        else{
            cout << "Invalid Move.";
            player--;
            cin.ignore();
            cin.get();
        }

        if(checkWin() == 1)
            win=1;
        else if(checkWin() == 2)
            win=2;
        else
            win=0;

        player++;
    }

    draw();
    if(win == 1)
        cout << "We have a winner!\n\n---Game Over!---\n" << endl;
    else
        cout << "--Game Draw!--\n" << endl;
}


