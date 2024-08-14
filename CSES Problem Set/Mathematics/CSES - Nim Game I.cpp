/*
* CSES - Nim Game I
* Tematica: Teoría de Juego
*
* Idea: Clasico juego del Nim 
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 1e6+10
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


bool nim(vector<int> stacks)
{
    int sums=0;
    if(stacks.empty()==false)
    {
        sums = stacks[0];
        for(int i=1;i<stacks.size();i++) sums = sums ^ stacks[i];
    }
    return (sums!=0);
}

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int cases, nstones;
    cin>>cases;
    while(cases--)
    {
        cin>>nstones;
        vector<int> stones(nstones);
        for(int i=0;i<nstones;i++)cin>>stones[i];
        if(nim(stones)) cout<<"first"<<ENDL;
        else cout<<"second"<<ENDL;
    }
    return 0;
}
