#include <string> 
bool comp(string a,string b){
    string ab = a+b;
    string ba = b+a;
    if(ab.compare(ba)>0){
        return true;//ab>ba
    }else{
        return false;
    }
}
 bool compareNum(string a, string b) {
            return a + b > b + a;
        }
string Solution::largestNumber(const vector<int> &A) 
{
    string res;
    vector<string> nums;
    for(auto x:A){
        nums.push_back(to_string(x));
    }
    sort(nums.begin(),nums.end(),comp);
    for(auto x:nums){
        res += x;
    }
    
    int pos = 0;
    while(res[pos]=='0' && pos+1<res.length()){
        pos++;
    }
    return res.substr(pos);
}


