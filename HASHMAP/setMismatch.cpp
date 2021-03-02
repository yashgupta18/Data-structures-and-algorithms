#include <iostream>
#include <vector>
#include <map>

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