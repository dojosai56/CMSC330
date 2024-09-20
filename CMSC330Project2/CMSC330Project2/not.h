#pragma once
#pragma once
class Not : public SubExpression
{
public:
    Not(Expression* left) : SubExpression(left, right)
    {
    }
    int evaluate()
    {
        return !(left->evaluate());
    }
};