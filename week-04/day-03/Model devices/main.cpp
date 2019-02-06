#include <iostream>
#include "Printer.h"
#include "Scanner.h"
#include "Printer2D.h"
#include "Printer3D.h"
#include "Copier.h"
#include <vector>
int main() {

std::vector<Printer*> printers;
Printer2D p21(3, 4);
Printer2D p22(5, 2);
Printer2D p23(5, 10);
Printer3D p31 (9, 10, 33);
Printer3D p32 (1, 15, 3);
Copier c1 (3, 6, 9);

printers.push_back(&p21);
printers.push_back(&p22);
printers.push_back(&p23);
printers.push_back(&p31);
printers.push_back(&p32);
printers.push_back(&c1);

for (int i = 0; i < printers.size(); i++) {
        printers.at(i)->print();
}


std::cout << std::endl << std::endl;

std::vector<Scanner*> scanners;

Copier c2(4, 8, 11);
Scanner s1(2);
Scanner s2(5);

scanners.push_back(&c1);
scanners.push_back(&c2);
scanners.push_back(&s1);
scanners.push_back(&s2);



for (int i = 0; i < scanners.size(); i++) {
        scanners.at(i)->scan();
}




    return 0;
}