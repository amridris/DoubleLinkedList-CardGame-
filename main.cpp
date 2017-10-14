#include <iostream>
#include "doubly_linked_list.h"
#include "node.h"
#include "deck.h"
using namespace std;

int main() {

    doubly_linked_list s;
    doubly_linked_list d;
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
    cout<<"The size of the list is: "<<s.get_size()<<endl;

    s.merge(d);
    s.insert_after(4,6111989);
    s.display();


}