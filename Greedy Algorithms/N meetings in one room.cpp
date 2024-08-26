  // Comparator function to sort meetings based on their end times
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

    // Function to find the maximum number of meetings that can be attended
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int, int>> time;

        // Store the start and end times as pairs in the vector
        for (int i = 0; i < n; i++) {
            time.push_back({start[i], end[i]});
        }

        // Sort meetings based on their end times using the custom comparator
        sort(time.begin(), time.end(), cmp);

        int count = 1;  // At least one meeting can always be attended
        int prevEnd = time[0].second;

        // Iterate over the rest of the meetings
        for (int i = 1; i < n; i++) {
            int currStart = time[i].first;
            int currEnd = time[i].second;

            // If the current meeting starts after the previous one ends, attend it
            if (currStart > prevEnd) {
                count++;
                prevEnd = currEnd;  // Update the end time to the current meeting's end
            }
        }

        return count;
    }
};
