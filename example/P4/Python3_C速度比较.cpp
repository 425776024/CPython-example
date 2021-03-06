//
// Created by jiang on 2020/7/19.
//
#include <Python.h>
#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

long range_add(int a, int b) {
    long sum = 0;
    for (int i = a; i < b; i++) {
        sum += i;
    }
    return sum;
}


void printc(char *s) {
    cout << "Printc:" << s << endl;
}


static PyObject *py_add(PyObject *self, PyObject *args) {
    /*
     * 用python规定的调用方式，加一层C语言的包装，包装内容包括
　　a.定义一个新的静态函数，接受两个PyObject *参数，返回一个PyObject *值
　　b.解析第二个输入的PyObject *（通过PyArg_ParseTuple等方法），把python输入的变量变成C的变量
　　c.调用原生C函数
　　d.将调用返回的C变量，转换为PyObject*或其子类（通过PyLong_FromLong）等方法，并返回
     * **/
    int num1, num2;
    if (!PyArg_ParseTuple(args, "ii", &num1, &num2)) return NULL;
    return PyLong_FromLong(add(num1, num2));
}


static PyObject *py_range_add(PyObject *self, PyObject *args) {
    long num1, num2;
    if (!PyArg_ParseTuple(args, "ii", &num1, &num2)) return NULL;
    return PyLong_FromLong(range_add(num1, num2));
}


static PyObject *py_printc(PyObject *self, PyObject *args) {
    char *st;
    if (!PyArg_ParseTuple(args, "s", &st)) return NULL;
    printc(st);
    return PyBytes_FromString("你好，python");
}

static PyMethodDef Methods[] = {
        {"add",       py_add,       METH_VARARGS},
        {"printc",    py_printc,    METH_VARARGS},
        {"range_add", py_range_add, METH_VARARGS},
        {NULL, NULL}
};

static struct PyModuleDef cModule = {
        PyModuleDef_HEAD_INIT,
        "CTest", /*module name*/
        "", /* module documentation, may be NULL */
        -1, /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
        Methods
};
PyMODINIT_FUNC PyInit_CTest(void) {

    return PyModule_Create(&cModule);
}