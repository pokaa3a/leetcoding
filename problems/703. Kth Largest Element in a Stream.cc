#include <iostream>
#include <vector>
#include <queue>

class compare {
public:
	bool operator() (int a, int b) {
		return a > b;	// 
	}
};

class KthLargest {
public:
	KthLargest(int k, std::vector<int> nums) {
		K = k;
		for (int i = 0; i < nums.size(); ++i) {
			add(nums[i]);
		}
	}

	int add(int val) {
		if (q.size() < K) {
			q.push(val);
		} else if (val > q.top()) {
			q.pop();
			q.push(val);
		}
		return q.top();
	}

private:
	std::priority_queue<int, std::vector<int>, compare> q;
	int K;
};

int main() {

	int k = 3;
	int arr[] = {4, 5, 8, 2};

	KthLargest kth(k, std::vector<int>(arr, arr+3));
	std::cout << kth.add(3) << std::endl;
	std::cout << kth.add(5) << std::endl;
	std::cout << kth.add(10) << std::endl;
	std::cout << kth.add(9) << std::endl;
	std::cout << kth.add(4) << std::endl;

}
