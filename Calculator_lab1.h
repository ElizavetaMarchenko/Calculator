#pragma once
using namespace std;
#include <iostream>
#include <map>
#include <functional>
#include <sstream>
#include <stack>
#include <string>
#include "read_plugin.h"

class Calculator {
private:
    //realise method from video https://www.youtube.com/watch?v=Vk-tGND2bfc
    map <string, int> pr; //appoint priority for all actions
    map <string, function<double(double, double)>> op; //match simbols with actions
    stack<double> num; //remember numbers from the expression
    stack<string> act; //remember actions from the expression    
    string newstr; //processed expression
    void create_actions(); //correlate actions with their icons
    void do_action(); //count one action
    void Count();
    read_plugin plugin;

public:
    Calculator() {};
    void process_expression(string str);
};