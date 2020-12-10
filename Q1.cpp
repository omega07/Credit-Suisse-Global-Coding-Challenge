#include <bits/stdc++.h>

using namespace std;

int findMaxProfit(int n, vector<int> a) {
    int suffmax[n], prefmin[n];
    for(int i=n-1;i>=0;i--) {
        suffmax[i] = a[i];
        if(i != n-1) suffmax[i] = max(suffmax[i],suffmax[i+1]);
    }
    for(int i=0;i<n;i++) {
        prefmin[i] = a[i];
        if(i) prefmin[i] = min(prefmin[i],prefmin[i-1]);
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans = max(suffmax[i]-prefmin[i],ans);
    }
    return ans;
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

int main() {
    string firstLine;
    getline(cin, firstLine);

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    int numOfPredictedDays = firstLineVec[0];
    vector<int> predictedSharePrices(firstLineVec.begin()+1, firstLineVec.end());


    int result = findMaxProfit(numOfPredictedDays, predictedSharePrices);

    // Do not remove this line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
