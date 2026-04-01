class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<tuple<int,int,char,int>> robots;
        
        for(int i = 0; i < n; i++){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        // Sort by position
        sort(robots.begin(), robots.end());
        
        stack<int> st; // store indices of robots in 'robots'
        
        for(int i = 0; i < n; i++){
            auto &[pos, health, dir, idx] = robots[i];
            
            if(dir == 'R'){
                st.push(i);
            } else {
                // dir == 'L'
                while(!st.empty() && get<2>(robots[st.top()]) == 'R'){
                    
                    if(get<1>(robots[st.top()]) < health){
                        // stack robot dies
                        health--;
                        st.pop();
                    }
                    else if(get<1>(robots[st.top()]) > health){
                        // current robot dies
                        get<1>(robots[st.top()])--;
                        health = 0;
                        break;
                    }
                    else{
                        // both die
                        health = 0;
                        st.pop();
                        break;
                    }
                }
                
                if(health > 0){
                    st.push(i);
                }
                
                get<1>(robots[i]) = health;
            }
        }
        
        // Collect survivors
        vector<pair<int,int>> survivors; // {original_index, health}
        
        while(!st.empty()){
            int i = st.top();
            st.pop();
            if(get<1>(robots[i]) > 0){
                survivors.push_back({get<3>(robots[i]), get<1>(robots[i])});
            }
        }
        
        // Sort by original index
        sort(survivors.begin(), survivors.end());
        
        vector<int> result;
        for(auto &p : survivors){
            result.push_back(p.second);
        }
        
        return result;
    }
};