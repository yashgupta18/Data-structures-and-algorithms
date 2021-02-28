
// Q. https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> mp;
    int maxFreq;
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int x) {
        freq[x]++;
        maxFreq=max(maxFreq,freq[x]);
        mp[freq[x]].push(x);
    }
    
    int pop() {
        int ans=mp[maxFreq].top();mp[maxFreq].pop();
        freq[ans]--;
        if(mp[maxFreq].size()==0){
            mp.erase(maxFreq);
            maxFreq--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */