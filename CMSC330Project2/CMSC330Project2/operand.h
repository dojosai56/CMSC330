class Operand: public Expression
{
public:
    static Expression* parse(std::stringstream& in);
};
