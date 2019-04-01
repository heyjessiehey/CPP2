//
// OOP345  Workshop 4 - Containers
// Created by Gayeon Ko on 2018-10-02.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca
//

#ifndef OOP345_WS4_MESSAGE_H
#define OOP345_WS4_MESSAGE_H

#include <iostream>

namespace w4 {
    class Message {
        std::string _msg;
    public:
        Message(){_msg="";};
        Message(std::ifstream& in, char c);
        bool empty() const;
        void display(std::ostream&) const;
    };
}

#endif //OOP345_WS4_MESSAGE_H
