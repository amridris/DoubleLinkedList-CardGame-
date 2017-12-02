#include <iostream>
#include "doubly_linked_list.h"
#include "node.h"
#include "deck.h"
using namespace std;
void fillVector(vector<unsigned>& vector)
{
    cout<<"Please type in your number"<<endl;
    unsigned input;
    cin>>input;

    while(input != -1)
    {
        vector.push_back(input);
        cin>>input;
    }
}

void printVector(const vector<unsigned>& vector)
{
    unsigned int i;
    for(i=0; i<vector.size(); i++)
    {
        cout<<vector[i]<<" ";
    }
    cout<<endl;
}
int main() {

    vector<unsigned> v;
    vector<unsigned> S;
    fillVector(v);
    printVector(v);
    doubly_linked_list listV(v);
    doubly_linked_list list2;
    list2.append(1);
    list2.append(2);
    list2.append(3);
    list2.append(4);
    list2.append(5);
    list2.append(6);
    list2.merge(listV);
    list2.display();
    return 0;
}