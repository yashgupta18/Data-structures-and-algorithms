#include <iostream>
#include <vector>
#include <map>
// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

 
using namespace std;
void findErrorNums(vector<int>& nums) {
	vector<int> ans;
    int n=nums.size();
    map<int, bool> mp;
    int repeating=0, missing=0;
    for(int i=0; i<n; i++){
        if(mp.find(nums[i])==mp.end()){
            mp[nums[i]]=true;
        }else{
            ans.push_back(nums[i]);
        }
    }
    
    for(int i=1; i<=n; i++){
        if(mp.find(i) == mp.end()){
            ans.push_back(i);
        }
    }
    for (int i = 0; i < ans.size(); ++i)
	{
		/* code */
		cout<<ans[i]<<" ";
	}
	return;
}

int main(){
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	findErrorNums(nums);
	
}