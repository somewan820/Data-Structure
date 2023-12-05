//使用链表实现一个栈
#include <iostream>
//定义链表节点的结构体
struct Node {
    int data;
    Node *next;
};
//定义头节点
Node *head = NULL;
//在栈顶插入数据
void Push(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = head;
    head = temp;
}
//删除栈顶数据
void Pop() {
    Node *temp = head;
    head = temp->next;
    delete temp;
}
//检验是否为空栈
// using_type -> (std::cout << (Isempty()?"Yes":"No") << std::endl;)
bool Isempty() { return head == NULL; }
//获取栈顶元素
int Top() {
    if (head == NULL) {
        std::cout << "Stack is empty." << std::endl;
        return -1;
    }
    return head->data;
}
//打印链表
void Print(Node *head) {
    Node *temp = head;
    std::cout << "List is:";
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}