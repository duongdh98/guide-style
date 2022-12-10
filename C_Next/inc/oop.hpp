#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>

class Animal
{
private:
    /* data */
    char *type;

public:
    char *nType;
    Animal();
    ~Animal();

    void getInfoAnimal();
    void show();
};

class Cat : public Animal 
{
private:
    /* data */
    int weigh;
    int heigh;
public:
    Cat();
    ~Cat();

    void getInfoCat();
    void show();
};