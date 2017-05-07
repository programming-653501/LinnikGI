//
// Created by Gleb Linnik on 25.04.17.
//

#include "../Header/Quiz.h"
#include <iostream>

Quiz::Quiz(const json &quizJson) : quizJson(quizJson) {
    name = quizJson["name"].get<std::string>();
    for (json &topic : this->quizJson["topics"]) {
        std::string tempTitle = topic["title"].get<std::string>();
        std::vector<Question> tempQuestions;
        for (json &question : topic["questions"]) {
            std::vector<std::string> tempAnswers;
            std::string tempQuestion = question["question"].get<std::string>();
            for (json &answer : question["answer"]) {
                tempAnswers.push_back(answer.get<std::string>());
            }
            tempQuestions.push_back(Question(tempQuestion, tempAnswers));
        }
        topics.push_back(Topic(tempTitle, tempQuestions));
    }
}

void Quiz::start() {
    std::cout << "Hello! Welcome to " << name << std::endl;
    while (1) {
        std::cout << "This quiz has these topics:\n";
        for (int i = 0; i < topics.size(); ++i) {
            std::cout << i + 1 << ") " << topics[i].title << std::endl;
        }
        std::cout << "0) Exit\n";
        std::cout << "Choose the topic: ";
        int choice;
        std::cin >> choice;
        if (choice) {
            if (choice <= topics.size())
                startQuizWithTopic(topics[choice - 1]);
        } else {
            break;
        }
    }
}

void Quiz::startQuizWithTopic(const Topic &topic) {
    uint correntAnswers = 0;
    for (int i = 0; i < topic.questions.size(); ++i) {
        Question question = topic.questions[i];
        std::cout << i + 1 << " question:\n" << question.question << std::endl;
        std::cout << "Answer: ";
        std::string answer;
        std::cin >> answer;
        if (std::find(question.answers.begin(), question.answers.end(), answer) != question.answers.end()) {
            std::cout << "Correct!\n";
            correntAnswers++;
        } else {
            std::cout << "You just suck!\n";
        }
    }
    std::cout << "You got " << correntAnswers << " out of " << topic.questions.size() << std::endl;
}
