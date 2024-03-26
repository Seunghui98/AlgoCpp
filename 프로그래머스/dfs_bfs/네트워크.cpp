// 네트워크 - DFS
// Level3

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> computer;
bool visited[200];

void dfs(int idx, int n){
    for(int i = 0;i<n;++i){
        if(computer[idx][i] == 1){
            if(visited[i] == false){
                visited[i] = true;
                dfs(i, n);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    computer = computers;
    for(int i=0;i<n;++i){
        if(visited[i] == true) continue;
        visited[i] = true;
        dfs(i, n);
        ++answer;
    }
    return answer;
}
