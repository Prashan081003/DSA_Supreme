#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the largest undefended rectangle area
int findLargestUndefendedRectangle(int row, int col, vector<pair<int, int>>& loc) {
    vector<int> xDim, yDim;

    // Include the grid boundaries
    xDim.push_back(0);
    xDim.push_back(col + 1);
    yDim.push_back(0);
    yDim.push_back(row + 1);

    // Add tower positions
    for (int i = 0; i < loc.size(); i++) {
        xDim.push_back(loc[i].first);
        yDim.push_back(loc[i].second);
    }

    // Sort to find gaps between towers
    sort(xDim.begin(), xDim.end());
    sort(yDim.begin(), yDim.end());

    // Find the maximum difference in x and y dimensions
    vector<int> xAns, yAns;
    for (int i = 1; i < xDim.size(); i++) {
        int diff = xDim[i] - xDim[i-1] - 1;
        xAns.push_back(diff);
    }

    for (int i = 1; i < yDim.size(); i++) {
        int diff = yDim[i] - yDim[i-1] - 1;
        yAns.push_back(diff);
    }

    // Calculate the area of the largest rectangle
    int maxi = -1;
    for (int i = 0; i < xAns.size(); i++) {
        for (int j = 0; j < yAns.size(); j++) {
            int prod = xAns[i] * yAns[j];
            maxi = max(maxi, prod);
        }
    }

    return maxi;
}

int main() {
    int testCases;
    cin >> testCases;  // Number of test cases

    while (testCases--) {
        int col, row, tower;
        cin >> col >> row >> tower;  // Input for the grid and the number of towers

        vector<pair<int, int>> loc(tower);

        // Input the locations of the towers
        for (int i = 0; i < tower; i++) {
            cin >> loc[i].first >> loc[i].second;
        }

        // Get the result and print it
        int result = findLargestUndefendedRectangle(row, col, loc);
        cout << result << endl;
    }

    return 0;
}
