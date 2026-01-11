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
    int lengthOfLoop(Node *head) {      //Find length of loop in a linked list using Floyd's Cycle-Finding Algorithm
        Node *slow = head;
        Node *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){       //Cycle detected
                int length = 1;
                Node *temp = slow->next;        //Counting nodes in loop
                while(temp!=slow){
                    length++;
                    temp = temp->next;
                }
                return length;
            }
        }
        return 0;
    }
    bool isPalindrome(ListNode* head) {     //Check if linked list is palindrome using stack
        stack<int> st;
        ListNode *temp = head;
        while(temp!=NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp =head;
        while(temp!=NULL){
            if(st.top() == temp->val){
                temp = temp->next;
                st.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {     //Check if linked list is palindrome without using extra space
        if (head == NULL || head->next == NULL) {
        return true;  
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){      //Finding middle using two pointer approach
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL;
        ListNode *temp = slow;
        while(temp!=NULL){      //Reversing second half of linked list
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        } 
        ListNode *first = head;
        ListNode *second = prev;
        while(second!=NULL){        //Comparing first half and reversed second half
            if(first->val == second->val){
                first = first->next;
                second = second->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
    ListNode* oddEvenList(ListNode* head) {     //Group all odd nodes together followed by the even nodes using position of nodes
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *odd = head;
        ListNode *even = head->next;        
        ListNode *evenhead = even;
        while(even!=NULL && even->next!=NULL){      //Traversing odd and even nodes
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
    ListNode* oddEvenList(ListNode* head) {     //Group all odd nodes together followed by the even nodes using position of nodes but more concise
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenhead = even;
        while(odd!=NULL && odd->next!=NULL && even->next!=NULL){        //Traversing odd and even nodes
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {     //Remove Nth node from end of linked list by reversing the linked list
        if(head== NULL){
            return NULL;
        }
        ListNode *newhead = reverseLL(head);        //Reversing the linked list
        ListNode *temp = newhead;
        int count = 0;
        ListNode *prev = NULL;
        while(temp!=NULL){
            count++;
            if(count == n){
                if(prev == NULL){
                    newhead = temp->next;       //If head is to be removed
                }
                else{
                    prev->next = temp->next;                //Bypassing the Nth node     
                }
                delete temp;
                break;
            }   
            prev = temp;        //Storing previous node
            temp = temp->next;      //Moving to next node
        }
        ListNode *finalhead = reverseLL(newhead);
        return finalhead;
    }
    ListNode* reverseLL(ListNode* revhead){     //Function to reverse a linked list
        ListNode *prev = NULL;
        while(revhead!=NULL){
            ListNode *front = revhead->next;
            revhead->next = prev;
            prev = revhead;
            revhead = front;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {     //Remove Nth node from end of linked list using two pointer approach
        if(head == NULL){
            return NULL;
        }
        ListNode *fast = head;
        for(int i=0;i<n;i++){       //Moving fast pointer n steps ahead
            fast = fast->next;
        }
        if (fast == NULL) {     // If we need to remove the head node
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        ListNode *slow = head;
        while(fast->next!=NULL){        //Moving both pointers until fast reaches the end
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *delnode = slow->next;     //Node to be deleted
        slow->next = slow->next->next;      //Bypassing the Nth node from end
        delete delnode;
        return head;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next==NULL){
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL;
        ListNode *temp = head;
        while(temp!=NULL){
            if(temp == slow){
                if(prev == NULL){
                    temp->next = NULL;
                    delete temp->next;
                }
                else{
                    prev->next = temp->next;
                }
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
    ListNode* deleteMiddle(ListNode* head) {        //Delete middle node of linked list using two pointer approach
        if(head == NULL || head->next==NULL){
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL;
        ListNode *temp = head;
        while(temp!=NULL){
            if(temp == slow){
                if(prev == NULL){       //If head is to be deleted
                    temp->next = NULL;
                    delete temp->next;
                }
                else{
                    prev->next = temp->next;        //Bypassing the middle node
                }
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
    ListNode* deleteMiddle(ListNode* head) {        //Delete middle node of linked list using optimized two pointer approach
        if(head == NULL || head->next==NULL){
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head->next->next;      //Fast pointer starts two steps ahead because we need slow to point to the node before middle so that we can bypass middle
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *midnode = slow->next;     //Middle node to be deleted
        slow->next = slow->next->next;      //Bypassing the middle node
        delete midnode;
        return head;
    }
int main(){
}