// 프로그래머스 - 최소직사각형
// brute force - Level1
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int h = 1;
    int w = 1;
    
    for(int i=0;i<sizes.size();i++){
        int temp_h_1 = max(h, sizes[i][0]);
        int temp_w_1 = max(w, sizes[i][1]);
        
        int temp_h_2 = max(h, sizes[i][1]);
        int temp_w_2 = max(w, sizes[i][0]);
        
        if(temp_h_1*temp_w_1 >= temp_h_2 * temp_w_2){
            h = temp_h_2;
            w = temp_w_2;
        } else {
            h = temp_h_1;
            w = temp_w_1;
        }
    } 
    int answer = h*w;
    return answer;
}
