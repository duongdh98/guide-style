#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;

/* >>> Example for Encapsulation  */
class Rectangle {

private:
    int mWidth;
    int mHeight;

public:
    Rectangle();
    ~Rectangle();
    void setValues(int w, int h, int c);
    int getArea(void);
    int getPerimeter(void);
    void printfInfomation();

protected:
    int numOfCorner;
};

/* >>> Excample for Inheritance   */
class Person
{

private:
    int idCard;

public:
    Person();
    ~Person();
    char zName[100];
    void setPeople(int id, char *name);
    int getIdCard();
    void prinntfInfomationPerson();
};

class Student: public Person
{
private:
    int idStudent;
    float zScore;

public:
    Student();
    ~Student();
    void setStudent(float score);
    void prinntfInfomationStudent();
};

/* Example for Polymorphism */
/* Ex 1 */
class PrintfValues
{
private:
public:
    PrintfValues();
    ~PrintfValues();

    void mPrintf(int i);
    void mPrintf(double f);
    void mPrintf(char *c);
};

/* Ex 2 */
class Pet
{
private:
protected:
    string nName;
public:
    Pet(string n);
    ~Pet();
    virtual string getSound();
    void makeSound(void);
};

class Cat : public Pet {
public:
    Cat(string n);
    ~Cat();
    string getSound();
};

class Dog : public Pet {
public:
    Dog(string n);
    ~Dog();
    string getSound();
};