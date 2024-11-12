#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int o = -1, opd, locctr = 0, start = 0, len = 0, s = -1, i, j = 0, flag = 0, size = 0;
char opcode[10], operand[10], label[10], t1[20], t2[20], t3[20];
FILE *input, *optab, *intermed, *symbol, *length;

struct OPTAB {
    char opcode[10], hexcode[10];
} ot[30];

struct SYMTAB {
    char label[10];
    int addr;
} st[30];

void readOptab() {
    while (1) {
        o++;
        fscanf(optab, "%s %s", ot[o].opcode, ot[o].hexcode);
        if (getc(optab) == EOF) break;
    }
}

void readLine() {
    strcpy(t1, "");
    strcpy(t2, "");
    strcpy(t3, "");
    fscanf(input, "%s", t1);
    if (getc(input) != '\n') {
        fscanf(input, "%s", t2);
        if (getc(input) != '\n') {
            fscanf(input, "%s", t3);
        }
    }
    if (strcmp(t1, "") != 0 && strcmp(t2, "") != 0 && strcmp(t3, "") != 0) {
        strcpy(label, t1);
        strcpy(opcode, t2);
        strcpy(operand, t3);
    } else if (strcmp(t1, "") != 0 && strcmp(t2, "") != 0 && strcmp(t3, "") == 0) {
        strcpy(label, "");
        strcpy(opcode, t1);
        strcpy(operand, t2);
    } else if (strcmp(t1, "") != 0 && strcmp(t2, "") == 0 && strcmp(t3, "") == 0) {
        strcpy(label, "");
        strcpy(opcode, t1);
        strcpy(operand, "");
    }
}

void main() {
    input = fopen("input.txt", "r");
    optab = fopen("optab.txt", "r");
    intermed = fopen("intermed.txt", "w");
    symbol = fopen("symtab.txt", "w");
    length = fopen("length.txt", "w");

    readOptab();

    fscanf(input, "%s %s %x", label, opcode, &opd);
    if (strcmp(opcode, "START") == 0) {
        start = opd;
        locctr = start;
        fprintf(intermed, "\t%s\t%s\t%x\n", label, opcode, opd);
        readLine();
    } 
    else {
        locctr = 0;
    }

    while (strcmp(opcode, "END") != 0) {
        fprintf(intermed, "%x\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        if (strcmp(label, "") != 0) {
            for (i = 0; i <= s; i++) {
                if (strcmp(st[i].label, label) == 0) {
                    printf("Error: Duplicate label.\n");
                    exit(0);
                }
            }
            s++;
            strcpy(st[s].label, label);
            st[s].addr = locctr;
        }

        flag = 0;
        for (i = 0; i <= o; i++) {
            if (strcmp(opcode, ot[i].opcode) == 0) {
                locctr += 0x3;
                size += 3;
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            if (strcmp(opcode, "WORD") == 0) {
                locctr += 0x3;
                size += 3;
            } else if (strcmp(opcode, "RESW") == 0) {
                locctr += (0x3 * atoi(operand));
            } else if (strcmp(opcode, "RESB") == 0) {
                locctr += atoi(operand);
            } else if (strcmp(opcode, "BYTE") == 0) {
                len = strlen(operand);
                if (operand[0] == 'C' || operand[0] == 'c') {
                    len -= 3;
                } else {
                    len = (len - 3) / 2;
                }
                locctr += len;
                size += len;
            }
        }

        readLine();
    }

    fprintf(intermed, "\t%s\t%s\t%s\n", label, opcode, operand);
    for(i = 0; i <= s; i++){
        fprintf(symbol,"%s\t%x",st[i].label, st[i].addr);
        if(i!=s){
            fprintf(symbol,"\n");
        }
    }
    printf("Length of the program: %x\n", locctr - start);
    fclose(input);
    fclose(optab);
    fclose(intermed);
    fclose(symbol);
    fclose(length);
}
