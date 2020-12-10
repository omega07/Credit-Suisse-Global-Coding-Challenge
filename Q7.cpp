#include <bits/stdc++.h>

using namespace std;
string findSuspiciousUserId(int n, vector<vector<int>> v) {
    
    map<int,set<int>> mp;
    
    
    for(int i=0;i<n;i++) {
        for(int j=1;j<v[i].size();j++) {
            mp[v[i][0]].insert(v[i][j]);   
        }
    }
    
    
    set<int> cheaters;
    for(auto i : mp) {
        for(auto j : i.second) {
            if(mp[j].count(i.first)) {
                cheaters.insert(i.first), cheaters.insert(j);
            }
        }
    }
    int c = 0;
    bool ok = c < cheaters.size();
    while(ok) {
        c = (int)cheaters.size();
        for(auto i : mp) {
            int cntx = 0;
            for(auto j : i.second) {
                if(cheaters.count(j)) cntx++;
            }
            if(cntx > 1) cheaters.insert(i.first);
        }
        if(c == cheaters.size()) ok = false;
    }
 
 
    string ans = "";
    for(auto i : cheaters) {
        ans += to_string(i);
        ans += ",";
    }
    ans.pop_back();
    return ans;
}

vector<string> split(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<int> splitStringToInt(const string& str, char delim) {
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec) {
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

void printVector(vector<string> vec) {
    for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    string firstLine;
    getline(cin, firstLine);

    int numOfQuestions = strtol(firstLine.c_str(), NULL, 10);;

    string questionAndAnswerStr;
    getline(cin, questionAndAnswerStr);

    vector<vector<int>> questionAndAnswerVecOfVec;
    vector<string> questionAndAnswerVecByComma = split(questionAndAnswerStr, ',');

    for (vector<string>::const_iterator i = questionAndAnswerVecByComma.begin(); i != questionAndAnswerVecByComma.end(); ++i) {
        vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, ' ');
        questionAndAnswerVecOfVec.push_back(bankerPreferenceVecByAnd);
    }

    string result = findSuspiciousUserId(numOfQuestions, questionAndAnswerVecOfVec);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
