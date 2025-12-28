class Solution {
public:
ListNode* swapNodes(ListNode* head, int k) {
// Find the length of the list
int len = 0;
ListNode* temp = head;
while (temp) {
len++;
temp = temp->next;
}
if (k > len) return head;
ListNode* first = head;
for (int i = 1; i <k; i++) {
first = first->next;
}
ListNode* second = head;
for (int i = 1; i < len - k + 1; i++) {
second = second->next;
}
// Swap the values of the nodes
int tempVal = first->val;
first->val = second->val;
second->val = tempVal;
return head;
}
};
