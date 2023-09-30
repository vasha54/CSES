/**
* CSES - Chessboard and Queens
* Tematica : Backtracking
* Idea: Problema clasico de calcular la cantidad de variante de colocar ocho reina
* en un tablero sin que se amenacen entre si con la adecuación que existe casillas
* donde no se puede colocar la dama.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 10
#define EPS 1e-9
#define INF 1000000000
#define READ_FILE freopen("Input.txt","r",stdin);
#define int long long

using namespace std;

struct Queen {
	int row, column;
};
vector<Queen> queens;
Queen A, B;

char boardFree[MAX_N][MAX_N];
int boardAttack[MAX_N][MAX_N], ways, nextColumn;

int searchCell(int row, int col) {
	if (row < 8)
		for (int i = col; i < 8; i++)
			if (boardAttack[row][i] == 0 && boardFree[row][i]=='.')
				return i;
	return (-1);
}

void placeQueen(int row, int col, int value) {
	int r, c;
	r = row + 1; c = col;
	while (r < 8) {
		boardAttack[r][c]+=value;
		r++;
	}
	r = row - 1;c = col;

	while (r >= 0) {
		boardAttack[r][c]+=value;
		r--;
	}
	r = row;c = col + 1;

	while (c < 8) {
		boardAttack[r][c]+=value;
		c++;
	}
	r = row - 1;c = col + 1;

	while (r >= 0 && c < 8) {
		boardAttack[r][c]+=value;
		c++;r--;
	}

	r = row + 1;
	c = col + 1;
	while (r < 8 && c < 8) {
		boardAttack[r][c]+=value;
		c++;r++;
	}

	r = row + 1;
	c = col - 1;
	while (r < 8 && c >= 0) {
		boardAttack[r][c]+=value;
		c--; r++;
	}
}

void backtracking(){
   if (queens.size() == 8) {
      Salto1:
         A = queens.back();
         queens.pop_back();
		 placeQueen(A.row, A.column, -1);
		 nextColumn = searchCell(A.row, A.column + 1);
		 if (nextColumn != -1) {
            A.column = nextColumn;
			placeQueen(A.row, A.column, 1);
			queens.push_back(A);
		 } else {
            if (queens.empty()) {
				A.row = A.row + 1;
				A.column = nextColumn;
				queens.push_back(A);
			} else {
				goto Salto1;
			}
		}
	} else {
      B.row = queens.back().row + 1;
      nextColumn = searchCell(B.row, 0);
      if (nextColumn != -1) {
         B.column = nextColumn;
         placeQueen(B.row, B.column, 1);
         queens.push_back(B);
      } else {
         Salto2:
            A = queens.back();
			queens.pop_back();
			placeQueen(A.row, A.column, -1);
			nextColumn = searchCell(A.row, A.column + 1);
			if (nextColumn != -1) {
               A.column = nextColumn;
               placeQueen(A.row, A.column, 1);
               queens.push_back(A);
            } else {
               if (queens.empty()) {
                   A.row = A.row + 1;
                   A.column = nextColumn;
                   placeQueen(A.row, A.column, 1);
                   queens.push_back(A);
                } else {
                   goto Salto2;
				}
			}
		}
	}
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    for(int i=0;i<8;i++){
        cin>>boardFree[i];
        fill(boardAttack[i],boardAttack[i]+MAX_N,0);
    }
    ways=0;
    queens.clear();
    A.row = A.column = 0;
    placeQueen(A.row, A.column, 1);
    queens.push_back(A);
    while (queens.front().row < 2) {
       if (queens.size() == 8)
          ways++;
       backtracking();
    }
    cout<<ways<<ENDL;


    return 0;
}
