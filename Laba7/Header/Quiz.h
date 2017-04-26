//
// Created by Gleb Linnik on 25.04.17.
//

#ifndef LABA7_QUIZ_H
#define LABA7_QUIZ_H

#include "json.hpp"
#include "Topic.hpp"
using json = nlohmann::json;

class Quiz {
public:
    Quiz(const json &quizJson);
    void start();
private:
    void startQuizWithTopic(const Topic &topic);
    json quizJson;
    std::vector<Topic> topics;
    std::string name;
};


#endif //LABA7_QUIZ_H
