#include<stdio.h>
#include <iostream> 
using namespace std; 
void removeSpaces(string& s)
{
    int pos = 0;
    int n = s.length();
    for(int i=0;i<n;i++){
        if((s[i]=='.' || s[i]==',' || s[i]=='?') && pos>=1 && s[i-1]==' '){
            s[pos] = s[i];
            pos++;
            
        }else if(s[i] != ' '){
            if(pos != 0){
                s[pos++] = ' ';
            }
            int j = i;
            while(j<n && s[j]!=' '){
                s[pos++] = s[j++];
            }
            i=j;
        }
    }
    s.erase(s.begin()+pos,s.end());
}
// void removeSpaces(string &str){
//     int i=0;
//     int pos=0;
//     int n = str.length();
    
//     while(i<n && str[i]==' '){
//         i++;
//     }
    
//     bool space_found=false;
//     while(i<n)
//     {
//         if(str[i] !=' ')
//         {
//             if(pos-1>=0 && str[pos-1] == ' ' && 
//             (str[i]==',' || str[i] == '.' || str[i]=='?'))
//             {
//                 str[pos-1] = str[i];
//                 i++;
//             }
//             else{
//                 str[pos] = str[i];
//                 i++;
//                 pos++;
//             }
//             space_found = false;
//         }
//         else if(str[i]== ' '){
//             if(space_found == false){
//                 space_found = true;
//                 str[pos]=' ';
//                 pos++;
//             }
//             i++;
//         }
//     }
//     //now we need to delete the rest 
//     str.erase(str.begin() + pos , str.end());
//     cout<<pos;
    
    
    
// }

int main()
{
    string str = "   Hello Geeks     . Welcome   to"
                 "  GeeksforGeeks   .    "; 
            
    string s2 = "  .";
  
    removeSpaces(s2); 
  
    cout << s2; 

	return 0;
}
