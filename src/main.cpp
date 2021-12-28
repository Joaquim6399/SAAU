#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

struct User {
        string username;
        string password;
};
bool verifyUsername(string username, vector<User> db);
bool verifyCredentials(User user, vector<User> db);

int main() {

    vector<User> userList;

    string username, password;
    User user1;
    user1.username = "joaquim6399";
    user1.password = "butano";

    userList.push_back(user1);

    cout << "Enter option:\n";
    cout << "1.Login" << endl;
    cout << "2.Sign Up" << endl;

    cout << endl;
    int option;

    do {

    cin >> option;
        switch(option) {
            case 1:
            {
                cout << "LOGIN\n";
                cout << "Username: ";
                cin >> username;
                User userToLogin;
                userToLogin.username = username;

                cout << "Password: ";
                cin >> password;
                userToLogin.password = password;

                if(verifyCredentials(userToLogin, userList))
                    cout << "Login successful" << endl;
                else 
                    cout << "Wrong credentials" << endl;

                break;
            }
            case 2:        
            {
                cout << "SIGN UP" << endl;
                cout << endl;
                User userToSignUp;

                cout << "Enter a username" << endl;
                
                while(cin >> username && verifyUsername(username, userList)) {

                    cout << "Username already taken." << endl;
                }

                userToSignUp.username = username;

                cout << "Enter password: " << endl;
                cin >> password;

                userToSignUp.password = password;

                userList.push_back(userToSignUp);

                cout << "User added successfully" << endl;
            }
        }
    } while(option >= 0);
    cout << endl;
    return 0;
}

bool verifyCredentials(User user, vector<User> db) {
    bool match = false;

    for(auto element : db) {
       if(element.username == user.username && element.password == user.password) {
           match = true;
           return match;
       }
    }

    return match;
}

bool verifyUsername(string username, vector<User> db) {
    bool match = false;

    for(auto i : db) {
        if(i.username == username) {
            match = true;
            return match;
        }
    }

    return match;
}