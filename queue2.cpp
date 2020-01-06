#include <iostream> 
using namespace std; 
  
struct Queue2 {
    int front2, rear2, capacity2; 
    int* queue2; 
    Queue2(int c2) 
    { 
        front2 = rear2 = 0; 
        capacity2 = 1000; 
        queue2 = new int; 
    } 
  
    ~Queue2() { delete[] queue2; } 
  
    // function to insert an element 
    // at the rear of the queue 
    void queueEnqueue2(int data2) 
    { 
        // check queue is full or not 
        if (capacity2 == rear2) { 
            cout <<"Queue 2 is full"<<endl; 
            return; 
        } 
  
        // insert element at the rear 
        else { 
            queue2[rear2] = data2; 
            rear2++; 
        } 
        return; 
    } 
  
    // function to delete an element 
    // from the front of the queue 
    void queueDequeue2() 
    { 
        // if queue is empty 
        if (front2 == rear2) { 
            cout <<"Queue 2 is Empty"<<endl;  
            return; 
        } 
        else{
        while(front2!= rear2 ){
        // shift all the elements from index 2 till rear 
        // to the left by one 
              queueDisplay2();
             cout<<" Printed at Printer 2." <<endl;
            // decrement rear 
            rear2--;
        }
      }
        return; 
    } 

    // print queue elements 
    void queueDisplay2() 
    { 
        int i; 
        if (front2 == rear2) { 
            cout <<"Queue 2 is Empty"<<endl;  
            return; 
        } 
  
        // traverse front to rear and print elements 
        cout << endl;
        for (i = front2; i < rear2; i++) { 
            cout<<"Document "<< queue2[i]<<endl; 
        } 
        cout << endl;
        return; 
    } 
  
  
    // print front of queue 
    void queueFront2() 
    { 
        if (front2 == rear2) { 
            cout <<"Queue 2 is Empty"<<endl;  
            return; 
        } 
        cout <<endl;
        cout<<"The next Print job at Printer 2 is , "<< queue2[front2]; 
        cout <<endl;
        return; 
    } 
}; 
  
 