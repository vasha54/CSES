/*
* CSES - Shortest Routes II
* Tematica: Teoría de Grafos + Floyd Warshall
*
* Idea: Clasico ejercicio de Floyd Warshall
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 510
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
int mov_r [] = { 0,  0, -1,  1};
int mov_c [] = {-1,  1,  0,  0};

int floyd[MAX_N][MAX_N];


signed main()
{
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    for(int i=1;i<MAX_N;i++)
        for(int j=1;j<MAX_N;j++)
            floyd[i][j]= (i == j) ? 0 : INF;
    int ncities,nconnections,nquerys,cityA,cityB,road;
    cin>>ncities>>nconnections>>nquerys;

    for(int i=0;i<nconnections;i++)
    {
        cin>>cityA>>cityB>>road;
        floyd[cityB][cityA]=floyd[cityA][cityB]=min(road,floyd[cityA][cityB]);
    }

    for(int k = 1; k <= ncities; k++)
        for(int i = 1; i <= ncities; i++)
            for(int j = 1; j <= ncities; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    for(int i=0;i<nquerys;i++)
    {
        cin>>cityA>>cityB;
        cout<<( floyd[cityA][cityB] == INF ? -1 : floyd[cityA][cityB])<<ENDL;
    }
    return 0;
}
