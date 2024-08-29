#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int n, int start[], int end[]) {
    // Step 1: Store the meeting times as pairs (end time, start time)
    vector<pair<int, int>> timing;

    for (int i = 0; i < n; i++) {
        timing.push_back(make_pair(end[i], start[i]));
    }

    // Step 2: Sort the meetings by their end times
    sort(timing.begin(), timing.end());

    // Step 3: Initialize count of meetings and set the end time of the first meeting
    int count = 1;
    int ansEnd = timing[0].first;

    // Step 4: Iterate through the meetings to find the maximum number of meetings
    for (int i = 1; i < n; i++) {
        if (timing[i].second > ansEnd) {  // If the start time of the meeting is after the last meeting ends
            count++;
            ansEnd = timing[i].first;  // Update the end time to the current meeting's end time
        }
    }

    return count;
}
