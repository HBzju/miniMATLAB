#ifndef INTEGRATE_H
#define INTEGRATE_H

#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;
double integrate(double x, void *params);
double tansform(double x);
void Char_Operation(char op,stack<double>& digit);
int Operation_Rank(char op);
bool Is_Single(char op);
void Single_Operation(string::iterator &it,stack<char> &ch);
class Log_Error{};
class Cos_Error{};
class Sin_Error{};
class Tan_Error{};
class Empty_Error{};
class Zero_Error{};
class OpType_Error{};

#endif // INTEGRATE_H
