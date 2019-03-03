#include "RpnCalculator.hpp"

static std::map<std::string, double (*)(double, double)> ops{
    {"+", [](double a, double b) { return a + b; }},
    {"-", [](double a, double b) { return a - b; }},
    {"*", [](double a, double b) { return a * b; }},
    {"/", [](double a, double b) { return a / b; }}};

const bool RpnCalculator::isNotOperator(const char ch)
{
    return (ch != '+' and ch != '-' and ch != '*' and ch != '/');
}

std::vector<std::string> RpnCalculator::parseOperation(const std::string &operation)
{
    std::vector<std::string> storage{};
    std::string tmp{};
    for (auto i = 0; i < operation.size(); i++)
    {
        if (operation[i] == ' ')
        {
            continue;
        }

        tmp += operation[i];

        if (i + 1 == operation.size() or operation[i + 1] == ' ')
        {
            storage.push_back(tmp);
            tmp = std::string{};
        }
    }
    return storage;
}

double RpnCalculator::compute(const std::string &operation)
{
    std::string tmp{};
    double val{};

    for (auto i : parseOperation(operation))
    {
        tmp = i;
        std::stringstream ss{};
        ss.str(tmp);

        ss >> val ? valStack.push(val) : computeWhenIsOperator(tmp);
    }
    return valStack.top();
}

double RpnCalculator::popStack()
{
    const auto r{valStack.top()};
    valStack.pop();
    return r;
}

void RpnCalculator::computeWhenIsOperator(std::string opr)
{
    const auto r{popStack()};
    const auto l{popStack()};

    const auto &op(ops.at(opr));
    const double result{op(l, r)};
    valStack.push(result);
}
