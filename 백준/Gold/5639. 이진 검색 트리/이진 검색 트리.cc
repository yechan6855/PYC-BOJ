#include <iostream>
#include <queue>
using namespace std;
struct NodeType{ 
    int info;
    NodeType *right;
    NodeType *left;
};
void InOrder(NodeType* tr ,queue<int>& q){
    if(tr != NULL){
        InOrder(tr->left, q);
        InOrder(tr->right, q);
        q.push(tr->info);
    }
}
void insert(NodeType*& tr, int a){
    if(tr == NULL){
        tr = new NodeType;
        tr->left = NULL;
        tr->right = NULL;
        tr->info = a;
    }else if(a > tr->info){
        insert(tr->right, a);
    }else{
        insert(tr->left, a);
    }
}
class tree{
public:
    tree(){
        root = NULL;
    }
    void enqueue(int a){
        insert(root, a);
    }
    void InOrderTree(queue<int>& q){
        InOrder(root, q);
    }
private:
    NodeType *root;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    queue<int> q;
    tree t;
    int n;
    while(cin >> n){
        if(n == EOF)
            break;
        t.enqueue(n);
    }
    t.InOrderTree(q);
    while(!q.empty()){
        cout << q.front() << '\n';
        q.pop();
    }
    return 0;
}