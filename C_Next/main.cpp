#include <cstdio>
#include "inc/oop.hpp"

using namespace std;

int main (int argc, char *argv[]) 
{
    printf(">>> Begin ================================================================== \n");

    Rectangle zRectangle;
    zRectangle.printfInfomation();
    cout << "\n========================================= \n";

    Student zStudent;
    zStudent.setStudent(7.5);
    zStudent.prinntfInfomationStudent();
    cout << "\n========================================= \n";

    PrintfValues zPrintfValues;
    zPrintfValues.mPrintf(7);
    zPrintfValues.mPrintf(7.777);
    zPrintfValues.mPrintf("Duong");
    cout << "\n========================================= \n";

    Cat *zCat = new Cat("Kitty");
    zCat->makeSound();
    delete zCat;

    Dog *zDog = new Dog("Doggie");
    zDog->makeSound();
    delete zDog;

    cout << "\n========================================= \n";
    
    printf(">>> End ==================================================================== \n");
    system("pause");
    return 0;
}