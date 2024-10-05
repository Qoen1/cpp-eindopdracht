#include <iostream>

#include "backend/enemy/Enemy.hpp"
#include "helpers/BigBrainPointer.hpp"

void test(backend::Enemy* e) {
    helpers::BigBrainPointer<backend::Enemy> enemy = helpers::BigBrainPointer(e);
}

int main()
{
    backend::Enemy* e = new backend::Enemy();
    e->name = "je moeder";

    test(e);


    return 0;
}
