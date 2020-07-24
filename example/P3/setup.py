from distutils.core import setup, Extension

module1 = Extension('Test', sources=['Python_import C++ Model in Python .cpp'])
setup(name='Test',
      version='1.0',
      description='This is a demo package',
      ext_modules=[module1])
