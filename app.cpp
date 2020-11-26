#include<iostream>
#include<string.h>
using namespace std;


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
            return "done";
        } else {
            return "password error\npassword must have atleast 1 number, 1 uppercase letter and 1 punctuation mark";
        }
    } else {
        cout << no << endl;
        return "password must be 6-12 character";
    }
}




int main() {

    cout << "Enter your password: ";

    typedef char str[15];

    str pass;

    cin.getline(pass, 13);

    string val = passVal(pass);

    cout << val;

    return 0;
}
