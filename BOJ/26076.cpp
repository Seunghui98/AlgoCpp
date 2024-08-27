// BOJ - 곰곰이의 식단 관리 2(플래티넘5)
// 이용 알고리즘 : 0-1 BFS(최단거리 찾는 알고리즘)
// - 0-1 BFS: deque를 이용해, 가중치가 0인 간선을 먼저 처리, 가중치가 1인 간선을 나중에 처리하는 방식
// 0-1 BFS : O(V+E) -> 최단 경로 탐색을 가중치에 따라 먼저 처리하므로, 경로 탐색을 더 빠르고 효율적으로 수행 가능

// 해결 방법
// 1. 시작점 , 도착점의 8방향 벽을 제외하고, 다 벽을 추가함
// 2. 오른쪽 맨 끝 위 벽에서 왼쪽 맨 아래 벽까지 0-1 BFS(빈벽을 최소화 하면서 탐색) 수행
// 3. 벽의 갯수를 카운트 해서 답에 맞도록 출력함

#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

using namespace std;

int N, M;
int map[2003][2003];
int visit[2003][2003];

const int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
	fastio;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i= 2; i <= M + 1; i++) map[0][i] = 1;
	for (int i = 0; i <= M - 1; i++) map[N + 1][i] = 1;
	for (int i = 2; i <= N; i++) map[i][0] = 1;
	for (int i = 1; i <= N - 1; i++) map[i][M + 1] = 1;

	deque<tuple<int, int, int>> dq;
	dq.push_back({ 0, M + 1, 1 });
	visit[0][M + 1] = 1;

	while (!dq.empty()) {
		int y, x, cnt;
		tie(y, x, cnt) = dq.front();
		dq.pop_front();
		if (y == N + 1 && x == 0) break;
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > N + 1 || nx > M + 1) continue;
			if (ny == 1 && nx == 1) continue;
			if (ny == N && nx == M) continue;

			int ncnt = cnt + !(map[ny][nx]);
			if (visit[ny][nx] > 0 && visit[ny][nx] <= ncnt) continue;
			if (map[ny][nx]) {
				visit[ny][nx] = ncnt;
				dq.push_front({ ny, nx, ncnt });
			}
			else {
				visit[ny][nx] = ncnt;
				dq.push_back({ ny, nx, ncnt });
			}

		}
	}

	cout << visit[N + 1][0] - 1 << "\n";
	return 0;
}

