#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

/* Function prototypes*/
void parseAssignments(std::stringstream& in);
void readFile();

/*
* main
* 
*/
int main()
{
    

    readFile();

    /*
    Expression* expression;
    char paren, comma;
    //string program;

    cout << "Enter expression: ";
    cin >> paren; // a + b, a=2, b=2;
    expression = SubExpression::parse();
    cin >> comma;  
    parseAssignments();
    cout << "Value = " << expression->evaluate() << endl;
    return 0;
    
    
    
    */
    
}


void readFile() {
    const int SIZE = 256;
    Expression* expression;
    char paren, comma, line[SIZE];
    string filename;

    cout << "Enter file name or path:" << endl;
    cin >> filename;


    ifstream myfile(filename);

    if (myfile.is_open()) {
        while (true) {

            symbolTable.init();
            myfile.getline(line, SIZE);

            if (!myfile) break;

            stringstream input(line, ios_base::in);

            input >> paren;
            cout << line << "";

            expression = SubExpression::parse(input);

            input >> comma;

            parseAssignments(input);

            int result = expression->evaluate();

            cout << "Value = " << result << endl;

        }
        myfile.close();
    }

} // readFile


void parseAssignments(std::stringstream& in)
{
    char assignop, delimiter;
    string variable;
    double value;
    do
    {
        variable = parseName(in);
        in >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}
   
