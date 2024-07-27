#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * Function to find the next greater value for each node in the linked list.
     * @param head: Pointer to the head of the singly-linked list.
     * @return A vector of integers where each element represents the next greater value for the corresponding node in the linked list.
     */
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st; // Stack to keep track of indices
        vector<int> ll; // Vector to store the values of the linked list

        // Traverse the linked list and store values in the vector
        while (head) {
            ll.push_back(head->val);
            head = head->next;
        }

        vector<int> ans(ll.size()); // Vector to store the answer

        // Traverse the vector to find the next larger value for each node
        for (int i = 0; i < ll.size(); i++) {
            // If the current value is greater than the value at the index on the top of the stack,
            // then it's the next greater value for the node at that index.
            while (!st.empty() && ll[i] > ll[st.top()]) {
                int idx = st.top(); // Index of the node that has found its next greater value
                st.pop();
                ans[idx] = ll[i]; // Assign the next greater value to the answer vector
            }
            st.push(i); // Push the current index onto the stack
        }

        // For nodes that don't have a next greater value, they remain 0 in the answer vector.
        return ans;
    }
};
