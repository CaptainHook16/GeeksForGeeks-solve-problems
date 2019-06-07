#include<stdio.h>
#include <iostream> 
using namespace std; 

void removeSpaces(string &str){
    int i=0;
    int pos=0;
    int n = str.length();
    
    while(i<n && str[i]==' '){
        i++;
    }
    
    bool space_found=false;
    while(i<n)
    {
        if(str[i] !=' ')
        {
            if(pos-1>=0 && str[pos-1] == ' ' && 
            (str[i]==',' || str[i] == '.' || str[i]=='?'))
            {
                str[pos-1] = str[i];
                i++;
            }
            else{
                str[pos] = str[i];
                i++;
                pos++;
            }
            space_found = false;
        }
        else if(str[i]== ' '){
            if(space_found == false){
                space_found = true;
                str[pos]=' ';
                pos++;
            }
            i++;
        }
    }
    //now we need to delete the rest 
    str.erase(str.begin() + pos , str.end());
    cout<<pos;
    
    
    
}

int main()
{
    string str = "   Hello Geeks     . Welcome   to"
                 "  GeeksforGeeks   .    "; 
            
    string s2 = "  .";
  
    removeSpaces(s2); 
  
    cout << s2; 

	return 0;
}
