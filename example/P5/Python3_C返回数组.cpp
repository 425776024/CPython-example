//
// Created by jiang on 2020/7/19.
//
#include <Python.h>
#include <iostream>

using namespace std;

static PyObject *py_pyList(PyObject *self, PyObject *args) {
    PyObject *pyList = PyList_New(3);
    PyObject *pyId = Py_BuildValue("i", 123);   // 创建Python 整型对象
    PyList_SetItem(pyList, 0, pyId);   // 将Python整型对象插入到Python列表对象中

    PyObject *pyName = Py_BuildValue("s", "你好，世界，hello");   // 创建一个字符串python对象
    PyList_SetItem(pyList, 1, pyName);   // 插入到Python列表对象里面去

    PyObject *pyFloat = Py_BuildValue("f", 23.98f);   // 创建一个浮点类型的Python对象
    PyList_SetItem(pyList, 2, pyFloat);   // 将其插入到Python列表对象中

    int listLength = PyList_Size(pyList);   // 获取列表的长度
    cout<<"列表长度:"<<listLength<<endl;

    return pyList;
}

static PyMethodDef Methods[] = {
        {"get_list", py_pyList, METH_VARARGS},
        {NULL, NULL}
};

static struct PyModuleDef cModule = {
        PyModuleDef_HEAD_INIT,
        "Test", /*module name*/
        "", /* module documentation, may be NULL */
        -1, /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
        Methods
};
PyMODINIT_FUNC PyInit_Test(void) {

    return PyModule_Create(&cModule);
}