/*
* CSES - Josephus Problem II
* Tematica: Estructura de datos + Estructuras de datos basado en políticas
*
* Idea: Se tiene N niños en forma de círculo y K niños se va eliminando .
* Se desea conocer el orden de eliminación se puede simular el proceso
* utilizando la estructura.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 100010
#define MAX_TREE (MAX_N << 2)
#define MID (left+right)/2
#define MOD 1000000007
#define EPS 1e-4
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define Point pair<int, int>
#define X first
#define Y second
#define PLUS '+'
#define MINUS '-'
#define SPACE ' '
#define CELL_FREE '.'
#define CELL_WALL '#'
#define PRINT_LINE cout<<ENDL;
using namespace std;
using namespace __gnu_pbds;
int mov_r [] = { 0,  0, -1,  1};
int mov_c [] = {-1,  1,  0,  0};

tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> Tree;
int N, K, idx;

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>N>>K;

    for(int i=1;i<=N;i++){
        Tree.insert(i);
    }

    idx = K;
    while(Tree.size()){
        idx %= Tree.size();
        int x = *Tree.find_by_order(idx);
        Tree.erase(x);
        cout<<x<<" ";
        idx += K;
    }
    cout<<ENDL;
    return 0;
}
