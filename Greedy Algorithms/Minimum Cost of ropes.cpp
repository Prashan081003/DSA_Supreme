long long minCost(long long arr[], long long n) {
        // Your code here
           priority_queue<long long ,vector<long long >, greater<long long > > minHeap;
	//insert all elements
	for(int i=0; i<n; i++ ){
		long long  val = arr[i];
		minHeap.push(val);
	}
	long long cost = 0;
	while(minHeap.size() > 1) {
		long long  a = minHeap.top();
		minHeap.pop();
		long long  b = minHeap.top();
		minHeap.pop();
		
		cost += a + b;
		long long sum = a+ b;
		minHeap.push(sum);
	}
	return cost;
    }
