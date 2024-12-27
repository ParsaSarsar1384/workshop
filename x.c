#include<stdio.h>
#include<string.h>
//403106216
int main(){
    char command[100],key[1001],nothing[50],text[5001],turn[5001];
    short int num16[1000],total;
    while(1){   
        scanf("%s", command);
        if(strcmp(command,"exit") == 0)
            break;
        else if(strcmp(command,"encrypt") == 0){
            scanf("%s %s\n",nothing,key);
            fgets(text,5000,stdin);
            for (int i = 0; i < (int)strlen(text)-1; i++)
            {
                total += (int)text[i];
                num16[i] = (((int)text[i])^((int)key[i%((int)strlen(key))])); 
            }
            for (int i = 0; i < (int)strlen(text)-1; i++)
            {
                char temp[1000],x;
                sprintf(temp, "%x", num16[i]);  
                if (num16[i] <16){
                    strcat(temp,"0");
                    x = temp[0];
                    temp[0] = temp[1];
                    temp[1] = x;
                }
                 strcat(turn, temp);
            }
            char temp[1000],x,temp2[1000];
            sprintf(temp, "%x", total); 
            if (strlen(temp) > 4)
            {
                temp[3] = temp[3 + strlen(temp) - 4];
                temp[2] = temp[2 + strlen(temp) - 4];
                temp[1] = temp[1 + strlen(temp) - 4];
                temp[0] = temp[0 + strlen(temp) - 4];
            }
            
             if (strlen(temp) ==2)
            {
                temp[2] = temp[0];
                temp[3] = temp[1];
                temp[0]= '0';                    
                temp[1] ='0';
            }
            else if (strlen(temp) ==3)
            {
                temp[3]=temp[2];
                temp[2]=temp[1];
                temp[1]=temp[0];
                temp[0]= '0';
            }
            temp2[0] = temp[2];
            temp2[1] = temp[3];
            temp2[2] = temp[0];
            temp2[3] = temp[1];
            strcat(turn, temp2);
            printf("%s",turn);
        } 
        else if(strcmp(command,"decrypt") == 0){
            scanf("%s %s\n",nothing,key);
            fgets(text,5000,stdin);
            for (size_t i = 0; i < strlen(text)-3; i+=2)
            {
                int temp=0;
                if ((int)text[i] <= 97)
                    temp+= (((int)text[i]) -  87) * 16;
                else
                    temp+= (((int)text[i]) -  47) * 16;
                 if ((int)text[i+1] <= 97)
                    temp+= (((int)text[i+1]) - 87);
                else
                    temp+= (((int)text[i+1]) - 47);

                printf("(%d)", temp);
            }
            // for (int i = 1; i < 1000; i++)
            // {
            //     if ((253^i)==232)
            //     {
            //         printf(":%d:\n",i);  
            //     }  
            // }
            
        }
    }
    // encrypt with Bitkey123   
    //       Hello World! How Are You?
    return 0;
}
