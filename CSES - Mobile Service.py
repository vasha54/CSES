#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
CSES - Mobile Service . (https://cses.fi/file/c36c23aae77044f961ec20908f3d2c74917e2e6445926158829986288e0b9909)
Tematica: Programación Dinamica
Idea: Obsérvese primero que inmediatamente antes de atender la solicitud ri, 
uno de los empleados del personal de servicio se encuentra en la ubicación ri−1.
Para cada i (0 ≤ i ≤ n), y para cada ubicación v2 y v3, defina el subproblema 
de atender las primeras i solicitudes con el mínimo coste, siempre que los
otros dos empleados se encuentren en la ubicación v2 y v3 al final. Denotemos 
este coste con Opt(i,v2,v3). La solución de la subtarea A es

min(v2,v3) Opt(n,v2,v3)

Nótese que Opt(i,v2,v3) es simétrica, es decir Opt(i,v2,v3) = Opt(i,v3,v2). 
Además, si ri = ri−1 entonces Opt(i,v2,v3) = Opt(i− 1,v2,v3)   


El costo de atender la solicitud ri moviendo al empleado de la ubicación ri−1 es

costo1 = Opt(i−1,v2,v3) +C(r[i−1],ri)

Por lo tanto, un valor posible de Opt(i,v2,v3) es cost1 
Si el empleado se mueve de la ubicación v2 para atender la solicitud ri, 
entonces un valor posible de Opt(i,v3,ri) es

costo2 = Opt(i−1,v2,v3) +C(v2,ri)

Si el empleado se mueve de la ubicación v2 para atender la solicitud ri, 
entonces un valor posible de Opt(i,v2,ri) es

costo3 = Opt(i−1,v2,v3) +C(v3,ri)

Realizamos recursión hacia adelante calculando para todos los v2 y v3 el valor 
de Opt(i,v2,v3) a partir de los valores Opt(i−1,x2,x3). 
Es esencial para el uso de la memoria que no haya necesidad de almacenar 
los valores Opt(i,v2,v3) para todos los i. Claramente, para calcular Opt(i,v2,v3)
necesitamos solo los valores Opt(i−1,x2,x3)

Para construir una solución óptima, (subtarea B) almacenamos la ubicación 
para la cual se obtuvo el mínimo para Opt(i,v2,v3) en el elemento de la matriz 
Move[i,v2,v3]                                             

Complejidad:
Tiempo: O(n ∗ m^2) 
Memoria: O(n ∗ m^2) 
"""
import math
from collections import deque
from itertools import chain

# Constants
Maxm = 200  # max. # of locations
Maxn = 1000  # max. # of requests
MaxC = 2000  # max. cost
Inf = Maxn * MaxC + 1

# Global variables
n, m = 0, 0
C = [[0] * (Maxm + 1) for _ in range(Maxm + 1)]  # cost matrix
R = [0] * (Maxn + 1)  # the requests
Move = [[[0] * (Maxm + 1) for _ in range(Maxm + 1)] for _ in range(Maxn + 1)]
Cost = 0  # the optimal total cost
v20, v30 = 0, 0

def read_in():
    global n, m, C, R
    m, n = map(int, input().split())
    for i in range(1, m + 1):
       C[i][1:m + 1] = map(int, input().split())
    R[1:n + 1] = map(int, input().split())

def write_out():
    global Cost, v20, v30
    S = [0] * (Maxn + 1)
    print(f"{Cost}")
    v2, v3 = v20, v30
    vm = Move[n][v2][v3]
    S[n] = vm
    for i in range(n - 1, 0, -1):
        if vm != R[i]:
            if R[i] == v2:
                v2 = vm
            else:
                v3 = vm
        if v2 > v3:
            v2, v3 = v3, v2
        vm = Move[i][v2][v3]
        S[i] = vm
        
    v1, v2, v3 = 1, 2, 3
    for i in range(1, n + 1):
        if S[i] == v1:
            print("1",sep="",end=" ")
            v1 = R[i]
        elif S[i] == v2:
            print("2",sep="",end=" ")
            v2 = R[i]
        else:
            print("3",sep="",end=" ")
            v3 = R[i]
    print("")

def compute_opt():
    global Cost, v20, v30
    Opt = [[[Inf] * (Maxm + 1) for _ in range(Maxm + 1)] for _ in range(2)]
    ir1 = False
    ir = True
    
    Opt[ir][1][2] = C[3][R[1]]
    Move[1][1][2] = 3
    Opt[ir][2][3] = C[1][R[1]]
    Move[1][2][3] = 1
    Opt[ir][1][3] = C[2][R[1]]
    Move[1][1][3] = 2

    Opt[ir][2][1] = Opt[ir][1][2]
    Move[1][2][1] = 3
    Opt[ir][3][2] = Opt[ir][2][3]
    Move[1][3][2] = 1
    Opt[ir][3][1] = Opt[ir][1][3]
    Move[1][3][1] = 2

    for i in range(2, n + 1):
        ir1 = ir
        ir = not ir
        for v2 in range(1, m + 1):
            for v3 in range(v2 + 1, m + 1):
                Opt[ir][v2][v3] = Inf

        for v2 in range(1, m + 1):
            for v3 in range(v2 + 1, m + 1):
                newcost = Opt[ir1][v2][v3] + C[R[i - 1]][R[i]]
                if (v2 != R[i]) and (v3 != R[i]) and (newcost < Opt[ir][v2][v3]):
                    Opt[ir][v2][v3] = newcost
                    Move[i][v2][v3] = R[i - 1]

                newcost = Opt[ir1][v2][v3] + C[v2][R[i]]  # v2 -> r[i]
                if R[i - 1] < v3:
                    v2i, v3i = R[i - 1], v3
                else:
                    v2i, v3i = v3, R[i - 1]
                if (v2i != v3i) and (v2i != R[i]) and (v3i != R[i]) and (newcost < Opt[ir][v2i][v3i]):
                    Opt[ir][v2i][v3i] = newcost
                    Move[i][v2i][v3i] = v2

                newcost = Opt[ir1][v2][v3] + C[v3][R[i]]  # v3 -> r[i]
                if R[i - 1] < v2:
                    v2i, v3i = R[i - 1], v2
                else:
                    v2i, v3i = v2, R[i - 1]
                if (v2i != v3i) and (v2i != R[i]) and (v3i != R[i]) and (newcost < Opt[ir][v2i][v3i]):
                    Opt[ir][v2i][v3i] = newcost
                    Move[i][v2i][v3i] = v3

    Cost = Inf
    for v2 in range(1, m + 1):
        for v3 in range(v2 + 1, m + 1):
            if Opt[ir][v2][v3] < Cost:
                Cost = Opt[ir][v2][v3]
                v20, v30 = v2, v3


if __name__ == '__main__':
   read_in()
   compute_opt()
   write_out()
    
