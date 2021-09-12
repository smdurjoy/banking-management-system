#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void admin();
void super_admin();
void user();
void super_admin_login();
void admin_login();
void user_login();
void registration(string text, string fileName, void (*login)());
void super_admin_panel(string username);
void admin_panel(string username);
void user_panel(string username);

int main() {
    int choice;
    system("cls");
    cout<<"*********************Welcome to our Banking Managment System*************************\n";
    cout<<"\nDashboard \n\n";
    for(int i=0; i<=84; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Super Admin \n";
    cout<<"\t\t\t2. Admin\n";
    cout<<"\t\t\t3. User\n";
    cout<<"\t\t\t4. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
        case 1:
            super_admin();
            break;
        case 2:
            admin();
            break;
        case 3:
            user();
            break;
        default:
            cout<<"Invalid choice";
            main();
    }

    return 0;
}

void super_admin() {
    int choice;
    system("cls");
    cout<<"*********************************Super Admin Panel*************************************\n";
    cout<<"\nOptions \n\n";
    for(int i=0; i<=84; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Login \n";
    cout<<"\t\t\t2. Go back \n";
    cout<<"\t\t\t3. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
        case 1:
            super_admin_login();
            break;
        case 2:
            main();
            break;
        default:
            cout<<"Invalid choice";
            super_admin();
    }
}

void admin() {
    int choice;
    system("cls");
    cout<<"*********************************Admin Panel*************************************\n";
    cout<<"\nOptions \n\n";
    for(int i=0; i<=84; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Login \n";
    cout<<"\t\t\t3. Go back \n";
    cout<<"\t\t\t4. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
        case 1:
            admin_login();
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
    system("cls");
    cout<<"********************************User Panel************************************\n";
    cout<<"\nOptions \n\n";
    for(int i=0; i<=84; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Login \n";
    cout<<"\t\t\t2. Register \n";
    cout<<"\t\t\t3. Go back \n";
    cout<<"\t\t\t4. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
        case 1:
            user_login();
            break;
        case 2:
            registration("User", "users.txt", user_login);
            break;
        case 3:
            main();
            break;
        default:
            cout<<"Invalid choice";
            user();
    }
}

void super_admin_login() {
    string username, password, uname, pass;
    int is_exists=0;
    system("cls");
    cout<<"*********************Super Admin login*************************\n\n";
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream input("super_admin.txt");

    while (input>>uname>>pass) {
        if(uname == username && pass == password) {
            is_exists = 1;
        }
    }
    input.close();

    if (is_exists) {
        super_admin_panel(username);
    } else {
        cout<<"Invalid credentials. Try again !\n";
        cout<<"Press enter to continue\n";
        cin.get();
        cin.get();
        super_admin_login();
    }
}

void admin_login() {
    string username, password, uname, pass;
    int is_exists=0;
    system("cls");
    cout<<"*********************Admin login*************************\n\n";
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
        admin_panel(username);
    } else {
        cout<<"Invalid credentials. Try again !\n";
        cout<<"Press enter to continue\n";
        cin.get();
        cin.get();
        admin_login();
    }
}

void user_login() {
    string username, password, uname, pass;
    int is_exists=0;
    system("cls");
    cout<<"*********************User login*************************\n\n";
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream input("users.txt");

    while (input>>uname>>pass) {
        if(uname == username && pass == password) {
            is_exists = 1;
        }
    }
    input.close();

    if (is_exists) {
        user_panel(username);
    } else {
        cout<<"Invalid credentials. Try again !\n";
        cout<<"Press enter to continue\n";
        cin.get();
        cin.get();
        user_login();
    }
}

void registration(string text, string fileName, void (*login)()) {
    string username, password;
    system("cls");
    cout<<"********************************"<< text << " " << "Registration************************************\n";
    cout<<"\nChoose a username and password combination \n\n";
    cout<<"\n\t\tEnter username: ";
    cin>>username;
    cout<<"\t\tEnter password: ";
    cin>>password;

    ofstream reg(fileName, ios::app);
    reg<<username<<" "<<password<<endl;
    reg.close();
    system("cls");
    cout<<"********************************"<< text << " " << "Panel************************************\n";
    cout<<"\nRegistration Successfull\n";
    cout<<"Press enter to login";
    cin.get();
    cin.get();
    (*login)();
}

void admin_panel(string username) {
    int choice;
    system("cls");
    cout<<"*********************Admin Panel*************************\n\n";
    cout << "Good evening " << username << ".\n\n";
    for(int i=0; i<=56; i++) cout<<"~";
    cout << "\n\nOptions-> \n";
    cout<<"\t1. Account holders list \n";
    cout<<"\t2. Find account \n";
    cout<<"\t3. Close or delete account \n";
    cout<<"\t4. Logout \n";
    cout<<"\t5. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
    case 1:
        cout<<"Coming soon :)";
        break;
    case 2:
        cout<<"Coming soon :)";
        break;
    case 3:
        cout<<"Coming soon :)";
        break;
    case 4:
        main();
        break;
    default:
        cout<<"Invalid choice";
        admin_panel(username);
    }
}

void user_panel(string username) {
    int choice;
    system("cls");
    cout<<"*********************User Panel*************************\n\n";
    cout << "Good evening " << username << ".\n\n";
    for(int i=0; i<=56; i++) cout<<"~";
    cout << "\n\nOptions-> \n";
    cout<<"\t1. Deposite Money \n";
    cout<<"\t2. Withdraw Money \n";
    cout<<"\t3. Transfer Money \n";
    cout<<"\t4. Take Loan \n";
    cout<<"\t5. Pay Loan \n";
    cout<<"\t6. Balance Enquiry \n";
    cout<<"\t7. Edit Account \n";
    cout<<"\t8. Logout \n";
    cout<<"\t9. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
    case 1:
        cout<<"Coming soon :)";
        break;
    case 2:
        cout<<"Coming soon :)";
        break;
    case 3:
        cout<<"Coming soon :)";
        break;
    case 4:
        cout<<"Coming soon :)";
        break;
    case 5:
        cout<<"Coming soon :)";
        break;
    case 6:
        cout<<"Coming soon :)";
        break;
    case 7:
        cout<<"Coming soon :)";
        break;
    case 8:
        main();
        break;
    default:
        cout<<"Invalid choice";
        user_panel(username);
    }
}

void super_admin_panel(string username) {
    int choice;
    system("cls");
    cout<<"*********************Super Admin Panel*************************\n\n";
    cout << "Good evening " << username << ".\n\n";
    for(int i=0; i<=62; i++) cout<<"~";
    cout << "\n\nOptions-> \n\n";
    cout<<"\t1. Create admin \n";
    cout<<"\t2. Account holders list \n";
    cout<<"\t3. Find account \n";
    cout<<"\t4. Close or delete account \n";
    cout<<"\t5. Logout \n";
    cout<<"\t6. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
    case 1:
        registration("Admin", "admin.txt", admin_login);
        break;
    case 2:
        cout<<"Coming soon :)";
        break;
    case 3:
        cout<<"Coming soon :)";
        break;
    case 4:
        cout<<"Coming soon :)";
        break;
    case 5:
        main();
        break;
    default:
        cout<<"Invalid choice";
        admin_panel(username);
    }
}

// void login(string fileName, void (*panel)(string));
// void login(string fileName, void (*panel)(string)) {
//     string username, password, uname, pass;
//     int is_exists=0;
//     system("cls");
//     cout<<"*********************Admin login*************************\n\n";
//     cout<<"Enter username: ";
//     cin>>username;
//     cout<<"Enter password: ";
//     cin>>password;

//     ifstream input(fileName);

//     while (input>>uname>>pass) {
//         if(uname == username && pass == password) {
//             is_exists = 1;
//         }
//     }
//     input.close();

//     if (is_exists) {
//         (*panel)(username);
//     } else {
//         cout<<"Invalid credentials. Try again !\n";
//         cout<<"Press enter to continue\n";
//         cin.get();
//         cin.get();
//         login(fileName, panel);
//     }
// }