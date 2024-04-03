/*
* CSES - Grid Paths
* Tematica : Fuerza bruta con optimizacion + Bactracking
* Idea: Dado una tablero de 7x7 y una secuencia de pasos donde algunos pasos son desco
* nocidos se quiere saber de cuantas formas se puede partir del celda (1,1) y llegar a la
* celda (7,1) ejecutando todos los pasos  pasadando por cada celda una sola vez.
* La primera versión del algoritmo no contiene ninguna optimización. Simplemente usamos el
* retroceso para generar todas las rutas posibles desde la esquina superior izquierda hasta
* la esquina inferior derecha y contamos el número de dichas rutas.
* 1. Si el camino llega al cuadrado inferior derecho antes de haber visitado todos los demás cuadrados
* de la cuadrícula, está claro que no será posible completar la solución. Usando esta observación,
* podemos terminar la búsqueda inmediatamente si llegamos al cuadrado inferior derecho demasiado pronto.
* 2. Si el camino toca una pared y puede girar hacia la izquierda o hacia la derecha, la cuadrícula se divide
* en dos partes que contienen cuadrados no visitados. En este caso, ya no podemos visitar todas las
* casillas, por lo que podemos finalizar la búsqueda.
* 3. La idea de la anterio se puede generalizar: si el camino no puede continuar hacia adelante pero puede
* girar hacia la izquierda o hacia la derecha, la cuadrícula se divide en dos partes y ambas contienen
* cuadrados no visitados. Está claro que ya no podemos visitar todas las casillas, por lo que podemos
* finalizar la búsqueda.
* 4. Si el camino crea un callejón sin salida que no es la esquina inferior izquierda, el camino no
* visitará todos los cuadrados (el camino puede detenerse en el callejón sin salida o pasar sobre él,
* sellando un cuadrado) o el camino terminará en el lugar incorrecto. Por tanto, queremos evitar crear
* callejones sin salida. Por ejemplo, si el cuadrado a la izquierda de nuestra ubicación actual está
* bloqueado en tres lados (incluida nuestra ubicación actual), entonces el siguiente paso debe ser hacia
* la izquierda para evitar crear un callejón sin salida
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 100010
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
#define PRINT_LINE cout<<ENDL;
using namespace std;
int mov_r [] ={-1, 0, 1, 0};
int mov_c [] ={0, 1, 0, -1};
vector<int> path;
bool board[9][9];

int searchSolution(int indexP, int curR, int curC) {
    if ((board[curR][curC - 1] && board[curR][curC + 1]) && (!board[curR - 1][curC] && !board[curR + 1][curC]))
        return 0;
    if ((board[curR - 1][curC] && board[curR + 1][curC]) && (!board[curR][curC - 1] && !board[curR][curC + 1]))
        return 0;
    if (curR == 7 && curC == 1) {
        if (indexP == 48) return 1;
        return 0;
    }
    if (indexP== 48) return 0;
    int ret = 0;
    board[curR][curC] = true;
    if (path[indexP] < 4) {
        int nxtR = curR + mov_r[path[indexP]];
        int nxtC = curC + mov_c[path[indexP]];
        if (!board[nxtR][nxtC]) ret += searchSolution(indexP + 1, nxtR, nxtC);
    }else{
        for (int i = 0; i < 4; i++) {
            int nxtR = curR + mov_r[i];
            int nxtC = curC + mov_c[i];
            if (board[nxtR][nxtC]) continue;
            ret += searchSolution(indexP + 1, nxtR, nxtC);
        }
    }
    board[curR][curC] = false;
    return ret;
}

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    string line;
    cin>>line;
    path.resize(48);
	for (int i = 0; i < 48; i++) {
        char cur = line[i];
        if (cur == 'U') path[i] = 0;
        else if (cur == 'R') path[i] = 1;
        else if (cur == 'D') path[i] = 2;
        else if (cur == 'L') path[i] = 3;
        else path[i] = 4;
    }
    for (int i = 0; i < 9; i++) {
		board[0][i] =board[8][i]= true;
		board[i][0] = board[i][8] = true;
	}
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) { board[i][j] = false; }
    }
    int ans =searchSolution(0, 1, 1);
    cout << ans << endl;
    return 0;
}
