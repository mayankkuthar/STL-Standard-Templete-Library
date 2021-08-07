#include<bits/stdc++.h> //includes all standard files
using namespace std; // we are using standard namespace. Namespace defines a scope for identifiers.
                     // C++ defines all it;s predefine function in "std" namespace

// Set - it has all the elements unique and sorted 
// Can't access value as s1[index], preferred way--> (s1.begin()+index) :. s1 is set
// It's function work on O(logN)
// We can't add int to iterator of set while it can be done in vector, 
// We can only increment or decrement iterator of set n .o of times

//Other Sets:

//Unordered Set -it has all the elements unique but stored in a random order 
//Avg. Time Complexcity is O(1). --> Faster than set whose is O(logN)
//Worst Time Complexcity is O(N)... But very rare case as hases is different everytime
//If unique but non-sorted fasion is required use UNORDERED SET
// :. If getting TLE means there exist a worst case, then use SET

//Multiset - stores all numbers in sorted form but dublicates also exist no uniqueness
//Time Complexcity is O(logN)

//Map - This container stores value in mapped fashion having key and value. #Like a dictonary in Python
// Stores data in sorted form according to keys
// Map only stores Unique Keys
// Time Complexcity (TC) is O(logN)

//Pair Class - is a container which stores 2 varaible of same or different data type in single unit. 
//#pair of 2 variable

// Map - stores data in form of pairs

//Unordered_map:
// This container stores value in mapped fashion having key and value. #Like a dictonary in Python
// Unique keys but Stores in random order
// Avg. Time Complexcity is O(1)
// Worst Time Complexcity is O(N)... But very rare


//DEQUE - Double ended queues are sequence containers with the feature of expansion and contraction on both the ends.

//List - Lists are sequence containers that allow non-contiguous memory allocation. 
//Traversal is slower than vector but insertion and deletion is quick TC-O(1)

//All function of Vectors are Applicable to BOTH

int main(){
    int arr[8]={1,2,5,3,1,3,5,2};

    //Set
    set <int> s1;
    for(auto i:arr){
        s1.insert(i); //Time Complexicity --> O(logn) -->Faster
    }
    //Now, Set s1 --> {1,2,3,5} , UNIQUE and SORTED

    for(auto i:s1) cout<<i<<" "; //Printing through FOR EACH LOOP
    cout<<endl;
    for(auto i=s1.begin();i!=s1.end();i++) cout<<*i<<" "; //Printing using iterator
    cout<<endl;

    s1.erase(s1.begin()); // delete element at .begin() --> s1={2,3,5}
    s1.erase(3); // deleate the value 3 from set --> s1={2,5}
    s1.erase(s1.begin(),s1.end()); // delete all element from .begin() to end() --> s1={}
    for(auto i:arr) s1.insert(i);

    auto it= s1.find(3);// it is an iterator pointing to the address of '3' in set
    auto it= s1.find(9);// As element is not found it points to .end()
    s1.emplace(4); //Same as insert function , But FASTER

    unordered_set <int> us1;
    for(auto i:arr)
        us1.emplace(i);

    multiset <int> ms1;
    for(auto i:arr)
        ms1.emplace(i);
    //Now ms1={1,1,2,2,3,3,5,5}

    ms1.erase(2);//all instances of 2 will delete --> ms1={1,1,3,3,5,5}
    auto it =ms1.find(3); //return an iterator pointing to first instance of 3 in set
    ms1.clear(); // delete all elements of set
    ms1.count(5);// returns the number of times an element occurs

    //Map
    map <string,int> m1; // map <'key' data_type,'value' datatype> var_name;
    m1["mayank"]= 1; // Add Key and Assign value to keys in a map container
    m1["kuthar"] =16;
    m1["zest"] =32;
    m1["fella"]=20;
    m1["mayank"]= 14; // As map only stores unique keys, Now m1["mayank"] =14 as it overwrite 1
    m1.emplace("codechef",23);//Also Add Key and Assign value to keys
    m1.erase("codechef"); //remove key and it's value from map
    m1.clear(); // makes whole Map EMPTY
    auto it = m1.find("zest");//returns an iterator pointing to key "zest"
    bool check = m1.empty();//returns 1 if map is empty else return 0
    
    //pair
    pair <int,int> p1;
    p1.first =2;
    p1.second=4;

    //Printing MAP
    for(auto it : m1) cout<<it.first<<": "<<it.second<<" "; cout<<endl; // 'it' is a pair first--> key, second-->value
    //Or
    for(auto it=m1.begin();it!=m1.end();it++) cout<<it->first<<": "<<(*it).second<<" "; cout<<endl;

    unordered_map <string,int> um1;
    um1["mayank"]= 1; // Add Key and Assign value to keys in a map container
    um1["kuthar"] =16;
    um1["zest"] =32;
    um1["mayank"]= 14; // As map only stores unique keys, Now m1["mayank"] =14 as it overwrite 1
    um1.emplace("codechef",23);//Also Add Key and Assign value to keys
    um1.erase("codechef"); //remove key and it's value from map
    um1.clear(); // makes whole Map EMPTY
    auto it = um1.find("zest");//returns an iterator pointing to key "zest"
    bool check = um1.empty();//returns 1 if map is empty else return 0
    //Printing MAP
    for(auto it : um1) cout<<it.first<<": "<<it.second<<" "; cout<<endl; // 'it' is a pair first--> key, second-->value

    //Pair Class
    pair <int,int> p1 ={1,4};
    //Nested Pair
    pair <pair<int,int>,int> p2 ={{1,4},8};
    pair <pair<int,int>,pair<int,int>> p2 ={{1,4},{2,8}};
    //Use:
    vector <pair<int,int>> vp1;
    map <pair<int,int>,int> mp1;
    //unordered_map <pair<int,int>,int> ump1; --> Can't do this as Unordered Map only stores single keys

    //Stack - Stack is a container with LIFO(Last In First Out)
    stack <int> st1;
    bool check = st1.empty();//  Returns 0 or 1 whether the stack is empty – Time Complexity : O(1) 
    st1.push(13);//  Adds the element ‘13’ at the top of the stack – Time Complexity : O(1) 
    st1.push(14);
    st1.push(15);
    cout<<st1.size()<<endl;//  Returns the size of the stack – Time Complexity : O(1) 
    cout<<st1.top()<<endl;// Returns the top element of the stack but can throw error if stack is empty
    if(!st1.empty()) cout<<st1.top()<<endl; // Added a check to get top element to avoid error :. IMP!!! for CP
    st1.pop();// Deletes the top most element of the stack – Time Complexity : O(1)
    while(!st1.empty()) st1.pop(); // delete all the elements of array

    //Queue -It is a type of container which operate in a first in first out (FIFO)
    queue <int> q1,q2;
    q1.empty();// Returns whether the queue is empty
    q1.size();//  Returns the size of the queue
    q1.emplace(2); //Insert a new element to the end of the queue
    q1.emplace(4);
    q2.emplace(1);
    q2.emplace(3);
    q1.swap(q2);//  Exchange the contents of two queues but the queues must be of same type, although sizes may differ
    q1.front();// returns a reference to the first element of the queue. 
    q1.back();// returns a reference to the last element of the queue.
    q1.push(8);// Insert a new element '8' to the end of the queue
    q1.pop();// function deletes the first element of the queue.
    while(!q1.empty()) q1.pop(); // Delete all elements of queue

        //Priority Queue - Every element is stored in non-increasing order, uses heapify-Heap Sort
    priority_queue <int> pq1;
    pq1.emplace(1); //Adds element
    pq1.push(4);//Adds element
    pq1.push(3); //--> pq1={4,3,1}
    while(!pq1.empty()) cout<<pq1.top()<<endl; // returns top element if queue is not empty --> 4
    pq1.pop(); // deletes top element --> pq1={3,1}

    priority_queue <pair<int,int>> ppq1;
    ppq1.emplace(1,1);
    ppq1.emplace(1,4);
    ppq1.emplace(2,5);
    ppq1.emplace(2,2);//--> ppq1={{2,5},{2,2},{1,4},{1,1}}

    //Logical Min. Priority Queue - store number using negation and output using re-negation
    priority_queue <int> pq2;
    for(int i=0;i<6;i++) pq2.emplace(-i); //pq2={0,-1,-2,-3,-4,-5}
    for(int i=0;i<pq2.size();i++){ 
        cout<<pq2.top()*-1<<" "; //--> 0 1 2 3 4 5
        pq2.pop();
    }

    deque <int> d1;
    for(int i=6;i<=9;i++) d1.push_back(i);//add elements in back of deque --> d1={6,7,8,9}
    for(int i=5;i>=1;i--) d1.push_front(i); //add elements in front of deque --> d1={1,2,3,4,5,6,7,8,9}
    d1.pop_front();//delete element from front--> 1 deleted
    d1.pop_back();//delete element from back--> 9 deleted
    for(auto i: d1) cout<<i<<" "; cout<<endl; //printing dequeue

    list <int> l1;
    for(int i=6;i<=9;i++) l1.push_back(i);//add elements in back of list --> d1={6,7,8,9}
    for(int i=5;i>=1;i--) l1.push_front(i); //add elements in front of list --> d1={1,2,3,4,5,6,7,8,9}
    l1.pop_front();//delete element from front--> 1 deleted
    l1.pop_back();//delete element from back--> 9 deleted
    for(auto i: l1) cout<<i<<" "; cout<<endl; //printing list
    l1.remove(8);// remove value from list
    l1.reverse();//reverse list in O(N)
    l1.sort();// Sorts list in NlogN time
    l1.unique();//remove duplicates make list unique

}