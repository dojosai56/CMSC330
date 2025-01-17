#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "parse.h"

string parseName(std::stringstream& in)
{
    char alnum;
    string name = "";

    in >> ws;
    while (isalnum(in.peek()))
    {
        in >> alnum;
        name += alnum;
    }
    return name;
}