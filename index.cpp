#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void admin();
void super_admin();
void user();
void super_admin_panel(string username);
void admin_panel(string username);
void user_panel(string username);

class loginRegister {
    public:
    string username, password, type;
    double balance;

    int login(string type, string fileName);
    int registration(string type, string fileName);
    int depositeMoney();
};

int main() {
    int choice;
    system("cls");
    cout<<"********************* Welcome to our Banking Managment System *************************\n";
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

int loginRegister :: registration(string type, string fileName) {
    system("cls");
    cout<<"******************************** "<< type << " " << " Registration ************************************\n";
    cout<<"\nChoose a username and password combination \n\n";
    cout<<"\n\t\tEnter username: ";
    cin>>username;
    cout<<"\t\tEnter password: ";
    cin>>password;
    cout<<"\t\tInitial Balance (min 50): ";
    cin>>balance;

    if (balance < 50) {
        cout << "Balance must be at least 50 tk"<<endl;
        cout<<"\t\tInitial Balance (min 50): ";
        cin>>balance;
    }

    ofstream reg(fileName, ios::app);
    reg<<username<<" "<<password<<" "<<balance<<endl;
    reg.close();
    return 1;
}

int loginRegister :: login(string type, string fileName) {
    string uname, pass;
    int is_exists=0;
    system("cls");
    cout<<"********************* "<< type << " login *************************\n\n";
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream input(fileName);

    while (input >> uname >> pass) {
        if(uname == username && pass == password) {
            is_exists = 1;
        }
    }
    input.close();

    if (is_exists) {
        return 1;
    } else {
        return 0;
    }
}

void super_admin() {
    int choice;
    system("cls");
    cout<<"********************************* Super Admin Panel *************************************\n";
    cout<<"\nOptions \n\n";
    for(int i=0; i<=86; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Login \n";
    cout<<"\t\t\t2. Go back \n";
    cout<<"\t\t\t3. Choose an option to continue: ";
    cin>>choice;

    loginRegister obj;
    switch (choice) {
        case 1: {
            int result = obj.login("Super Admin", "super_admin.txt");
            if (result) {
                string username = obj.username;
                super_admin_panel(username);
            } else {
                cout<<"Invalid credentials. Try again !\n";
                cout<<"Press enter to continue\n";
                cin.get();
                cin.get();
                obj.login("Super Admin", "super_admin.txt");
            }
            break;
        }
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
    cout<<"********************************* Admin Panel *************************************\n";
    cout<<"\nOptions \n\n";
    for(int i=0; i<=84; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Login \n";
    cout<<"\t\t\t2. Go back \n";
    cout<<"\t\t\t3. Choose an option to continue: ";
    cin>>choice;

    loginRegister obj;
    switch (choice) {
        case 1: {
            int result = obj.login("Admin", "admin.txt");
            if (result) {
                string username = obj.username;
                admin_panel(username);
            } else {
                cout<<"Invalid credentials. Try again !\n";
                cout<<"Press enter to continue\n";
                cin.get();
                cin.get();
                obj.login("Admin", "admin.txt");
            }
            break;
        }
        case 2: {
            int is_registered = obj.registration("Admin", "admin.txt");
            if (is_registered) {
                cout << "Registration Success";
                cout<<"Press enter to login\n";
                cin.get();
                cin.get();
                obj.login("Admin", "admin.txt");
            } else {
                cout<<"Something went wrong ! Try again.\n";
                obj.registration("Admin", "admin.txt");
            }
            break;
        }
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

    loginRegister obj;
    switch (choice) {
        case 1: {
            int result = obj.login("User", "users.txt");
            if (result) {
                string username = obj.username;
                user_panel(username);
            } else {
                cout<<"Invalid credentials. Try again !\n";
                cout<<"Press enter to continue\n";
                cin.get();
                cin.get();
                obj.login("User", "users.txt");
            }
            break;
        }
        case 2: {
            int is_registered = obj.registration("User", "users.txt");
            if (is_registered) {
                cout << "Registration Success";
                cout<<"Press enter to login\n";
                cin.get();
                cin.get();
                obj.login("User", "users.txt");
            } else {
                cout<<"Something went wrong ! Try again.\n";
                obj.registration("User", "users.txt");
            }
            break;
        }
        case 3:
            main();
            break;
        default:
            cout<<"Invalid choice";
            user();
    }
}

void accountHoldersList() {
    system("cls");
    cout<<"\tList of account holders\n";
    cout<<"\t-----------------------\n";
    ifstream file;
    file.open("users.txt"); 

    string user, pass, p;
    double bal;

    while (file >> user >> pass >> bal) {
        cout << "\n\tAccount holder: "<< user <<"\n\t Balance: " << bal <<endl;
        cout << "\t~~~~~~~~~~~~~~~~~~~~~";
    }
    cout<<"\n\n\tPress enter to go back to main menu\n";
}

void admin_panel(string username) {
    int choice;
    system("cls");
    cout<<"********************* Admin Panel *************************\n\n";
    cout << "Good evening " << username << ".\n\n";
    for(int i=0; i<=56; i++) cout<<"~";
    cout << "\n\nOptions-> \n\n";
    cout<<"\t1. Account holders list \n";
    cout<<"\t2. Find account \n";
    cout<<"\t3. Close or delete account \n";
    cout<<"\t4. Logout \n";
    cout<<"\t5. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
    case 1:
        accountHoldersList();
        cin.get();
        cin.get();
        admin_panel(username);
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

int depositeMoney() {
    ifstream file;
    ofstream out;

    string str, pass, p;
    short int status;
    double bal, totalBal=0, newBal=0;
    int updated = 1;

    file.open("users.txt"); 
    out.open("output.txt"); 

    cout << "\n\n\tEnter password: ";
    cin >> p;

    while (file >> str >> pass >> bal) {
        if (pass == p) {
            cout << "\n\tEnter deposite amount (min 20): ";
            cin >> newBal;

            if (newBal < 20) {
                cout << "\tDeposite amount must be at least 20 tk: ";
                cin >> newBal;
            }
            totalBal = bal+newBal;
            updated = 1;
        } else {
            totalBal = bal;
        }
        out << str << ' ' << pass << ' ' << totalBal << endl;
        totalBal = 0;
    }

    file.close();
    out.close();
    remove("users.txt");
	rename("output.txt", "users.txt");
    return updated;
}

int withdrawMoney() {
    ifstream file;
    ofstream out;

    string str, pass, p;
    short int status;
    double bal, totalBal=0, newBal=0;
    int updated = 0;

    file.open("users.txt"); 
    out.open("output.txt"); 

    cout << "\n\tEnter password: ";
    cin >> p;

    while (file >> str >> pass >> bal) {
        if (pass == p) {
            cout << "\n\tYour current balance is: "<<bal<<endl;
            cout << "\n\tEnter withdraw amount (min 20 tk in the account is required): ";
            cin >> newBal;

            if (newBal+20 > bal) {
                cout << "\n\tCan't withdraw. Amount is too long ! ";
                cout << "\n\tTry Again: ";
                cin >> newBal;
            }
            totalBal = bal-newBal;
            updated = 1;
        } else {
            totalBal = bal;
        }
        out << str << ' ' << pass << ' ' << totalBal << endl;
        totalBal = 0;
    } 

    file.close();
    out.close();
    remove("users.txt");
	rename("output.txt", "users.txt");
    return updated;
}

void user_panel(string username) {
    int choice;
    system("cls");
    cout<<"*********************User Panel*************************\n\n";
    cout << "Good evening " << username << ".\n\n";
    for(int i=0; i<=56; i++) cout<<"~";
    cout << "\n\nOptions-> \n\n";
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
    case 1: {
        int result = depositeMoney();
        if (result == 1) {
            cout << "\n\tDeposite Success\n";
            cout<<"\tPress enter to go back to main menu\n";
            cin.get();
            cin.get();
            user_panel(username);
        } else {
            cout << "\tInvalid password ! Press enter to try again. ";
            cin.get();
            cin.get();
            depositeMoney();
        }
        break;
    }
    case 2: {
        int result = withdrawMoney();
        if (result) {
            cout << "\n\tWithdraw Success\n";
            cout<<"\tPress enter to go back to main menu\n";
            cin.get();
            cin.get();
            user_panel(username);
        } else {
            cout << "\tInvalid password ! Press enter to try again. ";
            cin.get();
            cin.get();
            withdrawMoney();
        }
        break;
    }
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
    cout<<"\t2. Logout \n";
    cout<<"\t3. Choose an option to continue: ";
    cin>>choice;

    loginRegister obj;
    switch (choice) {
    case 1: {
        int is_registered = obj.registration("Admin", "admin.txt");
        if (is_registered) {
            cout << "Registration Success";
            cout<<"Press enter to login\n";
            cin.get();
            cin.get();
            obj.login("Admin", "admin.txt");
        } else {
            cout<<"Something went wrong ! Try again.\n";
            obj.registration("Admin", "admin.txt");
        }
        break;
    }
    case 2:
        main();
        break;
    default:
        cout<<"Invalid choice";
        super_admin_panel(username);
    }
}