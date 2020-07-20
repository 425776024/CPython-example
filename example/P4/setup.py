from distutils.core import setup, Extension

module1 = Extension('Test.Test', sources=['Python3_C速度比较.cpp'])
setup(name='Test',
      version='1.0',
      py_modules=['Test.he'],
      description='This is a demo package',
      ext_modules=[module1])
