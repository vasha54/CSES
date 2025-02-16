#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
CSES - Increasing Array
Temática: Add - Hoc

Idea: Dado una colección de valores se quiere realizar un grupo de operaciones
tal que cualquier elemento de la colección sea mayor o igual que el elemento que
le precede. Una operación consiste en escoger un elemento de la colección y
aumentar su valor en uno. Dado los valores se quiere hallar la mínima cantidad
de operaciones. La solución radica en sumas las diferencias entre dos valores
consecutivos siempre y cuando el primero sea mayor que el segundo. Cuando esto
ocurre el segundo toma el valor del primero ya que en la próxima iteracción será
el primero del par a analizar.

Complejidad:
Tiempo: O(N) 
Memoria: O(N) 
"""
import math
from collections import deque
from itertools import chain



if __name__ == '__main__':
   nvalues = int(input())
   values = [int(x) for x in input().split() ]
   answer = 0
   for i in range(1,nvalues):
      if values[i-1]>values[i]:
         answer=answer+(values[i-1] - values[i]);
         values[i] = values[i-1];
   print(answer)
    
