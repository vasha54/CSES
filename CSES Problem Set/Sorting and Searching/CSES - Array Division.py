"""
    CSES - Array Division

    Temática : Búsqueda Binaria
    
    Idea: Dado un array se quiere dividir en exactamente k subarray tal
    que se minimice la suma de la suma del maximo subarray. Para buscar 
    la solución vamos a realizar una busqueda binaria sobre el rango de
    x a X siendo X la suma de todos los elementos del array y x el maximo
    valor presente en el array. Se coge un valor P y se trata de armar k 
    subarray cuya suma no soprepase el valor k si es posible la próxima 
    iteración será de 0 a P-1 sino se búscara de k+1 a X.
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
MAX = 10**4
INF = 10**9

def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()

def is_posible(_array, _max_sum, _limit):
    subarrays = 1
    sum_current = 0
    for value in _array:
        if sum_current + value <= _max_sum:
            sum_current += value
        else:
            subarrays += 1
            sum_current = value
            if subarrays > _limit:
                return False
    return True

def solve():
    input_line = read_nonempty
    n, k = map(int,input_line().split())
    array = list(map(int,input_line().split()))
    begin = max(array)
    end = sum(array)
    best = end
    while begin <= end:
        pivot = (begin + end) // 2
        if is_posible(array,pivot,k) == True:
            best = min(pivot,best)
            end = pivot - 1
        else:
            begin = pivot + 1 
    print(best)

if __name__ == "__main__":
    solve()