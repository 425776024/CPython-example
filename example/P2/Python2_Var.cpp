
#include <Python.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    PyObject *pyList = PyList_New(3);
    PyObject *pyId = Py_BuildValue("i", 123);   // 创建Python 整型对象
    PyList_SetItem(pyList, 0, pyId);   // 将Python整型对象插入到Python列表对象中

    PyObject *pyName = Py_BuildValue("s", "lanyulei");   // 创建一个字符串python对象
    PyList_SetItem(pyList, 1, pyName);   // 插入到Python列表对象里面去

    PyObject *pyFloat = Py_BuildValue("f", 23.98f);   // 创建一个浮点类型的Python对象
    PyList_SetItem(pyList, 2, pyFloat);   // 将其插入到Python列表对象中

    int listLength = PyList_Size(pyList);   // 获取列表的长度
    printf("列表长度： %d\n", listLength);

//    print_pyobject(pyList);    // 打印列表数据
    cout << pyList << endl;
    PyObject *pyName2 = Py_BuildValue("s", "LanYuLei");  // 创建一个字符串python对象
    PyList_Insert(pyList, 1, pyName2);   // 在下标为1的位置插入一条数据

//    print_pyobject(pyList);    // 打印列表数据
    cout << pyList << endl;
    printf("------------sort-------------\n");
    PyList_Sort(pyList);    // 对列表进行排序
//    print_pyobject(pyList);    // 打印列表数据
    cout << pyList << endl;
    printf("---------------reverse--------------\n");
    PyList_Reverse(pyList);    // 反转列表数据
//    print_pyobject(pyList);    // 打印列表数据
    cout << pyList << endl;
    printf("----------------slice----------------\n");
    PyObject *pySlice = PyList_GetSlice(pyList, 1, 3);   // 获取分片数据
//    print_pyobject(pySlice);    // 打印分片数据
    cout << pyList << endl;
}