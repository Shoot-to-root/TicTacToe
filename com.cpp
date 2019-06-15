#include <iostream>
#include "com.h"
using namespace std;

char board[ROW][COLUMN]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player, com;

void display()
{
    system("cls");
    cout << "Tic Tac Toe\n" << endl;

    for(int i=0; i<ROW; i++){
        for(int j=0; j<COLUMN; j++){
            cout <<" " << board[i][j];
            if(j < COLUMN-1)
                cout << " |";
        }
        cout << endl;
        if(i < ROW-1)
            cout << "-----------" << endl;
    }

    cout << endl;
}

void comMove(char comChar, char pChar)
{
    bool found=false;
    srand(time(NULL));
    //first row(horizontal)
    if(board[0][0] == pChar && board[0][1] == pChar && board[0][2] != comChar){
        board[0][2] = comChar;
        return;
    }
    else if(board[0][0] == pChar && board[0][2] == pChar && board[0][1] != comChar){
        board[0][1] = comChar;
        return;
    }
    else if (board[0][1] == pChar && board[0][2] == pChar && board[0][0] != comChar){
        board[0][0] = comChar;
        return;
    }
    //second row
    else if(board[1][0] == pChar && board[1][1] == pChar && board[1][2] != comChar){
        board[1][2] = comChar;
        return;
    }
    else if(board[1][1] == pChar && board[1][2] == pChar && board[1][0] != comChar){
        board[1][0] = comChar;
        return;
    }
    else if(board[1][0] == pChar && board[1][2] == pChar && board[1][1] != comChar){
        board[1][1] = comChar;
        return;
    }
    //third row
    else if(board[2][0] == pChar && board[2][1] == pChar && board[2][2] != comChar){
        board[2][2] = comChar;
        return;
    }
    else if(board[2][0] == pChar && board[2][2] == pChar && board[2][1] != comChar){
        board[2][1] = comChar;
        return;
    }
    else if(board[2][2] == pChar && board[2][1] == pChar && board[2][0] != comChar){
        board[2][0] = comChar;
        return;
    }
    //first column(vertical)
    else if(board[0][0] == pChar && board[1][0] == pChar && board[2][0] != comChar){
        board[2][0] = comChar;
        return;
    }
    else if(board[0][0] == pChar && board[2][0] == pChar && board[1][0] != comChar){
        board[1][0] = comChar;
        return;
    }
    else if(board[2][0] == pChar && board[1][0] == pChar && board[0][0] != comChar){
        board[0][0] = comChar;
        return;
    }
    //second column
    else if(board[0][1] == pChar && board[1][1] == pChar && board[2][1] != comChar){
        board[2][1] = comChar;
        return;
    }
    else if(board[0][1] == pChar && board[2][1] == pChar && board[1][1] != comChar){
        board[1][1] = comChar;
        return;
    }
    else if(board[2][1] == pChar && board[1][1] == pChar && board[0][1] != comChar){
        board[0][1] = comChar;
        return;
    }
    //third column
    else if(board[0][2] == pChar && board[1][2] == pChar && board[2][2] != comChar){
        board[2][2] = comChar;
        return;
    }
    else if(board[0][2] == pChar && board[2][2] == pChar && board[1][2] != comChar){
        board[1][2] = comChar;
        return;
    }
    else if(board[2][2] == pChar && board[1][2] == pChar && board[0][2] != comChar){
        board[0][2] = comChar;
        return;
    }
    //diagonal
    else if(board[0][0] == pChar && board[1][1] == pChar && board[2][2] != comChar){
        board[2][2] = comChar;
        return;
    }
    else if(board[0][0] == pChar && board[2][2] == pChar && board[1][1] != comChar){
        board[1][1] = comChar;
        return;
    }
    else if(board[2][2] == pChar && board[1][1] == pChar && board[0][0] != comChar){
        board[0][0] = comChar;
        return;
    }
    else if(board[0][2] == pChar && board[1][1] == pChar && board[2][0] != comChar){
        board[2][0] = comChar;
        return;
    }
    else if(board[0][2] == pChar && board[2][0] == pChar && board[1][1] != comChar){
        board[1][1] = comChar;
        return;
    }
    else if(board[2][0] == pChar && board[1][1] == pChar && board[0][2] != comChar){
        board[0][2] = comChar;
        return;
    }

    else {
        while(!found){
            int row=rand()%3;
            int col=rand()%3;
            if(board[row][col] != comChar && board[row][col] != pChar){
                board[row][col]=comChar;
                found=true;
                return;
            }
        }
    }

}

void alternate(char pChar)
{
    int choice;
    cout << "Enter a number: ";
    cin >> choice;

    //mark on grid
    if (choice == 1 && board[0][0] == '1')
        board[0][0]=pChar;
    else if(choice == 2 && board[0][1] == '2')
        board[0][1]=pChar;
    else if(choice == 3 && board[0][2] == '3')
        board[0][2]=pChar;
    else if (choice == 4 && board[1][0] == '4')
        board[1][0]=pChar;
    else if(choice == 5 && board[1][1] == '5')
        board[1][1]=pChar;
    else if(choice == 6 && board[1][2] == '6')
        board[1][2]=pChar;
    else if (choice == 7 && board[2][0] == '7')
        board[2][0]=pChar;
    else if(choice == 8 && board[2][1] == '8')
        board[2][1]=pChar;
    else if(choice == 9 && board[2][2] == '9')
        board[2][2]=pChar;
    else{
        cout << "Invalid Move.";
        cin.ignore();
        cin.get();
    }
}

int check(char comChar, char pChar)
{   //player
    if(board[0][0]==pChar && board[0][1]==pChar && board[0][2]==pChar)
        return 1;
    else if(board[1][0]==pChar && board[1][1]==pChar && board[1][2]==pChar)
        return 1;
    else if(board[2][0]==pChar && board[2][1]==pChar && board[2][2]==pChar)
        return 1;
    else if(board[0][0]==pChar && board[1][0]==pChar && board[2][0]==pChar)
        return 1;
    else if(board[0][1]==pChar && board[1][1]==pChar && board[2][1]==pChar)
        return 1;
    else if(board[0][2]==pChar && board[1][2]==pChar && board[2][2]==pChar)
        return 1;
    else if(board[0][0]==pChar && board[1][1]==pChar && board[2][2]==pChar)
        return 1;
    else if(board[0][2]==pChar && board[1][1]==pChar && board[2][0]==pChar)
        return 1;
    //computer
    if(board[0][0]==comChar && board[0][1]==comChar && board[0][2]==comChar)
        return 2;
    else if(board[1][0]==comChar && board[1][1]==comChar && board[1][2]==comChar)
        return 2;
    else if(board[2][0]==comChar && board[2][1]==comChar && board[2][2]==comChar)
        return 2;
    else if(board[0][0]==comChar && board[1][0]==comChar && board[2][0]==comChar)
        return 2;
    else if(board[0][1]==comChar && board[1][1]==comChar && board[2][1]==comChar)
        return 2;
    else if(board[0][2]==comChar && board[1][2]==comChar && board[2][2]==comChar)
        return 2;
    else if(board[0][0]==comChar && board[1][1]==comChar && board[2][2]==comChar)
        return 2;
    else if(board[0][2]==comChar && board[1][1]==comChar && board[2][0]==comChar)
        return 2;
    //draw
    else if(board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' && board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' && board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
        return 3;
    else return 0;
}

void result()
{
    cout << "Choose the character you prefer(X/O): ";
    cin >> player;
    if(player == 'X')
        com='O';
    else
        com='X';

    int first;
    cout << "Who's first?" << "(Com=1, Player=2): ";
    cin >> first;

    int win=0;
    int count=0;

    if(first == 1){
        while (win == 0) {
            if(count%2 == 0)
                comMove(com, player);
            else
                alternate(player);

            display();
            count++;

            if(check(com, player) == 1){
                cout << "Player wins!\nGame Over!\n";
                win=1;
                return;
            }
            else if(check(com, player) == 2){
                cout << "Computer wins!\nGame Over!\n";
                win=2;
                return;
            }

            else if (check(com, player) == 3) {
                cout << "Game Draw!\n";
                win=3;
                return;
            }
            else win=0;
        }
     }

    if(first == 2){
        while (win == 0) {
            display();

            if(count%2 == 0)
                alternate(player);
            else
                comMove(com, player);

            display();
            count++;

            if(check(com, player) == 1){
                cout << "Player wins!\nGame Over!\n";
                win=1;
                return;
            }
            else if(check(com, player) == 2){
                cout << "Computer wins!\nGame Over!\n";
                win=2;
                return;
            }

            else if (check(com, player) == 3) {
                cout << "Game Draw!\n";
                win=3;
                return;
            }
            else win=0;
        }
    }
}

