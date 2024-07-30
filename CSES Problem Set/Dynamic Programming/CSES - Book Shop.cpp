/*
* CSES - Book Shop
* Tematica: Programación Dinámica : Mochila 01
* Idea: Mochila clásica
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 1010
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



signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int nitems,max_knapsack;
    cin>>nitems>>max_knapsack;
    vector<int> knapsack(max_knapsack+1,0);
    vector<int> weigths(nitems),beneficts(nitems);
    for(int i=0;i<nitems;i++) cin>>weigths[i];
    for(int i=0;i<nitems;i++) cin>>beneficts[i];

    for(int i=0; i<nitems;i ++){
        for(int j=max_knapsack;j>=1;j--){
            if(weigths[i]<=j){
                int x = knapsack[j] ;
                int y = knapsack[j-weigths[i]]+ beneficts[i];
                knapsack[j]=max(x,y);
            }
        }
    }
    cout<<knapsack[max_knapsack]<<ENDL;
    return 0;
}
