// 프로그래머스 - 모의고사
// brute force - Level1


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int student1[] = {1, 2, 3, 4, 5};
    int student2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int student3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int n1 = sizeof(student1) / sizeof(int);
    int n2 = sizeof(student2) / sizeof(int);
    int n3 = sizeof(student3) / sizeof(int);
    
    int sum[] = {0, 0, 0};
    
    for(int i=0;i<answers.size();++i){
        if(answers[i] == student1[i%n1]) ++sum[0];
        if(answers[i] == student2[i%n2]) ++sum[1];
        if(answers[i] == student3[i%n3]) ++sum[2];
    }
    
    int max_v = max(max(sum[0], sum[1]), sum[2]);
    
    for(int i=0;i<3;++i){
        if(sum[i] == max_v) answer.push_back(i+1);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

