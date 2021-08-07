#include<bits/stdc++.h> //includes all standard files
using namespace std; // we are using standard namespace. Namespace defines a scope for identifiers.
                     // C++ defines all it's predefine function in "std" namespace

//Bitset-A bitset is an array of bool, such that each bool takes 1 bit space only
//Space taken by bitset bs is less than that of bool bs[N] and vector bs(N)
//Limitation - N must be known at compile time, same as array container
//bitset starts its indexing backward --> index are 5 4 3 2 1 0 if N=6
// #CP - Generally Used in Segement tree Problems

// STL Algorithms-
// STL Sort()- uses Introsort --> a hybrid sorting algorithm , TC-O(N*logN)
// To minimize the running time, Introsort = Quicksort + Heapsort + Insertion Sort.
//Next Permutation - returns 1 if the function could rearrange the object as a lexicographically greater permutation
// Otherwise, returns 0
// Also modefiy object to next lexicographically greater permutation
//Previous Permutation - returns 1 if the function could rearrange the object as a lexicographically smaller permutation
// Otherwise, returns 0
// Also modefiy object to previous lexicographically smaller permutation
//TC - O(N)

#define N 32

bool comp(int ele1,int ele2){
    if(ele1>=ele2) return true;
    else return false;
}
//Sort acc to first each element if first of 2 element is equal reverse sort acc to second element
bool comp_p(pair<int,int>ele1,pair<int,int>ele2){
    if(ele1.first<ele2.first) return true;
    else if(ele1.first==ele2.first){
        if(ele1.second>ele2.second) return true;
        else return false;
    }
    else return false;
}


int main(){
    // default constructor initializes with all bits 0
    bitset <N> b1; // -->b1= 00000000000000000000000000000000
    // bset2 is initialized with bits of 20
    bitset<N> b2(20); // -->b2= 00000000000000000000000000010100
    // bset3 is initialized with bits of specified binary string
    bitset<N> b3(string("1100")); // --> b3= 00000000000000000000000000001100
    bool check_all = b1.all();// returns 1 if all bits are 1 else returns 0 
    bool check_none = b1.none();// returns 1 if all bits are 0 else returns 0 
    bool check_any = b1.any();// returns 1 if at least 1 bits is 1 else returns 0 
    int count__ = b1.count(); // return count of all 1s
    b1.flip(10);// flip the bit at index 10 from back -> 0 becomes 1 OR 1 becomes 0
    b1.set();// Sets whole bitset b1 with 1s
    b1.set(10);// Index 10 from back sets to 1
    b1.reset(10);// Index 10 from back sets to 0
    bool check = b1.test(3);//checks if index 3 is set or not --> 1 for set, 0 for not set
    b1.flip();// flip all the bits of bitset from 1 to 0 and 0 to 1 

    //Sorting an array
    int n; cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++) cin>>arr1[i];
    sort(arr1,arr1+n); //sort function in STL 
    sort(arr1+1,arr1+4); //Sorts a part of array from index 1 to 3
    //Sorting a vector
    vector <int> v;
    for(int i=0;i<n;i++){
        int temp; cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin()+1,v.begin()+4); //Sorts a part of vector from index 1 to 3
    sort(v.begin(),v.end());//sort function in STL 

    reverse(arr1,arr1+n); //reverses the array TC-O(N)
    reverse(v.begin(),v.begin()+4);//reverse a part of vector from index 0 to 3

    int max_ele = *max_element(arr1,arr1+n);//finds maximum element in array
    int min_ele = *min_element(arr1,arr1+n);//finds minimum element in array
    int max_ele_vec = *max_element(v.begin(),v.begin()+n);//finds maximum element in vector
    int min_ele_vec = *min_element(v.begin(),v.begin()+n);//finds minimum element in vector

    long long int sum =accumulate(arr1,arr1+n,0);//Finds sum of all elements of array
    long long int sum =accumulate(v.begin(),v.begin()+n,0);//Finds sum of all elements of vector

    int count_ = count(arr1,arr1+n,3); // counts the occurence of a element in array
    int count_ = count(v.begin(),v.begin()+n,3); // counts the occurence of a element in vector

    auto it = find(arr1,arr1+n,9);// returns iterator pointing to first address of 9, if 9 not found then end() or arr[n]
    int n_index = it-arr1; //gives index of 9 in array as find points to first address of 9 - address arr[0]
    auto itv = find(v.begin(),v.end(),9);
    int n_index_v = itv-v.begin();

    //Binary Search - STL
    //Only works on Sorted Array or vectors
    bool check =binary_search(arr1,arr1+n,8);//returns 1 if 8 exist else 0, TC-O(logN)
    bool check_v =binary_search(v.begin(),v.end(),8);//returns 1 if 8 exist else 0, TC-O(logN)

    //Lower_bound - returns iterator to first element not less than a given number in an array or vector
    //binary search Implemented in lower_bound(),works on sorted array, TC-O(logN)
    int lb_arr= *lower_bound(arr1,arr1+n,9); // gives out first element not less than 9 in arr array
    int lb_arr= *lower_bound(v.begin(),v.end(),9); // gives out first element not less than 9 in v vector
    
    //Upper_bound - returns iterator to an element just greater than a given number in an array or vector
    //binary search Implemented in upper_bound(),works on sorted array, TC-O(logN)
    int lb_arr= *upper_bound(arr1,arr1+n,9); // gives out an element just greater than 9 in arr array
    int lb_arr= *upper_bound(v.begin(),v.end(),9); // gives out an element just greater than 9 in v vector

    // Find the index where the element x lies in sorted Array
    int n,x; cin>>n>>x;
    int arr[n]; //array
    for(int i=0;i<n;i++) cin>>arr[i];

    if(binary_search(arr,arr+n,x)){ //checks if elemet exist or not
        auto itb = lower_bound(arr,arr+n,x); // since element exist lower_bound points to that element itself
        cout<<"Index: "<<itb - arr<<endl;
    }
    else cout<<"Element don't exist";

    //lower_bound(x)--> ... lowest exist in array from [x,x+1...]
    //upper_bound(x)--> ...lowest exist in array from [x+1,x+2...]
    // Find the index where the lastly element x lies in sorted Array
    // OR Find the last occurence of x in sorted Array

    if(binary_search(arr,arr+n,x)){ //checks if elemet exist or not
        auto itu = upper_bound(arr,arr+n,x); 
        // since element exist upper_bound points to the element just greater than last occurence of x
        cout<<"Index: "<<(itu-1) - arr<<endl;
    }
    else cout<<"Element don't exist";

    //Find number of times an element occurs in an sorted Array
    if(binary_search(arr,arr+n,x)){
        auto itb=lower_bound(arr,arr+n,x);
        auto itu=upper_bound(arr,arr+n,x);
        cout<<"Count: "<<itu-itb<<endl;
    }
    else cout<<"Element don't exist"<<endl;

    string s = "asdf";
    bool val_n = next_permutation(s.begin(),s.end());
    if (val_n == false)
        cout << "No Word Possible"<< endl;
    else
        cout << s << endl; //--> s="asfd"

    bool val_p = prev_permutation(s.begin(),s.end());
    if (val_p == false)
        cout << "No Word Possible"<< endl;
    else
        cout << s << endl; //--> s="asdf"  


    //Find all permutations of given string
    //TC - O(N(LogN + N!))

    string s;
    cin>>s;
    sort(s.begin(),s.end());
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));  

    //Comparators - it's a bool fuction which comare on basis of elements and return true or false
    // Used in Sort to make a different fashion of sorting
    // greater<int> is an inbuilt comparator which works only in descending order --> sort(arr, arr+n, greater<int>); 
    //Trick to Write Comparator:
    /* consider compression of 2 element of whole object
        if(the way you want then to sort) return true
        else false
    */
    int arr_num[6] ={1,4,2,7,5,8};
    sort(arr_num,arr_num+6,comp);// reverse sort as comparator switch of sort when ele1>=el2
    for(auto i: arr_num) cout<<i<<" "; cout<<endl;

    pair <int,int> arr_p[4]={{1,2},{5,4},{5,9},{5,9}};
    sort(arr_p,arr_p+4,comp_p); 
    for(auto i: arr_p) cout<<i.first<<":"<<i.second<<" "; cout<<endl;
}

