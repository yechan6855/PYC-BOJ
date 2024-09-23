#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    Node *left, *right, *parent;
    bool rev;
    ll val;
    ll sum;

    Node(ll v = 0) : left(nullptr), right(nullptr), parent(nullptr), rev(false), val(v), sum(v) {}
};

class LinkCutTree {
public:
    bool isRoot(Node* x) {
        return !x->parent || (x->parent->left != x && x->parent->right != x);
    }

    void push(Node* x) {
        if (x && x->rev) {
            swap(x->left, x->right);
            if (x->left) x->left->rev ^= true;
            if (x->right) x->right->rev ^= true;
            x->rev = false;
        }
    }

    void update(Node* x) {
        if (x) {
            x->sum = x->val;
            if (x->left) x->sum += x->left->sum;
            if (x->right) x->sum += x->right->sum;
        }
    }

    void rotate(Node* x) {
        Node* p = x->parent;
        Node* g = p->parent;
        if (!isRoot(p)) {
            if (g->left == p) g->left = x;
            else g->right = x;
        }
        x->parent = g;

        if (p->left == x) {
            p->left = x->right;
            if (x->right) x->right->parent = p;
            x->right = p;
            p->parent = x;
        }
        else {
            p->right = x->left;
            if (x->left) x->left->parent = p;
            x->left = p;
            p->parent = x;
        }
        update(p);
        update(x);
    }

    void splay(Node* x) {
        static vector<Node*> stack;
        stack.clear();
        Node* y = x;
        while (!isRoot(y)) {
            stack.push_back(y->parent);
            y = y->parent;
        }
        while (!stack.empty()) {
            push(stack.back());
            stack.pop_back();
        }
        push(x);

        while (!isRoot(x)) {
            Node* p = x->parent;
            Node* g = p->parent;
            if (!isRoot(p)) {
                if ((g->left == p) == (p->left == x)) rotate(p);
                else rotate(x);
            }
            rotate(x);
        }
    }

    void link(Node* x, Node* y) {
        makeRoot(x);
        x->parent = y;
    }

    void cut(Node* x, Node* y) {
        makeRoot(x);
        access(y);
        splay(y);
        if (y->left == x) {
            y->left->parent = nullptr;
            y->left = nullptr;
            update(y);
        }
    }

    bool connected(Node* x, Node* y) {
        if (x == y) return true;
        makeRoot(x);
        access(y);
        splay(y);
        while (y->left) {
            y = y->left;
        }
        return x == y;
    }

    void makeRoot(Node* x) {
        access(x);
        splay(x);
        x->rev ^= true;
    }

    void access(Node* x) {
        Node* last = nullptr;
        while (x) {
            splay(x);
            x->right = last;
            update(x);
            last = x;
            x = x->parent;
        }
    }

    ll queryPathSum(Node* x, Node* y) {
        makeRoot(x);
        access(y);
        splay(y);
        return y->sum;
    }

    void updateValue(Node* x, ll newVal) {
        splay(x);
        x->val = newVal;
        update(x);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Node*> nodes(N + 1, nullptr);
    for(int i=1; i<=N; i++){
        int penguin;
        cin >> penguin;
        nodes[i] = new Node(penguin);
    }

    int Q;
    cin >> Q;

    LinkCutTree lct;

    while(Q--){
        string cmd;
        cin >> cmd;
        if(cmd == "bridge"){
            int A, B;
            cin >> A >> B;
            if(lct.connected(nodes[A], nodes[B])){
                cout << "no\n";
            }
            else{
                lct.link(nodes[A], nodes[B]);
                cout << "yes\n";
            }
        }
        else if(cmd == "penguins"){
            int A, X;
            cin >> A >> X;
            lct.updateValue(nodes[A], X);
        }
        else if(cmd == "excursion"){
            int A, B;
            cin >> A >> B;
            if(lct.connected(nodes[A], nodes[B])){
                ll total = lct.queryPathSum(nodes[A], nodes[B]);
                cout << total << "\n";
            }
            else{
                cout << "impossible\n";
            }
        }
    }
}