/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <stack>
 
 //METHOD 1 - USING STACK (LIFO)- O(N) TIME & O(N) SPACE
int Solution::lPalin(ListNode* A) {
    ListNode* p2 = A;
    int count = 0;
    stack<ListNode*> s;
    while(p2 != NULL){
        s.push(p2);
        p2=p2->next;
        count++;
    }
    ListNode* p1 = A;
    count = count /2;
    while(count>0){
        if(p1->val != (s.top())->val){
            //cout<<s.top()->val<<endl;
            return  0;
        }
        s.pop();
        p1 = p1->next;
        count --;
        
    }
    return 1;
}
