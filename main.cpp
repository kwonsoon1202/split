#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin; using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> split(const string& s)
{
   vector<string> words;
    string::size_type i = 0;
    while (i != s.size()){
        while(i != s.size() && isspace(s[i])) {
            ++i;
        }
        string::size_type j = i;
        while(j != s.size() && !isspace(s[i])){
            ++j;

        }

    if (i != j){
        words.push_back(s.substr(i, j-i));
        i = j;
    }
}
   return words;
}

string::size_type width(const vector<string>& words)
{
    string::size_type maxLen = 0;
    for(vector<string>::const_iterator it = words.cbegin(); it != words.cend(); ++ it){
        maxLen = std::max(maxLen, it->size());
    }
    return maxLen;
}

vector<string> frame(const vector<string> words)
{
    vector<string> frameWords;

    string::size_type maxLen = width(words);

    string boarder(maxLen + 4, '*');
    frameWords.push_back(boarder);
    for(vector<string>::const_iterator it = words.cbegin(); it != words.cbegin(); ++it){
        frameWords.push_back("*" + *it + string(maxLen - it->size(), ' ') + "*");
    }
    frameWords.push_back(boarder);

    return frameWords;
}
int main() {
    string s;

    while(std::getline(cin, s)){
        vector<string> words = ::split(s);

        words = frame(words);

        for (vector<string>::const_iterator it = words.cbegin(); it != words.cend(); ++ it)
            cout << * it << endl;
    }
    return 0;
}
