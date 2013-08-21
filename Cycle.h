#ifndef CYCLE_H
#define CYCLE_H

class Cycle
{

public:
Cycle::Cycle();
void Cycle::makeCycle(float myarray[100][100]);
void Cycle::floyd();
int Cycle::getPath(int i, int j);
float path[100][100];
float next[100][100];

};

#endif
