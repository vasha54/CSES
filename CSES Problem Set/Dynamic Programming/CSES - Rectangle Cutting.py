"""
    CSES - Rectangle Cutting
    Temática : Programación Dinámica
    
    Idea: Dada una pieza de MxN y se quiere realizar la mínima cortes tal que las
    piezas resultantes sean cuadradas. Vamos a definir una matriz dp donde en [i][j]
    tenga el resultado para la pieza IxJ convertir en cuadrado. 

    Por simetría, podemos i <= j para evitar duplicar ya que dp[i][j] = dp[j][i]

    Caso base: Si i == j la solución es 0 por que cuadrado
    
    Para i < j: Debemos realizar al menos un corte. Podemos cortar horizontal o
    vertical

    Corte horizontal
    - Dividimos el rectángulo en dos rectángulos más pequeños de dimensiones 
    KxJ y (I-K)xJ, con 1 <= K <= I-1. El número total de cortes sería:
        1 +  dp[min(K,J)][max(K,J)] + dp[min(I-K,J)][max(I-K,J)]

    Corte vertical
    - Dividimos en dos rectángulos de dimensiones IxK y Ix(J-K), con 1 <= K <= J-1.
    El total de cortes:
        1 +  dp[min(I,K)][max(I,K)] + dp[min(I,J-K)][max(I,J-K)] 
"""
 
from functools import cmp_to_key, reduce
from collections import deque, Counter
 
# Comparadores en Estructuras de Datos
import heapq
import sys
import itertools
 
mov_r = [2, 2, -2, -2, 1, -1, 1, -1]
mov_c = [1, -1, 1, -1, 2, 2, -2, -2]
 
MOD = 10**9 + 7
MAX = 510
INF = 10**9

dp = [[0] * (MAX) for _ in range(MAX)]

def precalculate():
    global dp
    for i in range(1, MAX):
        for j in range(i + 1, MAX):
            dp[i][j] = INF

    for i in range(1, MAX):
        for j in range(i + 1, MAX):
            best = INF
            
            hi = i // 2
            for k in range(1, hi + 1):
                r1 = (k, j) if k <= j else (j, k)
                r2 = (i - k, j) if i - k <= j else (j, i - k)
                val = 1 + dp[r1[0]][r1[1]] + dp[r2[0]][r2[1]]
                if val < best:
                    best = val

            hj = j // 2
            for k in range(1, hj + 1):
                r1 = (i, k) if i <= k else (k, i)
                r2 = (i, j - k) if i <= j - k else (j - k, i)
                val = 1 + dp[r1[0]][r1[1]] + dp[r2[0]][r2[1]]
                if val < best:
                    best = val

            dp[i][j] = best
            dp[j][i] = best

def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()

def solve():
    input_line = read_nonempty
    precalculate()
    n, m = map(int,input_line().strip().split())
    print(dp[n][m])

if __name__ == "__main__":
    solve()