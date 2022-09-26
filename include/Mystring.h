//
// Created by saif on 9/24/22.
//

#ifndef STRING_MYSTRING_H
#define STRING_MYSTRING_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <ostream>

class Mystring {

public:
    //default constructor
    Mystring() : str_(nullptr), size_(0) {

    };

    // constructor
    Mystring(const char *const str);

    // copy constructor
    Mystring(const Mystring &obj);

    // copy assignment
    Mystring& operator=(const Mystring &obj);

    // move constructor
    Mystring(Mystring&& dyingObj) noexcept;

    // move assignment
    Mystring& operator=(Mystring&& dyingObj);

    //+operator
    Mystring operator+(const Mystring &obj);

    //+=operator
    Mystring& operator+=(const Mystring& obj);

    //destructor
    ~Mystring();

    void append(const char *str); //concat strings
    void append(Mystring const &str); //concat strings

    const char *c_str() const; //access to str_
    const size_t lenght() const;

private:
    char *str_ = nullptr;
    size_t size_ = 0;

    void destroy();
};


#endif //STRING_MYSTRING_H
