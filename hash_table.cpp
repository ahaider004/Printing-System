#include<iostream> 

using namespace std; 
  
//template for generic type 

//open address hash table 
//linear probing if the hash key has been occupied by another element we can use the formula to find the next free space (HashFunction(key)+n)%TABLE_SIZE
template<typename K, typename V> //template parameter allows us to pass a type as argument, it can adapt different type of data 


  
//Hashnode class 
//this will allow us to create objects for the templates

//template<typename K, typename V>
class HashNode 
{ 

    public: 
    V value; //create objects for  class/typename of V and K
    K key; 
      
    //Constructor of hashnode  
    //This to store all the elements of the hash table 
    HashNode(K key, V value) 
    { 
        this->value = value; //retrieve object's value hidden by variable value
        this->key = key; //retrieve object's key hidden by variable key
    } 
}; 
  
//template for generic type 
template<typename K, typename V> 
  
//creates a userdefined Hashmap class 
class HashMap 
{ 
    
    public:
    //hash element array 
    HashNode<K,V> **arr; //we are using class K, V  to create a hashnode which will initialize the objects key and value. We are also creating an array to store all the data
    //**arr is a Double pointer array ---> the first pointer is used to store the address of the variable and and 2nd pointer will store the address of the first pointer. we are using this bc we want to pass pointer as a paramter in a function and want to update it at the same time

    //the overall size of our hash table
    int capacity; 
    //current size of the hash
    int size; 
    //initial node 
    HashNode<K,V> *d1; 
  
  //  public: 
    HashMap()  //creating a constructor to initialize all the values 
    { 
        //Initial capacity of hash array 
        capacity = 500; 
        //initial size is 0
        size=0; 
        arr = new HashNode<K,V>*[capacity]; //calling constructor for hashnode then allocating space for each object and then call's the object's constructor. Creating 500 hashnode objects;
        //Initialise all elements of array as NULL 
        for(int i=0 ; i < capacity ; i++) 
            arr[i] = NULL; 
          
        //initial node with value and key -1 
        d1 = new HashNode<K,V>(-1, -1); 
    } 
    // This implements hash function to find index 
    // for a key 
    int hashCode(K key) 
    { 
        return key % capacity;  //whatever value we put in this functon will divide the value by the capacity so (500) then use the remainder as the index  for our key
    } 
      
    //Function to add key value pair 
    void insertNode(K key, V value) 
    { 
      //just like how we have a head in a linked this the following line of code will be our head for this hash table----> this line of code creates a temporary element to be inserted to hash table
        HashNode<K,V> *temp = new HashNode<K,V>(key, value); 
          
        // Apply hash function to find index for given key 
        //take value do the hash find the index and put it as key
        int hashIndex = hashCode(key); 
          
        //find next free space  
        //use our linear probing formula here 
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != key 
               && arr[hashIndex]->key != -1)  
        { 
          //increment hashIndex 
            hashIndex++; 
            //keep looking for the key using linear probing 
            //hash index is the remainder 
            hashIndex %= capacity; 
        } 
          
        //if new node to be inserted increase the current size 
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) 
            size++; //increment size 
        arr[hashIndex] = temp;  //store temo in array of hashindex
    } 
      
    //Function to delete a key value pair 
    V deleteNode(int key) 
    { 
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
          
        //finding the node with given key 
        while(arr[hashIndex] != NULL) 
        { 
            //if node found 
            if(arr[hashIndex]->key == key) 

            { 
              //mark the cell as the item to be deleted
                HashNode<K,V> *temp = arr[hashIndex]; 
                  
                //Insert d1 node here for further use 
                arr[hashIndex] = d1; 
                  
                // Reduce size 
                size--; 
                return temp->value; 
            }
            
            //this is the lienar probing fromula again ..IF there are more keys with same name then keep searching and deleting it if their r non then do nothing
            hashIndex++; 
            hashIndex %= capacity; 
  
        } 
          
        //If not found return null 
        return 0; 
    } 
      
    //Function to search the value for a given key 
    V get(int key) 
    { 
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
        int counter=0; 
        //finding the node with given key    
        while(arr[hashIndex] != NULL) 
        {    int counter =0; 
             if(counter++>capacity)  //to avoid infinite loop 
                return 0;         
            //if node found return its value 
            if(arr[hashIndex]->key == key) 
                return arr[hashIndex]->value; 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
        //If not found return null 
        return 0; 
    } 
      
    //Return current size  
    int sizeofMap() 
    { 
        return size; 
    } 
      
    //Return true if size is 0 
    bool isEmpty() 
    { 
        return size == 0; 
    } 
      
    //Function to display the stored key value pairs 
    void display() 
    { 
        for(int i=0 ; i<capacity ; i++) 
        { 
            if(arr[i] != NULL && arr[i]->key != -1) 
                cout << "Document:" << arr[i]->key <<" --->" 
                     <<"  Pages:"<< arr[i]->value <<  endl; 
        } 
    } 

     
}; 

