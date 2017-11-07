#include <iostream>
#include "doubly_linked_list.h"
#include "node.h"
#include "deck.h"
using namespace std;

int main() {

    doubly_linked_list s;
    doubly_linked_list d;
    doubly_linked_list m;
    doubly_linked_list split;
    s.append(4);
    s.append(5);
    s.append(6);
    s.append(7);
    s.append(8);
    s.append(9);
    s.append(10);
    s.append(11);
    s.append(12);
    s.append(13);
    s.append(14);
    s.append(15);
    s.append(16);
    s.append(17);
    s.append(18);
    s.split_set(2,10);
    s.display();
    return 0;
}