# CS 302 - Lecture 5 - Stacks
Date: 9/12/18

[Prev](./lecture_3.md) | [Next](./lecture_6.md)

QUIZ NEXT LECTURE: Linked list and stacks

### The ADT Stack
- LIFO
- Often implements peek in addition to push and pop
- Heavily used in CS
    - Function calls
    - Undo operations

#### Common operations
- `push` - Add item to top of stack
- `pop` - Remove item from top of stack
- `peek` - Return copy of item on top of stack (stack unchanged)
- `isEmpty` - Boolean true if stack is empty, else false

### Using the ADT Stack

#### Algebraic Expression
- Operator Precedence
- REMEMBER: Postfix notation == reverse polish notation
    - `(5 + 6) * 7` is expressed as `756+*`

#### Evaluating Infix Expressions
- Convert the infix expression to postfix
- Evaluate the postfix expression

```
infixExpression = infix expression to process
operatorStack = new empty stack
postfixExpression = new empty stack


```




