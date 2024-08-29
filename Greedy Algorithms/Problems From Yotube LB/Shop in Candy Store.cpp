 vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N); 
           int Mini = 0;
    int buy = 0;           // Number of candies bought
    int freeCandies = N-1;   // Total candies remaining to consider

    while (buy <= freeCandies) {
        Mini += candies[buy];  // Buy the cheapest candy
        buy++;                           // Move to next candy
        freeCandies -= K;                // Get K candies for free
    }

    // Step 4: Sort the prices in descending order for maximum cost calculation
    

    // Step 5: Calculate the maximum cost
    int Maxi = 0;
    buy = N-1;
    freeCandies = 0;

    while (freeCandies<=buy) {
        Maxi += candies[buy];  // Buy the most expensive candy
        buy--; 
        freeCandies += K;                // Get K candies for free
    }

    // Step 6: Prepare the answer vector
    vector<int> ans;
    ans.push_back(Mini);
    ans.push_back(Maxi);

    return ans; 
    }
