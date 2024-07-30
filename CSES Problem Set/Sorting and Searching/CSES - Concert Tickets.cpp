/*
* CSES - Concert Tickets
* Tematica: Busqueda  : Arbol Binario de Busqueda Balanceado (Set)
* Idea: Se tiene una serie de tickets con cierto valor cada uno y se tiene
* un grupo de compradores que estan dispuestos a pagar hasta cierto valor por
* ticket. Para cada comprador se debe buscar el ticket de mayor precio qque se le puede
* ofrecer sin superar el precio que el esta dispuesto a pagar.
* Para solucionar el probblema podemos utilizar un arbol binario de busqueda balanaceado
* que nos permita realizar todas las operaciones necesarias en logn (añadir,buscar,eliminar)
* tickets. No hay necesidad de implementar solo vamos utilizar el set que internamente implementa
* esta estructura ahora como puede existir tickets con el mismo precio vamos a insertar una tupla
* con el valor del ticket y su posicion ya esto hace que los elementos sean unicos y que las tuplas
* internamente sean organizadas primero por el precio y luego por la posición.
* Para buscar el posible tickect a un comprador utilizaremos el metodos upper_bounds que busca el mayor
* valor que no supere el valor pasado, en este caso le pasaremos una tupla con el valor a buscas y la
* cantidad de tickets que existen incialmente para asegurar que de existir un ticket con el precio que
* sea igual a lo que puede ofrecer el comprador pueda ser seleccionado ya que su segundo parametro de su tupla
* sea menor que el segundo valor de tupla que se utiliza de referencia en la busqueda. Tener en cuenta que puede
* no existir tickect para el comprador los que sucede cuando upper_bounds retorna un iterador que apunta al begin
* del set.
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
    set<pii> ABB;
    int ntickets,ncustomers,tickets,customers,answer;
    cin>>ntickets>>ncustomers;
    for(int i=0;i<ntickets;i++){
        cin>>tickets;
        ABB.insert(make_pair(tickets,i));
    }
    for(int i=0;i<ncustomers;i++){
        cin>>customers;
        auto it = ABB.upper_bound({customers, ntickets});
        answer = -1;
        if(it!=ABB.begin()){
            it--;
            answer = it->first;
            ABB.erase(it);
        }
        cout<<answer<<ENDL;
    }
    return 0;
}
