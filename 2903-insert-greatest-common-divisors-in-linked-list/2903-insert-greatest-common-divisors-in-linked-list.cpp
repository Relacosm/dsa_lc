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
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        
        while (curr && curr->next) {
            int gcdVal = __gcd(curr->val, curr->next->val);  // Compute GCD of current node and next node
            ListNode* newNode = new ListNode(gcdVal);  // Create a new node with GCD value
            
            newNode->next = curr->next;  // Insert the new node between curr and curr->next
            curr->next = newNode;
            
            curr = newNode->next;  // Move to the next pair
        }
        
        return head;
    }
};