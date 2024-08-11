#include <unordered_map>

/**
 * Definition for singly-linked list.
 * 
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * @brief Given the head of a linked list, remove all consecutive nodes that sum to zero.
 * 
 * This function removes all sublists from a linked list whose sum of node values equals zero.
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);  // Create a dummy node to handle edge cases easily
        dummyNode->next = head;  // Set the next of dummy node to the head of the list
        unordered_map<int, ListNode*> mp;  // Map to store prefix sums and corresponding nodes
        int prefixSum = 0;  // Initialize prefix sum to 0
        mp[0] = dummyNode;  // Map the prefix sum 0 to the dummy node
        
        while (head) {
            prefixSum += head->val;  // Update the prefix sum
            
            if (mp.find(prefixSum) != mp.end()) {  // Check if the prefix sum has been seen before
                ListNode* start = mp[prefixSum];  // Get the node where the prefix sum was seen
                ListNode* temp = start;  // Temporary pointer to traverse and remove nodes
                int pSum = prefixSum;  // Initialize a temporary sum with the prefix sum
                
                // Remove nodes between the previous occurrence and current node
                while (temp != head) {
                    temp = temp->next;  // Move to the next node
                    pSum += temp->val;  // Update the sum
                    if (temp != head)
                        mp.erase(pSum);  // Erase the sum from the map if not at the head
                }
                
                start->next = head->next;  // Skip over the zero-sum sublist
            } else {
                mp[prefixSum] = head;  // Map the current prefix sum to the current node
            }
            head = head->next;  // Move to the next node
        }
        
        return dummyNode->next;  // Return the modified list, skipping the dummy node
    }
};
