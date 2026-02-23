"""
    CSES - String Reorder
    Temática : Ordenamiento 
    
    Idea: reorganizar los caracteres de una cadena de manera que ningún 
    par de caracteres adyacentes sea igual y, entre todas las soluciones posibles, 
    elegir la lexicográficamente mínima.
 
 
 
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
    line = input_line()
    n = len(line)

    # Frecuencia en array fijo (más rápido que Counter)
    cnt = [0] * 26
    for ch in line:
        cnt[ord(ch) - ord('A')] += 1

    if max(cnt) > (n + 1) // 2:
        print(-1)
        return

    result = []
    prev = -1  # índice anterior

    for i in range(n):
        remaining = n - i - 1

        for c in range(26):
            if cnt[c] == 0 or c == prev:
                continue

            # probar usar esta letra
            cnt[c] -= 1

            if max(cnt) <= (remaining + 1) // 2:
                result.append(chr(c + ord('A')))
                prev = c
                break
            else:
                cnt[c] += 1

    print(''.join(result))
    
 
 
if __name__ == "__main__":
    solve()