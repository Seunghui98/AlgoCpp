// 프로그래머스 - 섬 연결하기
// greedy(MST) - Level3


#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int parent[101];
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void parent_union(int a, int b){
    a = find(a);
    b = find(b);
    parent[b] = a;
}

int solution(int n, vector<vector<int>> costs) {
    vector<pair<int, pair<int, int>>> v;
    
    for(int i=0;i<costs.size();i++){
        int a = costs[i][0];
        int b = costs[i][1];
        int c = costs[i][2];
        v.push_back({c, {a, b}});
    }
    
    sort(v.begin(), v.end());
    int answer = 0;
    for(int i=0;i<101;i++) parent[i] = i;
    for(int i=0;i<v.size();++i){
        int cost = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;
        int parent_a = find(a);
        int parent_b = find(b);
        if(parent_a != parent_b){
            parent_union(parent_a, parent_b);
            answer += cost;
        }
    }
    return answer;
}
