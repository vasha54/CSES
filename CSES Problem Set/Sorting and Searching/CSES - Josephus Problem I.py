"""
    CSES - Josephus Problem I
 
    Temática : Simulación
    
    Idea: El problema es la versión clásica del problema de Josephus con paso 2: 
    los niños están en un círculo y se elimina cada segundo niño hasta que no queda 
    ninguno. Una forma eficiente de solucionar el problema es simular el proceso 
    usando una cola doble 
 
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
    q = deque(range(1, n+1))
    removed = []

    while q:
        q.append(q.popleft())
        removed.append(q.popleft())
    print(" ".join(map(str, removed)))
 
if __name__ == "__main__":
    solve()
