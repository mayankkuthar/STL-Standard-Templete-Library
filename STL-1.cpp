#include<bits/stdc++.h> //includes all standard files
using namespace std; // we are using standard namespace. Namespace defines a scope for identifiers.
                     // C++ defines all it;s predefine function in "std" namespace

//iterators - begin(), end(), rbegin() and rend()
// begin()-- will access address of first element -- index-0
//rbegin()-- It returns a reverse iterator which points to the last element of the map. 
//           incrementing it means moving towards beginning of array
//end()-- will access address of next to the last element  -- index- n
//rend()-- It returns a reverse iterator pointing to the 
//         theoretical element right before the first element -- index -1

// System imposed memory-related limits on array on CP plateform it's 256MB so max size is n<=10^5
//General Possible size
//Global Array of (int,char,double --> 10^7 ) & (bool --> 10^8) as it's use HEAP
//In functions Array of (int,char,double --> 10^6 ) & (bool --> 10^7) as it's use STACK
//If not followed either Overflow(Segmentation fault) or Core Dumped

namespace zestfella{ //defined a new namespace "zestfella"
    int a= 100;
}

array <int,50> arr; //-- having all values as zero '0' as it is decleared global

struct List { // struct-- use to store heterogenous data.
              //It physically grouped list of different kind variables under one name in a block of memory.
    string name;
    int num;
    char a;
    float f;

    List(){//Default Constructor

    } 

    List(string name_,int num_,char a_,float f_){ //declearing and defining a "Parameterized Constructor"
        name = name_;
        num =num_;
        a=a_;
        f=f_;
    }
};

int main(){
    int a=20;
    cout<<a<<endl; //---> 20
    cout<<zestfella::a<<endl; //printing 'a' defined in namspace "zestfella" ---> 100

    //1st-Way -- Accessing every member to define it
    List L1;
    L1.name="Zestfella";
    L1.a='A';
    L1.num=20;
    L1.f= 3.45;

    //2nd-Way -- defining member using Constructor
    List L2("Zestfella",20,'A',3.45);

        //1st awy of defining array
    int arr1[100];

    //2nd way of defining array using container
    array <int,100> arr2; //-- having all value as Garbage Values

    array <int,100> arr3 ={1}; // index-0 is 1 and all rest are zero '0'
    array <int,100> arr4 ={0}; // all indexs are zero '0' as we set arr4[0]=0 and rest is automatically 0

    arr2.fill(1); // Every element of arr2 is now '1' & fill only works with container type decleration of array
    arr3.fill(5); // Every element of arr3 is '5' now.

    //Getting ith index of array
    int a = arr2.at(3); // it will get element at index-3

    //To print the array
    for(int i=0;i<100;i++){
        cout<<arr2.at(i)<<" ";
    }

    array <int,5> arr;
    arr.fill(4);

    //Iterating over array container using iterator
    //auto will automatically assign the data type which is pointer in this case
    for(auto it =arr.begin(); it!=arr.end(); it++){ 
        cout<<*it<<" ";
    }
    cout<<endl;
    
    //Iterating over array container using iterator in reverse order
    for(auto it= arr.rbegin(); it!=arr.rend(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //FOR-EACH Loop

    //Iterating forward over array using iterator
    //auto will automatically assign the data type which is value of element itself of arr
    for(auto it: arr){ 
        cout<<it<<" ";
    }

    vector <int> arr11; //Empty Vector of Size=0
    arr11.push_back(24); //pushback a value 24 at index 0 and now size = 1 -->{24}
    arr11.push_back(28); //pushback a value 20 at index 1 and now size = 2 -->{24,28}
    arr11.pop_back(); //Pop out last element of vector and size =1 -->{24}
    arr11.clear(); //Makes whole vector empty -->{}
    arr11.emplace_back(10); // It also pushback a value 10 at index 0 , FASTER than push_back() --> {10}

    vector <int> vec(5,0); // create a vector with 5 elements all 0 --> {0,0,0,0,0}

    vector <int> vec_copy(vec); //vec_copy is copy of vector vec
    vector <int> vec_copy_2(vec.begin(),vec.end()); // vec_copy_2 is also copy of vec
    vector <int> vec_copy_3(vec.rbegin(),vec.rend()); // vec_copy_2 is a reverse copy of vec
    vector <int> part(vec.begin(),vec.begin()+2); // "part" is a vector having element from index 0 to (0+2)-1 of vec --> {0,0}

    vector<int> v1 = { 1, 2, 3 };
    vector<int> v2 = { 4, 5, 6 };
    v1.swap(v2); // swapping the vectors v1 and v2 --> v1={4,5,6} v2={1,2,3}
    swap(v1,v2); // also swaps the vectors

    vector <vector <int> > matrix; // matrix is a vector have multiple vectors as rows, So it forms a 2D vector
    vector <int> row1 ={1,2,3};
    vector <int> row2 ={4,5,6};
    vector <int> row3 ={7,8,9};
    matrix.emplace_back(row1);
    matrix.emplace_back(row2);
    matrix.emplace_back(row3);

    // printing 2D vector --> Nested For Each Loop
    for(auto row:matrix){ // row is vector data-type iterator
        for(auto i:row)  // i is int data-type iterator as row store int data-type
            cout<<i<<" ";
        cout<<endl;
    }

    int m=10,n=20;
    // create a 2d vector mxn
    vector <vector <int>> matrix2(m, vector <int> (n,0)); //its a 2D vector of mxn with each element zero '0'
    //array of vectors
    vector<int> arr_[10]; // arr_ is an array of size 10 with data-type as vector of integers
    //vector of arrays
    vector <array <int,10>> matrix3; // matrix3 is a vector whose every element is an array of size 10 with data-type int

     //3D VECTORS
    vector <vector <vector <int>>> cube(10,vector <vector <int>> (10, vector <int> (10,0)));

    // printing 3D vector
    for(auto i:cube){
        for(auto j:i){
          for(auto k:j){
            cout<<k<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    cout<<endl;


}