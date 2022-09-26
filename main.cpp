#include <iostream>
#include "include/Mystring.h"

int main() {
    char hello[] = "Hello, ";
    char world[] = "World!";
    //Mystring world("World!");
    Mystring mystring(hello);
    mystring.append(world);
    std::cout << mystring.c_str() << std::endl;
    std::cout << mystring.lenght() << std::endl;
    //test copy constructor
    Mystring mystring2 = mystring;
    std::cout << mystring2.c_str() << std::endl;
    std::cout << mystring2.lenght() << std::endl;

    //test copy assignment
    Mystring one("one"), two("two");
    two = one;
    Mystring three = one;
    std::cout << two.c_str() << std::endl;
    std::cout << three.c_str() << std::endl;

    //test move operator
    Mystring apple, apple2;

    //test move assignment
    std::cout << "Test move operator" << std::endl;
    apple = Mystring("Apple");
    std::cout << "apple = " << apple.c_str() << std::endl;

    apple2 = Mystring(apple);
    std::cout << "apple2 = " << apple2.c_str() << std::endl;
    std::cout << "apple = " << apple.c_str() << std::endl;

    std::cout << "Test +operator" << std::endl;
    Mystring orange("orange ");
    Mystring juice = "juice";
    Mystring orangejuice = orange + juice;
    std::cout << orangejuice.c_str() << std::endl;




    return 0;
}
