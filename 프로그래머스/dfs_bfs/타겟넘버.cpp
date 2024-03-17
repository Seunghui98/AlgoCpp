// 프로그래머스 - 타겟넘버(dfs/bfs)
// 문제번호 : 43165, Level-2

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int> number, int n, int t, int depth){
    int answer = 0;
    if(number.size() == depth)
        if(n == t)
            return 1;
        else
            return 0;
    
    answer += dfs(number, n+number[depth], t, depth+1);
    answer += dfs(number, n-number[depth], t, depth+1);
    
    return answer;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = dfs(numbers, 0, target, 0);
    
    return answer;
}
