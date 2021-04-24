/*
사이트: 백준, 2211번
분류: Dijkstra
코멘트
레벨에 비해 쉬운 문제이다. 기본적인 다익스트라 알고리즘 구현과 약간의 생각을 하면 쉽게 풀 수 있는 문제이다.
단 방향 그래프인지 아닌지 알려주지 않기 때문에 주의해야 한다.
*/

#include <iostream>
#include <deque>
#include <queue>

using namespace std;

#define SIZE 1000
#define INF 10e8

typedef pair<int, int> pii;

deque<pii> network[SIZE + 1];

deque<int> dijk(int s){
    
    priority_queue<pii> pq;
    
    deque<int> dist(SIZE + 1, INF);
    deque<int> cnn(SIZE + 1);
    
    pq.push(make_pair(0, s));
    dist[s] = 0;
    
    while(!pq.empty()){
        int start = pq.top().second;
        int cost = -pq.top().first;
        
        pq.pop();
        
        if (dist[start] < cost){
            continue;
        }
        
        for(int i = 0; i < network[start].size(); ++i){
            int nextNode = network[start][i].first;
            int nextCost = network[start][i].second;
            
            int nextDist = dist[start] + nextCost;
            
            if (dist[nextNode] > nextDist){
                dist[nextNode] = nextDist;
                
                pq.push(make_pair(-nextCost, nextNode));
                
                // 간선이 갱신되면 역방향으로 정보를 저장
                // 순방향으로 저장할 시, 시작 노드에서 여러 갈래로 뻗어가는 간선들을 모두 저장할 수 없음
                // 간선의 개수는 n - 1이기 때문에 역방향으로 저장하면 1차원 배열/벡터에 저장이 가능함
                cnn[nextNode] = start;
            }
        }
    }
    
    return cnn;
}

int main(void){

    cin.tie(0);
    int n, m;

    cin >> n >> m;



    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        network[a].push_back(make_pair(b, c));
        network[b].push_back(make_pair(a, c));
    }
    
    deque<int> cnn = dijk(1);
    
    cout << n - 1 << endl;
    
    for(int i = 2; i <= n; ++i){
        cout << i << " " << cnn[i] << endl;
    }
    
    
    
    return 0;
}
