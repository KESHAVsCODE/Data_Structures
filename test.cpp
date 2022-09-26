#include<iostream>
#include<stdio.h>
using namespace std;
int* hell(int *t)
{
    if(1)
    printf("%u",t);
    else
        return &t;
}
int main()
{
    int k=3;
    printf(" %u",hell(&k));
}
