// EE 312 Project 8 submission by
// Chieh-An Chen
// cc67994
// Slip days used: <1>
// Summer 2022

#ifndef PROJECT_8_PROJECT8_H
#define PROJECT_8_PROJECT8_H
#include <iostream>
#include "UTString.h"
#include <vector>
#include <cstdlib>
#include "Parse.h"
#include <map>
#include <string.h>
#include <stdio.h>

using namespace std;
void run(); //check
int calculations(vector<UTString>& copyblip); //check
int checkval(UTString first); //check
bool isOperator(const char* words); //check
void gotoNextLine(); //check
void SetandInit (int vara, int seta, int outa); //check
void eraseFirstElement(vector<UTString>& copyblip); //check
int StringtoInt (vector<UTString>& copyblip, UTString first); //check
#endif //PROJECT_8_PROJECT8_H

