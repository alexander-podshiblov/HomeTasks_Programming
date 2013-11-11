#include "robograph.h"

RoboGraph::RoboGraph(FILE *f)
{
    fscanf(f, "%i", &numOfVertex);
    for (int i = 0; i < numOfVertex; i++)
    {
        for (int j = 0; j < numOfVertex; j++)
        {
            fscanf(f, "%i", &originalGraph[i][j]);
            modifiedGraph[i][j] = 0;
        }

    }
    fscanf(f, "%i", &numOfRobot);
    for (int i = 0; i < numOfRobot; i++)
    {
        fscanf(f, "%i", &robots[i]);
    }
}

void RoboGraph::modification()
{
    for (int i = 0; i < numOfVertex; i++)
    {
        int numOfAdjacentVertex = 0;
        int adjacentVertex[50];
        for (int j = 0; j < numOfVertex; j++)
        {
            if (originalGraph[i][j] == 1)
            {
                adjacentVertex[numOfAdjacentVertex] = j;
                numOfAdjacentVertex++;
            }
        }

        for (int j = 0; j < numOfAdjacentVertex - 1; j++)
        {
            for (int k = j + 1; k < numOfAdjacentVertex; k++)
            {
                modifiedGraph[adjacentVertex[j]][adjacentVertex[k]] = 1;
                modifiedGraph[adjacentVertex[k]][adjacentVertex[j]] = 1;
            }
        }
    }
}

void RoboGraph::dfs(int vertex)
{


    usedInDfs[vertex] = true;
    for(int i = 0; i < numOfRobot; i++)
    {
        if(robots[i] == vertex)
        {
            robotsInComps[numOfComps - 1]++;
        }
    }
    for (int i = 0; i < numOfVertex; i++)
    {
        if(modifiedGraph[vertex][i] == 1 && !usedInDfs[i])
        {
            dfs(i);
        }
    }
}

void RoboGraph::analise()
{
    modification();
    answer = true;
    numOfComps = 0;
    for(int i = 0; i < numOfVertex; i++)
        usedInDfs[i] = false;

    for (int i = 0; i < numOfVertex; i++)
    {
        if(!usedInDfs[i])
        {
            numOfComps++;
            dfs(i);
        }
    }
    for(int i = 0; i < numOfComps; i++)
    {
        if(robotsInComps[i] == 1)
        {
            answer = false;
            break;
        }
    }
}

bool RoboGraph::getAnswer()
{
    return answer;
}
