//
// Created by Gayeon Ko on 2018-09-12.
// Student Number: 040 704 124
// Email: gko4@myseneca.ca
//
#include <iostream>
#include "CString.h"

int store = w1::MAX;

namespace w1{

    CString::CString(const char* str) {
        // Check for receipt of the null address.
        // Store an empty string in that case.
        if(str == nullptr){
            m_myString[0] = '\0';
        }else{
            strncpy(m_myString, str, MAX+1);
            m_myString[MAX] = '\0';
        }
    }

    void CString::display(std::ostream& os) const{
        os << m_myString;
    }

    std::ostream& operator<<(std::ostream& os, const CString& s){
        static int count = 0;
        os << count++;
        s.display(os);
        return os;
    }

}