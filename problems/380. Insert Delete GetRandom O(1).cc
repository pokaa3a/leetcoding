class RandomizedSet {
private:
    map<int, int> hash;
    vector<int> list;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash.find(val)!=hash.end()) return false;
        hash[val] = list.size();
        list.push_back(val);
        return true;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash.find(val)==hash.end()) return false;
        int idx = hash[val];
        list[idx] = list.back();
        list.pop_back();
        hash[list[idx]] = idx;
        hash.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(list.size()==0) return -1;
        return list[rand()%list.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */