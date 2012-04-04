#pragma once
#include <stdio.h>

class MatrixIO
{
public:
    void scan(FILE *stream, int **a, int m, int n);
    void print(FILE *stream, int **a, int m, int n);
};

