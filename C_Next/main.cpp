#include <cstdio>
#include "inc/oop.hpp"

using namespace std;

int main (int argc, char *argv[]) 
{
    printf(">>> Begin ================================================================== \n");

    Cat nCat;
    Animal *nAnimal = &nCat;
    nAnimal->show();

    printf(">>> End ==================================================================== \n");
    return 0;
}