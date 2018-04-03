# CS 202 - Lab 5 - Makefiles
Date: 2/22/18

### Compiling with Multiple FIles
```
g++ main.cpp functions.cpp functions.h -o TestProgram
```

### Makefiles
Useful when we want to include several source files. Makes builds faster
and easier. Only rebuilds the parts of the project that have changed
since the last build.


### Example
Class Files
 - triangle.h triangle.cpp
 - square.h square.cpp

Library Files
 - mathLib.h mathLab.cpp

Main Driver
 - main.cpp

### Syntax
Comments denoted by `#`.

```
test: example.cpp
```