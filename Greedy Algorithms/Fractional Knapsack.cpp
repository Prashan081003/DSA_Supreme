 <<<<<<=== Method 1 Using Sorting ============>>>>>
   class Solution {
  public:
    static bool cmp(pair<Item, double>& a, pair<Item, double>& b) {
        return a.second > b.second;
    }
    
    double fractionalKnapsack(int w, Item arr[], int n) {
        vector<pair<Item, double>>v;
        for(int i = 0; i < n; i++) {
            double perUnitValue = (1.0 * arr[i].value)/arr[i].weight;
            v.push_back({arr[i], perUnitValue});
        }
        sort(v.begin(), v.end(), cmp);
        double totalValue = 0;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first.weight > w) {
                totalValue += (w * v[i].second);
                w = 0;
            }
            else {
                w -= v[i].first.weight;
                totalValue += v[i].first.value;
            }
        }
        return totalValue;
    }
};
 <<<<<<=== Method 2 Using heap ============>>>>>
int fractionalKnapsack(vector<int> val, vector<int> wt, int n, int capacity) {
	vector<float> valWtRatio;
	for(int i=0; i<n; i++) {
		float ratio  = (val[i] * 1.0) / wt[i];
		valWtRatio.push_back(ratio);
	}

	priority_queue<pair<float,pair<int,int> > > maxi;
	for(int i=0; i<n; i++) {
		maxi.push({valWtRatio[i], {val[i], wt[i] } } ); 
	}
	//max heap is ready 
	int totalVal = 0;
	while(capacity != 0 && !maxi.empty() ) {
		auto front = maxi.top();
		float ratio = front.first;
		int value = front.second.first;
		int weight = front.second.second;
		maxi.pop();
		//fulll insert hoga
		if(capacity >= weight) {
			totalVal += value;
			capacity = capacity - weight;
		}
		else {
			//fractional insert hoga
			int valueToInclude = ratio * capacity;
			totalVal += valueToInclude;
			capacity = 0;
			break;
		}
	}
	return totalVal;
}
