 #include <iostream>

//定义节点
struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* head;

//在链表的开头插入一个新的节点
Node* Head_Insert(Node* head,int x)
{ 
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    if(head!=NULL) temp->next = head;
    head = temp;
    return head;
}

//在链表任意处插入一个节点
void Any_Insert(int data,int n){
    Node* temp1 = new Node;
    temp1->data = data;
    temp1->next = NULL;
    if(n==1){                   //同Head_Insert    
        temp1->next = head;
        head = temp1;
        return; 
    }
    Node* temp2 = head;
    for(int i=0;i<n-2;i++){
        temp2 = temp2->next;
    }//找到第n-1处节点位置
    temp1->next = temp2->next;
    temp2->next = temp1;
}

//在链表任意处删除一个节点
void Delect(int n){
    Node* temp1 = head;
    if(n == 1){
        head = temp1->next;
        delete temp1;
        return;
    }
    for(int i=0;i<n-2;i++){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

//反转一个链表
Node* Reverse(Node* head){
    Node *current,*prev,*next;
    current = head;
    prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

//用迭代方法反转链表
void Itertion_Reverse(Node* p){
    if(p->next==NULL){
        head = p;
        return;
    }
    Itertion_Reverse(p->next);
}



//打印链表
void Print(Node* head)
{
    Node* temp = head;
    std::cout << "List is:";
    while(temp!=NULL){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

//以迭代的方式反向打印链表
void Iteration_Print(Node* head){
    if(head==NULL){
        std::cout << std::endl;
        return;
    }
    std::cout << head->data << " ";
    Iteration_Print(head->next);
}