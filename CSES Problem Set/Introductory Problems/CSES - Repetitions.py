#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
CSES - Repetitions
Tematica: Programación Dinamica + Busqueda 
Idea: Dada una secuencia de letras en este caso ADN encontrar el substring con
mayor longitud tal que las letras que conforman ese subtring sean todas iguales.

Para solucionar el problema bien podemos aplicar una fuerza bruta y generar todos
los posibles subcadenas y ver aquellas que cumplen con la condición que sean compuesta
por una sola letra y cuya longitud sea mayor pero esta idea su complejidad en N²

Para optimizar la idea anterior vamos aplicar un poco de programación dinámica y
busqueda. Cada letra aporta un subtring que cumple con las condiciones del problema
y su longitud es 1 por tanto para incrementar ese substring basta comprobar si la letra
en i+1 es igual a i y tendriamos entonces un substring de longitud 2 y este enfoque
puede ser replicado de forma similar para las siguientes posiciones. Por tanto 
vamos a crear dos contadores (answer y count) el primero va almacenar el mayor
valor alcanzado por el segundo durante el procesamiento de la cadena, mientras
el segundo incrementa en uno su valor siempre que se cumpla que [i] == [i+1] o su
valor va ser 1 en caso contrario. Inicialemente el valor de ambos contadores va 
ser 1 y la cadena se comienza su procesamiento a partir de la segunda letra. 

Complejidad:
Tiempo: O(N) 
Memoria: O(N) 
"""
import math
from collections import deque
from itertools import chain



if __name__ == '__main__':
   ADN = str(input())
   answer,count = 1,1
   for i in range(1,len(ADN)):
      if ADN[i-1] == ADN[i]:
         count = count + 1
      else:
         count = 1
      answer = max(answer,count)
   print(answer)
    
