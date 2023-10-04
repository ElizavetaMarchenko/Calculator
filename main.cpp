#include "Calculator_lab1.h"
#include <iostream>

int main() {
    cout << "Calculator performs '+', '-', '*', '/', '()'. Enter your expression. If you want to finish, enter 'exit'." << endl;
    string Str;
    getline(cin, Str);
    while (Str != "exit") {
        Calculator Cal;
        try {
            Cal.process_expression(Str);
        }
        catch (exception) {
            cout << "Error!!!" << endl;
        }
        getline(cin, Str);
    }
}