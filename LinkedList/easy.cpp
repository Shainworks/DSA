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
int main(){
}