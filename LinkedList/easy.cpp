#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
void deleteNode(ListNode* node) {       //To delete a node in a singly linked list given only access to that node
        //O(1) solution
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
     Node *reverse(Node *head) {        //Reverse a doubly linked list using stack
        Node *temp = head;
        stack<int> st;
        while(temp != NULL){
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            temp -> data = st.top();        //Assigning values from stack to nodes
            st.pop();       //Popping stack
            temp = temp->next;  
        }
        return head;
    }
    Node *reverse(Node *head) {     //Reverse a doubly linked list without using stack  
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node *current = head;
        Node * last = NULL;
        while(current != NULL){
            last = current->prev;       //Storing previous pointer
            current->prev = current->next;      //Swapping prev and next pointers
            current->next = last;       //Swapping prev and next pointers
            current = current->prev;        //Moving to next node
        }
        return last->prev;      //New head of reversed list
    }
    ListNode* middleNode(ListNode* head) {      //Find middle node of singly linked list
        ListNode *temp = head;
        int count = 0;
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }   
        while(temp!= NULL){     //Counting total nodes
            count++;
            temp = temp->next;
        }
        int midnode = (count/2) + 1;        //Finding position of middle node
        temp = head;
        while(temp!=NULL){
            midnode = midnode-1;        //Decrementing midnode to reach middle
            if(midnode == 0){
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    ListNode* middleNode(ListNode* head) {      //Find middle node of singly linked list using two pointer approach
        // ListNode *temp = head;
        // int count = 0;
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode *slow = head;      //Slow pointer moves one step
        ListNode *fast = head;      //Fast pointer moves two steps
        while(fast!=NULL && fast->next!=NULL){      //When fast reaches end, slow will be at middle
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
int main(){
}