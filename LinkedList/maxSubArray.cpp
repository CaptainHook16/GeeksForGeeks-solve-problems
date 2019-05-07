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

//METHOD 2 - Kadane’s algorithm
int Solution::maxSubArray(const vector<int> &A) {
    int max = INT_MIN;
    int count = 0;
    for(int i=0;i<A.size();++i){
        count += A[i];
        if(count > max){
            max = count;
        }
        if(count<0){
            count = 0;
        }
    }
    return max;
}
