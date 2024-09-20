class SubExpression: public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    static Expression* parse(std::stringstream& in);
protected: 
    Expression* left;
    Expression* right;
};    