//
// Created by Gayeon Ko on 2018-09-12.
// Student Number: 040 704 124
// Email: gko4@myseneca.ca
//

#include <iostream>
#include "CString.h"
#include "process.h"

void process(char* str, std::ostream& os){
    w1::CString obj(str);
    os << obj << std::endl;
}