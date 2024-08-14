/*
* CSES - Stick Game
* Tematica: Teoría de Juego
*
* Idea: Clasico juego del ganar o perder
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 1000010
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

bool isWinning[MAX_N];

void winOrLoss(int K, vector<int> moves)
{
    fill(isWinning, isWinning + (K + 1), false);
    for (int i = 1; i <= K; i++)
    {
        for (int j=0;j<moves.size();j++)
        {
           if (i - moves[j] >= 0 && isWinning[i - moves[j]] == false)
           {
                isWinning[i] = true; break;
           }
        }
    }
}


signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int N, nmoves;
    cin>>N>>nmoves;
    vector<int> moves(nmoves);
    for(int i=0;i<nmoves;i++) cin>>moves[i];
    winOrLoss(N,moves);
    for(int i=1;i<=N;i++)cout<<( isWinning[i] ? "W" :"L" );
    cout<<ENDL;
    return 0;
}
