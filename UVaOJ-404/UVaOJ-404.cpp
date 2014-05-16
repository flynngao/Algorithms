#include <stdio.h>
#include <string.h>


#define MAXS 1000

char s[MAXS];

char fc[MAXS];

int num;

int ispf(char* string){

    
    for(int i = 0;i < num/2;i++){
        if(string[i] !=  string[num - i - 1]){
            return 0;     
        }
    }
    return 1;
}
int ismf(char* string){

    for(int i = 0;i < num/2;i++){
        if((!fc[string[i]] || (fc[string[i]] != string[num - i - 1])) ){
            return 0;     
        }
        
    }
    if(num%2 && fc[string[num /2 ]] != string[num /2 ]){
            return 0;
    }
    return 1;
}

int main(){

    int isp = 0;
    int ism = 0;
    memset(fc, 0, sizeof(fc));
    fc['A'] = 'A';
    fc['E'] = '3';
    fc['H'] = 'H';
    fc['I'] = 'I';
    fc['J'] = 'L';
    fc['L'] = 'J';
    fc['M'] = 'M';
    fc['O'] = 'O';
    fc['S'] = '2';
    fc['T'] = 'T';
    fc['U'] = 'U';
    fc['V'] = 'V';
    fc['W'] = 'W';
    fc['X'] = 'X';
    fc['Y'] = 'Y';
    fc['Z'] = '5';
    fc['1'] = '1';
    fc['2'] = 'S';
    fc['3'] = 'E';
    fc['5'] = 'Z';
    fc['8'] = '8';

    while(scanf("%s", s)!=EOF){

        num = strlen(s);
        isp=ispf(s);
        ism=ismf(s);
        if(isp && ism)
        {
            printf("%s -- is a mirrored palindrome.\n", s);
        }
        else if(isp)
        {
            printf("%s -- is a regular palindrome.\n", s);
        }
        else if(ism)
        {
            printf("%s -- is a mirrored string.\n", s);
        }
        else
        {
            printf("%s -- is not a palindrome.\n", s);
        }
        printf("\n");
    }
         
}