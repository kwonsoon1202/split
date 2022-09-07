#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> split(const string& s)

   vector<string> words;
    string::size_type i = 0;
    while (i != s.szie()){
        while(i != s.size() && isspace(s[i])) {
            ++i;
        }
        string::size_type j = i;
        while(j != s.szie() && !isspace(s[j])){
            ++j;

        }
    }
   return words;
}

int main() {

    return 0;
}
