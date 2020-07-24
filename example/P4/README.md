# P4
use but not install
```shell

1: python setup.py build (then maybe create a "build" dir)
2: then copy file "build/lib.xxx-xx/Test/CTest.xxxx-xxx.so" to ./Test
3: now , you can import c++ model in python code , like : ./Test/run.py

```

use and install to local python env(which python's env)
```
1: python setup.py install 
2: now , you can import c++ model in python code , like : ./Test/run.py
```
> This command will install a package "Test" 
>to like " /Users/xxx/anaconda3/lib/python3.7/site-packages/Test"(which python's env path)
>

check ,whether install package by "python setup.py install" to your Python env's site-packages dir
```shell script
ls  /Users/xxx/anaconda3/lib/python3.7/site-packages/Test   
```                  
> You'll see "CTest.xxx-xxx.so ", is your C++ model , and can import in Python Code any where
