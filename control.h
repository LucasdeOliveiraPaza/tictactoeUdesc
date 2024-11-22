#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

void buildTable(char table[4][4]);

void showTable(char table[4][4]);

int inputValue(char table[4][4], char value, char line, char column);

int checkGameState(char table[4][4]);

#endif // CONTROL_H_INCLUDED
