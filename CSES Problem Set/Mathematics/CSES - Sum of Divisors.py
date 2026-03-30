"""
    CSES - Sum of Divisors

    Temática : Teoría de Numeros + Suma de prefijos
    
    Idea: Dado un entero n (hasta 10^12), se pide calcular la suma de los divisores de todos los números desde 1 hasta n.


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
INV2 = (MOD + 1) // 2   # inverso modular de 2
MAX = 10**6+10
INF = 10**9
# dp = [[0]*(MAX+5) for _ in range((MAX+5))]

def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()

def sum_divisors(n):
    total = 0
    d = 1
    while d <= n:
        q = n // d
        # el último d con este cociente
        d_max = n // q
        # suma de d desde d hasta d_max
        # sum = (d + d_max) * (d_max - d + 1) // 2
        # pero como trabajamos con módulo, usamos INV2
        suma_d = (d + d_max) % MOD
        suma_d = suma_d * ((d_max - d + 1) % MOD) % MOD
        suma_d = suma_d * INV2 % MOD
        total = (total + (q % MOD) * suma_d) % MOD
        d = d_max + 1
    return total

def solve():
    input_line = read_nonempty
    n = int(input_line())
    answer = sum_divisors(n)
    print(answer)


if __name__ == "__main__":
    solve()
