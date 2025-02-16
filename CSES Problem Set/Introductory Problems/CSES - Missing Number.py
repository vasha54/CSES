#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
CSES - Missing Number. (https://cses.fi/problemset/task/1083)
Tematica: Aritmética - Algebra
Idea: El problema se reduce a dada una colección con N-1 valores con  
los numeros de 1 a N encontrar el valor que falta sabiendo que lo valores no se 
repiten. 

Una solución trivial seria sumar todos los valores de 1 a N cuyo valor lo 
llamaremos Z despues a medida que se lea los valores ir restando los valores 
a Z y el valor almacenados en Z al final será la solución.

Una forma rapida de calcular la suma de todos los valores de 1 a N es aplicar 
la sumatoria de Gauss que permite sumar todos los valores de 1 a N  cuya expresión
es:
   Z = N(N+1)/2

"""
import math
from collections import deque
from itertools import chain

if __name__ == '__main__':
    n = int(input())
    Z = (n*(n+1))//2
    values_str = input().split()
    values = [int (x) for x in values_str]
    for x in values:
       Z = Z - x
    print(Z)