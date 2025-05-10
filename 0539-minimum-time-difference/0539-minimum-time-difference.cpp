class Solution {
public:
     int timeToMinutes(const string& time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }
    int findMinDifference(vector<string>& timePoints) {
         vector<int> minutes;

        // Convert all time points to minutes
        for (const string& time : timePoints) {
            minutes.push_back(timeToMinutes(time));
        }

        // Sort the time points in minutes
        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        int n = minutes.size();

        // Find the minimum difference between consecutive time points
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        // Account for circular difference (between first and last time points)
        minDiff = min(minDiff, (1440 - minutes.back() + minutes[0]));

        return minDiff;
    }
    
};