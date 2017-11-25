#include "doubly_linked_list.h"
using namespace std;
/*
 * You will be writing all of the code for each of these functions.
 * Remember, this is a doubly linked list, not an array. You need to
 * be using pointers, and not overwriting your values like you would
 * in an array.
 *
 * If you need to write auxiliary functions, you are more than welcome
 * to, but you can't change the signature of any of the functions we
 * have written.
 *
 * Information on doubly linked lists can be found at
 * https://en.wikipedia.org/wiki/Doubly_linked_list
 *
 * Hints: - Keep track of size. If you add or delete something, you
 *          need to change size.
 *        - This isn't an array, so moving things around is actually
 *          a lot easier. Just change the pointers to the objects.
 *        - Keep track of your edge cases; empty, 1 item, and 2 items
 *        - Some of these functions are basically the same thing,
 *          with the index shifted or return ignored. Don't rewrite
 *          code, just call the function with the 'correct' inputs.
 *        - Test your doubly linked list by itself before testing it
 *          in the deck class. It will make it easier to find any bugs
 *        - Use your debugger. It is your best friend for finding
 *          issues!
 *        - Don't forget to ask for help on Slack!
 *
 * We will be making changes throughout the week to the deck.cpp as
 * well as adding testing into the project. Make sure to pull and
 * merge frequently.
 */


// Default constructor
doubly_linked_list::doubly_linked_list() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;


}

// Take in a vector of inputs and construct a doubly linked list from them
doubly_linked_list::doubly_linked_list(std::vector<unsigned> &values) {

    //Since this is a constructor we assume the list is always empty1
    this->head = this->tail = 0;
    this->size = 0;
    unsigned int i;
    node *temp;

    //creating the first node for value[0]
    this->head = this->tail = temp = new node(values[0]);
    size++;

    //creating the rest of the list
    for (i = 1; i < values.size(); i++) {
        this->tail = new node(values[i]);
        this->tail->prev = temp;
        temp->next = tail;
        temp = temp->next;
        size++;
    }

    return;
}

// Copy constructor
doubly_linked_list::doubly_linked_list(const doubly_linked_list& original) {
    //Use a temp pointer to transfer the values to the new list
    node* temp_ori = original.head;

    //creating an empty starting node for the new list with the new list head and tail pointers pointing to it
    this->head = new node(temp_ori->data);
    this->tail = head;

    //since we are copying the list, the size of the new list is gone be equal to the size of the original list
    this->size = original.size;
    //create temp_new pointer to help us copy the values
    node* temp_new = this->head;
    temp_ori= temp_ori->next;

    for(int i=1; i<original.size;i++)
    {
        //using temp_new & this->tail, we will copy the values
        temp_new->next = new node(temp_ori->data);
        //move temp_ori to the next node to copy it
        temp_ori = temp_ori->next;
        //move temp_new to the next node
        temp_new = temp_new->next;
        //copy the address of the previous node to the prev memory of the new node
        temp_new->prev = tail;
        //move tail to the next node
        tail = tail->next;
        //no need to update the size value because it matches the original list size
    }


}

// Create doubly linked linked list with one input value
doubly_linked_list::doubly_linked_list(unsigned input) {
    //create a temp node pointer and point it to a new created node with value input
    auto *temp = new node (input);
    //have the head & tail list point to the new node
    this->head = this->tail = temp;
    //since we are adding one node, size = 1
    this->size++;


}

// Default destructor
doubly_linked_list::~doubly_linked_list() {
    //create an integer to iterate
    int i=0;
    //create two node pointers
    node* temp;
    node *eraser;
    //set the two pointers to head
    temp = eraser = this->head;
    //loop through the list using its size value
    while(temp)
    {
        //move the temp pointer to the next node to avoid losing the address
        temp = temp->next;
        //delete the node pointed by eraser
        delete eraser;
        //move eraser to the next node to erase
        eraser = temp;
    }

}

// return the value inside of the list located at position
unsigned doubly_linked_list::get_data(unsigned position) {
    int i=1;
    //create a node temp to locate the position and return the value
    node* temp;
    //set temp to point to the first node
    temp = head;

    //Check to see if the value is within range
    if(position > this->size)
    {
        cerr<<"Error! Value specified is out range"<<endl;
        exit(1);
    }

    else {
        while (i < position) {
            //move temp to the location
            temp = temp->next;
            i++;
        }
    }
    return temp->data;
}

// Get a set of values between position_from to position_to
std::vector<unsigned> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {

    //FYI, starting from 1 2 3 4 5 6 and not 0 1 2 3 4 5...
    int i=1;

    //create a vector to save the values
    std::vector<unsigned>result;

    //create a temp node and point it to the first node
    node *temp = head;

    //move temp to the position_from(starting point)
    while(i<position_from)
    {
        temp=temp->next;
        i++;
    }

    //check to see if the position_to is within the list range
    if(position_to > this->size)
    {
        std::cout<<"Error encountered! location specified is out of range."<<std::endl;
        exit(1);
    }

    else { //create a for loop to insert the values to the vector.
        unsigned int y=0;
        for (y=position_from; y <= position_to; y++) {
            result.push_back(temp->data);
            temp = temp->next;
        }
    }

    return result;
}

// Add a value to the end of the list
void doubly_linked_list::append(unsigned data) {
    //create a new node
    node* temp;
    if(this->head == nullptr && this->tail == nullptr)
    {
        temp = new node (data);
        this->head = this->tail = temp;
        this->size++;
    }

    else {
        //temp will be pointing to the end of the list
        temp = tail;
        //assign the node next field to the newly created node and insert data value to the new node
        temp->next = new node(data);
        //move temp to the new node
        temp = temp->next;
        //new node prev is assigned the address to the previous node using the tail pointer
        temp->prev = tail;
        // move tail pointer to the new node since it is the last node
        tail = tail->next;
        //update the size
        this->size++;
    }
}

// Merge two lists together in place, placing the input list at the end of this list
const doubly_linked_list doubly_linked_list::merge(doubly_linked_list rhs) {
    //add the two sizes to get the size of the merged list
    this->size += rhs.size;
    //assign the this->tail->next field to point to rhs.head address to forward link the last end of this list to the rhs list
    this->tail->next = rhs.head;
    //assign rhs.head->prev to point to this->tail to create a back link
    rhs.head->prev = this->tail;
    // let this->tail point to the same node as rhs.tail is pointing to
    this->tail = rhs.tail;

}

// Allow for the merging of two lists using the + operator.
doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {

    //create a new list to store the values of two lists
    doubly_linked_list s;
    s.size = this->size + rhs.size;
    node *temp, *temp1, *temp2;
    temp1 = this->head;
    temp2 = rhs.head;
    temp = new node (temp1->data);
    s.head = s.tail = temp;
    temp1 = temp1->next;

    while(temp1!= nullptr)
    {
        temp->next  = new node(temp1->data);
         temp = temp->next;
        temp->prev = s.tail;
        s.tail = s.tail->next;
        temp1 = temp1->next;
    }


    while(temp2!= nullptr)
    {
        temp->next = new node(temp2->data);
        temp = temp->next;
        temp->prev = s.tail;
        s.tail = s.tail->next;
        temp2 = temp2->next;
    }



    //return the newly created list
    return s;
}

// Insert a node before the node located at position
void doubly_linked_list::insert_before(unsigned position, unsigned data) {
    //create a temp node pointer
    node *temp;
    temp = head;
    int i=1;

    if(position > this->size || position <= 0)
    {
        cout<<"Error encountered!. The position is out of range, please enter a different value."<<endl;
        exit(0);
    }
    //move temp pointer to the desired location
    while(i<position)
    {
        temp = temp->next;
        i++;
    }

    //once temp is at the desired location
    //create new node with data value
    auto *newnode = new node(data);
    //link the newnode to the node located at position & position-1.
    newnode->next = temp;
    newnode->prev = temp->prev;
    //fix the linkage of node located at position
    temp->prev = newnode;
    //move temp backward to fix the linkage at position-1
    temp = newnode->prev;
    //point temp->next to the newnode
    temp->next = newnode;
    //update the size
    this->size++;


}

// Insert a node after the node located at position
void doubly_linked_list::insert_after(unsigned position, unsigned data) {
    //create a temp node pointer
    node *temp, *temp1;
    temp = head;
    int i=1;

    if(position >= this->size || position < 0)
    {
        cout<<"Error encountered!. The position is out of range, please enter a different value."<<endl;
        exit(0);
    }
    //move temp pointer to the desired location
    while(i<=position)
    {
        temp = temp->next;
        i++;
    }

    if(temp->next == nullptr)
    {
        auto *newnode = new node(0);
        newnode->prev = temp;
        temp->next = newnode;
        this->size++;
    }
    else {

        temp1 = temp->next;
        //once temp is at the desired location
        //create new node with data value
        auto *newnode = new node(data);
        //link the newnode to the node located at position & position+1.
        newnode->next = temp1;
        temp1->prev = newnode;
        newnode->prev = temp;
        temp->next = newnode;

        //update the size
        this->size++;
    }
}

// Remove the node located at position from the linked list
void doubly_linked_list::remove(unsigned position) {
    //we need to node pointers
    node *temp, *temp1;
    int i=0;
    temp = temp1 = head;
    //traverse to the location
    while(i<position)
    {
        temp = temp->next;
        i++;
    }
    //move temp1 to the node after temp
    temp1 = temp->next;
    //link temp1->prev1 to temp->prev, to skip the node that will be deleted
    temp1 = temp->prev;
    //move temp1 to the node before temp to fix the linkage
    temp1 = temp->prev;
    //assign temp1->next to temp->next to skip the node that will be deleted
    temp1->next = temp->next;
    //now that the node pointed by temp has been completed disconnected from the list, we can delete it
    delete temp;

    //update the size
    this->size--;


}

// Split the list with the node being split on being included in the returned list
doubly_linked_list doubly_linked_list::split_before(unsigned position) {
    //save the split list under split_list
    doubly_linked_list split_list;
    int i=0;
    //create a node
    node* temp = head;
    //travers to the location
    while(i<position)
    {
        temp = temp->next;
        i++;
    }
    //split list head will be pointing at the position node.
    split_list.head = temp;
    //split list tail will be pointing to the tail of "this" list.
    split_list.tail = this->tail;
    //move this->tail to the node before temp
    this->tail = temp->prev;
    //break the split, by assigning this->tail->next to null.
    this->tail->next = nullptr;
    //and by assigning split_list.head->prev to null
    split_list.head->prev = nullptr;
    //update the sizes
    this->size = size - position-1;
    split_list.size = split_list.size - position+1;
    //return the new split_list
    return split_list;

}

// Split the list with the node being split on being included in the retained list
doubly_linked_list doubly_linked_list::split_after(unsigned position) {
    //save the split list under split_list
    doubly_linked_list split_list;
    int i=0;
    //create a node
    node* temp = head;
    //travers to the location
    while(i<position)
    {
        temp = temp->next;
        i++;
    }
    //split list head will be pointing at the position node.
    split_list.head = temp->next;
    //split list tail will be pointing to the tail of "this" list.
    split_list.tail = this->tail;
    //move this->tail to the node before temp
    this->tail = temp;
    //break the split, by assigning this->tail->next to null.
    this->tail->next = nullptr;
    //and by assigning split_list.head->prev to null
    split_list.head->prev = nullptr;
    //update the sizes
    this->size = size - position+1;
    split_list.size = split_list.size - position-1;
    //return the new split_list
    return split_list;
}

// Create two lists, one starting at position_from and ending with position_to and return that list
// Merge the beginning of the original list with the end of the original list and retain it
doubly_linked_list doubly_linked_list::split_set(unsigned position_from, unsigned position_to) {

    doubly_linked_list split_list;
    if(position_from !=0 && position_to != size) {
        node *temp1, *temp2, *temp3, *temp4;
        temp1 = temp2 = this->head;

        int i = 0, y = 0;

        while (i < position_from) {
            temp1 = temp1->next;
            i++;
        }
        while (y < position_to) {
            temp2 = temp2->next;
            y++;
        }

        temp3 = temp1->prev;
        temp4 = temp2->next;

        temp4->prev = nullptr;
        temp2->next = nullptr;


        temp3->next = nullptr;
        temp1->prev = nullptr;

        split_list.head = temp1;
        split_list.tail = temp2;

        this->head->prev = tail;
        this->tail->next = head;
        this->head = temp4;
        this->tail = temp3;

    }

    else if(position_from == 0 && position_to != size)
    {
        node *temp,*temp1;
        temp = this->head;
        int i=0;
        while(i<=position_to)
        {
            temp1 = temp1->next;
            i++;
        }
        split_list.head = temp;
        this->head = temp1->next;
        split_list.tail = temp1;
        temp1->next = nullptr;
        this->head->prev = nullptr;



    }

    else
    {
        node *temp,*temp1;
        temp = this->head;
        int i=0;
        while(i<=position_from)
        {
            temp1 = temp1->next;
            i++;
        }
        temp = this->tail;
        this->tail = temp1->prev;
        split_list.head = temp;
        split_list.tail = temp1;
        temp->prev = nullptr;
        this->tail->next = nullptr;


    }

    return split_list;


}

// Swap two nodes in the list. USE POINTERS. Do not just swap the values!
void doubly_linked_list::swap(unsigned position1, unsigned position2) {
    node* temp1, *temp2;

    node* swap_1_1, *swap_1_2, *swap_2_1, *swap_2_2;

    temp1 = temp2 = head;

    //traverse temp1 to position1
    int i=0, y=0;
    while(i<position1)
    {
        temp1 = temp1->next;
        i++;
    }
    //traverse temp2 to position2
    while(y<position2)
    {
        temp2 = temp2->next;
        y++;
    }

    swap_1_1 = temp1->prev;
    swap_1_2 = temp1->next;
    swap_2_1 = temp2->prev;
    swap_2_2 = temp2->next;

    temp1->next = swap_2_2;
    temp1->prev = swap_2_1;
    temp2->next = swap_1_2;
    temp2->next = swap_1_1;

}

// Swap two sets of cards. The sets are inclusive. USE POINTERS!
void doubly_linked_list::swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from,
                                  unsigned position2_to) {

    node *temp1, *temp2, *temp3, *temp4;
    temp1 = temp2 = temp3 = temp4 = head;
    node* swap_1_1, *swap_1_2, *swap_2_1, *swap_2_2, *swap_3_1, *swap_3_2, *swap_4_1, *swap_4_2;

    //traverse all of the temp pointers to their respective locations
    int i=0, y=0, a=0, c=0;
    while(i<position1_from)
    {
        temp1= temp1->next;
        i++;
    }

    while(y<position1_to)
    {
        temp2 = temp2->next;
        y++;
    }

    while(a<position2_from)
    {
        temp3 = temp3->next;
        a++;
    }
    while(c<position2_to)
    {
        temp4 = temp4->next;
        c++;
    }

    swap_1_1 = temp1->prev;
    swap_1_2 = temp1->next;
    swap_2_1 = temp2->prev;
    swap_2_2 = temp2->next;
    swap_3_1 = temp3->prev;
    swap_3_2 = temp3->next;
    swap_4_1 = temp4->prev;
    swap_4_2 = temp4->next;

    temp3->prev = swap_1_1;
    temp3->next = swap_1_2;
    temp4->prev = swap_2_1;
    temp4->next = swap_2_2;
    temp1->prev = swap_3_1;
    temp1->next = swap_3_2;
    temp2->prev = swap_4_1;
    temp2->next = swap_4_2;
}

// Overload operator=
doubly_linked_list &doubly_linked_list::operator=(const doubly_linked_list &RHS) {

    this->size = RHS.size;
    node* temp_RHS, *temp_this;
    temp_RHS = RHS.head;
    temp_this = new node(0);
    this->head=this->tail=temp_this;

    while(temp_RHS!= nullptr)
    {
        temp_this->data = temp_RHS->data;
        temp_this->next = new node(0);
        temp_this = temp_this->next;
        temp_this->prev = this->tail;
        temp_RHS = temp_RHS->next;
        this->tail = this->tail->next;
    }

    return *this;
}

// Append the rhs to the end of the this list
doubly_linked_list &doubly_linked_list::operator+=(const doubly_linked_list &RHS) {

    this->size += RHS.size;
    this->tail->next = RHS.head;
    RHS.head->prev = this->tail;
    this->tail = RHS.tail;
    RHS.head->next = RHS.head->prev = RHS.tail->next = RHS.tail->prev = nullptr;

    return *this;
}

unsigned doubly_linked_list::get_size() {
    return size;
}

bool doubly_linked_list::is_empty() {
    return !size;
}

void doubly_linked_list::display()
{
    node *temp;
    temp = this->head;
    while(temp!= nullptr)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }

}