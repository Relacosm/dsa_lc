#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Trie node structure
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int count = 0;  // Count of how many words pass through this node
};

class Solution {
public:
    // Insert a word into the Trie and update the counts
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++;
        }
    }
    
    // Calculate the score of each prefix for a given word
    int calculateScore(TrieNode* root, const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            node = node->children[c];
            score += node->count;
        }
        return score;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        // Insert all words into the Trie
        for (const string& word : words) {
            insert(root, word);
        }
        
        // Calculate the sum of scores for each word
        vector<int> answer;
        for (const string& word : words) {
            answer.push_back(calculateScore(root, word));
        }
        
        return answer;
    }
};
