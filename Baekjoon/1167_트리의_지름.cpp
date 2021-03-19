/*
사이트: 백준, 1167번
분류: Depth First Search(DFS), Tree
코멘트
처음에는 다익스트라 알고리즘을 사용하여 각 노드에서의 최단거리 중 최댓값을 찾으면 될 줄 알았다. 하지만 시간초과가 났다.
dfs을 어디에선가 실행하여 지름이 최대인 노드를 찾고, 그 노드에서 다시 dfs를 실행하는 것을 반복한다. 좋은 문제인 것 같다.
*/

#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

const int SIZE = 100000;

int n;
int visited[SIZE];
int total, start;

deque<deque<pii>> mm(SIZE);

void dfs(int node, int cost){
    if (visited[node]){
        return;
    }
    
    visited[node] = 1;
    
    // 지름 정보 저장
    if (cost > total){
        start = node;
        total = cost;
    }
    
    // dfs 재귀 호출
    for(auto a: mm[node]){
        dfs(a.first, cost + a.second);
    }
}

int main(void){
    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        int node, to, cost;

        scanf("%d", &node);
        --node;
        
        scanf("%d", &to);
        while(to != -1){
            --to;
            scanf("%d", &cost);
            
            mm[node].push_back(make_pair(to, cost));
            
            scanf("%d", &to);
        }
    }
    
    int before;
    
    memset(visited, 0, sizeof(visited));
    dfs(3, 0); // 아무데서나 시작해도 상관 없음
    do{
        before = start;
        memset(visited, 0, sizeof(visited));
        dfs(start, 0);
    }while(before != start); // dfs를 두 번 실행했을 때 서로를 가르키면 종료
    
    cout << total << endl;
    
    return 0;
}
