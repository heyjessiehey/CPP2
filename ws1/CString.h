//
// Created by Gayeon Ko on 2018-09-12.
// Student Number: 040 704 124
// Email: gko4@myseneca.ca
//

#ifndef OOP345_WS1_CSTRING_H
#define OOP345_WS1_CSTRING_H

#include <iostream>
#include <cstring>


namespace w1 {

    // constant definition of the number of characters to be stored
    const int MAX = 3;

    class CString {
        char m_myString[MAX+1];

    public:
        // a constructor that receives the address of a C-style null-terminated string
        CString(const char* str = nullptr);
        // a member query named display()that receives a reference to an ostream object
        // and displays the string as stored in your CString object
        void display(std::ostream& os) const;
    };

    // a helper non-friend operator that inserts the stored string into the left ostream operand.
    // This operator prefaces the string with the number of the insertion and increment that number
    std::ostream& operator<<(std::ostream& os, const CString& s);
}


#endif //OOP345_WS1_CSTRING_H
