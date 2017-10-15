#include <iostream>
#include "doubly_linked_list.h"
#include "node.h"
#include "deck.h"
using namespace std;

int main() {

    doubly_linked_list s;
    doubly_linked_list d;
    doubly_linked_list m;
    d.append(1);
    d.append(2);
    d.append(9);
    d.append(47);
    d.append(1000);
    s.append(4);
    s.append(6);
    s.append(25);
    s.append(46);
    s.append(2544);
    s.append(124);

    m = s+d;
    m.display();
    return 0;
}