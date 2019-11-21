#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

#define INF INT_MAX



vector<vector<pair<int,int> > > G(20); // vector de vectores de pares de máximo 20, con límite de 20 nodos.

vector<int> Dist;


void Dijkstra(int N) {
    // Aquí va tu código.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    
    Dist.assign(N, INF);
    Dist[0] = 0;
    pair<int,int> p(0,0);
    Q.push(p);
    while(!Q.empty()) {
        int u = Q.top().first;
        Q.pop();
        for(int i = 0; i < G[u].size(); i++){
            pair<int, int> p = G[u][i];
            int v = p.first;
            int w = p.second;
            if(Dist[v] > Dist[u] + w){
                Dist[v] = Dist[u] + w;
                pair<int, int> nuevo (v, Dist[v]);
                Q.push(nuevo);
            }
        }
    }
    
}

int main() {
    int Veces = 0;
    cin >> Veces;
    for(int i = 0; i < Veces; i++) {
    unordered_map<char, int> hash = {{'A',1}, {'B',2},{'C',3},{'D',4},{'E',5},{'F',6},{'G',7},{'H',8},{'I',9},{'J',10},{'K',11},{'L',12},{'M',13},{'N',14},{'O',15},{'P',16},{'Q',17},{'R',18},{'S',19},{'T',20} };
    int N, M, u, v, w;
    char cU, cV;
    cin >> N >> M;
    
    for(int i=0;i<M;++i){
        cin >> cU >> cV >> w;
        v = hash[cV];
        u = hash[cU];
        pair<int,int> n1(v-1,w); //Le resto 1 porque los vectores inician en 0
        pair<int,int> n2(u-1,w);
        G[u-1].push_back(n1);
        G[v-1].push_back(n2);
    }
    Dijkstra(N);
    
    int max = 0;
    int temp = 0;
    for(int i=1;i<N;i++){
        if(Dist[i] > max) {
            max = Dist[i];
            temp = i+1;
        }
    }
    
    for(auto x:hash){
        if(x.second == temp) cout << "Case " << i + 1 << ": " << x.first << endl;
    }
        
    }
    
    
    return 0;
}

/*
 5 8
 1 2 2
 1 3 12
 1 4 10
 2 3 9
 2 5 5
 3 4 6
 3 5 3
 4 5 7
 */



