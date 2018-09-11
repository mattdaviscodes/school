/**
 * @brief  CS-302 Project 1
 * @Author Matt Davis (mattdavis@nevada.unr.edu)
 * @date   9/10/18
 */

#include <iostream>
#include "LinkedList.h"

int menu();
int get_int_between(int min, int max);

template<class T>
void add_item_to_list(LinkedList<T> &ll);
template<class T>
void remove_item_from_list(LinkedList<T> &ll);
template<class T>
void show_list_length(LinkedList<T> &ll);
template<class T>
void show_list(LinkedList<T> &ll);

int main() {
    LinkedList<int> ll;
    int selection;
    bool exit = false;

    do {
        selection = menu();
        switch (selection) {
            case 1: add_item_to_list(ll); break;
            case 2: remove_item_from_list(ll); break;
            case 3: show_list_length(ll); break;
            case 4: show_list(ll); break;
            case 5: exit = true; break;
        }
    } while (!exit);

    return 0;
}

/**
* Display a menu to the user and prompt user for selection
*/
int menu() {
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1) Add item to list" << std::endl;
    std::cout << "2) Remove item from list" << std::endl;
    std::cout << "3) Show list length" << std::endl;
    std::cout << "4) Show list" << std::endl;
    std::cout << "5) Exit" << std::endl;

    return get_int_between(1, 5);
}

/**
 * Prompt user for an integer between min and max, inclusive.
 * NOTE: This function completely blows up user enters non-integer
 */
int get_int_between(int min, int max) {
    int selection;

    // Prompt until valid selection entered
    do {
        std::cout << "Enter selection (" << min << "-" << max << "): ";
        std::cin >> selection;   // TODO: Prevent non-integer input infinite loop

    } while (selection < min || selection > max);

    return selection;
}

template<class T>
void add_item_to_list(LinkedList<T> &ll) {
    T item;

    std::cout << "Enter item to add: ";
    std::cin >> item;

    ll.push(item);
}

template<class T>
void remove_item_from_list(LinkedList<T> &ll) {
    ll.pop();
}

template<class T>
void show_list_length(LinkedList<T> &ll) {
    std::cout << ll.len() << std::endl;
}

template<class T>ls
void show_list(LinkedList<T> &ll) {
    std::cout << ll << std::endl;
}
