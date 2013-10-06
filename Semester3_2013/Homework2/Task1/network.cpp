#include "network.h"
#include <stdlib.h>

Network::Network(FILE *f)
{
    riskWindows = 6;
    riskLinux = 2;

    f = fopen("input.txt", "r");
    fscanf(f, "%i", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(f, "%i", &connections[i][j]);

    for (int i = 0; i < n; i++)
        fscanf(f, "%i", &os[i]);
    // 0 - is Linux, 1 - i Windows


    for (int i = 0; i < n; i++)
        fscanf(f, "%i", &virus[i]);

}

bool Network::isInfected(int risk)
{
    if (rand() % maxRisk < risk)
        return true;
    else
        return false;
}

void Network::tryToInfect(int k)
{
    for(int i = 0; i < n; i++)
    {
        if(connections[k][i] == 1 && virus[i] == 1)
        {
            int risk = 0;
            if (os[k] == 0)
                risk = riskLinux;
            else
                risk = riskWindows;

            if (isInfected(risk))
            {
                virus[k] = 1;
            }
        }
    }
}



void Network::update()
{
    for (int i = 0; i < n; i++)
    {
        if (virus[i] == 0)
            tryToInfect(i);
    }
}

bool Network::isWinOfVirus()
{
    for(int i = 0; i < n; i++)
    {
        if(virus[i] == 0)
            return false;
    }
    return true;
}

void Network::printState(int step)
{
    printf("Step %i\n", step);
    for (int i = 0; i < n; i++)
    {
        if(os[i] == 0)
        {
            printf("Linux    ");
            if(virus[i] == 1)
                printf("infected\n");
            else
                printf("not infected\n");
        }
        else
        {
            printf("Windows    ");
            if(virus[i] == 1)
                printf("infected\n");
            else
                printf("not infected\n");
        }
    }
}
