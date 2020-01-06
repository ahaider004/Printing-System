#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class LoginManager
{
 public:
    string currentUser;
    string userNameAttempt;
    string passwordAttempt;
     LoginManager()
     {
        accessGranted = 0;
     }
     void viewStudentMenu() 
    {
   //   cout << "TEST" << endl;
    }
     void login()
     {
     //START
      cout << "Welcome to NAC Printing System!" << endl;
LABEL1:
      cout << "Please input your username." << endl;
      cout << "Username: ";
      cin >> userNameAttempt;

LABEL2:         
      if(find(userName.begin(), userName.end(), userNameAttempt) != userName.end()) //if entered username is in the list
      {
			  index = 0;
			  cout << "Password: ";
        cin >> passwordAttempt;

         for (int i = 0; i < 30; ++i) // finding index of userName
        {
            if (userName.at(i) != userNameAttempt)
            {
              index += 1;
            }
        	  else
        	  {
        		//cout << index << endl;
        	 	  break;
        	  }
      }
        if(passwordAttempt == passWord[index]) // if password is in the list
        {
          cout << "Login successful."; //go to student class
          //currentUser = userNameAttempt;
          viewStudentMenu(); 
        }
        else  // if password is not in the list
        {
          cout << "Login unsuccessful. Please try again." << endl;
          goto LABEL2;
        }
      }
      else if(userNameAttempt == "admin") // if entered username is admin 
      {
          cout << "Password: ";
          cin >> specialPasswordAttempt; 
          if (specialPasswordAttempt == "admin") 
          {
            cout << "Login sucessful." << endl; // go to admin class
            currentUser = userNameAttempt;
          }
        else
        {
            cout << "Login unsucessful. Please try again." << endl;
            goto LABEL1;
        }
      }

      else // if entered username is not in the list
      {
        cout << "Username not found. Please try again." << endl;
        goto LABEL1;
      }
     }


private:
    vector<string> userName = {"cyates", "cking", "mespinoza", "lguerra", "kschroeder", "lmaldonado", "asolomon", "rfrancis", "mgay", "dgrant", "lharris", "spatton", "bhull", "mhoward", "ccunningham", "tgood", "kjacobson", "bvalenzuela","sdaugherty", "hkrueger", "trichards","nruiz", "aliu", "sfrazier", "dfinley", "tterry", "eandersen", "bgreer", "iknight", "aflynn"};
    vector<string> passWord = {"moxa97", "tihi27", "lumo10", "yasa40", "waca61", "bupo41", "sino67", "zogu92", "zadu67", "dota36", "gufe15", "cudo77", "zito25", "hiva18", "jite79", "cute11", "koba39", "bipi40", "wobu60", "wami19", "gupe73", "himu52", "kare10", "seme37", "vaci37", "fulu86", "pive34", "kuti93", "tono59", "fiso29"};
    vector<string> balance = {"1000", "1000", "1000","1000", "1000", "1000","1000", "1000", "1000","1000", "1000", "1000","1000", "1000", "1000","1000", "1000", "1000","1000", "1000", "1000","1000", "1000", "1000","1000", "1000", "1000","1000", "1000", "1000"};
    vector<string> fullName = {"Camden Yates", "Claire King", "Michael Espinoza", "London Guerra", "Kaiya Schroeder", "Lillian Maldonado", "Armani SOlomon", "Rashad Francis", "Marcel Gay", "Diya Grant", "Leanna Harris", "Serenity Patton", "Braiden Hull", "Mila Howard", "Cordell Cunningham", "Trevon Good", "Kaden Jacobson", "Brycen Valenzuela", "Steven Daugherty", "Helen Krueger", "Theodore Richards", "Nash Ruiz", "Aryana Liu", "Sean Frazier", "Desmond Finley", "Tamia Terry", "Evie Andersen", "Brycen Greer", "Izabelle Knight", "Alessandra Flynn"};
    string specialPasswordAttempt; 
    bool accessGranted;
    int index = 0;
};
