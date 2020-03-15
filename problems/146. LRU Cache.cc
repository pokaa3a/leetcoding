class LRUCache {
private:
    int maxCap;
    list<int> used; // key
    map<int, pair<int, list<int>::iterator>> cache; // key,<val,iterator>
public:
    LRUCache(int capacity) {
        maxCap = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it==cache.end()) return -1;  // not exist
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it!=cache.end()) touch(it);  // already exist, touch it only
        else {
            if(cache.size()==maxCap){   // if full
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value, used.begin()};
    }
    
    void touch(map<int, pair<int, list<int>::iterator>>::iterator it){
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
};