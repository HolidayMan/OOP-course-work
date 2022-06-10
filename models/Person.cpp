#include <iostream>
#include <utility>
#include "Model.h"
#include "Person.h"
#include "PersonManager.h"

using namespace std;

Person::Person(string _name, Date* _birthDate, string _sex, string _family)
: manager(new PersonManager()), name(move(_name)), birthDate(_birthDate), sex(move(_sex)), family(move(_family)) { }

Person *Person::save() const {
    manager->save(this);
}
