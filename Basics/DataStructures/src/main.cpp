#include "DataStructures/helpers/helpers.hpp"
#include "DataStructures/include/linear/linked_list.h"

// https://www.geeksforgeeks.org/data-structures/

bool run_single_linked_list_test(){

    LinkedList* ll = new LinkedList();
    ll->Add(1);

    assert(ll->Size() == 1 && "wrong num elems");
    
    return true;
}

int main(){

    // linear data structures:
    // each element is attached to its previous and next adjacent elements

    // Static data structures: has a fixed memory size, making it easier to access elems
    // eg Array
    int arr[10];

    // Dynamic data structures: size is not fixed, can be updated during the runtime improving memory efficiancy
    
    // Linked List:
    // A linked list comprises nodes, each with data and a reference to the next node
    // +        - Dynamic Data structure: memory can be allocated or de-allocated at run
    //          - Ease of Insertion/Deletion: simpler than arrays since no elements need to be shifted
    //          - Efficient Memory Utilization: since dynamic  
    //          - Implementation: Various advanced data structures can be implemented as linked list like a stack, queue, graph, hash maps
    
    // Single Linked List:
    // [1] -> [2] -> [3]
    //assert(run_single_linked_list_test() && "Simple linked list test failed");

    // Double Linked List:
    // [1] <-> [2] <-> [3]

    // Circular Linked List:
    // [1] -> [2] -> [3] -> [1]


    // ------------------------


    // ==============================================================
    // ==============================================================
    // Non-linear data structure:
    // elements are not placed sequentially or linearly
    // we can’t traverse all the elements in a single run only

    run_single_linked_list_test();

    std::cout << "finished" << std::endl;
    return 0;
}