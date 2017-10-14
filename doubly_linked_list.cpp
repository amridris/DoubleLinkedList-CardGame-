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
doubly_linked_list::doubly_linked_list(std::vector<unsigned> values) {

    if(this->head == nullptr && tail->prev == nullptr)//List is empty
    {
        head = tail = new node(values[0]); //created an empty node
        this->size = 1; //since we created a single node
        node* temp = head; // create a node pointer

        for(int i=1; i<=values.size();i++)//loop through to insert all of the vector values
        {
          temp->next = new node(values[i]); //create a new node and link the two nodes together (only next linkage
          this->size++; //increase size value with every node created
          temp = temp->next; //move temp to the new node
          temp->prev = tail; // link the nodes together (both ways)
          tail = tail->next;  //move tail such that at the end the tail is pointing to the last node
        }


        return; //return
    }

    else // list is not empty, we will continue adding values to the list
    {
        node* temp = tail; //create a new node and have it point to the node tail pointer is pointing to, that way we are adding values at the end

        for(int i=0; i<=values.size();i++)
        {
            temp->next = new node(values[i]);
            this->size++;//update the size value with each added nodes.
            temp = temp->next;
            temp->prev = tail;
            tail = tail->next;
        }



        return;
    }
}

// Copy constructor
doubly_linked_list::doubly_linked_list(const doubly_linked_list& original) {
    //Use a temp pointer to transfer the values to the new list
    node* temp_ori = original.head;

    //creating an empty starting node for the new list with the new list head and tail pointers pointing to it
    this->head = new node(0);
    this->tail = head;

    //since we are copying the list, the size of the new list is gone be equal to the size of the original list
    this->size = original.size;
    //create temp_new pointer to help us copy the values
    node* temp_new = this->head;

    for(int i=0; i<=original.size;i++)
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

    return;

}

// Create doubly linked linked list with one input value
doubly_linked_list::doubly_linked_list(unsigned input) {
    //create a temp node pointer and point it to a new created node with value input
    node *temp = new node(input);
    //have the head & tail list point to the new node
    this->head = this->tail = temp;
    //since we are adding one node, size = 1
    this->size++;

    return;

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
    while(i<=this->size)
    {
        //move the temp pointer to the next node to avoid losing the address
        temp = temp->next;
        //delete the node pointed by eraser
        delete eraser;
        //move eraser to the next node to erase
        eraser = temp;
    }
    //once all the list is deleted, delete head and tail pointers
    delete head, tail, size;
}

// return the value inside of the node located at position
unsigned doubly_linked_list::get_data(unsigned position) {
    int i=0;
    //create a node temp to locate the position and return the value
    node* temp;
    //set temp to point to the first node
    temp = head;

    while(i<=position)
    {
        //move temp to the location
        temp = temp->next;
    }

    return temp->data;
}

// Get a set of values between position_from to position_to
std::vector<unsigned> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
    int i=0;
    //create a vector to save the values
    std::vector result;
    //create a temp node and point it to the first node
    node *temp = head;
    //move temp to the position_from(starting point)
    while(i<=position_from)
    {
        temp=temp->next;
    }

    //check to see if the position_to is within the list range

    if(position_to < this->size)
    {
        std::cout<<"Error encountered! location specified is out of range."<<std::endl;
        exit;
    }

    //create a for loop to insert the values to the vector.
    for(int i=0; i<=position_to; i++)
    {
        result.push_back(temp->data);
        temp = temp->next;
    }

    return result;

}

// Add a value to the end of the list
void doubly_linked_list::append(unsigned data) {
    //create a new node
    node* temp;
    //temp will be pointing to the end of the list
    temp=tail;
    //assign the node next field to the newly created node and insert data value to the new node
    temp->next = new node(data);
    //move temp to the new node
    temp = temp->next;
    //new node prev is assigned the address to the previous node using the tail pointer
    temp->prev = tail;
    // move tail pointer to the new node since it is the last node
    tail=tail->next;
    //update the size
    this->size++;

}

// Merge two lists together in place, placing the input list at the end of this list
void doubly_linked_list::merge(doubly_linked_list rhs) {
    //add the two sizes to get the size of the merged list
    this->size += rhs.size;
    //assign the this->tail->next field to point to rhs.head address to forward link the last end of this list to the rhs list
    this->tail->next = rhs.head;
    //assign rhs.head->prev to point to this->tail to create a back link
    rhs.head->prev = this->tail;
    // let this->tail point to the same node as rhs.tail is pointing to
    this->tail = rhs.tail;

    //delete rhs.head & rhs.tail
    delete rhs.head, rhs.tail;

    return;

}

// Allow for the merging of two lists using the + operator.
doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {

    //create a new list to store the values of two lists
    doubly_linked_list s;
    //the new list size = size of list 1 + size of list 2
    s.size = this->size + rhs.size;
    //let the new list point to the first node of the first list, by assigning s.head = this-> head
    s.head = this->head;
    //let the new list point to the end node of the 2nd list by assigning s.tail = rhs->tail
    s.tail = rhs.tail;
    // link the end node of the first list to the first node of the 2nd list
    this->tail->next = rhs.head;
    rhs.head->prev = this->tail;
    //delete all the heads and tails of the first and 2nd lists.
    delete this->tail, this->head, rhs.head, rhs.tail;
    //return the newly created list
    return s;
}

// Insert a node before the node located at position
void doubly_linked_list::insert_before(unsigned position, unsigned data) {
    //create a temp node pointer
    node *temp;
    temp = head;
    int i;

    //move temp pointer to the desired location
    while(i<= position)
    {
        temp = temp->next;
    }

    //once temp is at the desired location
    //create new node with data value
    node *newnode = new node(data);
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

    return;

}

// Insert a node after the node located at position
void doubly_linked_list::insert_after(unsigned position, unsigned data) {
    //create a temp node pointer
    node *temp;
    temp = head;
    int i;

    //move temp pointer to the desired location
    while(i<= position)
    {
        temp = temp->next;
    }

    //once temp is at the desired location
    //create new node with data value
    node *newnode = new node(data);
    //link the newnode to the node located at position & position+1.
    newnode->next = temp->next;
    newnode->prev = temp;
    //fix the linkage of node located at position
    temp->next = newnode;
    //move temp forward to fix the linkage at position+1
    temp = newnode->next;
    //point temp->prev to the newnode
    temp->prev = newnode;
    //update the size
    this->size++;

    return;
}

// Remove the node located at position from the linked list
void doubly_linked_list::remove(unsigned position) {
    //we need to node pointers
    node *temp, *temp1;
    int i=0;
    temp = temp1 = head;
    //traverse to the location
    while(i<=position)
    {
        temp = temp->next;
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
    while(i<=position)
    {
        temp = temp->next;
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
    while(i<=position)
    {
        temp = temp->next;
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
//    return ;
}

// Swap two nodes in the list. USE POINTERS. Do not just swap the values!
void doubly_linked_list::swap(unsigned position1, unsigned position2) {

}

// Swap two sets of cards. The sets are inclusive. USE POINTERS!
void doubly_linked_list::swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from,
                                  unsigned position2_to) {

}

// Overload operator=
doubly_linked_list &doubly_linked_list::operator=(const doubly_linked_list &RHS) {
//    return <#initializer#>;
}

// Append the rhs to the end of the this list
doubly_linked_list &doubly_linked_list::operator+=(const doubly_linked_list &RHS) {
//    return <#initializer#>;
}

unsigned doubly_linked_list::get_size() {
    return size;
}

bool doubly_linked_list::is_empty() {
    return !size;
}