"""
    CSES - Nim Game II

    Temática : Teoria de Juego + Nim y Sprague-Grundy
    
    Idea: Se trata de una variante del juego de Nim donde en cada turno el 
    jugador puede quitar 1, 2 o 3 sticks de una pila (no cualquier cantidad). 
    Aunque la regla es diferente, podemos aplicar el teorema de Sprague-Grundy 
    para reducir el juego a un Nim estándar.

    Para una sola pila de tamaño x, los movimientos permitidos son reducirla a 
    x−1, x−2 o x−3 (siempre que sean no negativos). El valor de Grundy g(x) se 
    calcula recursivamente como el mex (mínimo excluyente) de los valores de 
    los estados alcanzables. Calculando lo primeros valores se observa un patrón
    cíclico de período 4:
        g(x) = x mod 4

    Cuando hay varias pilas, el valor de Grundy total es la XOR de los Grundy 
    de cada pila. El jugador que tiene el turno gana si y solo si esa XOR es 
    distinta de cero (teorema de Sprague-Grundy).

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
    cases = int(input_line())
    while cases > 0:
        cases -= 1
        nvalues = int(input_line())
        values = list(map(int,input_line().split()))
        values = [ x%4 for x in values]
        xor_sum = 0
        for i in range(nvalues):
            xor_sum ^= values[i]
        print(("first" if xor_sum != 0 else "second"))


if __name__ == "__main__":
    solve()
