"""
    CSES - Tasks and Deadlines

    Temática : Ordenamiento
    
    Idea: Debes procesar n tareas. Cada tarea tiene una duración y una fecha 
    límite, y las procesarás en orden, una tras otra. Tu recompensa por cada 
    tarea es d-f, donde d es la fecha límite y f la hora de finalización. (La 
    hora de inicio es 0, y debes procesar todas las tareas, incluso si una tarea 
    genera una recompensa negativa). Debemos determinar cual es la máxima 
    recompensa si actúas de manera óptima.

    Para maximizar la recompensa total, debemos minimizar la suma de los tiempos 
    de finalización de las tareas, ya que la recompensa total es la suma de los 
    plazos (constante) menos la suma de los tiempos de finalización. El orden 
    óptimo para minimizar la suma de tiempos de finalización es el de duración 
    ascendente (regla SPT, "Shortest Processing Time first"). Luego, simplemente 
    calculamos la suma acumulada de duraciones y la sumamos para obtener la suma 
    de tiempos de finalización. La respuesta es la suma de todos los plazos menos 
    esa suma.

    
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


def solve():
    input_line = read_nonempty
    ntask = int(input_line())
    tasks = []
    sum_deadline = 0
    
    for i in range(0,ntask):
        duration, deadline = map(int,input_line().split())
        sum_deadline += deadline
        tasks.append((duration,deadline))

    tasks.sort(key=lambda x: x[0])
    time = 0
    sum_finish = 0
    for a, _ in tasks:
        time += a
        sum_finish += time
    answer = sum_deadline - sum_finish
    print(answer)


if __name__ == "__main__":
    solve()
