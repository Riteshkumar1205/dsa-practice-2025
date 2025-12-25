class MapSum {
private:
    struct TrieNode {
        TrieNode* children[26];
        int sum;
        
        TrieNode() {
            sum = 0;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    unordered_map<string, int> mp; 
    
public:
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int delta = val;
        
        if (mp.count(key))
            delta -= mp[key];
        
        mp[key] = val;
        
        TrieNode* node = root;
        for (char c : key) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            
            node = node->children[idx];
            node->sum += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx])
                return 0;
            node = node->children[idx];
        }
        
        return node->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */