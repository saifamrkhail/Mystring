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

    m_init();
}

Mystring::Mystring(const char* str) {

    m_init();
    m_append(str);
}

// copy constructor
Mystring::Mystring(const Mystring &obj) {
    //TODO beim copy constructor gibt es keine bestehende Instanz die überschrieben wird
    // daher muss ich keine Resourcen freigeben, passe realloc an.
    m_init();
    m_append(obj);
}


// move constructor
Mystring::Mystring(Mystring &&dyingObj) noexcept {
    //TODO beim move constructor gibt es keine bestehende Instanz die überschrieben wird
    // daher muss ich keine Resourcen freigeben, passe realloc an.
    m_move(dyingObj);
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
        m_str = nullptr;
        m_buff = 0;
        m_size = 0;

        size_t size = length(str);
        m_realloc(size);

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
        m_move(dyingObj);
    }

    return *this;
}

//+operator
Mystring Mystring::operator+(const Mystring &obj) {

    m_append(obj.c_str());
    return *this;
}

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

    const char *str = obj.c_str();
    return append(str);
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

void Mystring::m_init() {

    if (m_str != nullptr) {
        delete[]  m_str;
    }

    m_buff = INIT_BUFF;
    m_str = new char[INIT_BUFF];
    m_size = 0;

    for (int i = 0; i < INIT_BUFF; ++i) {
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
    //release resources
    delete[] m_str;
    m_str = nullptr;

    m_str = tmp;
    m_size = length(m_str);
}

void Mystring::m_concat(const char *str_first, const char *str_second) {

    size_t size_str_first = length(str_first);
    size_t size_str_second = length(str_second);

    for (size_t i = 0; i < size_str_first; i++) {
        m_str[i] = str_first[i];
    }
    for (size_t i = 0; i < size_str_second; i++) {
        m_str[size_str_first + i] = str_second[i];
    }
    m_size = length(m_str);
}

void Mystring::m_append(const char *str) {

    size_t old_size = length(m_str);
    char *old_str = new char[length(m_str)];

    for (size_t i = 0; i < old_size; i++) {
        old_str[i] = m_str[i];
    }

    size_t str_size = length(str);

    m_realloc(old_size + str_size);
    m_concat(old_str, str);
}

void Mystring::m_move(Mystring &dyingObj) {

    m_realloc(length(dyingObj.c_str()));
    // m_move data from the incoming object
    m_str = dyingObj.m_str;
    m_size = length(m_str);
    //reset dyingObj
    dyingObj.m_size = 0;
    dyingObj.m_buff = 0;
    dyingObj.m_str = nullptr;
}

size_t Mystring::length(const char *str) {

    size_t len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}
