//
// Created by saif on 9/24/22.
//

#include "include/Mystring.h"

// constructor
Mystring::Mystring(const char *const str) {
    size_ = strlen(str);
    str_ = new char[size_ + 1]; // + 1 for the keeping the null character
    for (int i = 0; i < size_; ++i) {
        str_[i] = str[i];
    }
};

// copy constructor
Mystring::Mystring(const Mystring& obj) {
    std::cout << "Copy constructor called " << std::endl;
    size_ = obj.size_;
    str_ = new char[size_ + 1];
    for (int i = 0; i < size_; ++i) {
        str_[i] = obj.str_[i];
    }
    str_[-1] = '\0';
}

// move constructor
Mystring::Mystring(Mystring&& dyingObj) {
    //do clean up
    destroy();

    // Copy data from dying object
    size_ = dyingObj.size_;
    str_ = dyingObj.str_;
    dyingObj.str_ = nullptr;
}

// move constructor
/*Mystring::Mystring& operator=(Mystring && dyingObj) {
    //__cleanup__(); // cleanup any existing data

    // Copy data from the incoming object
    size_ = dyingObj.size_;

    // Transfer ownership of underlying char buffer from incoming object to this object
    str = dyingObj.str;
    dyingObj.str = nullptr;

    return *this;
}*/

Mystring::~Mystring() {
    if (str_ != nullptr) {
        str_ = nullptr;
        delete[] str_;
    }
}

void Mystring::append(const char* str) {
    char* old_str = this->str_;
    size_t old_size = lenght();
    size_t new_size = lenght() + strlen(str);
    size_ = new_size;
    str_ = new char[new_size + 1];

    for (int i = 0; i < old_size; ++i) {
       str_[i] = old_str[i];
    }

    for (int i = old_size; i < new_size; ++i) {
        str_[i] = str[i-old_size];
    }

    str_[-1] = '\0';
}

void Mystring::append(Mystring const &mystring) {
    Mystring::append(mystring.c_str());
}

const char* Mystring::c_str() const {
    return str_;
}

const size_t Mystring::lenght() const {
    return strlen(str_);
}

void Mystring::destroy() {
    if ( str_ != nullptr) {
        delete[] str_;
    }
    size_ = 0;
}
