

#include<iostream> 
#include<climits>
#include "LoginCredentia.cpp"
#include "queue1.cpp"
#include "queue2.cpp"
#include "queue3.cpp"
#include "queue4.cpp"
#include "hash_table.cpp"

int main() 
{ 
    int choice;
    LoginManager app;
    app.login();
    cin.get();

    int balance=1000;

    Queue1 Printer1(1000);
    Queue2 Printer2(1000);
    Queue3 Printer3(1000);
    Queue4 Printer4(1000);
    
    int Key,Value;
    HashMap<int,int> *h = new HashMap<int, int>;    

    cout << "Balance = 1000 pages" << endl;
    cout << endl;
    cout << "Select an Option: "<<endl;
  
     do
   {
    cout<<"\n1.Add Documents\n";
    cout<<"2.View Documents\n";
    cout<<"3.Add Document to Printer Queue\n";
    cout<<"4.Print\n";
    cout<<"5.View Positions in Queue\n";
    cout<<"6.Logout \n";
    cout<<endl;
    cout<<"Enter choice : ";
    cin>>choice;
//--------------------menu option 1-----------------------------
            switch(choice)
            {
             case 1:
             cout << endl;

            cout<<"Enter Document Page Count: ";
            cin>>Value;
            if(Value > 15){
              cout<<"X-Too many Pages!"<<endl;
            }else{
            cout<<"Enter Document Name[1,2,3...n]: ";
            cin>> Key;
           
           
             cout << endl;
             cout<<"Document "<<Key<<" has been added"<<endl;
            cout <<"What do you want to do next?" << endl;
            }
                break;
//-------------------menu option 2------------------------------
            case 2:
            
            h->display();
            
            cout <<"What do you want to do next?" << endl;
                break;
//----------------------menu option 3---------------------------
            case 3:
            cout<<"Enter the document name: " << endl;
            cin>>Key;
            
            
            if (h->get(Key)== -1) {
               cout<<"Invalid Document Name "<<endl;
               continue;
            } else {
               cout<<"Document "<<Key<<" has been found. " <<endl;
               
            }
            cout << "Which printer do you want to use?" << endl;
                    int printer_selection1;
                    cin>>printer_selection1;
                    switch(printer_selection1){
                      case 1:
                      Printer1.queueEnqueue1(Key);
                      cout<<"Document " << Key << " with " << Value << " Pages is held at Printer 1" << endl;
                      cout<<endl;
                       h->deleteNode(Key); 
                       balance-=Value;
                       cout<<endl;
                       cout<<"New Balance: "<< balance;
                       cout<<endl;




                      break;

                      case 2:
                      Printer2.queueEnqueue2(Key);
                      cout<<"Document " << Key << " with " << Value << " Pages is held at Printer 2" << endl;
                      cout<<endl;
                      h->deleteNode(Key);
                      cout<<endl;
                      balance-=Value;
                      cout<<endl;
                       cout<<"New Balance: "<< balance;
 

                      break;

                      case 3:
                      Printer3.queueEnqueue3(Key);
                      cout<<"Document " << Key << " with " << Value << " Pages is held at Printer 3" << endl;
                      cout<<endl;
                      h->deleteNode(Key); 
                      cout<<endl;
                      balance-=Value;
                      cout<<endl;
                       cout<<"New Balance: "<< balance;


                      break;

                      case 4:
                      Printer4.queueEnqueue4(Key);
                      cout<<"Document " << Key << " with " << Value << " Pages is held at Printer 4" << endl;
                      cout<<endl;
                      h->deleteNode(Key); 
                      cout<<endl;
                      balance-=Value;
                      cout<<endl;
                       cout<<"New Balance: "<< balance;

                     


                      break;

                      default :
                      cout<<"Invalid choice. \n";

                  
                    }

            
                break;
//----------------menu option 4--------------------------------
            case 4:
                  cout<<endl;
                  cout<<"Select Printer[1,2,3,4]: ";
                  int printer;
                    cin>>printer;
                    switch(printer){
                      case 1:
                     
                      Printer1.queueDequeue1();
                      

                      

                      break;

                      case 2:

                      Printer2.queueDequeue2();
                      

                      break;

                      case 3:

                      Printer3.queueDequeue3();
                     

                      break;

                      case 4:
                      Printer4.queueDequeue4();
                      
                      
                     
                      break;

                      default :
                       cout<<"Invalid choice. \n";
                      


                  
                    }


                break;
//----------------menu option 5---------------------------------
            case 5: // view positions inside the queues 
            cout << "Which printer's positions do you want to see? ";
                    int printer_position;
                    cin>>printer_position;
                    switch(printer_position){
                      case 1:
                     
                     Printer1.queueDisplay1();
                     Printer1.queueFront1();

                      break;

                      case 2:

                     Printer2.queueDisplay2();
                     Printer2.queueFront2();

                      break;

                      case 3:
                      Printer3.queueDisplay3();
                      Printer3.queueFront3();

                      break;

                      case 4:
                     
                     Printer4.queueDisplay4();
                     Printer4.queueFront4();

                      break;

                  
                    }

            
                break;
//------------------menu option 6-------------------------------
            case 6:
                cout << "Logging out..." << endl << endl;

                cout << "Logout sucessfull!" << endl << endl;

                  app.login();
              
                break;  
                 
            default :
                cout<<"Invalid choice. \n";
            }
        
          
        }
   
         while(choice != 7);
          cout <<"All DONE";

} 