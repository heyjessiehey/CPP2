//
// OOP345  Workshop 4 - Containers
// Created by Gayeon Ko on 2018-10-02.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca
//

#ifndef OOP345_WS4_NOTIFICATIONS_H
#define OOP345_WS4_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

namespace w4 {
    const int SIZE = 10;

    class Notifications {
        Message _msgarr[SIZE]{}; //subObj
        int _count=0;
    public:
        Notifications()= default; //- default constructor - empty
        Notifications(const Notifications&); //- copy constructor
        Notifications& operator=(const Notifications&); //- copy assignment operator

        Notifications(Notifications&&); //- move constructor
        Notifications& operator=(Notifications&&); //- move assignment operator

        ~Notifications()= default; //- destructor

        void operator+=(const Message& msg); //- adds msg to the set
        void display(std::ostream& os) const; //- inserts the Message objects to the os output stream

    };

}
#endif //OOP345_WS4_NOTIFICATIONS_H
