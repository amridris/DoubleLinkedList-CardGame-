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
    d.append(80);
    d.append(32);
    d.append(2321);
    s.append(322);
    s.append(6698);
    s.append(4);

    s.insert_before(3,778);

    m = s+d;
    m.display();
    return 0;
}