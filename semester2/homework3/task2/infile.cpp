#include "infile.h"
#include "outputer.h"
#include <stdio.h>

InFile::InFile()
{
    f = fopen("output.txt", "w");
}

InFile::~InFile()
{
    fclose(f);
}

void InFile::print(int elem)
{
    fprintf(f, "%i ", elem);
}
