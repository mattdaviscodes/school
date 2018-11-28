#include <iostream>
#include <string>
#include <cctype>

#include "../cs302-hw2-code-package/StackLinked.h"

float evaluate_postfix(const std::string postfix, StackLinked<float> & stack);
float apply_operator(const float operand1, const float operand2, const char operator_to_apply) throw(logic_error);

int main() {
    StackLinked<float> stack;

    std::cout << "Excercise 1. Assignment 1." << std::endl;
    std::cout << "(3+4)*(5/2) = 34+52/* = " << evaluate_postfix("34+52/*", stack) << std::endl;

    std::cout << std::endl;
    std::cout << "Excercise 1. Assignment 2." << std::endl;
    std::cout << "1. 9-2/(5*2)+3 = 9252*/-3+ = " << evaluate_postfix("9252*/-3+", stack) << std::endl;
    std::cout << "2. 8-4+2*9*9 = 84-29*9*+ = " << evaluate_postfix("84-29*9*+", stack) << std::endl;
    std::cout << "3. (9*9)/(2*6) = 99*26*/ = " << evaluate_postfix("99*26*/", stack) << std::endl;
    std::cout << "4. 8/2/3*(5-2) = 82/3/52-* = " << evaluate_postfix("82/3/52-*", stack) << std::endl;
    std::cout << "5. 3+9/7*(1*3)/(2*7) = 397/13**27*/+ = " << evaluate_postfix("397/13**27*/+", stack) << std::endl;

    return 0;
}

float evaluate_postfix(const std::string postfix, StackLinked<float> & stack) {
    // Just in case
    stack.clear();

    for (int i = 0, len = postfix.length(); i < len; i++) {
        if (isdigit(postfix[i])) {
            // Convert char to float and push to stack
            stack.push(postfix[i] - '0');
        } else {
            float operand1 = stack.pop();
            float operand2 = stack.pop();

            float result = apply_operator(operand1, operand2, postfix[i]);

            stack.push(result);
        }
    }

    return stack.pop();
}

float apply_operator(const float operand1, const float operand2, const char operator_to_apply) throw(logic_error) {
    switch (operator_to_apply) {
        case '+': return operand2 + operand1;
        case '-': return operand2 - operand1;
        case '*': return operand2 * operand1;
        case '/': return operand2 / operand1;
        default : throw logic_error("Invalid operator");
    }
}
