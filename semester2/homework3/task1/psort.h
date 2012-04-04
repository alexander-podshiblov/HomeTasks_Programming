#include "sort.h"
#include <stdio.h>
#pragma once

class PSort : public Sort
{
public:
    void sorting(int *m, int n);

private:
    void swap(int *a, int i, int j);
    void screening(int *a, int i, int n);
    void sort(int *a, int n);
};

