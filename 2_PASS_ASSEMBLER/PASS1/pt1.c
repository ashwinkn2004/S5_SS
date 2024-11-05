#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *fp1, *fp2, *fp3, *fp4;
int o = -1, start, locctr, i, s = -1, flag, len, size, opd;
char label[30], opcode[30], t1[30], t2[30], t3[30], operand[30];

struct OPTAB{
    char opcode[10], hexcode[10];
}ot[30];

struct SYMTAB{
    char label[30];
    int addr;
}st[30];

void readOptab(){
    while(1){
        o++;
        fscanf(fp2,"%s %s",ot[o].opcode,ot[o].hexcode);
        if(getc(fp2) == EOF) break;
    }
}

void readLine(){
    strcpy(t1,"");
    strcpy(t2,"");
    strcpy(t3,"");
    fscanf(fp1,"%s",t1);
    if(getc(fp1) != '\n'){
        fscanf(fp1,"%s",t2);
        if(getc(fp1) != '\n'){
            fscanf(fp1,"%s",t3);
        }
    }
    if(strcmp(t1,"") != 0 && strcmp(t2,"") != 0 && strcmp(t2,"") != 0){
        strcpy(label,t1);
        strcpy(opcode,t2);
        strcpy(operand,t3);
    }
    if(strcmp(t1,"" ) != 0 && strcmp(t2,"")  != 0 && strcmp(t2,"" ) == 0){
        strcpy(label,"");
        strcpy(opcode,t1);
        strcpy(operand,t2);
    }
    if(strcmp(t1,"")  != 0 && strcmp(t2,"")  != 0 && strcmp(t2,"")  != 0){
        strcpy(label,"");
        strcpy(opcode,t1);
        strcpy(operand,"");
    }
}

void main(){
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("intermed.txt", "w");
    fp4 = fopen("symtab.txt", "w");

    readOptab();

    fscanf(fp1,"%s %s %x", label, opcode, &opd);
    if(strcmp(opcode,"START") == 0){
        start = opd;
        locctr = start;
        fprintf(fp3,"\ts\t%s\t%x\n",label, opcode, opd);
        readLine();
    }
    else{
        locctr = 0;
    }
    while(strcmp(opcode,"END")!= 0){
        fprintf(fp3,"%x\t%s\t%s\t%s\n", locctr, label, opcode, operand);
        if(strcmp(label,"")!=0){
            for(i = 0; i <= s; i++){
                if(strcmp(st[i].label,label) == 0){
                    printf("Duplicate\n");
                    exit(0);
                }
            }
            s++;
            strcpy(st[s].label,label);
            st[s].addr = locctr;
        }
        flag = 0;
        for(i = 0; i <= o; i++){
            if(strcmp(ot[i].opcode,opcode) == 0){
                locctr += 0x3;
                size += 3;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            if(strcmp(opcode,"WORD") == 0){
                locctr += 3;
                size += 3;
            }
            else if(strcmp(opcode,"RESW") == 0){
                locctr += (0x3*atoi(operand));
            }
            else if(strcmp(opcode,"RESB") == 0){
                locctr += atoi(operand);
            }
            else if(strcmp(opcode,"BYTE") == 0){
                len = strlen(operand);
                if(operand[0] == 'C' || operand[0] == 'c'){
                    len -= 3;
                }
                else{
                    len = (len-3)/2;
                }
                locctr += len;
                size += len;
            }
        }
        readLine();
    }
    fprintf(fp3,"\ts\t%s\t%s\t%s\n",label,opcode,operand);
    for(i = 0; i <= s; i++){
        fprintf(fp4,"%s\t%x\n",st[i].label,st[i].addr);
        if(i!=s){
            fprintf(fp4,"\n");
        }
    }
    printf("Length = %x",locctr - start);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}