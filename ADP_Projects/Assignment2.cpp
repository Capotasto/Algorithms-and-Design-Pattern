//
//  Assignment2.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 4/11/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "Assignment2.hpp"

using std::cout;
using std::cin;

void printOptions(void){
    
    //Print options
    cout << "Choose the option number below\n";
    cout << "1. Demonstrating Vectors\n";
    cout << "2. Demonstrating Lists\n";
    cout << "3. Demonstrating Deques\n";
    cout << "4. Demonstrating Maps\n";
    cout << "5. Demonstrating MultiMaps\n";
    cout << "6. Demonstrating Sets\n";
    cout << "7. Demonstrating Multisets\n";
    cout << "8. Demonstrating Stacks\n";
    cout << "9. Demonstrating Queues\n";
    cout << "10. Demonstrating Priority Queues\n";
    
}

enum optionNum{
    VECTORS,//0
    LISTS,//1
    DEQUES,//2
    MAPS,//3
    MULTI_MAPS,//4
    SETS,//5
    MULTI_SETS,//6
    STACKS,//7
    QUEUES,//8
    PRIORITY_QUEUES//9
    
};

void createPriorityQueues(){
    
    //Push into the Priority Queue
    std::priority_queue<int> priorityQueue;
    
    priorityQueue.push(10);
    priorityQueue.push(20);
    priorityQueue.push(30);
    priorityQueue.push(40);
    
    //Pop from the Priority Queue
    //Print The Priority Queue
    
    
    while (!priorityQueue.empty()) {
        cout << priorityQueue.top() << std::endl;
        priorityQueue.pop();
    }
    

}

void createQueues(){
    std::queue<int> queue;
    //Push into the Queue
    queue.push(10);
        queue.push(20);
        queue.push(30);
        queue.push(40);
    
    //Pop from the Queue
    //Print The Queue

    std::queue<int>::size_type size = queue.size();
    
    for (int i = 0; i < size; i++) {
        cout << queue.front() << std::endl;
        queue.pop();
    }
}

void createStacks(){
    std::stack<int> stack;
    
    //Push into the Stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    
    
    //Pop from the Stack
    //Print The Stack
    std::stack<int>::size_type size = stack.size();

    for (int i = 0; i < size; i++) {
        cout << stack.top() << std::endl;
        stack.pop();
    }
    
}

void createMultiSets(){
    std::multiset<int> multiSet;
    //Add an Element to the MultiSet
    multiSet.insert(40);
    multiSet.insert(30);
    multiSet.insert(20);
    multiSet.insert(10);
    
    //std::set<int>::iterator it = set.begin();
    std::set<int>::const_iterator conIt = multiSet.begin();
    
    //Printing the Set
    for (*conIt; conIt != multiSet.end() ; conIt++) {
        cout << *conIt << std::endl;
    }
    
    //Show that Multiple similar Set values are allowed ( By adding and printing)
    puts("Add same value of this multi Set. 10 or 20 or 30 or 40");
    int num;
    cin >> num;
    multiSet.insert(num);
    
    //Printing the Set
    conIt = multiSet.begin();
    for (*conIt; conIt != multiSet.end() ; conIt++) {
        cout << *conIt << std::endl;
    }

}

void createSets(){
    
    //Add an Element to the Set
    std::set<int> set;
    
    set.insert(10);
    set.insert(20);
    set.insert(30);
    set.insert(40);
    
    //std::set<int>::iterator it = set.begin();
    std::set<int>::const_iterator conIt = set.begin();

    //Printing the Set
    for (conIt; conIt != set.end() ; conIt++) {
        cout << *conIt << std::endl;
    }
    
    //Show that Multiple similar Set values are ignored ( By adding and printing)
    
    puts("Add same value of this map. 10 or 20 or 30 or 40");
    int num;
    cin >> num;
    set.insert(num);
    
    //Printing the Set
    conIt = set.begin();
    for (*conIt; conIt != set.end() ; conIt++) {
        cout << *conIt << std::endl;
    }
}

void createMultiMaps(){
    //Add an Element to the MultiMap
    std::multimap<int, std::string> multimap;
    
    multimap.insert(std::multimap<int, std::string>::value_type(10, "aaa"));
    multimap.insert(std::multimap<int, std::string>::value_type(20, "bbb"));
    multimap.insert(std::multimap<int, std::string>::value_type(30, "ccc"));
    multimap.insert(std::multimap<int, std::string>::value_type(40, "ddd"));
    
    cout << multimap.find(10)->second << std::endl;
    cout << multimap.find(20)->second << std::endl;
    cout << multimap.find(30)->second << std::endl;
    cout << multimap.find(40)->second << std::endl;
    
    //Show that Multiple similar Mapped values are allowed ( By adding and printing)
    puts("Add same value of this map. 10 or 20 or 30 or 40");
    int num;
    cin >> num;
    multimap.insert(std::map<int, std::string>::value_type(num, "newRecord"));
    
    //Printing the MultiMap
    std::multimap<int, std::string>::iterator it = multimap.begin();
    
    while (it != multimap.end()) {
        cout << "multimap is " << (*it).first << ":" << (*it).second << std::endl;
        it++;
    }
    
}

void createMaps(){
    //Add an Element to the Map
    std::map<int, std::string> map;
    
    map.insert(std::map<int, std::string>::value_type(10, "aaa"));
    map.insert(std::map<int, std::string>::value_type(20, "bbb"));
    map.insert(std::map<int, std::string>::value_type(30, "ccc"));
    map.insert(std::map<int, std::string>::value_type(40, "ddd"));
    
    cout << map[10] << std::endl;
    cout << map[20] << std::endl;
    cout << map[30] << std::endl;
    cout << map[40] << std::endl;
    
    //Show that Multiple similar Mapped values are ignored ( By adding and printing)
    puts("Add same value of this map.");
    int num;
    cin >> num;
    map.insert(std::map<int, std::string>::value_type(num, "newRecord"));
    
    cout << map[10] << std::endl;
    cout << map[20] << std::endl;
    cout << map[30] << std::endl;
    cout << map[40] << std::endl;
    
    //Printing the Map
    std::map<int, std::string>::iterator it = map.begin();
    
    while (it != map.end()) {
        cout << "map is " << (*it).first << ":" << (*it).second << std::endl;
        it++;
    }
    
}

void createDeques(){
    std::deque<int> deq;
    
    deq.push_back(20);
    deq.push_back(30);
    deq.push_back(40);
    
    cout << "Now you have Deque Variable is below." << std::endl;
    cout << "The values of list is: " << std::endl;
    
    for (int i = 0; i < deq.size(); i++) {
        printf("%3d", deq[i]);
    }
    puts("\n");
    
    //Add an Element to the end of list
    int num;
    cout << "Enter the some number to add an Element to the end of Deque." << std::endl;
    cin >> num;
    deq.push_back(num);
    for (int i = 0; i < deq.size(); i++) {
        printf("%3d", deq[i]);
    }
    puts("\n");
    
    
    //Add an element to the beginning of the list
    cout << "Enter the some number to add an Element to the front of Deque." << std::endl;
    cin >> num;
    deq.push_back(num);
    for (int i = 0; i < deq.size(); i++) {
        printf("%3d", deq[i]);
    }
    puts("\n");
    
    //Access a particular Element in the Deque by using Iterator
    std::deque<int>::iterator it = deq.begin();
    
    printf("*(it+2) is %d\n", *(it+2));
    
    //Access a Particular Element in the Deque by using [] operator
    for (int i=0; i < deq.size(); i++) {
        printf("deq[%d] is %d\n",i, deq[i]);
        
    }
    
}

void createList(){
    int num;
    size_t position;
    std::list<int> list;
    
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    cout << "Now you have List Variable is below." << std::endl;
    cout << "The values of list is: " << std::endl;
    std::list<int>::iterator it = list.begin();
    
    for (int i = 0; i < list.size(); i++) {
        printf("%3d", *it);
        it++;
    }
    puts("\n");
    
    //Add an Element to the end of vector.
    cout << "Enter the some number to add an Element to the end of List." << std::endl;
    cin >> num;
    list.push_back(num);
    it = list.begin();
    
    cout << "The values of list is: " << std::endl;
    for (int i = 0; i < list.size(); i++) {
        printf("%3d", *it);
        it++;
    }
    puts("\n");
    
    //Add an element to the beginning of the list
    cout << "Enter the some number to add an Element to the end of List." << std::endl;
    cin >> num;
    
    list.insert(list.begin(), num);
    it = list.begin();
    
    cout << "The values of list is: " << std::endl;
    for (int i = 0; i < list.size(); i++) {
        printf("%3d", *it);
        it++;
    }
    puts("\n");
    
    
    //Add an element to a specific location in the list
    cout << "Enter the some number to add an Element to the end of List." << std::endl;
    cin >> num;
    cout << "Enter the position number to add an element to a specific location in the list." << std::endl;
    printf("But it must be from 0 to %lu\n", list.size()-1);
    cin >> position;
    std::list<int>::iterator itTemp = std::next(list.begin(), position);
    list.insert(itTemp, num);
    it = list.begin();
    
    cout << "The values of list is: " << std::endl;
    for (int i = 0; i < list.size(); i++) {
        printf("%3d", *it);
        it++;
    }
    puts("\n");
    
    
    //Print the list using Copy Algorithm and otream iterator
    std::list<int> list2;
    std::copy(list.begin() , list.end(), std::back_inserter(list2));
    
    //Print the list using list iterator
    puts("Print the list using Copy Algorithm and otream iterator.");
    
    for (it = list2.begin(); it != list2.end(); ++it) {
        cout << ' ' << *it;
        cout << '\n';
    }
    
    //Show list’s size
    printf("List size is %lu\n", list.size());
    printf("List2 size is %lu\n", list2.size());
    
}


void createVector(){
    
    int num;
    size_t position;
    std::vector< int > v;
    
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    cout << "Now you have Vecotor Variable is below." << std::endl;
    cout << "The values of v is: " << std::endl;
    for (int i = 0; i < v.size(); i++) {
        printf("%3d", v[i]);
    }
    puts("\n");
    
    //Add an Element to the end of vector.
    cout << "Enter the some number to add an Element to the end of vector." << std::endl;
    cin >> num;
    v.push_back(num);
    cout << "The values of v is: " << std::endl;
    for (int i = 0; i < v.size(); i++) {
        printf("%3d", v[i]);
    }
    puts("\n");
    
    //Add an element to the beginning of the vector
    cout << "Enter the some number to add an element to the beginning of the vector." << std::endl;
    cin >> num;
    v.insert(v.begin(), num);
    cout << "The values of v is: " << std::endl;
    for (int i = 0; i < v.size(); i++) {
        printf("%3d", v[i]);
    }
    puts("\n");
    
    //Add an element to a specific location in the vector
    cout << "Enter the some number to add an element to a specific location in the vector." << std::endl;
    cin >> num;
    cout << "Enter the position number to add an element to a specific location in the vector." << std::endl;
    printf("But it must be from 0 to %lu\n", v.size()-1);
    cin >> position;
    v.insert(v.begin() + position, num);
    cout << "The values of v is: " << std::endl;
    for (int i = 0; i < v.size(); i++) {
        printf("%3d", v[i]);
    }
    puts("\n");
    
    //Show Vector’s size
    cout << "Vecotor size is " << v.size() << std::endl;
    puts("\n");
    
    //Access a particular Element in the vector by using Iterator
    cout << "Access a particular Element in the vector by using Iterator" << std::endl;
    std::vector< int >::iterator itr = v.begin();
    for (int i = 0; i < v.size(); i++) {
        cout << *itr << std::endl;
        ++itr;
    }
    
    puts("\n");
    
    
    //Access a Particular Element in the vector by using [] operator
    cout << "Access a Particular Element in the vector by using [] operator" << std::endl;
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << std::endl;
        
    }
    
    puts("\n");
    
}

void mainAssignment2(void){
    
    int inputNum;
    
    //Print options
    printOptions();
    
    //Input the number
    cin >> inputNum;
    
    //printf("%d", inputNum);
    
    switch (inputNum-1) {
        case VECTORS:
            createVector();
            
            break;
        case LISTS:
            createList();
            break;
            
        case DEQUES:
            createDeques();
            break;
            
        case MAPS:
            createMaps();
            break;
            
        case MULTI_MAPS:
            createMultiMaps();
            break;
            
        case SETS:
            createSets();
            break;
            
        case MULTI_SETS:
            createMultiSets();
            break;
            
        case STACKS:
            createStacks();
            break;
            
        case QUEUES:
            createQueues();
            break;
            
        case PRIORITY_QUEUES:
            createPriorityQueues();
            break;
            
        default:
            cout << "That's wrong number.\n";
            break;
    }
    
}