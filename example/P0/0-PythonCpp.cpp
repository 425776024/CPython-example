//
// Created by jiang on 2020/5/24.

//

#include <iostream>

using namespace std;

void pt(string what) {
    cout << what << endl;
}

int func(int a) {
    return a + 10;
}

extern "C" {
#include "stdio.h"
int c_func(int a) {
    return func(a);
}


void c_pt(char what[]) {
    pt(what);
}
}

int main() {
    pt("哈哈哈哈");
    return 0;
}