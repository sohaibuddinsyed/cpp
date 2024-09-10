#include <iostream>
#include <vector>
using namespace std;

vector<string> splits(string &s) {
    vector<string> vs;
    int i = 0, n = s.length();
    string curr;
    while(i < n) {
        char ch = s[i];
        if(i == n - 1 || ch == ',') {
            vs.push_back(curr);
            curr.clear();
        } else curr += ch;
        i++;
    }

    for(string &s: vs) {
        int i = s.find_first_not_of(' '), j = s.find_last_not_of(' ');
        s = s.substr(i, j - 1 + 2);
    }

    return vs;
}

int main() {
    string s = "Apple Ball,  Joking !   , Kite,     a    ";
    splits(s);
    return 0;
}