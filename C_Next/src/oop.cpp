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

/* Set */
// Set là một dạng cấu trúc dữ liệu dùng để lưu trữ các phần tử không trùng lặp 
// và được sắp xếp theo thứ tự tăng dần hoặc giảm dần. (Mặc định trong setset là 
// tăng dần và chúng ta có thể viết lại hàm so sánh theo mục đích của chúng ta)

/* List */
// List trong C++ là một danh sách liên kết đôi được sử dụng làm tiêu chuẩn để xử lý các 
// đối tượng chứa nhiều phần tử trong C++.

// Danh sách liên kết đôi ở đây có nghĩa là từng Node trong danh sách sẽ chứa thông 
// tin vị trí của Node đứng trước và sau nó, nên việc xác định vị trí của một Node trong danh sách 
// sẽ trở nên dễ dàng hơn với độ phức tạp của thuật toán sẽ là O(1) mà thôi.

/* Vector */
// Vector trong C++ là các mảng động (dynamic array) dùng để lưu trữ dữ liệu. 
// Khác với array – dùng để lưu trữ dữ liệu tuần tự và có bản chất tính, các vector có độ linh hoạt cao hơn nhiều. 
// Vector có thể tự động resize khi có phần tử được chèn hay xoá khỏi array, trong khi đó array thường có kích thước cố định.

/* Map */
// Map trong C++ là một tập hợp các phần tử được sắp xếp theo thứ tự cụ thể, 
// mà mỗi phần tử trong đó được hình thành bởi sự kết hợp của một cặp khóa và giá trị (key & value), 
// với mỗi khóa là duy nhất trong map.
