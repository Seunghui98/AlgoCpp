// 프로그래머스 - 체육복
// greedy - Level1

#include <string>
#include <vector>


using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int student[32] = {0};

    for(int i=1;i<=n;++i) {
        student[i] = 1;
    }
    
    for(int i=0;i<lost.size();++i){
        student[lost[i]] -= 1;
    }
    for(int i=0;i<reserve.size();++i){
        student[reserve[i]] += 1;
    }
        
    for(int i=1;i<=n;++i){
       if(student[i] == 0){
           // 앞 사람한테 빌리기
           if(student[i-1] == 2){
               student[i-1] -= 1;
               student[i] += 1;
               continue;
           }
           // 뒷 사람한테 빌리기
           if(student[i+1] == 2){
               student[i+1] -= 1;
               student[i] += 1;
               continue;
           }
       }
    }
    
    int answer = 0;
    for(int i=1;i<=n;++i){
        if(student[i] == 1 || student[i] == 2)
            ++answer;
    }
    return answer;
}
