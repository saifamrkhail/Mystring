//
// Created by saif on 9/24/22.
//

#include "include/Mystring.h"

// constructor
Mystring::Mystring(const char *const str) {
    std::cout << "Constructor called " << std::endl;
    size_ = strlen(str);
    // + 1 for the keeping the null character
    str_ = new char[size_ + 1];
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

// copy assignment
Mystring& Mystring::operator=(const Mystring &obj) {
    std::cout << "Copy assignment operator called " << std::endl;
    //do clean up
    destroy();

    size_ = obj.size_;
    str_ = new char[size_ + 1]; // + 1 for the keeping the null character
    for (int i = 0; i < size_; ++i) {
        str_[i] = obj.str_[i];
    }
    str_[-1] = '\0';

    return *this;
}

// move constructor
Mystring::Mystring(Mystring&& dyingObj) noexcept {
    std::cout << "Move constructor called " << std::endl;
    //do clean up
    destroy();

    // Copy data from dying object
    size_ = dyingObj.size_;
    str_ = dyingObj.str_;
    str_[-1] = '\0';
    dyingObj.str_ = nullptr;
}

// move assignment
Mystring& Mystring::operator=(Mystring && dyingObj) {
    std::cout << "Move assignment operator called " << std::endl;
    //clean up
    destroy();

    // Copy data from the incoming object
    size_ = dyingObj.size_;

    // assign str and make dyingObj.str_ a nullptr
    str_ = dyingObj.str_;
    dyingObj.str_ = nullptr;
    str_[-1] = '\0';
    return *this;
}
//+operator
Mystring Mystring::operator+(const Mystring &obj) {
    std::cout << "+operator called " << std::endl;
    //TODO use append here
    Mystring newstr;
    newstr.size_ = this->size_ + obj.size_;
    newstr.str_ = new char[newstr.size_ + 1];

    for (int i = 0; i < size_; ++i) {
        newstr.str_[i] = str_[i];
    }

    for (int i = size_; i < newstr.size_; ++i) {
        newstr.str_[i] = obj.str_[i-size_];
    }

    return newstr;
}

//+=operator
Mystring& Mystring::operator+=(const Mystring& obj) {
    //TODO use append here
    char* oldstr = str_;
    size_t oldsize = size_;
    size_ = size_ + obj.size_;
    str_ = new char[size_ + 1]; // + 1 for the keeping the null character

    for (int i = 0; i < oldsize; ++i) {
        str_[i] = oldstr[i];
    }

    for (int i = 0; i < strlen(obj.str_); ++i) {
        str_[i+oldsize] = obj.str_[i];
    }

    str_[-1] = '\0';

    return *this;
}


//destructor
Mystring::~Mystring() {
    std::cout << "Destructor called " << std::endl;

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
