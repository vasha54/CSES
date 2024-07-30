/*
* CSES - Labyrinth
* Tematica: Teoría de grafos + BFS sobre tablero
* Idea: Dados dos puntos sobre el tablero saber si existe un camino y cual sería
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

struct Cell{
    int r,c;
    Cell(int x=0,int y=0){
        r = x;
        c = y;
    }
};

int nrows, ncolummns;
char board[MAX_N][MAX_N];
string line;
Cell beginPath, endPath;

bool validCell(Cell z){
    return (1<=z.r && z.r<=nrows && 1<=z.c && z.c<=ncolummns);
}

void searchPath(Cell z){
    queue<Cell> visited;
    Cell y ;
    visited.push(z);
    board[z.r][z.c] = 'A';

    while(!visited.empty()){
        z = visited.front();
        visited.pop();
        for(int i=0;i<4;i++){
            y.r = z.r+mov_r[i];
            y.c = z.c+mov_c[i];
            if(validCell(y) && board[y.r][y.c]==CELL_FREE){
                visited.push(y);
                board[y.r][y.c]=mov_s[i];
            }
        }
    }
}

void printMap(){
    for(int i=1;i<=nrows;i++){
        for(int j=1;j<=ncolummns;j++)
            cout<<board[i][j];
        cout<<ENDL;
    }
}

void buildPath(Cell z){
    deque<char> paths;
    while(board[z.r][z.c]!='A'){
        paths.push_front(board[z.r][z.c]);
        if(board[z.r][z.c]=='U') z.r++;
        else if(board[z.r][z.c]=='D') z.r--;
        else if(board[z.r][z.c]=='L') z.c++;
        else if(board[z.r][z.c]=='R') z.c--;
    }
    cout<<"YES"<<ENDL;
    cout<<paths.size()<<ENDL;
    for(char x: paths) cout<<x;
    cout<<ENDL;
}

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>nrows>>ncolummns;
    for(int i=1;i<=nrows;i++){
        cin>>line;
        for(int j=1;j<=ncolummns;j++){
            board[i][j]=line[j-1];
            if(board[i][j]=='A'){
                beginPath = Cell(i,j);
                board[i][j] ='.';
            }
            if(board[i][j]=='B'){
                endPath = Cell(i,j);
                board[i][j] ='.';
            }
        }
    }

    searchPath(beginPath);
    if(board[endPath.r][endPath.c]==CELL_FREE){
        cout<<"NO"<<ENDL;
    }else{
        buildPath(endPath);
    }
    return 0;
}
