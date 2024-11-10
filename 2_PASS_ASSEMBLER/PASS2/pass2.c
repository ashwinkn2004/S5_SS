#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6;
char lenght[20], size[20], label[20], opcode[20], operand[20], startAddrs[20], t1[30], t2[30], t3[30], t4[30], address[30], ad[30];
int o = -1, s = -1;

struct SYMTAB{
    char label[20], addr[20];
}st[30];

struct OPTAB{
    char opcode[20], hexcode[20];
}ot[30];

void readOptab(){
    while(1){
        o++;
        fscanf(fp3, "%s %s", ot[o].opcode, ot[o].hexcode);
        if(getc(fp3) == EOF) break;
    }
}
void readSymtab(){
    while(1){
        s++;
        fscanf(fp2, "%s %s", st[s].label, st[s].addr);
        if(getc(fp2) == EOF) break;
    }
}

void readLine(){
    strcpy(t1,"");
    strcpy(t2,"");
    strcpy(t3,"");
    strcpy(t4,"");
    fscanf(fp1,"%s",t1);
    if(getc(fp1) != '\n'){
        fscanf(fp1,"%s",t2);
        if(getc(fp1) != '\n'){
            fscanf(fp1,"%s",t3);
            if(getc(fp1) != '\n'){
                fscanf(fp1,"%s",t4);
            }
        }
    }
    if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0 && strcmp(t4,"")!=0){
        strcpy(address,t1);
        strcpy(label,t2);
        strcpy(opcode,t3);
        strcpy(operand,t4);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0 && strcmp(t4,"")==0){
        strcpy(address,t1);
        strcpy(label,"");
        strcpy(opcode,t2);
        strcpy(operand,t3);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")==0 && strcmp(t4,"")==0){
        if(strcmp(t1,"END") == 0){
            strcpy(address,"");
            strcpy(label,"");
            strcpy(opcode,t1);
            strcpy(operand,t2);
        }
        else{
            strcpy(address,t1);
            strcpy(label,"");
            strcpy(opcode,t2);
            strcpy(operand,"");
        }
    }
}


void main(){
    fp1 = fopen("intermed.txt", "r");
    fp2 = fopen("symtab.txt", "r");
    fp3 = fopen("optab.txt", "r");
    fp4 = fopen("length.txt", "r");
    fp5 = fopen("assmlist.txt", "w");
    fp6 = fopen("objcode.txt", "w");

    fscanf(fp4,"%s %s",lenght, size);
    readOptab();
    readSymtab();
    fscanf(fp1, "%s %s %s",label, opcode, operand);
    strcpy(startAddrs,operand);
    if(strcmp(opcode,"START") == 0){
        fprintf(fp5,"\t%s\t%s\t%s\n",label, opcode, operand);
        fprintf(fp6,"H^%s  ^00%s^0000%s\n",label, operand, lenght);
        fprintf(fp6,"T^00%s^%x",operand, atoi(size));
        readLine();
    }
    while (strcmp(opcode,"END") != 0){
        if(strcmp(opcode, "BYTE") == 0){
            sprintf(ad,"%x",operand[2]);
            fprintf(fp5,"%x\t%s\t%s\t%s\t%s\n",address, label, opcode, operand, ad);
            fprintf(fp6,"^%s",ad);
        }
        else if(strcmp(opcode, "WORD") == 0){
            sprintf(ad,"%x",atoi(operand));
            fprintf(fp5,"%x\t%s\t%s\t%s\t00000%s\n",address, label, opcode, operand, ad);
            fprintf(fp6,"^00000%s",ad);
        }
        else if(strcmp(opcode, "RESB") == 0 || strcmp(opcode,"RESW") == 0){
            fprintf(fp5,"%x\t%s\t%s\t%s\n",address, label, opcode, operand);
        }
        else{
            int i = 0, j = 0;
            while(strcmp(opcode,ot[i].opcode)!=0){
                i++;
            }
            while(strcmp(operand,st[j].label)!=0){
                j++;
            }
            fprintf(fp5,"%x\t%s\t%s\t%s\t%s%s\n",address, label, opcode, operand,ot[i].hexcode, st[j].addr);
            fprintf(fp6,"^%s%s",ot[i].hexcode, st[j].addr);
        }
        readLine();
    }
    fprintf(fp5,"\t%s\t%s\t%s\n", label, opcode, operand);
    fprintf(fp6,"\nE^00%s",startAddrs);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);
}