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

    //TODO why can't I implement the copy assignment operator in .cpp file?
    // I get errors there

    // copy assignment
    Mystring &operator=(const Mystring &obj) {
        std::cout << "Copy assignment operator called " << std::endl;
        //do clean up
        destroy();

        size_ = obj.size_;
        str_ = new char[size_ + 1]; // + 1 for the keeping the null character
        for (int i = 0; i < size_; ++i) {
            str_[i] = obj.str_[i];
        }
        return *this;
    }

    // move constructor
    Mystring(Mystring&& dyingObj);

    Mystring &operator=(Mystring &&dyingObj); // move assignment

    ~Mystring(); //destructor

    void append(const char *str); //concat strings
    void append(Mystring const &str); //concat strings

    Mystring operator+(const Mystring &obj) {
        Mystring ns; // create a new string named 's'
        ns.size_ = this->size_ + obj.size_;
        ns.str_ = new char[ns.size_ + 1]; // allocate memory to keep the concatenated string
        //strncpy_s(ns.str_, this->str_ + 1, this->str_, this->size_); // copy the 1st string
        //strncpy_s(ns.str_ + this->size_, obj.size_ + 1, obj.str_, obj.size_);

        return ns;
    }

    const char *c_str() const; //access to str_
    const size_t lenght() const;

private:
    //TODO str_ kann nicht wie in der Angabe als const char* deklariert werden
    // sonst kann im constructor str_ nicht gesetzt werden.
    char *str_ = nullptr;
    size_t size_ = 0;

    void destroy();
};


#endif //STRING_MYSTRING_H
