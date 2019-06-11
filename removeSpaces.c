#include <stdio.h>


void removeSpaces(char* s){
    int pos=0;
    char *t;
    int n=0;
    
    //get length of string - one pass (still linear)
    for(t=s;*t!='\0';t++){
        n++;
    }
    //printf("%d",n);
    
    /*
    solving idea:
    scan the string, after each word i'll put a space in the string and continue scan the string
    if the current char is not a space it means that I found new word so i'll put a space in current position
    Note: I'll check that the current position is not the first char in the string because we dont want space at first (I assume)
    */
    for(int i=0;i<n;++i)
    {
        //check if current char is not space
        if(s[i] != ' ')
        {
            //IF WE DONT CARE PUT SPACE IN FIRST CHAR WE DONT NEED THIS CHECK CONDTION
            if(pos != 0 )
            {
                s[pos]=' ';
                pos++;
            }
                //now lets find the word
                int j=i;
                while(j<n && s[j]!=' ')
                {
                    s[pos]=s[j];
                    pos++;
                    j++;
                }
                i=j;
            
        }
    }
    //printf("%d",pos);
    
    //put a null terminator to indicates end of string - avoid letters we have already wrote to be written again
    s[pos]='\0';
}

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char s[] = "   I  l   ove ice    .";
    char s2[]="HI  H HHH   .";
    // printf("%s",s);
    removeSpaces(s2);
    printf("%s",s2);
    return 0;
}
