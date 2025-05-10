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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
          vector<ListNode*> result(k, nullptr);  // Declare 'result' properly here
        
        // Step 1: Find the total length of the list
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }

        // Step 2: Calculate part sizes
        int partSize = length / k;        // Base size of each part
        int extraNodes = length % k;      // Remaining nodes to distribute one at a time

        // Step 3: Split the list
        current = head;
        for (int i = 0; i < k && current; i++) {
            result[i] = current;          // Start of the i-th part
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0); // Add an extra node if needed
            extraNodes--;

            // Move the current pointer to the end of this part
            for (int j = 1; j < currentPartSize; j++) {
                if (current) current = current->next;
            }

            // Disconnect the current part from the next part
            if (current) {
                ListNode* nextPart = current->next;
                current->next = nullptr;
                current = nextPart;
            }
        }

        return result;
    }
    };