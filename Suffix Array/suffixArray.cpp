#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>

#include<map>
using namespace std; 

struct suffix {
    int first;
    int second;
    int index;
}


int makeSuffixArray(string s){
    int SA[s.length]; // Suffix Array

    int P[][]; // P[i][j] denotes rank of suffix at position 'j' when all suffixes are sorted by their first '2^i' characters

    string str=''; // initial string, 1 based indexing

    int POWER[]; //array of powers of 2, POWER[i] denotes 2^i


    int suffix L[]; // Array of Tuples

    int N = str.length;

    for(int i=0; i<N; i++){
        P[0][i] = str[i] - 'a' // Give initial rank when suffixes are sorted by their first 2^0 = 1 character.
    }

    step = 1;

    for (int i = 1; POWER[i-1]<N; i++; step++)
        for (int j = 1 j<N; j++){
            L[j].index = j
            L[j].first = P[i-1][j]
            L[j].second = (j+POWER[i-1]<=n ? P[i-1][j+POWER[i-1]] : -1)
        }
        sort(L);

        for (j = 1; j<N; j++){
            P[i][L[j].index] = ((j>1 and L[j].first==L[j-1].first and L[j].second==L[j-1].second) ? P[i][L[j-1].index] : j) 
            /*Assign same rank to suffixes which have same number in the first and second fields of their respective tuples.*/
        }
    step = step - 1;
}

int main() 
{ 
    string s="abbabba";
    makeSuffixArray(s);
    return 0; 
} 