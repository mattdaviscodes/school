# Lecture[1][1] Notes
Date: 9/7/16
[Scratch](scratch1.c)

### Announcements
* Join [ACM](https://www.acm.org/)
    * Guess this is a big deal. Professional association. Looks good on resumes. I should do this.
* Linux install party noon MS327 (hosted by ACM)

### scanf
A scanf format string may contain only conversion specifications:
```
int i, j;
float x, y;
scanf("%d%d%f%f", &i, &j, &x, &y);
```
Sample input: `1 -20 .3 -4.0e3`

When looking for an int, looks only for digit '+' or '-'

Using 'the M' (length specifier) of 1 in scanf will tell interpreter to only grab single digits. `%1d`

### Expressions
Expressions are built from variables constants, and **operators**. Many different kinds:
* arithmetic operators
* relational
* ...

All arithmetic operators (+, -, etc) are **binary operators** because they expect two operands, one on either side.

Unary operators also exist, need only one operand. Examples: `i = +1;`

**Modulo** is the final arithmetic operator, and stands apart from the others because it isn't seen in standard math. Works like 3rd grade division -- finds the leftover number. Mod requires that both operands are integers.
```
10 % 3 = 1
3 % 4 = 3
```

### Operator Precedence (order of operations)
`i + j * k` -- What order doe these statements evaluate?

Unary operators execute first. Then multiplication, division, and modulo. Finally, remaining binary operators are executed.

Parentheses are a way to break out of the set rules. By strategically placing parentheses around statements, you take total control of order of operations and communicate intent (a little) to yourself and other readers of the code.

If two binary operators of equal precendence come together, they execute left to right. `i * j / k` is equal to `(i * j) / k`.

Unary operators are different, operate right to left (or inside to outside). `-(-1)`
