// 프로그래머스 - 구명보트
// greedy - Level2

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int s = 0;
    int e = people.size()-1;
    int answer = 0;
    while(s <= e){
        if(people[s]+people[e] <= limit){
            s += 1;
        }
        e -= 1;
        answer += 1;
    }

    
    return answer;
}
