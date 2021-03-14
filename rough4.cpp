#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>

#include<map>
#define MUL(a,b) a*b
using namespace std; 

bool solve(vector<vector<int>>& producers, vector<vector<int>>& consumers) {
    map<int, int> j;

    for (auto& p : producers) {
        j[p[0]] += p[2];
        j[p[1] + 1] -= p[2];
    }

    for (auto& p : consumers) {
        j[p[1] + 1] += p[2];
        j[p[0]] -= p[2];
    }

    int start = 0;

    for (auto& entry : j) {
        start += entry.second;

        if (start < 0) {
            return false;
        }
    }

    return true;
}

int main(){
	vector<vector<int>>& producers;
	vector<vector<int>>& consumers;

// producers = [
//     [0, 10, 5],
//     [5, 15, 10]
// ]
// consumers = [
//     [5, 10, 15],
//     [11, 15, 8]
// ]





}












