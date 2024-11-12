#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    FILE *fp1;
    int i, j, hexaddr, start_hexaddr;
    char line[100], addr[100];

    fp1 = fopen("input.txt","r");

    if(fp1 == NULL){
        printf("No Text file\n");
        exit(0);
    }
    printf("Enter the actual starting address: ");
    scanf("%x", &start_hexaddr);
    while(fscanf(fp1,"%s",line) != EOF){
        if(line[0] == 'T'){
            for (i = 1, j = 0; i <= 6; i++, j++){
                addr[j] = line[i];
            }
            addr[j] = '\0';
            hexaddr = strtol(addr, NULL, 16); // Convert to hex number
            i = 9;
            while (line[i] != '\0') {
                printf("%x \t %c%c\n", hexaddr + start_hexaddr, line[i], line[i + 1]);
                hexaddr++;
                i += 2;
            }
        }
    }
    fclose(fp1);
}