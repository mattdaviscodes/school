//
// Created by Matthew Davis on 5/7/18.
//

#include "Cover.h"
#include "Client.h"

int main() {
    char * test = "test";
    char * test2 = "test2";

    std::cout << test2 << std::endl;

    strcpy(test2, test);

    std::cout << test2 << std::endl;

    return 0;
}