#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adj;
        for(auto x: pairs){
            adj[x[0]].emplace(x[1]);
            adj[x[1]].emplace(x[0]);
        }

        //TAMAÑO DEL UNORDERED_SET, NODO PADRE
        priority_queue<pair<int,int>> q; //de menor a mayor

        for(auto [i,a]: adj) q.push({a.size(), i});
        int n=q.size(), fl=0;
        unordered_set<int> vis;

        while(!q.empty()){
            auto [sz,cur]=q.top(); //tamaño, nodo
            q.pop();
            int u=0;
            int usz=n+1; //tamaño del queue+1
            if(!vis.empty()){
                for(auto x: adj[cur]){
                    if(vis.count(x) && usz > adj[x].size()){
                        usz=adj[x].size(); //usz se va volviendo pequeño cada vez mas
                        u=x;
                    }
                }
            }
            vis.emplace(cur); //marcado como visitado
            if(u==0){
                if(sz!=(n-1)) return 0; //es decir, no hay manera de ordenar el arbol
                continue;
            }
            for(auto x: adj[cur]){
                if(x==u) continue;
                if(adj[u].count(x)==0) return 0; //lo mismo de arriba
            }
            if(usz==sz) fl=1;
        }
        if(fl==1) return 2;
        return 1;
    }
};

int main(){
    return  0;
}