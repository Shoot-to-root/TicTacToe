#ifndef COM_H
#define COM_H
#include <cstdlib>
#include <time.h>
#define ROW 3
#define COLUMN 3



void display();
void comMove(char comChar,char pChar);
void alternate(char pChar);
int check(char comChar, char pChar);
void result();
void comMove(char comChar, char pChar);

#endif // COM_H
