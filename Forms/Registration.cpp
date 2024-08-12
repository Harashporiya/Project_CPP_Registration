#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class User {
    string username, userpassword;

public:
    User(string name, string password) {
        username = name;
        userpassword = password;
    }
    string getUserName() {
        return username;
    }

    string getUserPassword() {
        return userpassword;
    }
};

class UserManager {
    vector<User> users;
    vector<pair<string, string>> DataUser;

    void saveDataToFile() {
        ofstream file("userdata.txt");
        if (file.is_open()) {
            for (auto &user : DataUser) {
                file << user.first << " " << user.second << endl;
            }
            file.close();
        }
    }

    void loadDataFromFile() {
        ifstream file("userdata.txt");
        if (file.is_open()) {
            string username, password;
            while (file >> username >> password) {
                DataUser.push_back(make_pair(username, password));
                users.push_back(User(username, password));
            }
            file.close();
        }
    }

public:
    UserManager() {
        loadDataFromFile();
    }

    void Registration() {
        string username, userpassword;
        cout << "\t\t Enter Your Name: ";
        cin >> username;
        cout << "\t\t Enter Your Password: ";
        cin >> userpassword;

        User newUser(username, userpassword);
        users.push_back(newUser);
        DataUser.push_back(make_pair(username, userpassword));

        saveDataToFile(); 
        cout << "\t\t User Registered Successfully...." << endl;
    }

    bool loginUser(string name, string password) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUserName() == name && users[i].getUserPassword() == password) {
                cout << "\t\t Login Successfully..." << endl;
                return true;
            }
        }
        cout << "\t\t Invalid username or password" << endl;
        return false;
    }

    void showUser() {
        cout << "\t\t---User List---" << endl;
        for (int i = 0; i < users.size(); i++) {
            cout << "\t\t" << users[i].getUserName() << endl;
        }
    }

    void searchUser(string username) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUserName() == username) {
                cout << "\t\t User Found" << endl;
                return;
            }
        }
        cout << "\t\t User Not Found" << endl;
    }

    void deleteUser(string username) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUserName() == username) {
                users.erase(users.begin() + i);
                DataUser.erase(DataUser.begin() + i);
                saveDataToFile();  // Save after deletion
                cout << "\t\t User Removed Successfully...." << endl;
                return;
            }
        }
        cout << "\t\t User Not Removed Successfully...." << endl;
    }

    void printUserCredentials() {
        cout << "\t\t---Usernames and Passwords---" << endl;
        for (int i = 0; i < DataUser.size(); i++) {
            cout << "\t\tUsername: " << DataUser[i].first << ", Password: " << DataUser[i].second << endl;
        }
    }
};
int main() {
    UserManager userManager;
    int option;
    char choice;
    do {
        cout << "\t\t1. Register User " << endl;
        cout << "\t\t2. Login " << endl;
        cout << "\t\t3. Show User List " << endl;
        cout << "\t\t4. Search User " << endl;
        cout << "\t\t5. Delete User " << endl;
        cout << "\t\t6. Print User Credentials " << endl;
        cout << "\t\t7. Exit " << endl;
        cout << "\t\tEnter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            userManager.Registration();
            break;
        case 2: {
            string username, userpassword;
            cout << "\t\t Enter Username: ";
            cin >> username;
            cout << "\t\t Enter Password: ";
            cin >> userpassword;
            userManager.loginUser(username, userpassword);
            break;
        }
        case 3:
            userManager.showUser();
            break;
        case 4: {
            string username;
            cout << "\t\t Enter the username to find: ";
            cin >> username;
            userManager.searchUser(username);
            break;
        }
        case 5: {
            string username;
            cout << "\t\t Enter the username to delete: ";
            cin >> username;
            userManager.deleteUser(username);
            break;
        }
        case 6:
            userManager.printUserCredentials();
            break;
        case 7:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "\t\tInvalid choice!" << endl;
        }
        cout << "Do You Want to Continue [Yes/No] ? :";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
