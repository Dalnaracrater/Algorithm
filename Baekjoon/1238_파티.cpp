/*
사이트: 백준, 1238번
분류: Dijkstra, graph
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define INF 10e7+1

using namespace std;

vector<int> dijk(int a);

int mm[1001][1001] = { 0, };
int n, m, x;

int main(void) {

	scanf("%d %d %d", &n, &m, &x);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mm[i][j] = INF;
		}
	}
	for (int i = 0; i <= n; i++) {
		mm[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		mm[a][b] = t;
	}

    // 되돌아오는 경우, x에서의 최단거리
    // 아래 for문에서 일일히 계산하지 않도록 하기 위함 (안그러면 시간 초과)
	vector<int> back = dijk(x);

	int max = 0;

	for (int i = 1; i <= n; i++) {
		if (i == x)
			continue;
		
		int dist = dijk(i)[x] + back[i];
		
		max = max > dist ? max : dist;
	}

	std::cout << max;


	return 0;
}

vector<int> dijk(int a) {
// priority queue를 이용한 dijkstra algorithm 구현
	int visited[1001] = { 0, };
	vector<int> dist(n+1, INF);

	queue<int> q;
	priority_queue<pii> pq;

    // 시작 점 설정, cost 0
	dist[a] = 0;
	pq.push(make_pair(0, a));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

        // 불필요한 노드가 우선순위 큐에 삽입되었기 때문에
        // 최단거리가 될 가능성이 없는 경우 탐색하지 않도록 함
		if (dist[node] < cost)
			continue;

		for (int i = 1; i <= n; i++) {
			int tempCost = mm[node][i] + dist[node];

            // 기존에 알고있는 a-i의 최단 경로보다 더 짧은 경우
			if (dist[i] > tempCost) {
				dist[i] = tempCost;
                // 우선순위 큐는 오름차순이 기본 설정임
                // 내림차순으로 정렬하기 위해서 따로 설정해야하기 때문에 (귀찮음)
                // -1을 곱해 음수에 대한 오름차순으로 정렬
				pq.push(make_pair(-tempCost, i));
			}
		}
	}

	return dist;
}