#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
    FILE *fp1;
    int i, j, hexaddr;
    char line[100], addr[100];
    fp1 = fopen("input.txt","r");
    if(fp1 == NULL){
        printf("Error found in file\n");
        exit(0);
    }
    while(fscanf(fp1,"%s",line)!=EOF){
        if(line[0] == 'T'){
            for (i = 1, j = 0; i <= 6; i++, j++){
                addr[j] = line[i];
            }
            addr[j] = '\0';
            i = 9;
            hexaddr = strtol(addr,NULL,16);
            while(line[i] != '\0'){
                printf("%x \t%c%c\n",hexaddr, line[i], line[i+1]);
                hexaddr++;
                i += 2;
            }
        }
    }
    fclose(fp1);
}