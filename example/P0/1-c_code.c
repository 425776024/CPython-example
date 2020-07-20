
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void loop(int a,int b) {
    for(int i=a;i<b;i++){
        printf("i:%d\n",i);
    }
}


void print(char *h) {
    printf("h:%s\n",h);
}

// 使用：gcc  -o my_c_python.so -shared -fPIC 1-c_code.c
//命令，生成离线so库，在1.c.py中使用