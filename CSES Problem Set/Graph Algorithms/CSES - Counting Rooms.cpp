/**
* CSES - Counting Rooms
* Tematica : Teoria de Grafos : BFS + Componentes conexa
* Idea: Dado un mapa de una casa determinar la cantidad de habitaciones .
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 1010
#define EPS 1e-9
#define INF 1000000000
#define READ_FILE freopen("Input.txt","r",stdin);
#define int long long

using namespace std;

struct Cell{int r,c;};

int movX [] ={ 0, 0, 1,-1};
int movY [] ={ 1,-1, 0, 0};

int columns, rows, rooms;
char board[MAX_N][MAX_N];

bool validCell(Cell _cell){
    return (0 <= _cell.r && _cell.r < rows && 0 <= _cell.c && _cell.c < columns);
}

void scanRoom(int _r, int _c){
    Cell curr,next;
    queue<Cell> bfs;
    curr.c = _c;
    curr.r = _r;
    bfs.push(curr);
    board[curr.r][curr.c]='#';

    while(!bfs.empty()){
        curr = bfs.front();
        bfs.pop();
        board[curr.r][curr.c]='#';
        for(int i=0;i<4;i++){
            next.r = curr.r + movY[i];
            next.c = curr.c + movX[i];
            if( validCell(next) && board[next.r][next.c]=='.'){
                board[next.r][next.c]='#';
                bfs.push(next);
            }
        }
    }
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    cin>>rows>>columns;

    for(int i=0;i<rows;i++) cin>>board[i];

    rooms = 0;

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(board[i][j]=='.'){
                rooms++;
                scanRoom(i,j);
            }
        }
    }

    cout<<rooms<<ENDL;

    return 0;
}
