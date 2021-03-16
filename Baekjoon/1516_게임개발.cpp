/*
사이트: 백준, 1516번
분류: Dynamic Programming
코멘트: 랭크에 비해 쉬운 DP 문제였던 것 같다.
*/

#include <iostream>
#include <vector>

const int SIZE = 500;

using namespace std;

int n;
int cost[SIZE], visited[SIZE];
vector<int> mm[SIZE];

int build(int node){
    if (visited[node] != 0){
        return visited[node];
    }
    
    int max = -1;
    for(int i = 0; i < mm[node].size(); ++i){
        int result = build(mm[node][i]) + cost[node];
        max = max > result ? max : result;
    }

    return visited[node] = max;
}

int main(void)
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i){
        scanf("%d", &cost[i]);
        
        int pre;
        scanf("%d", &pre);
        
        while(pre != -1){
            mm[i].push_back(pre - 1);
            scanf("%d", &pre);
        }
        
        if (mm[i].size() == 0){
            visited[i] = cost[i];
        }
    }
    
    for(int i = 0; i < n; ++i){
        cout << build(i) << endl;
    }
    
    return 0;
}
