#include <iostream>

//定义节点
struct Node {
    int data = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
};

Node *head = nullptr;

//在链表任意处插入一个节点
void Any_Insert(int data, int n) {
    Node *temp1 = new Node;
    temp1->data = data;
    temp1->next = nullptr;
    if (n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node *temp2 = head;
    for (int i = 0; i < n - 2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

//在链表任意处删除一个节点
void Delect(int n) {
    Node *temp1 = head;
    if (n == 1) {
        head = temp1->next;
        delete temp1;
        return;
    }
    for (int i = 0; i < n - 2; i++) {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

//反转一个链表
Node *Reverse(Node *head) {
    Node *current, *prev, *next;
    current = head;
    prev = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

//用递归方法反转链表
void Recursive_Reverse(Node *p) {
    if (p->next == nullptr) {
        head = p;
        return;
    }
    Recursive_Reverse(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = nullptr;
}

//打印链表
void Print(Node *head) {
    Node *temp = head;
    std::cout << "List is:";
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

//以递归的方式反向打印链表
void Recursive_Print(Node *head) {
    if (head == nullptr) {
        std::cout << std::endl;
        return;
    }
    std::cout << head->data << " ";
    Recursive_Print(head->next);
}
