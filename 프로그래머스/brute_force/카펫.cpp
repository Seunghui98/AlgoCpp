// 프로그래머스 - 카펫
// 브루트포스 - Level2

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;
    for(int h=3;h<=5000;++h){
        if((area % h) == 0){
            int w = area / h;
            if((h-2)*(w-2) == yellow){
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    
    return answer;
}
