"""
    CSES - Nearest Smaller Values

    Temática : Búsqueda + Pilas
    
    Idea: Tenemos un grupo de valores y para cada valor de la posición i queremos 
    encontrarla primera posición a su izquierda mas cercana a él donde el valor 
    que se encuentra ahi es menor que el valor de la posición.  Para cada posición 
    i queremos la posición más cercana a la izquierda con valor estrictamente menor 
    que x[i]. Recorremos el arreglo de izquierda a derecha manteniendo una pila 
    monótona de elementos con valores estrictamente crecientes. Para el elemento actual 
    x[i] descartamos de la pila todos los elementos con valor ≥ x[i]. Si la pila 
    queda vacía la respuesta es 0, si no, la cima de la pila contiene el índice 
    buscado. Después adicionado el par (x[i],i) en la pila.

"""
 
from functools import cmp_to_key, reduce
from collections import deque, Counter
 
# Comparadores en Estructuras de Datos
import heapq
import sys
import itertools
import math
 
mov_r = [2, 2, -2, -2, 1, -1, 1, -1]
mov_c = [1, -1, 1, -1, 2, 2, -2, -2]
 
MOD = 10**9 + 7
INV2 = (MOD + 1) // 2   # inverso modular de 2
MAX = 10**6+10
INF = 10**9
# dp = [[0]*(MAX+5) for _ in range((MAX+5))]

def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()



def solve():
    input_line = read_nonempty
    n = int(input_line())
    x = list(map(int,input_line().split()))
    stack = []
    answer = [0] * n
    for i in range(0,n):
        while stack and stack[-1][0] >= x[i]:
            stack.pop()
        answer [i] = 0 if not stack else stack[-1][1]
        stack.append((x[i],i+1))

    print(' '.join(str(answer[i]) for i in range(0, n))) 



if __name__ == "__main__":
    solve()

