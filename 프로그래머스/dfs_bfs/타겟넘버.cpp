// 프로그래머스 - 타겟넘버(dfs/bfs)
// 문제번호 : 43165, Level-2

#include <string>
#include <iostream>
#include <vector>

using namespace std;
int ans = 0;
void dfs(vector<int>& number, int n, int t, int depth){
    if(number.size() == depth){
        if(n == t)
            ++ans;
        return;
    }

    dfs(number, n+number[depth], t, depth+1);
    dfs(number, n-number[depth], t, depth+1);
    
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, 0, target, 0);
    answer = ans;
    return answer;
}
