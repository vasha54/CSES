#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Mar 24 10:19:25 2024

@author: vasha
CSES -Summa
Tematica: Add - Hoc
Idea: Dados dos numeros hallar la suma de estos.
"""

#Begin the template for read data from console o file
buffer = []
bufferFile = []
READ_FILE = False

def readData():
    global READ_FILE
    global bufferFile
    if READ_FILE:
        if len(bufferFile) ==0:
            with open("Input.txt",'r') as file:
                data=file.read()
            bufferFile=data.split('\n')
        line = bufferFile[0]
        bufferFile.pop(0)
        return line
    else:
        return input()

def next():
    global buffer
    try:
        if len(buffer) == 0:
            line = readData()
            buffer = line.split()
        token = buffer[0]
        buffer.pop(0)
        return token
    except EOFError:
        return None

def nextInt():
    token = next()
    if token is not None:
        return int(token)
    else:
        return None

def nextStr():
    token = next()
    if token is not None:
        return str(token)
    else:
        return None

def activeReadFile():
    global READ_FILE
    READ_FILE= True
#End the template for read data from console o file


def solve():
    a = nextInt()
    b = nextInt()
    print(a+b)

def main():
    #activeReadFile()
    solve()


if __name__ == '__main__':
    main()