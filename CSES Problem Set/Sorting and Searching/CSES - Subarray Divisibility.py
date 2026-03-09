"""
    CSES - Subarray Divisibility
    Temática : Ordenamiento -> Counting Sort
    
    Idea:  Dado un grupo de valores en un array determinar la cantidad
    de subarray que la suma de los elementos es divisible por la cantidad de elementos
    del array. Para resolver el problema vamos a realizar una suma prefijo con los
    valores modulada en N (cantidad de elementos del array). Eso generá un array con
    valores en el rango de 0 a N-1. Luego solo tengo que contar la cantidad de ocurrencia
    de cada valor. La cantidad de ocurrencia (p) de un valor x aportará a la solución final
    un total de p*(p-1)/2 de subarray cuya suma de valores es un producto de N.
 
"""
from functools import cmp_to_key, reduce
from collections import deque, Counter
 
# Comparadores en Estructuras de Datos
import heapq
import sys
 
mov_r = [2, 2, -2, -2, 1, -1, 1, -1]
mov_c = [1, -1, 1, -1, 2, 2, -2, -2]
 
MOD = 10**9 + 7

def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()

def solve():
    input_line = read_nonempty
    n = int(input_line().strip())
    arr = list(map(int, input_line().split()))
    count = [0] * n
    count[0] = 1
    prefix = 0
    for x in arr:
        prefix = (prefix + x) % n
        count[prefix] += 1
    total = 0
    for c in count:
        total += c * (c - 1) // 2
    print(total)    
 
if __name__ == "__main__":
    solve()
