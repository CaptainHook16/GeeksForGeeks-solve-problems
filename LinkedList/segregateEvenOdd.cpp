#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class LinkedList{
    public:
    Node* head;
    
    LinkedList();
    ~LinkedList();
    void pushNode(int data);
    void SwapNodes(int x,int y);
    void devideEvenOdd();
    void printList();
};

void LinkedList::printList(){
    Node* cure = this->head;
    while(cure != NULL){
        cout<<cure->data<<" ";
        cure = cure->next;
    }
}

void LinkedList::devideEvenOdd(){
    Node* odd_start = NULL;
    Node* odd_end = NULL;
    Node* even_start = NULL;
    Node* even_end = NULL;
    Node* cure = this->head;
    
    while(cure != NULL){
        if(cure->data % 2 != 0)
        {
            if(odd_start == NULL){
                odd_start = cure;
                odd_end = odd_start;
            }
            else{
                odd_end->next = cure;
                odd_end = odd_end->next;
            }
        }
        else{
            if(even_start == NULL){
                even_start = cure;
                even_end = even_start;
            }else{
                even_end->next = cure;
                even_end = even_end->next;
            }
        }
        cure = cure->next;
    }
    if(even_start == NULL || odd_start == NULL){
        return;
    }
    even_end->next = odd_start;
    odd_end->next = NULL;
    this->head = even_start;
}

void LinkedList::pushNode(int data){
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
}

LinkedList::LinkedList(){
    this->head = NULL;
}

LinkedList::~LinkedList(){
    std::cout << "LIST DELETED";
}

void swap(Node*& a,Node*& b){
    //Node* a_next = a->next;
    //Node* b_next = b->next;
    Node* temp = a;
    a = b;
    b = temp;
    
    // Node* a_next = (a->next);
    // a->next = b->next;
    // b->next = a_next;
}

void LinkedList::SwapNodes(int x,int y){
    if(x==y){
        return;
    }
    Node** a = NULL;
    Node** b = NULL;
    Node** cure = &(this->head);
    while(*cure)
    {
        if((*cure)->data == x){
            a = cure;
        }
        if((*cure)->data == y){
            b = cure;
        }
        cure = &((*cure)->next);
    }
    if(a && b){
        //swap((a->next),(b->next));
        swap(*a,*b);
        swap(((*a)->next), ((*b)->next)); 
    }
}

int main()
{
    
    LinkedList *l = new LinkedList();
    l->pushNode(11);
    l->pushNode(10);
    l->pushNode(9);
    l->pushNode(6);
    l->pushNode(4);
    l->pushNode(1);
    
    l->printList();
    cout<<endl;
    // l->devideEvenOdd();
    // l->printList();
    l->SwapNodes(10,6);
    l->printList();

    return 0;
}
