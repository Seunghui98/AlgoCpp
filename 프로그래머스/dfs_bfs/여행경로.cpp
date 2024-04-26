// 프로그래머스 - 여행경로
// dfs&bfs - Level3


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string>> ticket;
vector<string> ans_list;

void dfs(string s, string str, vector<bool> visited, int depth, const int n){
    if(depth == n) {
        ans_list.push_back(str);
        return;
    }
    
    for(int i=0;i<n;++i){
        if(visited[i]) {
            continue;
        }
        string s1 = ticket[i][0];
        if(s != s1) {
            continue;
        }
        string s2 = ticket[i][1];
        visited[i] = true;
        dfs(s2, str+" "+s2, visited, depth+1, n);
        visited[i] = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int n = tickets.size();
    vector<bool> visited(n, false);
    ticket = tickets;
    
    dfs("ICN", "ICN", visited, 0, n);
    sort(ans_list.begin(), ans_list.end());
    
    vector<string> answer;
    string ans_str = ans_list[0];
    string str = "";    
    for(int i=0;i<ans_str.length();++i){
        if(ans_str[i] == ' '){
            answer.push_back(str);
            str = "";
        } else {
            str += ans_str[i];
        }
    }
    answer.push_back(str);
    return answer;
}
