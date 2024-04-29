// 프로그래머스 - 큰 수 만들기
// greedy - Level2

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<bool> check(number.length(), false);
    int cnt = 0;
    for(int i=0;i<number.length();++i){
        if(cnt == k) break;
        int num1 = number[i] - '0';
        for(int j=0;j<=k-cnt;++j){
            int num2 = number[i+j] - '0';
            if(num2 > num1) {
                check[i] = true;
                ++cnt;
                break;
            }
        }
        
        
    }
    
    
    for(int i=0;i<number.length();++i){
        if(cnt != k && i > k-cnt) continue;
        if(!check[i]) answer += number[i]; 
    }
    return answer;
}
