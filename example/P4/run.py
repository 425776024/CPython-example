# import sys

# sys.path.append('os')

import Test as t
import time

a, b = 1, 300000


# python实现
def py_addrange(a, b):
    sum = 0
    for i in range(a, b):
        sum += i
    return sum


s = time.process_time()
# c++实现
sum = t.range_add(a, b)
t1 = (time.process_time() - s)
print(t1)

s2 = time.process_time()
sum2 = py_addrange(a, b)
t2 = (time.process_time() - s2)
print(t2)

print(sum)
print(sum2)

# 慢了1000倍
print(t2 / t1)
