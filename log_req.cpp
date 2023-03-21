#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool IsLoggedIn(){
    string username, password, un, pw;
    cout<<"Enter your username: "; cin>>username;
    cout<<"Enter your password: "; cin>>password;

    ifstream read( username +".txt");

    getline(read, un);
    getline(read, pw);
    if(un == username && pw == password){
        return true;
    }
    else{
        return false;
    }
};


int main(){
    int choice;
    cout<<"\n\n\tWelcome!"<<endl
        <<"1. Register"<<endl
        <<"2. Login"<<endl
        <<"3. exit"<<endl
        <<"Enter your choice: "; cin>>choice;
    
    if(choice == 1){
        string username, password;

        cout<<"Enter new username: "; cin>>username;
        cout<<"Enter new password: "; cin>>password;

        ofstream MyFile(username+".txt");

        MyFile<<username<<endl<<password<<endl;
        MyFile.close();
        
        main();
    }
    else if(choice == 2){
        bool stats = IsLoggedIn();
        if(stats){
            cout<<"Logged in successfully"<<endl;
            system("pause");
            return 1;
        }
        else if(!stats){
            cout<<"Your credentials are false!"<<endl;
            system("pause");
            return 0;
        }
    }
    else if(choice == 3){
        exit(0);
    }
    else{
        cout<<"\nDo it again!"<<endl;
        main();
    }
}