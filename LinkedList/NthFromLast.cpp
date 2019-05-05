/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <set>
using namespace std;

class Node{
    public:
    int data;
    Node* next = NULL;
};

class LinkedList{
    public:
    Node* head;
    
    LinkedList();
    ~LinkedList();
    void pushNode(int x);
    void printList();
    void printNthFromLast(int k);
    void removeDup();
};

void LinkedList::printNthFromLast(int k){
    int count = 0;
    Node* p1 = this->head;
    Node* p2 = this->head;
    
    while(count<k){
        if(p2==NULL){
            cout<<"list length is less than k"<<endl;
        }
        p2 = p2->next;
        count++;
    }
    
    while(p2 != NULL){
        p1 = p1->next;
        p2=p2->next;
    }
    
    cout<<"Kth Node from end is : "<<p1->data<<endl;
}

void LinkedList::removeDup(){
    std::set<int> s ;
    
    Node* prev = NULL;
    Node* cure = this->head;
    
    while(cure != NULL){
        if(s.count(cure->data)){
            prev -> next = cure->next;
            delete(cure);
        }
        else{
            s.insert(cure->data);
            prev = cure;
            
        }
        cure = cure->next;
    }
}

void LinkedList::pushNode(int x){
    Node* n = new Node();
    n->data = x;
    n->next = this->head;
    this->head = n;
}


void LinkedList::printList(){
    if(this->head == NULL){
        return;
    }
    Node* p = this->head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

LinkedList::LinkedList(){
    this->head = NULL;
}

LinkedList::~LinkedList(){
    cout<<"free";
}





int main()
{
    LinkedList *l = new LinkedList();
    //l->printList();
    l->pushNode(11);
    l->pushNode(10);
    l->pushNode(9);
    l->pushNode(6);
    l->pushNode(9);
    l->pushNode(1);
    l->printList();
    
    l->removeDup();
    l->printList();
    l->printNthFromLast(3);

    return 0;
}
