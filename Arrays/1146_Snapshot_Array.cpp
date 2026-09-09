#include <iostream>
using namespace std;
}#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s = "{[()]}";
    stack<char> st;

    for (char c : s) {

    cout << (st.empty() ? "Valid" : "Invalid")
    return 0;
}
