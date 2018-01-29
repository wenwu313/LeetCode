class MedianFinder {
public:
	int count = 0;
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;

	/** initialize your data structure here. */
	MedianFinder() {
	}

	void addNum(int num) {
		count++;
		if (count & 0x1 == 1){
			minheap.push(num);
			maxheap.push(minheap.top());
			minheap.pop();
		}
		else{
			maxheap.push(num);
			minheap.push(maxheap.top());
			maxheap.pop();
		}
	}

	double findMedian() {
		if (count & 0x1 == 1)
			return maxheap.top();
		else
			return (maxheap.top() + minheap.top()) / 2.0;  //注意浮点数
	}
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder obj = new MedianFinder();
* obj.addNum(num);
* double param_2 = obj.findMedian();
*/