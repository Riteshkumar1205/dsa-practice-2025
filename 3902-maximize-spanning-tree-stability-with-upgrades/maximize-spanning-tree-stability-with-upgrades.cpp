class Solution {
public:

    struct DSU {
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++) parent[i]=i;
        }

        int find(int x){
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        }

        bool unite(int a,int b){
            a=find(a);
            b=find(b);

            if(a==b) return false;

            if(rank[a]<rank[b]) swap(a,b);

            parent[b]=a;

            if(rank[a]==rank[b]) rank[a]++;

            return true;
        }
    };

    bool check(int n, vector<vector<int>>& edges, int k, int x){

        DSU dsu(n);

        int used=0;

        for(auto &e:edges){

            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must==1){

                if(s<x) return false;

                if(!dsu.unite(u,v)) return false;

                used++;
            }
        }

        vector<vector<int>> normal, upgrade;

        for(auto &e:edges){

            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must==1) continue;

            if(s>=x) normal.push_back(e);
            else if(2*s>=x) upgrade.push_back(e);
        }

        for(auto &e:normal){
            if(dsu.unite(e[0],e[1])) used++;
        }

        int up=0;

        for(auto &e:upgrade){

            if(up==k) break;

            if(dsu.unite(e[0],e[1])){
                used++;
                up++;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int l=0,r=200000,ans=-1;

        while(l<=r){

            int mid=(l+r)/2;

            if(check(n,edges,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        return ans;
    }
};