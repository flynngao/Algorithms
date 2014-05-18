#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXS 1000


char wall[50][50];
char words[20][50];

int output[20][2];
int testcases;
int move[8][2]={ 
                 {0,1},   
                 {1,1},   
                 {1,0},   
                 {1,-1},  
                 {0,-1},  
                 {-1,-1}, 
                 {-1,0},  
                 {-1,1}
               };  //

int l = 0 ,c = 0 , w = 0;

void findwords(){
    for (int i = 0; i < w; ++i)
    {
        int len = strlen(words[i]);
        for (int j = 0; j < l; ++j)
        {
            for (int k = 0; k < c; ++k)
            {
                if (tolower(words[i][0]) == tolower(wall[j][k]))      
                {
                        
                        for (int m = 0; m < 8; ++m){

                            int has = 1;
                            
                            for (int h = 1; h < len; ++h){
                                // printf("%c", wall[j+move[i][0]*h][k+move[i][1]*h]);
                                // 
                                

                                if( (j+move[m][0]*len >= l && j+move[m][0]*len < 0) || 
                                    (k+move[m][0]*len >= c && k+move[m][0]*len < 0) || 
                                     tolower(words[i][h]) != tolower(wall[j+move[m][0]*h][k+move[m][1]*h])
                                   ){
                                    
                                    has = 0;
                                    break;
                                }

                                    
                            }
                            if(has){
                                output[i][0] = j+1;
                                output[i][1] = k+1;
                            }
                        }

                    
                }
            }
        }
    }

}


int main(){

    scanf("%d", &testcases);

    for(int i = 0; i < testcases ; i++){

        memset(output, 0, sizeof(output));

        
        scanf("%d %d",&l,&c);
        for(int j=0; j < l; j++){
            scanf("%s",wall[j]);
        }
        scanf("%d", &w);
        for (int j = 0; j < w; ++j){
            scanf("%s",words[j]);
        }

        findwords();
        for (int j = 0; j < w; ++j){
            printf("%d %d\n",output[j][0],output[j][1]);
        }

    }
         
}