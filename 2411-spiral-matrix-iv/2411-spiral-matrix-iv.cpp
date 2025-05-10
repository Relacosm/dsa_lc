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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> matrix(m, vector<int>(n, -1));  // Initialize m x n matrix with -1
        
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode* current = head;
        
        while (top <= bottom && left <= right && current != nullptr) {
            // Fill top row (left to right)
            for (int i = left; i <= right && current != nullptr; i++) {
                matrix[top][i] = current->val;
                current = current->next;
            }
            top++;
            
            // Fill right column (top to bottom)
            for (int i = top; i <= bottom && current != nullptr; i++) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            right--;
            
            // Fill bottom row (right to left)
            for (int i = right; i >= left && current != nullptr; i--) {
                matrix[bottom][i] = current->val;
                current = current->next;
            }
            bottom--;
            
            // Fill left column (bottom to top)
            for (int i = bottom; i >= top && current != nullptr; i--) {
                matrix[i][left] = current->val;
                current = current->next;
            }
            left++;
        }
        
        return matrix;
    }
};