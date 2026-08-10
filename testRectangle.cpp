#include "testRectangle.h"
#include <assert.h>
#include <stdio.h>

void TestRectangle::test1(){
    SetValues(3,2);
    int area = GetArea();
    int peremeter = GetPeremeter();
    fprintf(stdout,"Test 1 is working..\n");
    assert(area > 0);
    assert(peremeter > 0);
    fprintf(stdout,"\nTest 1 Passed\n");
}

void TestRectangle::test2() {
    SetValues(3,2);
    int area = GetArea();
    int peremeter = GetPeremeter();
    fprintf(stdout,"Test 2 is working..\n");
    assert(area == 6);
    assert(peremeter == 10);
    fprintf(stdout,"\nTest 2 Passed!\n");
}