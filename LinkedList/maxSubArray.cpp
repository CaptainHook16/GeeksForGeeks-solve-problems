#include <limits.h>
//METHOD 1 - DYNAMIC PROGRAMMING:

int Solution::maxSubArray(const vector<int> &A) {
    vector<int> c;
    c.push_back(A[0]);
    
    for(int i=1;i<A.size();++i){
        c.push_back(max(c[i-1]+A[i],A[i]));
    }
    int max = INT_MIN;
    for(auto x:c){
        if(x>max){
            max = x;
        }
    }
    return max;
}
