//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>

#include "StackLinked.h"

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
//    string inputLine;            // Input line
//    char   ch;                   // Holding pen for input chars
//
//    cout << "This program checks for properly matched delimiters."
//         << endl;
//
//    while( cin )
//    {
//        cout << "Enter delimited expression (<EOF> to quit) : "
//             << endl;
//
//        // Read in one line
//        inputLine = "";
//        cin.get(ch);
//        while( cin && ch != '\n' )
//        {
//            inputLine = inputLine + ch;
//            cin.get(ch);
//        }
//
//        if( ! cin )              // Reached EOF: stop processing
//            break;
//
//        if ( delimitersOk (inputLine) )
//            cout << "Valid" << endl;
//        else
//            cout << "Invalid" << endl;
//    }

    std::cout << "1. [(<>)]{} " << (delimitersOk("[(<>)]{}") ? "Valid" : "Invalid") << std::endl;
    std::cout << "2. (this is a parenthetical) " << (delimitersOk("(this is a parenthetical)") ? "Valid" : "Invalid") << std::endl;
    std::cout << "3. { " << (delimitersOk("{") ? "Valid" : "Invalid") << std::endl;
    std::cout << "4. (<)> " << (delimitersOk("(<)>") ? "Valid" : "Invalid") << std::endl;
    std::cout << "5. ({})) " << (delimitersOk("({}))") ? "Valid" : "Invalid") << std::endl;

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below

bool delimitersOk ( const string &expression ) {
    StackLinked<char> stack;

    try {
        for (int i = 0, len = expression.length(); i < len; i++) {
            switch (expression[i]) {
                // Opening delimiters
                case '(':
                case '{':
                case '<':
                case '[': stack.push(expression[i]); break;

                    // Closing delimiters
                case ')': if (stack.pop() != '(') {return false;}; break;
                case '}': if (stack.pop() != '{') {return false;}; break;
                case '>': if (stack.pop() != '<') {return false;}; break;
                case ']': if (stack.pop() != '[') {return false;}; break;


            }
        }

        // If stack is empty now, delimiters all matched
        return stack.isEmpty();
    } catch (logic_error) {
        // Catch popping from empty stack errors
        return false;
    }
}




