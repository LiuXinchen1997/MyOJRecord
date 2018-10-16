//  π”√Lazy Tag£°
#include <iostream>
#include <cstdio>

using namespace std;

#define INF 100005
int n,m,du,k1,k2,k3;
char k;

struct segment_tree{
    #define X tr[x]
    #define lx (x<<1)
    #define rx ((x<<1)+1)
    #define L tr[lx]
    #define R tr[rx]
    #define Mid (l+r>>1)
    #define sz(x) (X.r-X.l+1)
    struct node{long long l,r,s,t1;} tr[4*INF];

    long long mer(int x,int y) {return tr[x].s + tr[y].s;}

    void build(int x,int l,int r) {
        if (l == r) {X = (node){l, r, (scanf("%d",&du),du), 0}; return;}
        build(lx, l, Mid);
        build(rx, Mid+1, r);
        X = (node){l, r, mer(lx, rx), 0};
    }

    void addtag(int x, int v){
        X.s += v*sz(x);
        X.t1 += v;
    }

    void Down(int x){
        if (X.t1 != 0){
            addtag(lx, X.t1);
            addtag(rx, X.t1);
            X.t1 = 0;
        }
    }

    void add(int x, int l, int r, int v) {
        if (l <= X.l && X.r <= r){addtag(x, v); return;}
        Down(x);
        if (l <= L.r) add(lx, l, r, v);
        if (R.l <= r) add(rx, l, r, v);
        X.s = mer(lx, rx);
    }

    long long query(int x, int l, int r){
        if (l <= X.l && X.r <= r) return X.s;
        Down(x);
        long long ret = 0;
        if (l <= L.r) ret += query(lx, l, r);
        if (R.l <= r) ret += query(rx, l, r);
        return ret;
    }
} tree;

int main(){
    cin >> n >> m;
    tree.build(1, 1, n);
    while (m-- && cin >> k){
        if (k == 'C'){
            cin >> k1 >> k2 >> k3;
            tree.add(1, k1, k2, k3);
        }
        if (k == 'Q'){
            cin >> k1 >> k2;
            cout << tree.query(1, k1, k2) << endl;
        }
    }
    return 0;
}
