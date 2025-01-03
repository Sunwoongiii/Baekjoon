#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
int n,m;
int parent[1010101];

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void hap(int a, int b){
    parent[find(a)] = find(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;
    for(int i = 0; i<=n; i++){
        parent[i] = i;//자기 자신 설정
    }

    for(int i = 0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;

        if(a == 0){
            hap(b, c);//a가 0일 경우 합치기
        }
        else{
            if(find(b) == find(c)){
                cout<<"YES\n";//부모노드가 같으면 같은 집합
            }
            else{
                cout<<"NO\n";//부모노드가 다르면 다른 집합
            }
        }
    }
}