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
    //Поле типа json для хранения json структуры данного теста
    json quizJson;
    //Ветор из структуры темы с темами данного теста
    std::vector<Topic> topics;
    //Строка с названием теста
    std::string name;
};


#endif //LABA7_QUIZ_H
