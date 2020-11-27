#include<iostream>
#include<string.h>

using namespace std;

bool authFail = false;
bool active = true;


// password validation

string passVal(char pass[20]) {

    int password = 0, no = 0, character = 0;

    int length = strlen(pass);

    if(length > 5 && length < 13) {
        for(int i=0; i < length; i++) {
            if(isupper(pass[i])) {
                password += 1;
            }
            if(isdigit(pass[i])) {
                no += 1;
            }
            if(ispunct(pass[i])) {
                character += 1;
            }
        }
         if(password >= 1 && no >= 1 && character >= 1) {
            active = false;
            authFail = false;
            return "done\n";

        } else {

            authFail = true;

            return "password error\npassword must have atleast 1 number, 1 uppercase letter and 1 punctuation mark\n";
        }
    } else {

        authFail = true;

        return "password must be 6-12 character\n";
    }
}




int main() {

    while(active) {

        if(authFail) {
            cout << "\nTry again\n";
        }

        cout << "[+] enter q to exit | Enter your password: ";

        typedef char str[20];

        str pass;

        cin.getline(pass, 20);

        if(strlen(pass) ==  1 && pass[0] == 'q') {

            cout << "Program is terminated\n";

            exit(1);
        }

        string val = passVal(pass);

        cout << val;

    }

    return 0;
}
