#include <iostream> 
//#include "LoginManager.cpp"
using namespace std;

struct Queue1 { 
    int front1, rear1, capacity1; 
    int* queue1;
    Queue1(int c1) 
    { 
        front1 = rear1 = 0; 
        capacity1 = 1000; 
        queue1 = new int; 
    } 
  
    ~Queue1() { delete[] queue1; } 
  
    // function to insert an element 
    // at the rear of the queue 
    void queueEnqueue1(int data1) 
    { 
        // check queue is full or not 
        //if the rear reaches the capacity than we can say the queue is full
        if (capacity1 == rear1) { 
            cout <<"Queue 1 is full"<<endl;  
            return; 
        } 
  
        // insert element at the rear 
        //if queue is empty 
        else { 
            queue1[rear1] = data1; //insert element at the rear position
            rear1++; //move the rear to next position
        } 
        return; 
    } 
  
    // function to delete an element 
    // from the front of the queue 
   void queueDequeue1() 
    { 
        // if queue is empty 
        //if rear and front are at the same position than we will not have any elements in the queue 
        if (front1 == rear1) { 
            cout <<"Queue 1 is Empty"<<endl;  
            return; 
        } 
        //tthe else statement will shift all the elements from index 2 till rear by shifting it to the left by 1
        else{
          //rear element is number of elements - 1 (which will give u the index)
          
        while(front1!= rear1 ){
        // shift all the elements from index 2 till rear 
        // to the left by one 
              queueDisplay1();
             cout<<" Printed at Printer 1." <<endl;
            // decrement rear 
            rear1--;
        }
      }
        return; 
    } 

   
 
  
    // print queue elements 
    void queueDisplay1() 
    { 
        int i; 
        if (front1 == rear1) { 
            cout <<"Queue 1 is Empty"<<endl;  
            return; 
        } 
        
        // traverse front to rear and print elements 
        cout << endl;
        for (i = front1; i < rear1; i++) { 
            cout<<"Document "<< queue1[i]  <<  endl; // << userName
        } 
        cout << endl;
        return; 
    } 
  
    // print front of queue 
    void queueFront1() 
    { 
        if (front1 == rear1) { 
            cout <<"Queue 1 is Empty"<<endl;  
            return; 
        } 
        cout <<endl;
        cout<<"The next Print job at Printer 1 is , "<< queue1[front1]; 
        cout <<endl;
        return; 
    } 

  
}; 
  
 