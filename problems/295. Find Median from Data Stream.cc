class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()){
            left.push(num);
            return;
        }
        
        if(num<=left.top()){
            left.push(num);
            if(left.size() > right.size()+1){
                right.push(left.top());
                left.pop();
            }
        } else {
            right.push(num);
            if(right.size() > left.size()){
                left.push(right.top());
                right.pop();
            }
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()) return ((double)left.top() + (double)right.top())/2;
        else return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */