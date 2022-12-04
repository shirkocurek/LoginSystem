#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registration();
void forgot();


int main() 
{
    int c;
    cout<<"\t\t\t_________________________________________________________________________\n\n\n";
    cout<<"\t\t\t                          Welcome to the Login page!                     \n\n\n";
    cout<<"\t\t\t__________________________           MENU           _____________________\n\n\n";
    cout<<"                                                                               \n\n\n";
    cout<<"\t| Press 1 to LOGIN                         |"<<endl;
    cout<<"\t| Press 2 to REGISTER                      |"<<endl;
    cout<<"\t| Press 3 if FORGOT PASSWORD               |"<<endl;
    cout<<"\t| Press 4 to EXIT                          |"<<endl;
    cout<<"\n\t\t\t Please enter your choice: ";
    cin>>c;
    cout<<endl;

    switch (c)
    {
       case 1:
            login();
            break;

       case 2:
            registration();
            break;

       case 3:
            forgot();
            break;

       case 4:
            cout<<"\t\t\t Thank you! \n\n";
            break;

        default:
            system("clear");
            cout<<"\t\t\t Please select one of the options 1-4 \n"<<endl;
            main();



    }

}


    void login()
    { 
        int count;
        string userId, password, id, pass;
        system("clear");
        cout<<"\t\t\t Please enter username and password: "<<endl;
        cout<<"\t\t\t username: ";
        cin>>userId;
        cout<<"\t\t\t password: ";
        cin>>password;

        ifstream input("records.txt");

        while(input>>id>>pass)
        {
            if(id==userId && pass==password)
            {
                count=1;
                system("clear");
            }
        }
        input.close();

        if(count==1)
        {
            cout<<"\n\t\t\t"<<userId<<"\n\t\t\t Your LOGIN was successful! \n";
            main();
        }
        else{
            cout<<"\n\t\t\t LOGIN ERROR! \n\t\t\t Please check your username and password \n";
            main();
        }



    }

    void registration()
    {
        string ruserId,rpassword,rpass;
        system("clear");
        cout<<"\t\t\t Enter username : ";
        cin>>ruserId;
        cout<<"\t\t\t Enter password : ";
        cin>>rpassword;

        ofstream f1("records.txt" , ios::app);
        f1<<ruserId<<' '<<rpassword<<endl;
        system("clear");
        cout<<"\n\t\t\t Registration was successful! \n";
        main();

    }

    void forgot()
    {
        int option;
        system("clear");
        cout<<"\t\t\t Forgot Password? \n";
        cout<<"\t\t\t Press 1 to search your id by username "<<endl;
        cout<<"\t\t\t Press 2 to go back to the main menu "<<endl;
        cout<<"\t\t\t Enter your choice: ";
        cin>>option;
        switch(option)
        {
        case 1: {
            int count=0;
            string suserId, sId, spass;
            cout<<"\n\t\t\t Enter the last username: ";
            cin>>suserId;

            ifstream f2("records.txt");
            while (f2>>sId>>spass)
            {
                if(sId==suserId){
                   count=1; 
                }
            }
            f2.close();
            if(count==1)
            {
                cout<<"\n\n\t\t\t Your account is found!";
                cout<<"\n\n\t\t\t Your password is: "<<spass<<"\n\n";
                main();
            }
            else{
                cout<<"\n\t No account found by this username! \n";
                main();
            }
            break;
        }
           case 2:
           {
            main();
           }
           default :
               cout<<"\t\t\t Wrong choice! Please try again "<<endl;
               forgot();
        }
    }
