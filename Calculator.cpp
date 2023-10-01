#include "Calculator.h"
#include <iostream>
#include <map>

Calculator::Calculator() {
    pr["+"] = 1;
    pr["-"] = 1;
    pr["*"] = 2;
    pr["/"] = 2;   
    op["+"] = [](double x, double y) {return y + x; };
    op["-"] = [](double x, double y) {return y - x; };
    op["*"] = [](double x, double y) {return y * x; };
    op["/"] = [](double x, double y) {return y / x; };
}

bool is_act(string act) {
    if (act == "+" || act == "-" || act == "*" || act == "/") {
        return true;
    }
    return false;
}

bool is_act(string act, int n) {
    if (act == "+" || act == "-" || act == "*" || act == "/" || act == "(" || act == ")") {
        return true;
    }
    return false;
}

template <typename T1, typename T2>
bool compare_types(T1& t1, T2& t2) {
    stringstream s;
    s << t1;
    return static_cast<bool>(s >> t2);
}


void Calculator::process_expression(string str) { 
    //rewrite expression fot stringstream
    string st;
    double db;
    char pr = '('; //remember privious element / start with number < 0
    for (const auto& u : str) {
        if (u == ' ') continue;

        compare_types(u, st);

        if (u == '-' && pr == '(') {
            newstr += " 0 " + st;
            pr = u;
            continue;
        }

        if (is_act(st, 6)) {
            newstr += " " + st + " ";
            pr = u;
            continue;
        }

        if (compare_types(u, db) != compare_types(pr, db) && u != '.' && pr != '.') {
            newstr += " " + st;
            pr = u;
            continue;
        }

        newstr += st;
        pr = u;
    }
    
    Count(newstr);
}

//perform action from map with two top numbers  
void Calculator::action() {
    string opr = act.top();
    act.pop();
    double x, y;
    x = num.top(); 
    num.pop();
    y = num.top(); 
    num.pop();
    num.push(op[opr](x, y));  
}

void Calculator::Count(string Str) {
    stringstream StrSt(newstr);
    string elem;
    double d;
    while (StrSt >> elem) {
        if (compare_types(elem, d)) {
            num.push(d);
            continue;
        }

        if (act.empty() || act.top() == "(") {
            act.push(elem);
            continue;
        }

        if (elem == ")") {
            while (act.top() != "(") {
                action();
            }
            act.pop();
            continue;
        }

        while (!act.empty() && act.top() != "(" && (is_act(elem)) && pr[act.top()] >= pr[elem]) {
            action();
        }

        act.push(elem);
    }

    while (!act.empty()) {
        action();
    }

    cout << num.top() << endl;    
}


