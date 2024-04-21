// 프로그래머스 - DFS/BFS
// 단어변환 - level3

#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool visited[51];
int min_ans = (int)1e9;

void dfs(string now, string target, int depth, vector<string> words){
    if(now == target) {
        if (min_ans > depth) min_ans = depth;
        return;
    }
    
    for(int i=0;i<words.size();++i){
        if(visited[i]) continue;
        int diff_cnt = 0;
        for(int j=0;j<now.length();++j){
            if(now[j] != words[i][j]) ++diff_cnt;
        }  

        if(diff_cnt == 1){
            visited[i] = true;
            dfs(words[i], target, depth+1, words);
            visited[i] = false;
        }
    }
    
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    int n = words.size();
    for(int i=0;i<n;++i){
        visited[i] = false;
    }
    min_ans = (int)1e9;
    
    dfs(begin, target, 0, words);
    if (min_ans != (int)1e9)
        answer = min_ans;
    return answer;
}
