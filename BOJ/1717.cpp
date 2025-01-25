// BOJ - 집합의 표현(1717)
// 분리 집합

#include <bits/stdc++.h>
using namespace std;

int N, M;
int a, b, c;
int parent[1000005];
int find_parent(int x)
{
    if (parent[x] == x)
        return x;
    parent[x] = find_parent(parent[x]); // 경로 압축 -> 업데이트를 안 해주면 시간 복잡도 O(N) 증가함
    return parent[x];
}

bool union_parent(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);
    if (a == b)
        return false;
    parent[b] = a;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        if (a == 0)
        {
            union_parent(b, c);
        }
        else
        {
            int b_parent = find_parent(b);
            int c_parent = find_parent(c);
            if (b_parent == c_parent)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
