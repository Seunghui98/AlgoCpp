// 프로그래머스 - 단속카메라
// greedy - Level3

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    int temp = routes[0][1];
    
    for(vector<int> r:routes){
        // 다음차가 현재차가 나간 후에 들어온다면
        if(temp < r[0]){
            // 카메라 설치
            answer += 1;
            temp = r[1];
        }
        
        // 현재차보다 다음차가 나가는 거리보다 짧다면 값 갱신
        if(temp >= r[1]) {
            temp = r[1];
        }
    }
        
    
    
    
    return answer;
}
