#include "../inc/oop.hpp"
#include <cstdio>

using namespace std;

/* >>> Example for Encapsulation  */
Rectangle::Rectangle() {
    // numOfCorner = 4;
    setValues(100, 50, 4);
}
Rectangle::~Rectangle() {}

void Rectangle::setValues(int w, int h, int c) {
    mWidth = w;
    mHeight = h;
    numOfCorner = c;
}

int Rectangle::getArea(void) {
    return mWidth * mHeight;
}

int Rectangle::getPerimeter(void) {
    return 2 *  (mWidth + mHeight); 
}

void Rectangle::printfInfomation() {
    cout << __FUNCTION__ << ": Information of rectangle : \n";
    cout << "Num Of Corner  : " << numOfCorner << endl;
    cout << "Width          : " << mWidth << endl;
    cout << "Heigh          : " << mHeight << endl;
    cout << "Area           : " << getArea() << endl;
    cout << "Perimeter      : " << getPerimeter() << endl;
}

/* >>> Excample for Inheritance   */
Person::Person() {
    setPeople(123456789, "Duong");
}

Person::~Person() {}

void Person::setPeople(int id, char *name) {
    idCard = id;
    strcpy(zName, name);
}

int Person::getIdCard() {
    return idCard;
}

void Person::prinntfInfomationPerson() {
    // cout << __FUNCTION__ << ": Information of rectangle : \n";
    cout << "idCard  : " << idCard << endl;
    cout << "Name    : " << zName << endl;
}

Student::Student() {
    idStudent = getIdCard();
}

Student::~Student() {}

void Student::setStudent(float score) {
    zScore = score;
}

void Student::prinntfInfomationStudent() {

    cout << __FUNCTION__ << ": Information of student : \n";
    prinntfInfomationPerson();
    cout << "Score : " << zScore << endl;
}

/* Example for Polymorphism */
/* Ex 1 */
PrintfValues::PrintfValues(){}
PrintfValues::~PrintfValues(){ }

void PrintfValues::mPrintf(int i) {
    cout << "Value <int>   : " << i << endl;
}

void PrintfValues::mPrintf(double f) {
    cout << "Value <double> : " << f << endl;
}

void PrintfValues::mPrintf(char *c) {
    cout << "Value <char> : " << c << endl;
}

/* Ex 2 */
Pet::Pet(string n){
    nName = n;
}
Pet::~Pet(){}

string Pet::getSound() {
    return "";
}

void Pet::makeSound(void) {
    cout << nName << " says: " << getSound() << endl;
}

Cat::Cat(string n) : Pet(n){
}
Cat::~Cat(){};

string Cat::getSound() {
    return "Meow! Meow!";
}

Dog::Dog(string n) : Pet (n){
}
Dog::~Dog(){};

string Dog::getSound() {
     return "Woof! Woof!";
}

template <class T> void bubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}
  