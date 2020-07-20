#define PY_SSIZE_T_CLEAN

#include <Python.h>

int main(int argc, char *argv[]) {
    Py_Initialize();
    PyRun_SimpleString("import os");
    PyRun_SimpleString("print(os.path)");

    PyRun_SimpleString("import numpy as np");
    PyRun_SimpleString("a = np.array([1, 2, 3])");
    PyRun_SimpleString("print(a)");
    PyRun_SimpleString("print(np.__version__)");
    Py_Finalize();
    return 0;
}
