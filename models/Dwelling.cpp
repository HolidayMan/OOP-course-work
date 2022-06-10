#include <iostream>
#include "Dwelling.h"

using namespace std;


Dwelling::Dwelling(string _address, int _rooms)
: address(move(_address)), rooms(_rooms), manager(new DwellingManager()) { }

Dwelling *Dwelling::save() const {
    return manager->save(this);
}

int Dwelling::remove() const {
    manager->remove(this);
    return 0;
}
