#include <iostream>
#include "LinkedList.h"

int main() {
    Insert(2, 1);
    Insert(3, 2);
    Insert(4, 1);
    Insert(5, 2);
    Delect(2);
    Print(head);
    RecursivePrint(head);
    return 0;
}