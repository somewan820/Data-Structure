//使用数组实现一个栈
#include <iostream>

int top = -1;
int a[10];

void Push(int x) {
    top = top + 1;
    a[top] = x;
}

void Pop() { top = top - 1; }

int Top() { std::cout << a[top]; }

bool Isempty() {
    if (top >= 0)
        return true;
    else
        return false;
}
