class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count1, count2;
        vector<string> result;

        // Function to split sentence into words and count occurrences
        auto countWords = [](const string& sentence, unordered_map<string, int>& countMap) {
            istringstream iss(sentence);
            string word;
            while (iss >> word) {
                countMap[word]++;
            }
        };

        // Count words in both sentences
        countWords(s1, count1);
        countWords(s2, count2);

        // Find uncommon words
        auto addUncommonWords = [&](const unordered_map<string, int>& countMap1, const unordered_map<string, int>& countMap2) {
            for (const auto& [word, count] : countMap1) {
                if (count == 1 && countMap2.find(word) == countMap2.end()) {
                    result.push_back(word);
                }
            }
        };

        // Add uncommon words from s1 to s2 and vice versa
        addUncommonWords(count1, count2);
        addUncommonWords(count2, count1);

        return result;
    }
};