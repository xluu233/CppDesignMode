#include <iostream>
#include "Aggregate.h"

int main() {

    Aggregate<int> *aggregate = new Aggregate<int>();
    aggregate->push(1);
    aggregate->push(3);
    aggregate->push(5);

    MyIterator<int,Aggregate<int>>* iterator = aggregate->createIterator();

    for (iterator->first(); !iterator->isDone(); iterator->next()) {
        std::cout << *iterator->curItem() << std::endl;
    }

    delete iterator;
    delete aggregate;

    return 0;
}
