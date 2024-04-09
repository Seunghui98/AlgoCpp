// 프로그래머스 - 게임맵최단거리(1844)
// Level2 - dfs&bfs

/**
효율성 해결방법
1) int visited[n][m] 사용 안함
- visited 배열을 사용하지 않음
- 기존의 map 형태를 이용
  - map은 0또는 1로 초기화 되어 있음
  - 이것을 이용해서, 방문했으면 -1로 설정하도록 -> 재방문 안 하도록!

2) 매개변수 &의 reference 사용
**/

#include<vector>
#include<queue>
#include<utility>
#include<iostream>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(vector<vector<int>>& map, const int n, const int m){
    queue<pair<pair<int, int>, int>> q;
    map[0][0] = -1;
    q.push({{0, 0}, 1});
    
    while(!q.empty()){
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int dist = p.second;
        int x = p.first.first;
        int y = p.first.second;
        
        if(x == n-1 && y == m-1) return dist;
        
        for(int i=0;i<4;++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] == 0) continue;
            if(map[nx][ny] == -1) continue;
            
            map[nx][ny] = -1;

            q.push({{nx, ny}, dist+1});
        }
    }

    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    if(maps[n-1][m-1] == 0) answer = -1;
    else answer = bfs(maps, n, m);
    
    return answer;
}
