//
// OOP345  Workshop 4 - Containers
// Created by Gayeon Ko on 2018-10-02.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca
//
#include <fstream>
#include "Message.h"

namespace w4 {
    //- constructor retrieves a record from the in file object,
    // parses the record (as described above)
    // and stores its components in the Message object.
    // c is the character that delimits each record
    Message::Message(std::ifstream &in, char c) {
        if (in.is_open()) {
            getline(in, _msg, c);
        } else
            _msg = "";
    }

    //- returns true if the object is in a safe empty state
    bool Message::empty() const {
        return _msg == "";
    }

    //- displays the Message objects within the container
    void Message::display(std::ostream &os) const {
        if (!empty()) {
            std::string user = "";
            std::string reply = "";
            std::string tweet = "";
            std::string msg = _msg;

            user = msg.substr(0, msg.find(' ')); // first letter to [jim] until find a space
            msg.erase(0, msg.find(' ') + 1);// remove [jim ] +1 including space

            if (msg.find('@') == 0) { // there is @ means 0
                reply = msg.substr(1, msg.find(' ') - 1);
                msg.erase(0, msg.find(' ') + 1);
            }
            tweet = msg.substr(0); // first letter to end of string

            if (user != tweet) {
                os << "Message" << std::endl;
                os << " User  : " << user << std::endl;
                if (reply != "") {
                    os << " Reply : " << reply << std::endl;
                }
                os << " Tweet : " << tweet << std::endl;
                //}
                os << std::endl;
            }
        }
    }
}
/* data
jim Workshop 5 is cool
harry @jim working on workshop 5 now
chris
dave what the ^#$%!

john @harry I'm done
 */
