//
// Created by Gleb Linnik on 25.04.17.
//

#ifndef LABA7_TOPIC_HPP
#define LABA7_TOPIC_HPP

#include "Question.hpp"

struct Topic {
    Topic(const std::string &title, const std::vector<Question> &questions) : title(title), questions(questions) {}
    std::string title;
    std::vector<Question> questions;
};


#endif //LABA7_TOPIC_HPP
