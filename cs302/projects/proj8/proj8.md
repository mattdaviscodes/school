# CS 302 - Project 8
Date: 12/12/18 | Author: Matt Davis | [Assignment](./cs302-hw8.pdf)

### Exercise 1
For this project, the goal was to implement a Left-Leaning Red
Black Tree based on a sample provided by the professor here: http://www.teachsolaisgames.com/articles/balanced_left_leaning.html.

The assignment proved much more difficult than I had expected before
beginning. My initial plan was to first implement a Red Black Tree (no
lean) and then afterwards apply the Left-Leaning part. I accomplished
the first half of my goal, but then realized that the majority of the
code I'd written didn't play well with the second half of the goal. I
ended up overwriting nearly everything I began with. I wish I'd have
kept it to compare afterward, but I kept just chaninging bits to make
it work, and eventually it was completely different.

I found two invaluable resources online that let you dynamically create
and manipulate Red Black Trees -- both basic and Left-Leaning -- in
the browser. I used these to validate my code. I purposely did not
seed my RNG so I'd always get the same numbers, then I input those
numbers into the web tools and compared results. Here they are:

- [Basic](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)
- [Left-Leaning](http://inst.eecs.berkeley.edu/~cs61b/fa17/materials/demos/ll-red-black-demo.html)

My code is almost entirely in [LeftLeaningRedBlackTree.h](./LeftLeaningRedBlackTree.h)
with a fairly minor subset in [RedBlackNode.h](RedBlackNode.h). Build with
`make`. Representative output can be found [here](./proj8.out).