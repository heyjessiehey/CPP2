//
// OOP345  Workshop 4 - Containers
// Created by Gayeon Ko on 2018-10-02.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca
//

#include <iostream>
#include "Notifications.h"

namespace w4{
    //copy constructor
    Notifications::Notifications(const Notifications &src) {
        *this = src;
    }
    //copy assignment
    Notifications& Notifications::operator=(const Notifications &src) {
        if(this != &src){
            _count = src._count;
            for(int i=0;i<_count;++i){
                _msgarr[i] = src._msgarr[i];
            }
        }
        return *this;
    }

    //move constructor
    Notifications::Notifications(Notifications &&src) {
        *this = std::move(src);
    }
    //move assignment
    Notifications& Notifications::operator=(Notifications &&src) {
        if(this != &src){
            Message tempArr[SIZE];
            for(int i=0; i<src._count;++i){
                tempArr[i] = _msgarr[i];
            }
            for(int i=0; i<src._count;++i){
                _msgarr[i] = src._msgarr[i];
            }
            _count = src._count;
            for(int i=0; i<src._count;++i){
                src._msgarr[i] = tempArr[i];
            }
            src._count=0;
        }
        return *this;
    }


    void Notifications::operator+=(const Message& msg) {
        if(_count < SIZE){
            _msgarr[_count] = msg;
            _count++;
        }
    }

    void Notifications::display(std::ostream& os) const {
        for(int i=0; i<_count; ++i){
            _msgarr[i].display(os);
        }
    }
}