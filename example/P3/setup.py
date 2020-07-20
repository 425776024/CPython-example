from distutils.core import setup, Extension

module1 = Extension('Test', sources=['Python3_C生成模块供Python调用.cpp'])
setup(name='Test',
      version='1.0',
      description='This is a demo package',
      ext_modules=[module1])
