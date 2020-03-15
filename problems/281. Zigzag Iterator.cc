class ZigzagIterator {
private:
    vector<int> listA;
    vector<int> listB;
    int iterator;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		listA = v1;
		listB = v2;
		iterator = 0;
    }

    int next() {
		int next;
		if(iterator<2*min(listA.size(), listB.size())){
			if(iterator%2==0){
				next = listA[iterator/2];
			}
			else{
				next = listB[iterator/2];
			}
		}
		else{
			next = listA.size()>listB.size()?listA[iterator-min(listA.size(),listB.size())]:listB[iterator-min(listA.size(),listB.size())];
		}
		iterator++;
		return next;
    }

    bool hasNext() {
		if(iterator<listA.size()+listB.size()){
			return true;
		}
		else{
			return false;
		}
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */