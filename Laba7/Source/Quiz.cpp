//
// Created by Gleb Linnik on 25.04.17.
//

#include "../Header/Quiz.h"


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
    std::cout << "This quiz has these topics:\n";
    for (int i = 0; i < topics.size(); ++i) {
        std::cout << i + 1 << ") " << topics[i].title << std::endl;
    }
    std::cout << "Choose the topic: ";
    int choice;
    std::cin >> choice;
    startQuizWithTopic(topics[choice - 1]);
}

void Quiz::startQuizWithTopic(const Topic &topic) {
    for (int i = 0; i < topic.questions.size(); ++i) {
        Question question = topic.questions[i];
        std::cout << i + 1 << " question:\n" << question.question << std::endl;
        std::cout << "Answer: ";
        std::string answer;
        std::cin >> answer;
        if (std::find(question.answers.begin(), question.answers.end(), answer) != question.answers.end()) {
            std::cout << "Correct!\n";
        } else {
            std::cout << "You just suck!\n";
        }
    }
}
