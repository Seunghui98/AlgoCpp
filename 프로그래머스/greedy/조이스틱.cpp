// 프로그래머스 - 조이스틱
// greedy - Level2

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int solution(string name) {
    int answer = 0;
    int n = name.length();

    int min_move = n-1;
    // 처음 시작

    for(int i=0;i<n;++i){
        if(name[i] - 'A' < 14) answer += (name[i]-'A');
        else answer += ('Z'-name[i]+1);
        
        int n_idx = i+1;
        while(n_idx < n && name[n_idx] == 'A') ++n_idx;
        // 1. (원점) -> i -> (원점) -> n_idx
        // i + i + n-n_idx = 2i + n - n_idx 
        // 2. (원점) -> n_idx -> (원점) -> i
        // (n-n_idx) + (n-n_idx) + i = i + 2n - 2*n_idx
        // 1번과 2번의 최솟값 비교 -> 그러나 i + n - n_idx는 공통
        min_move = min(min_move, i+n-n_idx+min(i, n-n_idx));
    }
    
    answer += min_move;
    return answer;
}
