int Solution::maximumGap(const vector<int> &A) {
    if(A.size() == 0){
        return -1;
    }
    if(A.size()==1){
        return 0;
    }
    vector<pair<int,int>> pairs;
    for(int i=0;i<A.size();++i){
        pairs.push_back(make_pair(A[i],i));
    }
    sort(pairs.begin(),pairs.end());
    int n= pairs.size();
    int max_diff = 0;
    int right_index = pairs[n-1].second;
    for(int i=n-2;i>=0;--i){
        max_diff = max(max_diff,right_index - pairs[i].second);
        right_index = max(right_index,pairs[i].second);
    }
    return max_diff;
    
    // int max = 0;
    // int i,j;
    // for(i=0;i<A.size();++i){
    //     for(j=i+1;j<A.size();++j){
    //         if(A[i]<=A[j] && max<j-i)
    //         {
    //             max = j-i;
    //         }
    //     }
    // }
    // return max;
}
