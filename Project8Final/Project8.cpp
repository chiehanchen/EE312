// EE 312 Project 8 submission by
// Chieh-An Chen
// cc67994
// Slip days used: <1>
// Summer 2022
#include "Project8.h"
map<UTString, int> variables;
vector<UTString> prefix;

bool isOperator(const char* words) {
    int result = 0;
    if (strcmp(words, "text") != 0 && strcmp(words, "output") != 0
        && strcmp(words, "set") != 0 && strcmp(words, "var") != 0){
        return result = 1;
    }

    for (int i = 0; words[i]; i++) {
        if ( words[i] >= '0' && words[i] <= '9')
            return result = 2;
    }
    return result;
}

void gotoNextLine(){
    if (!(strcmp(next_token(), "//"))) {
        skip_line();
    }
}

void SetandInit (int vara, int seta, int outa){
    if (vara == 0 && seta == 0 && outa == 1){
        while(next_token_type != END && isOperator(peek_next_token())){
            read_next_token();
            if (strcmp(next_token(), "//") == 0) {
                skip_line();
            } else if (next_token_type == NAME || (strcmp(next_token(), "") != 0)){
                prefix.emplace_back(next_token());
            }
        }
        cout << calculations(prefix);
        auto clearing = prefix.begin();
        while(clearing != prefix.end()) {
            prefix.erase(clearing);
            clearing++;
        }
        return;
    }
    read_next_token();
    UTString variable = UTString(next_token());
    while(next_token_type != END && isOperator(peek_next_token())){
        read_next_token();
        if (strcmp(next_token(), "//") == 0) {
            skip_line();
        } else if (next_token_type == NAME || (strcmp(next_token(), "") != 0)){
            prefix.emplace_back(next_token());
        }
    }
    if (vara == 1 && seta == 0 && outa == 0 && variables.count(variable) != 0){
        cout << "variable " << variable.c_str() << " incorrectly re-initialized" << endl;
        variables[variable] = calculations(prefix);
        auto clearing = prefix.begin();
        while(clearing != prefix.end()) {
            prefix.erase(clearing);
            clearing++;
        }
        return;
    } else if (vara == 0 && seta == 1 && outa == 0 && variables.count(variable) == 0){
        cout << "variable "<< variable.c_str()<< " not declared" << endl;
        variables[variable] = calculations(prefix);
        auto clearing = prefix.begin();
        while(clearing != prefix.end()) {
            prefix.erase(clearing);
            clearing++;
        }
        return;
    } else {
        variables[variable] = calculations(prefix);
        auto clearing = prefix.begin();
        while(clearing != prefix.end()) {
            prefix.erase(clearing);
            clearing++;
        }
    }
}

int checkval(UTString first){
    if (first == "0" || first == "1" || first == "2"
        || first == "3" || first == "4" || first == "5"
        || first == "6" || first == "7" || first == "8"
        || first == "9") {
        return 1;
    } else if (first != "==" && first != "!=" && first != ">="
                && first != "<=" && first != ">" && first != "<"
                && first != "&&" && first != "||"&& first != "+"
                && first != "%" && first != "!" && first != "~"
                && first != "-" && first != "*" && first != "/"
                && first != "text" && first != "output" && first != "set"
                && first != "var" && first != "//"){
        return 2;
    } else if (first == "==" || first == "!=" || first == ">=" || first == "<="
               || first == ">" || first == "<" || first == "&&" || first == "||"
               || first == "+" || first == "%" || first == "!" || first == "~"
               || first == "-" || first == "*" || first == "/") {
        return 3;
    } else {
        return 0;
    }
}

void eraseFirstElement(vector<UTString>& copyblip){
    copyblip.erase(copyblip.begin());
}
int StringtoInt (vector<UTString>& copyblip, UTString first){ //convert to int
    eraseFirstElement(copyblip);
    return stoi(first.c_str());
}


int calculations(vector<UTString>& copyblip){
    UTString first = copyblip.front();
    int val = checkval(first);
    if (val == 3) {
        if (variables.count(first) != 0) {
            eraseFirstElement(copyblip);
            return variables[first];
        }
        eraseFirstElement(copyblip);
        int x = calculations(copyblip);
        int y = 0;
        if (first != "~" && first != "!") {             // it creates malloc error when i don't do this
            y = calculations(copyblip);
        }

        if (first == "==") {
            return (x == y);
        } else if (first == "!=") {
            return (x != y);
        } else if (first == ">") {
            return (x > y);
        } else if (first == "<") {
            return (x < y);
        } else if (first == "<=") {
            return (x <= y);
        } else if (first == ">=") {
            return (x >= y);
        } else if (first == "*") {
            return (x * y);
        } else if (first == "/") {
            return (x / y);
        } else if (first == "+") {
            return (x + y);
        } else if (first == "-") {
            return (x - y);
        } else if (first == "%") {
            return (x % y);
        } else if (first == "&&") {
            return (x && y);
        } else if (first == "||") {
            return (x || y);
        } else if (first == "!") {
            return (!x);
        } else if (first == "~") {
            return (0 - x);
        }
    } else if (val == 1 || val == 2) {
        if (variables.count(first) != 0) {
            eraseFirstElement(copyblip);
            return variables[first];
        }
        while (val == 1 || val == 2) {
            int num = StringtoInt(copyblip, first);                 //convert to int
            val = 0;
            return num;
        }
    }

}

void run(){
    while (next_token_type != END){
        int rancheck = 0;                               //debugging
        UTString token = UTString(next_token());
        if (!(strcmp(next_token(), "//"))) {
            skip_line();
        }
        else if (!(strcmp(next_token(), "text"))){
            read_next_token();
            gotoNextLine();
            cout << next_token();
            rancheck = 1;
        }
        else if (!(strcmp(next_token(), "var"))){
            int vera = 1;
            int seta = 0;
            int outa = 0;
            SetandInit(vera, seta, outa);
            rancheck = 1;
        }
        else if (!(strcmp(next_token(), "set"))){
            int vera = 0;
            int seta = 1;
            int outa = 0;
            SetandInit(vera, seta, outa);
            rancheck = 1;
        }
        else if (!(strcmp(next_token(), "output"))) {
            int vera = 0;
            int seta = 0;
            int outa = 1;
            SetandInit(vera, seta, outa);
        }
        read_next_token();
    }
}


int main() {
    set_input("test_grader.blip");
    run();
}