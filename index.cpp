#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void admin();
void user();
void admin_login();
void admin_register();
void user_login();
void user_register();

int main() {
    int choice;
    system("cls");
    cout<<"*********************Portals*************************\n";
    cout<<"1. Admin \n";
    cout<<"2. User\n";
    cout<<"3. Enter the choice: ";
    cin>>choice;

    switch (choice) {
        case 1:
            admin();
            break;
        case 2:
            user();
            break;
        default:
            cout<<"Invalid choice";
            main();
    }

    return 0;
}

void admin() {
    int choice;
    system("cls");
    cout<<"*********************Admin options*************************\n";
    cout<<"1. Login \n";
    cout<<"2. Register \n";
    cout<<"3. Go back \n";
    cout<<"4. Enter the choice: ";
    cin>>choice;

    switch (choice) {
        case 1:
            admin_login();
            break;
        case 2:
            admin_register();
            break;
        case 3:
            main();
            break;
        default:
            cout<<"Invalid choice";
            admin();
    }
}

void user() {
    int choice;
    cout<<"*********************User options*************************\n";
    cout<<"1. Login \n";
    cout<<"2. Register \n";
    cout<<"3. Go back \n";
    cout<<"4. Enter the choice: ";
    cin>>choice;

    switch (choice) {
        case 1:
            user_login();
            break;
        case 2:
            user_register();
            break;
        case 3:
            main();
            break;
        default:
            cout<<"Invalid choice";
            user();
    }
}

void admin_register() {
    string username, password;
    system("cls");
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ofstream reg("admin.txt");
    reg<<username<<" "<<password<<endl;
    system("cls");
    cout<<"Registration Successfull";
    main();
}

void admin_login() {
    string username, password, uname, pass;
    int is_exists=0;
    system("cls");
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream input("admin.txt");

    while (input>>uname>>pass) {
        if(uname == username && pass == password) {
            is_exists = 1;
        }
    }
    input.close();

    if (is_exists) {
        int choice;
        system("cls");
        cout<<"*********************Admin panel*************************\n\n";
        cout << "Welcome to the admin portal " << username << ".\n";
        cout << "Options-> \n";
        cout<<"\t1. Some option \n";
        cout<<"\t2. Go back \n";
        cout<<"\t3. Enter the choice: ";
        cin>>choice;

        switch (choice) {
        case 1:
            cout<<"Coming soon :)";
            break;
        case 2:
            main();
            break;
        default:
            cout<<"Invalid choice";
        }
    } else {
        cout<<"Invalid credentials";
    }
}

void user_register() {
    
}

void user_login() {

}