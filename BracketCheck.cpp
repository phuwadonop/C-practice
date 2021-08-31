#include<stack>
#include<iostream>
#include<string.h>

using namespace std;

int type(char);
void checkBracket(string);

int main () {
    stack<char> storange;

    string str;

    cin >> str;

    checkBracket(str);


}

int type(char x){
    if( x == '{' || x == '[' || x == '(') return 1;
    else if (x == '}' || x == ']' || x == ')') return 2;
    else return 0;
}

void checkBracket(string str){
    bool error = false;
    stack<char> st;
    for(int i = 0 ; i < str.length() ;i++)
    {   
        if(type(str.at(i)) == 1) {
            st.push(str.at(i));
        }
        else if (type(str.at(i)) == 2) {
            if(!st.empty()){
                if( ((str.at(i) == '}') && (st.top() == '{')) || 
                    ((str.at(i) == ']') && (st.top() == '[')) || 
                    ((str.at(i) == ')') && (st.top() == '(')))
                {
                    st.pop();
                }
                else {
                    error = true;
                    break;
                }
            }
            else {
                error = true;
                break;
            }
        }
    }
    if (error == true || st.empty() == false) cout << "Error";
    else cout << "Pass";
}

