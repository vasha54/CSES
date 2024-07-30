/*
* CSES - Range Update Queries
* Tematica: Estructura de datos : Rangee Tree + Lazy Progation
* Idea: Ejercicio clasico de esta estructura de datos;
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 200010
#define MAX_TREE (MAX_N << 2)
#define MID (left+right)/2
#define MOD 1000000007
#define EPS 1e-4
#define INF 1000000000
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
int mov_r [] = { 0,  0, -1,  1};
int mov_c [] = {-1,  1,  0,  0};
char mov_s [] =  {'L','R','U','D'};

struct Node{
    int value;
    int lazy;
};

Node tree[MAX_TREE];

void buildRangeTree(int treeIndex, int left, int right){
    tree[treeIndex].lazy=0;
    tree[treeIndex].value=0;
    if(left==right){
        cin>>tree[treeIndex].value;
        return;
    }
    buildRangeTree(2*treeIndex,left,MID);
    buildRangeTree(2*treeIndex+1,MID+1,right);
}

void updateLazyRangeTree(int treeIndex, int left, int right, int i, int j,int x){
    if (left > right || left > j || right < i) return;

    if (i <= left && right <= j){
        tree[treeIndex].lazy+=x;
        return;
    }

    if(tree[treeIndex].lazy!=0){
        tree[2*treeIndex].lazy+=tree[treeIndex].lazy;
        tree[2*treeIndex+1].lazy+=tree[treeIndex].lazy;
        tree[treeIndex].lazy = 0;
    }

    updateLazyRangeTree(2 * treeIndex , left, MID, i, j, x);
    updateLazyRangeTree(2 * treeIndex + 1, MID + 1, right, i, j, x);
}

int queryLazyRangeTree(int treeIndex, int left, int right, int pos){
    if(left==right){
        int answer = tree[treeIndex].value+tree[treeIndex].lazy;
        return answer;
    }
    if (tree[treeIndex].lazy != 0){
        tree[2*treeIndex].lazy+=tree[treeIndex].lazy;
        tree[2*treeIndex+1].lazy+=tree[treeIndex].lazy;
        tree[treeIndex].lazy = 0;
    }
    if (pos > MID)
        return queryLazyRangeTree(2*treeIndex+1,MID+1,right,pos);
    if (pos <= MID)
        return queryLazyRangeTree(2*treeIndex,left,MID,pos);
}

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int nvalues,nqueries,operation,pos,posA,posB,value;
    cin>>nvalues>>nqueries;
    buildRangeTree(1,1,nvalues);
    for(int i=1;i<=nqueries;i++){
        cin>>operation;
        switch(operation){
            case 1:
            cin>>posA>>posB>>value;
            updateLazyRangeTree(1,1,nvalues,min(posA,posB),max(posA,posB),value);
            break;
            case 2:
            cin>>pos;
            cout<<queryLazyRangeTree(1,1,nvalues,pos)<<ENDL;
            break;
        }
    }
    return 0;
}
