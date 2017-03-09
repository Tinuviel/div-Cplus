#pragma once
/**
* Lovisa Colérus
* 2017-03-09
* Excercise in functionpointers and a bit struct
* takes two ints and a mathematical op from the user
* Header file with typedef
*/

typedef int(*arithmeticFcn)(int, int);

int askUserForInteger();
char askUserForOperator();
arithmeticFcn getArithmeticFunction(char op);
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);
