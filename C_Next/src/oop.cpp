#include "../inc/oop.hpp"
#include <cstdio>

using namespace std;

/* >>> Anime module =======================================================  */
Animal::Animal() {
    printf(">>> Init information for Animal ================ \n");
    this->type = "animal type";
    nType = "nAnimal type";
}

Animal::~Animal() {
    printf(">>> Clear information for animal =============== \n");
}

void Animal::getInfoAnimal() {
    printf(">>> Get Information of cat : \n");
    printf(">>> Type : %s \n", this->type);
}

void Animal::show() {
    printf(">>> animal class ===================  \n");
}

/* >>> End anime module =======================================================  */

/* >>> Cai module =======================================================  */
Cat::Cat() {
    printf(">>> Init information for cat ================ \n");
    this->heigh = 50;
    this->weigh = 1500;
}

Cat::~Cat() {
    printf(">>> Clear information for cat =============== \n");
}

void Cat::getInfoCat() {
    printf(">>> Get Information of cat : \n");
    printf(">>> Heigh : %d \n", this->heigh);
    printf(">>> Weigh : %d \n", this->weigh);
}

void Cat::show() {
    printf(">>> cat class ===================  \n");
}

/* >>> End Cat module =======================================================  */