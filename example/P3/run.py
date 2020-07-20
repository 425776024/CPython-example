import sys

sys.path.append('os')

import Test as t

add=t.add
# 数值运算，传递数值，接收返回的数值
print(add(1, 3))

# 打印，传递字符串
c = t.printc('哈哈哈收到')
# 接受bytes，转成str打印
print(str(c.decode()))
