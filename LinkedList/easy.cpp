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
int main(){
}