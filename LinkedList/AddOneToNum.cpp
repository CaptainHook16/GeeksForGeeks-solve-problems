vector<int> Solution::plusOne(vector<int> &A) {
    //cout<<"hi";
    int pos = 0;
    while(A[pos]==0 && pos+1<A.size()){
        pos++;
    }
    
    int n = A.size();
    vector<int> res;
    int carry = 1;
    int i=n-1;
    //cout<<i;
    int sum;
    while(i>=pos && carry!=0){
       sum = A[i]+carry;
       //cout<<i;
       carry = sum/10;
       //cout<<sum%10;
       res.push_back(sum%10);
       i--;
    }
    //cout<<i;
    while(i>=pos){
        res.push_back(A[i]);
        //cout<<A[i];
        i--;
    }
    
    //cout<<"hi";
    if(carry==1){
        res.push_back(1);
    }
    
    int j=res.size()-1;
    int temp;
    i=0;
    //cout<<res[j];
    //res[0] = res[1];
    while(i<j){
        temp = res[i];//0
        //cout<<res[j];
        res[i]=res[j];//9
        res[j]=temp;//0
        i++;
        j--;
    }
    
    
    return res;
    
   
}
