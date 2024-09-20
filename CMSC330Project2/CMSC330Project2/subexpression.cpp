#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greaterThan.h"
#include "lessThan.h"
#include "equalTo.h"
#include "and.h"
#include "or.h"
#include "not.h"
SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse(std::stringstream& in)
{
    Expression* left;
    Expression* right;
    char operation, paren;
    
    left = Operand::parse(in);
   // cout << "left: " << left;
    in >> operation;
    right = Operand::parse(in);
   // cout << "right: " << right;
    in >> paren;
    switch (operation)
    {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Times(left, right);
        case '/':
            return new Divide(left, right);
        case '>':
            return new GreaterThan(left, right);
        case '<':
            return new LessThan(left, right);
        case '=':
            return new EqualTo(left, right);
        case '&':
            return new And(left, right);
        case '|':
            return new Or(left, right);
        case '!':
            return new Not(left);
    }
    return 0;
}
        