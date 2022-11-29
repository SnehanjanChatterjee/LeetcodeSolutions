class RandomizedSet {
private:
    unordered_set<int> randomizedSet;
public:
    RandomizedSet() {
        randomizedSet = unordered_set<int>();
    }
    
    bool insert(int val) {
        auto itr = randomizedSet.insert(val);
        return itr.second;
    }
    
    bool remove(int val) {
        auto itr = randomizedSet.find(val);
        if(itr != randomizedSet.end()) {
            randomizedSet.erase(itr);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto it = randomizedSet.cbegin();
        int random = rand() % randomizedSet.size();
        std::advance(it, random);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */