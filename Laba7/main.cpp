#include <iostream>
#include <fstream>
#include "Header/json.hpp"

using namespace std;
using json = nlohmann::json;

int main(int argc, char* argv[]) {
    cout << "    ___   __ __\n"
            "   /   | | || /\n"
            "  / /| |&|   /   \n"
            " / ___ | | |\\ \\  \n"
            "/_/  |_| |_| \\_\\Inc. \n"
            "Audacious & Keen\n"
            "Presents:\n"
            "_______________           _____ \n"
            "___/   |__  __/_____________  /_\n"
            "__/ /| |_/ /  _  _ \\_  ___/  __/\n"
            "_/ /_| |/ /   /  __/(__  )/ /_  \n"
            "/______/_/    \\___//____/ \\__/  \n"
            "                                ";
    string quizFile;
    if (argc == 1) {
        cout << "Please, enter the path to the Quiz file: ";
        cin >> quizFile;
    } else {
        quizFile = argv[1];
    }

    ifstream input(quizFile);
    json quizJson;
    try {
        input >> quizJson;
    } catch (...) {
        cout << "It seems you've passed the wrong file.\nProgram will terminate.\n";
        exit(1);
    }
    //cout << quizJson["topics"][0]["title"] << endl;
    return 0;
}