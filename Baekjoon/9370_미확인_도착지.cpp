/*
번호: 백준, 9370
분류: Dijkstra
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define ARR_SIZE 2001
#define INF 10e7
#define pii pair<int, int>

using namespace std;

vector<int> dijk(int x);

int n, m, t;
int s, g, h;
int mm[ARR_SIZE][ARR_SIZE];

int main(void)
{
    int testcase;

    scanf("%d", &testcase);

    while (testcase--) {

        int candidate[100];
        vector<int> ans;

        scanf("%d %d %d", &n, &m, &t);

        scanf("%d %d %d", &s, &g, &h);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mm[i][j] = INF;
            }
        }

        for (int i = 0; i < m; i++) {
            int a, b, d;

            scanf("%d %d %d", &a, &b, &d);
            mm[a][b] = d;
            mm[b][a] = d;
        }

        for (int i = 0; i < t; i++) {
            scanf("%d", candidate + i);
        }

        // g-h가 존재할 경우 s -> t까지의 최단 거리 벡터
        vector<int> original = dijk(s);
        
        // g-h가 존재하지 않을 경우
        int inter = mm[g][h];
        mm[g][h] = mm[h][g] = 0;

        // 양방향 그래프이기 때문에 s -> h, h -> s에 대해 모두 고려해야 함
        vector<int> sgh = dijk(s);
        vector<int> gt = dijk(g);
        vector<int> ht = dijk(h);
        
        for (int i = 0; i < t; i++) {
            // 기준이 되는 s -> t 간 최단 거리
            int base = original[candidate[i]];

            // 양방향임을 고려
            // s -> g -> h -> t
            int sght = sgh[g] + inter + ht[candidate[i]];
            // s -> h -> g -> t
            int shgt = sgh[h] + inter + gt[candidate[i]];

            if (base == sght || base == shgt) {
                ans.push_back(candidate[i]);
            }
        }

        // 출력 표준
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}

vector<int> dijk(int x) {
    // 다익스트라 알고리즘을 통한 최단거리
    vector<int> dist(ARR_SIZE, INF);

    dist[x] = 0;
    priority_queue<pii> pq;

    pq.push(make_pair(0, x));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cost) {
            continue;
        }

        for (int i = 1; i <= n; i++) {
            if (dist[i] > mm[node][i] + dist[node]) {
                dist[i] = mm[node][i] + dist[node];
                pq.push(make_pair(-dist[i], i));
            }
        }
    }

    return dist;
}