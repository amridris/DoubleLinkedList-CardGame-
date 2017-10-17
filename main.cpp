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
    d.append(1);
    d.append(80);
    d.append(32);
    d.append(2321);
    s.append(322);
    s.append(6698);
    s.append(4);
    s.insert_before(3,778);
    cout<<"List m is displayed below"<<endl;

    m = s+d;
    m.display();

    m.split_before(3);
    cout<<"split m displayed below"<<endl;
    m.display();
    return 0;
}