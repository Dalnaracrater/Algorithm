/*
사이트: 백준, 1197번
분류: Minimum Spanning Tree (MST), Kruskal algorithm, Disjoint Set
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define ll long long

using namespace std;

struct DisjointSet{
    vector<int> parent, rank;
    
    DisjointSet(int n): parent(n), rank(n, 1) {
        for(int i = 0; i < n; ++i){
            parent[i] = i;
        }
    }
    
    int find(int u){
        if (u == parent[u]){
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v){
        u = find(u);
        v = find(v);
        
        if (u == v){
            return;
        }
        if (rank[u] > rank[v]){
            swap(u, v);
        }
        parent[u] = v;
        if (rank[u] == rank[v]){
            ++rank[v];
        }
    }
};

int main(void) {
    int v, e;
    
    scanf("%d %d", &v, &e);
    
    vector<pair<ll, pii>> mm;
    
    for(int i = 0; i < e; ++i){
        int f, t;
        ll cost;
        scanf("%d %d %lld", &f, &t, &cost);
        mm.push_back(make_pair(cost, make_pair(f-1, t-1)));
    }
    
    // 가중치를 기준으로 오름차순 정렬
    sort(mm.begin(), mm.end());
    
    // 간선의 가중치가 4바이트 정수형 크기를 넘어가지 않는다고 되어있지만
    // 결과 값을 구할 때는 가중치의 합을 필요로 하기 때문에 더 큰 크기의 자료형이 필요
    ll ans = 0;
    DisjointSet x(v);

    for(int i = 0; i < e; ++i){
        int node1, node2;
        node1 = mm[i].second.first;
        node2 = mm[i].second.second;

        // 사이클 생성
        if (x.find(node1) == x.find(node2)) {
            continue;
        }
        // 사이클을 생성하지 않는 경우
        else {
            ans += mm[i].first;
            x.merge(node1, node2);
        }
    }
    
    cout << ans << endl;

    return 0;
}
