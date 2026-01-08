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
     ListNode* reverseList(ListNode* head) {//      Reverse a singly linked list
     ListNode *temp = head;
     ListNode *prev = NULL; 
     while(temp!=NULL){
        ListNode *front = temp->next;       //Storing next node
        temp->next = prev;
        prev = temp;
        temp = front;
     }
     return prev;
    }
       ListNode* reverseList(ListNode* head) {      //Reverse a singly linked list using recursion
     if(head == NULL || head->next == NULL){        //Base case
        return head;
     }
     ListNode *newhead = reverseList(head->next);       //Reversing rest of the list
     ListNode *front = head->next;      //Storing next node
     front->next = head;    //Reversing the link
     head->next = NULL;     //Setting next of current node to NULL
     return newhead;        //Returning new head of reversed list
    }
    bool hasCycle(ListNode *head) {     //Detect cycle in a linked list using hashing
        unordered_set<ListNode*> visited;
        ListNode *temp = head;
        while(temp!=NULL){
            if(visited.find(temp) != visited.end()){            //Cycle detected
                return true;
            }
            visited.insert(temp);           //Marking node as visited
            temp = temp->next;
        }
        return false;
    }
    bool hasCycle(ListNode *head) {     //Detect cycle in a linked list using Floyd's Cycle-Finding Algorithm
        if(head == NULL || head->next ==NULL ){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){      //Moving slow by one and fast by two
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){       //Cycle detected
                return true;
            }
        }       
        return false;
    }
    ListNode *detectCycle(ListNode *head) {     //Detect the starting node of cycle in a linked list using hashing
        ListNode* temp = head;
        unordered_map<ListNode*, int> nodeMap;
        while (temp != nullptr) {       
            if (nodeMap.find(temp) != nodeMap.end()) {      //Cycle detected 
                return temp;        //Starting node of cycle
            }
            nodeMap[temp] = 1;
            temp = temp->next;
        }
        return NULL;
    }
int main(){
}