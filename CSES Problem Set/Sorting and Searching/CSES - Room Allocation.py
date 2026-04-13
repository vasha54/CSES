"""
    CSES - Room Allocation
 
    Temática : Ordenamiento + Cola con prioridad
    
    Idea: El problema pide asignar el mínimo número de habitaciones a un 
    conjunto de reservas (intervalos [a,b)) de modo que no haya solapamientos 
    en la misma habitación y además devolver la asignación en el orden 
    original; la solución estándar es ordenar las reservas por día de llegada y 
    usar una cola de prioridad (min-heap) que guarde la fecha de salida más 
    temprana junto con el id de la habitación; para cada reserva, si la salida 
    más temprana es estrictamente menor que la llegada actual se reutiliza esa 
    habitación (se actualiza su nueva salida), y si no se puede reutilizar se 
    crea una habitación nueva; este enfoque garantiza optimalidad, corre en O(
    nlogn) por la ordenación y las operaciones de heap, y permite reconstruir 
    fácilmente la asignación por cliente.
 
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
MODM1 = MOD - 1          # para exponentes
MOD2M1 = 2 * MODM1       # para reducir d(N) antes de dividir por 2

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
    customers = []
    for i in range(n):
        a, b = map(int, input().split())
        customers.append((a, b, i))
    customers.sort(key=lambda x: x[0])
    heap = []
    ans = [0] * n
    rooms_used = 0

    for a, b, idx in customers:
        if heap and heap[0][0] < a:
            dep, room_id = heapq.heappop(heap)
            ans[idx] = room_id
            heapq.heappush(heap, (b, room_id))
        else:
            rooms_used += 1
            ans[idx] = rooms_used
            heapq.heappush(heap, (b, rooms_used))

    print(rooms_used)
    print(' '.join(map(str, ans)))
        
if __name__ == "__main__":
    solve()
