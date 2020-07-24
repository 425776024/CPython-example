from distutils.core import setup, Extension

module1 = Extension('Test.CTest', sources=['Python3_C速度比较.cpp'])
setup(name='CTest',
      version='1.0',
      py_modules=['Test.he'],
      description='This is a demo package',
      ext_modules=[module1])
