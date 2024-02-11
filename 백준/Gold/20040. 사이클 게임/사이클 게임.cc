#include <iostream>  
#include <vector>  
  
using namespace std;  
  
vector<int> parent;  
  
int find(int x) {  
    if (parent[x] == x) {  
        return x;  
    }  
    return parent[x] = find(parent[x]);  
}  
  
void unionSets(int a, int b) {  
    int rootA = find(a);  
    int rootB = find(b);  
  
    if (rootA != rootB) {  
        parent[rootB] = rootA;  
    }  
}  
  
int main() {  
    int n, m;  
    cin >> n >> m;  
  
    parent.resize(n);  
    for (int i = 0; i < n; i++) {  
        parent[i] = i;  
    }  
  
    int answer = 0;  
  
    for (int i = 1; i <= m; i++) {  
        int a, b;  
        cin >> a >> b;  
  
        if (find(a) == find(b)) {  
            // 현재 간선이 이미 같은 집합에 속하는 두 노드를 연결하면 사이클이 형성됨  
            answer = i;  
            break;  
        }  
  
        unionSets(a, b);  
    }  
  
    cout << answer << "\n";  
  
    return 0;  
}