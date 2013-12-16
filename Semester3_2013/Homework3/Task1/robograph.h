#pragma once
#include <stdio.h>

class RoboGraph
{
public:
    RoboGraph();
    RoboGraph(FILE *f);
    void setFile(FILE *f);
    void analise();
    bool getAnswer();

private:
    int numOfVertex;
    int numOfRobot;
    int robots[50];
    int originalGraph[50][50];
    int modifiedGraph[50][50];
    bool usedInDfs[50];
    int numOfComps;
    int robotsInComps[50];
    bool answer;
    void modification();
    void dfs(int vertex);

};

