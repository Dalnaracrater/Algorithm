/*
사이트: 백준, 17472번
분류: Depth First Search(DFS), Minimum Spanning Tree(MST), Kruskal, Disjoint Set
코멘트: 체크해야할 제약조건들이 너무 많아 통과하는데 시간이 오래 걸렸다.
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define ll long long

const int SIZE = 10;
const int INF = 1000;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

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

int mm[SIZE][SIZE], island[6][6], visited[SIZE][SIZE];
int islandCount = 0;
int n, m;

void dfs(int x, int y){
    // dfs를 통해 섬에 번호를 부여함
    mm[x][y] = islandCount;
    visited[x][y] = islandCount;

    for(int i = 0; i < 4; ++i){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        
        if (x1 < 0 || n <= x1 || y1 < 0 || m <= y1 || visited[x1][y1] || mm[x1][y1] == 0){
            continue;
        }
        
        dfs(x1, y1);
    }
}

void CalDistance(int x, int y){
    for(int i = 0; i < 4; ++i){
        int x1 = x +  dx[i];
        int y1 = y +  dy[i];
        
        int distance = 0;
        
        while(x1 >= 0 && n > x1 && y1 >= 0 && m > y1){
            if (mm[x][y] == mm[x1][y1]){
                break;
            }
            
            if (mm[x1][y1] == 0){
                x1 += dx[i];
                y1 += dy[i];
                ++distance;
                continue;
            }
            
            if (mm[x1][y1] != mm[x][y] ){
                int a = mm[x][y] - 1;
                int b = mm[x1][y1] - 1;
                
                if (distance != 1){
                    // 섬 a와 섬 b 사이에 거리가 2 이상인 최소 거리
                    island[a][b] = distance > island[a][b] ? island[a][b] : distance;
                    island[b][a] = island[a][b];
                }

                break;
            }
        }
    }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d", &mm[i][j]);
        }
    }
    
    // 섬에 번호 부여
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if (visited[i][j] == 0 && mm[i][j]){
                ++islandCount;
                dfs(i,j);
            }
        }
    }
    
    // 각 섬 간 최소 거리 계산
    for(int i = 0; i < islandCount; ++i){
        for(int j = 0; j < islandCount; ++j){
            island[i][j] = INF;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if (mm[i][j]){
                CalDistance(i, j);
            }
        }
    }
    
    // Kruskal 알고리즘을 이용한 MST 구성 및 가중치의 최솟값 계산
    vector<pair<int, pii>> mst;

    for(int i = 0; i < islandCount; ++i){
        for(int j = i + 1; j < islandCount; ++j){
            if(island[i][j] != INF){
                mst.push_back(make_pair(island[i][j], make_pair(i,j)));
            }
        }
    }

    sort(mst.begin(), mst.end());
    
    DisjointSet s(islandCount);
    int ans = 0;
    
    for(int i = 0; i < mst.size(); ++i){
        int node1 = mst[i].second.first;
        int node2 = mst[i].second.second;
        
        if (s.find(node1) == s.find(node2)){
            continue;
        } else {
            s.merge(node1, node2);
            ans += mst[i].first;
        }
    }
    
    // 모든 섬이 연결되어있는지 확인
    int check = s.find(0);
    for(int i = 1; i < islandCount; ++i){
        if (check != s.find(i)){
            cout << -1 << endl;
            return 0;
        }
    }
    
    if (ans){
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
