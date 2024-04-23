// 프로그래머스(dfs&bfs)
// 아이템 줍기 - Level3

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int visited[101][101] = {0};
int answer = (int)1e9;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int a, int b, int ans_a, int ans_b, int depth){
    if(a == ans_a && b == ans_b){
        answer = min(answer, depth);
        return;
    }
    
    for(int i=0;i<4;++i){
        int na = a + dx[i];
        int nb = b + dy[i];
        if(visited[na][nb] == -1){
            visited[na][nb] = 0;
            dfs(na, nb, ans_a, ans_b, depth+1);
            visited[na][nb] = -1;
        }
    }
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 1배로 했을 때-> 다른 방향을 타고 갈 노선이 있는데 거기로 깡충 뛰어버림;;
    // 2배로 늘려서 위의 문제를 방지 하기
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    
    // 내부 영역 다 칠하기
    for(int i=0;i<rectangle.size();i++){
        for(int a=rectangle[i][0]*2;a<=rectangle[i][2]*2;++a){
            for(int b=rectangle[i][1]*2;b<=rectangle[i][3]*2;++b){
                visited[a][b] = -1;
            }
        }
    }
    
    // 속 안에 파기
    for(int i=0;i<rectangle.size();++i){
         for(int a=rectangle[i][0]*2+1;a<rectangle[i][2]*2;++a){
            for(int b=rectangle[i][1]*2+1;b<rectangle[i][3]*2;++b){
                visited[a][b] = 0;
            }
        }
    }
    
    visited[characterX][characterY] = 1;
    dfs(characterX, characterY, itemX, itemY, 0);

    return answer/2;
}
