#pragma once
using namespace std;
#include <iostream>
#include <map>
#include <functional>
#include <sstream>
#include <stack>

class Calculator {
    //realise method from video https://www.youtube.com/watch?v=Vk-tGND2bfc
    map <string, int> pr; //appoint priority for all actions
    map <string, function<double(double, double)>> op; //match simbols with actions
    stack<double> num; //remember numbers from the expression
    stack<string> act; //remember actions from the expression
    void action();
    string newstr;
    void Count(string expression);
public:
    Calculator();
    void process_expression(string str);
};