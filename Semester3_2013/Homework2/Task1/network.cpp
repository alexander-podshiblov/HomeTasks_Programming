#include "network.h"
#include <stdlib.h>

Network::Network(FILE *f, MyRand *r)
{



    f = fopen("input.txt", "r");
    fscanf(f, "%i", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fscanf(f, "%i", &connections[i][j]);

        comps[i] = new Computer();
        comps[i]->setRand(r);
    }
    for (int i = 0; i < n; i++)
    {
        int os;
        fscanf(f, "%i", &os); // 0 - is Linux, 1 - is Windows
        if (os == 0)
            comps[i]->setRisk(2);
        else if (os == 1)
            comps[i]->setRisk(6);
    }

    for (int i = 0; i < n; i++)
    {
        int inf;
        fscanf(f, "%i", &inf);
        comps[i]->setInf(inf);
    }

}



void Network::doStep()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (connections[i][j] == 1)
            {
                if (!comps[i]->isInfected() && comps[j]->isInfected())
                    comps[i]->tryToInfect();
                else if (comps[i]->isInfected() && !comps[j]->isInfected())
                    comps[j]->tryToInfect();

            }
        }
    }
}

bool Network::isWinOfVirus()
{
    for(int i = 0; i < n; i++)
    {
        if(!comps[i]->isInfected())
            return false;
    }
    return true;
}

void Network::printState(int step)
{
    printf("Step %i\n", step);
    for (int i = 0; i < n; i++)
    {
        if(comps[i]->getRisk() == 2)
        {
            printf("Linux    ");
            if(comps[i]->isInfected())
                printf("infected\n");
            else
                printf("not infected\n");
        }
        else if(comps[i]->getRisk() == 6)
        {
            printf("Windows    ");
            if(comps[i]->isInfected())
                printf("infected\n");
            else
                printf("not infected\n");
        }
    }
}
