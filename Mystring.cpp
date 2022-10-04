//Mystring is a simple implementation of C++ string.
//
// Created by saif on 9/24/22.
//

#include "Mystring.h"

/*
* =================================================
* Myiterator
* =================================================
*/

Mystring::Myiterator Mystring::begin() const {

    return Mystring::Myiterator(&m_str[0]);
}

Mystring::Myiterator Mystring::end() const {

    return Mystring::Myiterator(&m_str[m_size]);
}

/*
 * =================================================
 * Constructors
 * =================================================
 */

//default constructor
Mystring::Mystring() {

    m_init(INIT_BUFF);
}

Mystring::Mystring(const char *str) {

    m_init(length(str));
    m_copy(str);
}

// copy constructor
Mystring::Mystring(const Mystring &obj) {

    m_init(length(obj.c_str()));
    m_copy(obj.c_str());
}


// move constructor
Mystring::Mystring(Mystring &&dyingObj) noexcept {

    const char *ptr = dyingObj.c_str();
    m_init(length(ptr));
    m_copy(ptr);
    dyingObj.m_size = 0;
    dyingObj.m_buff = 0;
    dyingObj.m_str = nullptr;
}

/*
 * =================================================
 * Destructor
 * =================================================
 */

Mystring::~Mystring() {

    if (m_str != nullptr) {
        delete[] m_str;
        m_str = nullptr;
    }
}

/*
 * =================================================
 * Operators
 * =================================================
 */

// copy assignment
Mystring &Mystring::operator=(const Mystring &obj) {

    if (this != &obj) {
        const char *str = obj.c_str();
        size_t size = length(str);

        if (size > this->m_buff) {
            m_realloc(size);
        } else {
            size_t i = 0;
            while (m_str[i] != '\0') {
                m_str[i++] = '\0';
            }
        }

        for (size_t i = 0; i < size; i++) {
            m_str[i] = str[i];
        }

        m_size = length(m_str);
        return *this;
    }
    return *this;
}

// move assignment
Mystring &Mystring::operator=(Mystring &&dyingObj) noexcept {

    if (&dyingObj != this) {
        m_realloc(length(dyingObj.c_str()));
        // m_move data from the incoming object
        m_str = dyingObj.m_str;
        m_size = length(m_str);
        //reset dyingObj
        dyingObj.m_size = 0;
        dyingObj.m_buff = 0;
        dyingObj.m_str = nullptr;
    }

    return *this;
}

//+operator
Mystring Mystring::operator+(const Mystring &obj) {

    m_append(obj.c_str());
    return *this;
}

//+operator
Mystring Mystring::operator+(const char *str) {
    m_append(str);
    return *this;
}

//+=operator
Mystring &Mystring::operator+=(const Mystring &obj) {

    m_append(obj.c_str());
    return *this;
}

Mystring &Mystring::operator+=(const char *str) {

    m_append(str);
    return *this;
}

/*
 * =================================================
 * Public Methods
 * =================================================
 */

Mystring &Mystring::append(const char *str) {

    m_append(str);
    return *this;
}

Mystring &Mystring::append(Mystring const &obj) {

    m_append(obj.c_str());
    return *this;
}

const char *Mystring::c_str() const {

    if (m_str != nullptr) {
        return m_str;
    }

    return "";
}

/*
* =================================================
* Private Methods
* =================================================
*/

void Mystring::m_init(size_t size) {

    if (m_str != nullptr) {
        delete[]  m_str;
    }

    m_size = size;
    m_buff = m_size;
    //++m_buff one additinal index for '\0'
    m_str = new char[++m_buff];

    for (size_t i = 0; i < m_buff; i++) {
        m_str[i] = '\0';
    }
}

size_t Mystring::size() {

    return length(m_str);
}

void Mystring::m_realloc(const size_t size) {

    m_buff = INIT_BUFF;

    while (size > m_buff) {
        m_buff *= BUFF_INC;
    }

    char *tmp = new char[m_buff];

    for (size_t i = 0; i < m_buff; i++) {
        tmp[i] = '\0';
    }

    m_size = 0;
    delete[] m_str;
    m_str = tmp;
}

void Mystring::m_append(const char *str) {

    //save m_str in old_str
    size_t old_size = length(m_str);
    char *old_str = new char[length(m_str)];
    for (size_t i = 0; i < old_size; i++) {
        old_str[i] = m_str[i];
    }

    size_t str_size = length(str);
    m_realloc(old_size + str_size);

    for (size_t i = 0; i < old_size; i++) {
        m_str[i] = old_str[i];
    }
    for (size_t i = 0; i < str_size; i++) {
        m_str[old_size + i] = str[i];
    }
    m_size = old_size + str_size;

}

void Mystring::m_copy(const char *str) {
    size_t size = length(str);
    for (size_t i = 0; i < size; i++) {
        m_str[i] = str[i];
    }
}

size_t Mystring::length(const char *str) {

    size_t len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}
