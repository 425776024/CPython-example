#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
import time

ll = cdll.LoadLibrary
lib = ll("my_c_python.so")


def loop_by_python(a, b):
    start = time.time()
    for i in range(a, b):
        print('i:', i)
    t = time.time() - start
    print('py:', t)


def loop_by_c(a, b):
    # 数字的沟通
    start = time.time()
    lib.loop(a, b)
    t = time.time() - start
    print('c:', t)


def string():
    # 字符串的"沟通"，变成流
    '''
    str_test="need_bytes"
    foo.myprint(str_test) # 输出结果：n
    utf8=str_test.encode()
    foo.myprint(utf8)  #输出结果为：need_bytes
    '''
    str1 = c_char_p(bytes("哈哈", 'utf-8'))
    lib.print(str1)


def arr():
    # 10 元素的 c_int 类型的数组
    a = (c_int * 10)()
    myArr10 = c_int * 10
    a = myArr10()
    for i in range(0, len(a)):
        a[i] = i
        print(a[i], end=" ")


string()
arr()
# 那个快？？是add_by_c，越CPU密集型越明显
loop_by_python(0, 2 ** 5)
loop_by_c(0, 2 ** 5)
