//
// Created by Gleb Linnik on 25.04.17.
//

#ifndef LABA7_QUESTION_HPP
#define LABA7_QUESTION_HPP


#include <string>
#include <vector>

struct Question {
    Question(const std::string &question, const std::vector<std::string> &answers) : question(question),
                                                                                     answers(answers) {}
    std::string question;
    std::vector<std::string> answers;
};


#endif //LABA7_QUESTION_HPP
