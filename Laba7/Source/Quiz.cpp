//
// Created by Gleb Linnik on 25.04.17.
//

#include "../Header/Quiz.h"


Quiz::Quiz(const json &quizJson) : quizJson(quizJson) {
    name = quizJson["name"];
    for (json &topic : this->quizJson["topics"]) {
        std::string tempTitle = topic["title"];
        std::vector<Question> tempQuestions;
        for (json &question : topic["questions"]) {
            std::vector<std::string> tempAnswers;
            std::string tempQuestion = question["question"];
            for (json &answer : question["answer"]) {

            }
        }
    }
}
