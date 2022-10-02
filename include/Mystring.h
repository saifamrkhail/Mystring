//Mystring is a simple implementation of C++ string.
//
// Created by saif on 9/24/22.
//

#ifndef STRING_MYSTRING_H
#define STRING_MYSTRING_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <ostream>

#define INIT_BUFF 32
# define BUFF_INC 2

class Mystring {
public:
    class Myiterator : public std::iterator<std::bidirectional_iterator_tag, Mystring> {
    public:
        //constructor with initialization list
        Myiterator(char *str) : m_ptr(str) {};

        //prefix operator ++i
        Myiterator operator++() {
            m_ptr++;
            return *this;
        }

        //postfix operator i++
        Myiterator operator++(int) {
            Myiterator tmp = *this;
            ++(*this);
            return tmp;
        }

        //prefix operator --i
        Myiterator operator--() {
            m_ptr--;
            return *this;
        }

        //postfix operator i++
        Myiterator operator--(int) {
            Myiterator tmp = *this;
            --(*this);
            return tmp;
        }

        //comparison operator not equal
        bool operator!=(Mystring::Myiterator other) const { return m_ptr != other.m_ptr; }

        //comparison operator equal to
        bool operator==(Mystring::Myiterator other) const { return m_ptr == other.m_ptr; }

        //conversion function
        char operator*() const { return m_ptr[0]; }

    private:
        char *m_ptr = nullptr;
    };

    /*
     * =================================================
     * Constructors
     * =================================================
     */

    //default constructor
    Mystring();

    // constructor
    Mystring(const char *const str);

    // copy constructor
    Mystring(const Mystring &obj);

    // move constructor
    Mystring(Mystring &&dyingObj) noexcept;

    /*
     * =================================================
     * Destructor
     * =================================================
     */

    ~Mystring();

    /*
     * =================================================
     * Operators
     * =================================================
     */

    // copy assignment
    Mystring &operator=(const Mystring &obj);

    // move assignment
    Mystring &operator=(Mystring &&dyingObj) noexcept;

    //+operator
    Mystring operator+(const Mystring &obj);

    //+opertor
    Mystring operator+(const char *str);

    //+=operator
    Mystring &operator+=(const Mystring &obj);

    //+=operator
    Mystring &operator+=(const char *str);

    /*
    * =================================================
    * Conversion function
    * =================================================
    */
    operator char *() const {
        return this->m_str;
    }

    /*
    * =================================================
    * Methods
    * =================================================
    */

    Mystring &append(const Mystring &obj);

    Mystring &append(const char *str);

    const char *c_str() const;

    size_t size();

    Myiterator begin() const;

    Myiterator end() const;

private:
    char *m_str = nullptr;
    size_t m_size = 0;
    size_t m_buff = 0;

    void m_init();

    void m_realloc(const size_t size);

    void m_concat(const char *str_first, const char *str_second);

    void m_append(const char *str);

    void m_move(Mystring &dyingObj);

    size_t length(const char *str);

};

#endif //STRING_MYSTRING_H
