#include <stdio.h>
#include "Shape.h"
#include "Rectangle.h"
#include "testRectangle.h"


int main() {
    
    TestRectangle test;
    Rectangle rec;
    Shape * shapesRec = &rec;
    shapesRec->SetValues(5,3);
    printf("Area of rectangle %d\n",rec.GetArea());
    printf("Peremeter of rectangle %d\n",rec.GetPeremeter());
    test.test1();
    test.test2();
    return 0;
}