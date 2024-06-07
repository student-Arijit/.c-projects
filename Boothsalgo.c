// This c project code prints the all step for booth's algorithm multiplication
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void heading();
int decimaltobinary(int);
int count(int);
int bitnum(int);
char* decimalToBinaryStatic(int, int);
void reverseStr(char *bin);
char* addBinary(char *a, char *b);
char* onesComplement(char *binary);
int main(void){
while(1){
  int ol;
  printf("Enter Choice - \n1. Run\n2. Stop\nChoice = ");  
  scanf("%d", &ol);
  switch(ol){
    case 1:{
    int num1, num2;
    printf("Enter two decimal integer no to perform Booth's Algorithm - \n");
    printf("Number1 = ");
    scanf("%d", &num1);
    printf("Number2 = ");
    scanf("%d", &num2);
    int bin1 = decimaltobinary(num1);
    int bin2 = decimaltobinary(num2);
    heading();
    int bit1 = count(bin1);
    int bit2 = count(bin2);
    int nwbit = bitnum(bit1);
    int A1 = 0;
    int Q1 = 0;
    int M2 = 1;
    int check1 = 1;
    int check0 = 0;
    char A[65], Q[65], Q_1[65], M[65], Mn[65], Mp[65], temp[65], check[2], checkn[2];
    strcpy(A, decimalToBinaryStatic(A1, nwbit));
    strcpy(Q, decimalToBinaryStatic(num1, nwbit));
    strcpy(Q_1, decimalToBinaryStatic(Q1, 1));
    strcpy(M, decimalToBinaryStatic(num2, nwbit));
    strcpy(Mn, onesComplement(M));
    strcpy(temp, decimalToBinaryStatic(M2, 1));
    strcpy(Mp, addBinary(Mn,temp));
    strcpy(check, decimalToBinaryStatic(check1, 1));
    strcpy(checkn, decimalToBinaryStatic(check0, 1));
    for(int i = 0; i <= nwbit ; i++){
        printf("step %d\t", i);
        if(i == 0)
            printf("%s\t%s\t%s\t%s\tInitialization", A, Q, Q_1, M);
        else{
            if(Q[nwbit-1] == check[0] && Q_1[0] == checkn[0]){
                strcpy(A, addBinary(A, Mp));
                int len = strlen(A);
                if(len > nwbit){
                    reverseStr(A);
                    A[len - 1] = '\0';
                    reverseStr(A);
                }
                printf("%s\t%s\t%s\t%s\tA = A - M", A, Q, Q_1, M);
                putchar('\n');
                Q_1[0] = Q[nwbit-1];
                for(int j = nwbit - 1; j != 0; j--)
                    Q[j] = Q[j - 1];
                Q[0] = A[nwbit - 1];
                for(int j = nwbit - 1; j != 0; j--)
                    A[j] = A[j - 1];
                printf("\t%s\t%s\t%s\t%s\tASR", A, Q, Q_1, M);
            }
            else if(Q[nwbit-1] == checkn[0] && Q_1[0] == check[0]){
                strcpy(A, addBinary(A, M));
                reverseStr(M);
                int len = strlen(A);
                if(len > nwbit){
                    reverseStr(A);
                    A[len - 1] = '\0';
                    reverseStr(A);
                }
                printf("%s\t%s\t%s\t%s\tA = A + M", A, Q, Q_1, M);
                putchar('\n');
                Q_1[0] = Q[nwbit-1];
                for(int j = nwbit - 1; j != 0; j--)
                    Q[j] = Q[j - 1];
                Q[0] = A[nwbit - 1];
                for(int j = nwbit - 1; j != 0; j--)
                    A[j] = A[j - 1];
                printf("\t%s\t%s\t%s\t%s\tASR", A, Q, Q_1, M);
            }
            else if(Q[nwbit-1] == Q_1[0]){
                Q_1[0] = Q[nwbit-1];
                for(int j = nwbit - 1; j != 0; j--)
                    Q[j] = Q[j - 1];
                Q[0] = A[nwbit - 1];
                for(int j = nwbit - 1; j != 0; j--)
                    A[j] = A[j - 1];
                printf("%s\t%s\t%s\t%s\tASR", A, Q, Q_1, M);
            }
        }
        printf("\n");
    }
    }
    break;
    case 2:
        exit(0);
    break;
    default:
        printf("!!Please enter the correct choice!!\n");
  }
}
    return 0;
}
void heading(void){
    printf("|step|");
    printf("A (Accumulator)|");
    printf("Q (Multiplier)|");
    printf("Q-1|");
    printf("M|");
    printf("Operation|");
    printf("\n");
    printf("Prints according to the order - ");
    printf("\n");
}
int decimaltobinary(int num){
    int rem, bin = 0, place = 1;
    while(num){  
        rem   = num % 2;  
        num   = num / 2;  
        bin   = bin + (rem * place);  
        place = place * 10;  
    } 
    return bin;
}
int count(int num){
    int count = 0;
    while(num){
        num = num/10;
        count++;
    }
    return count;
}
int bitnum(int num){
    if(num <= 4 )
        return 4;
    else{
        int power, flag = 1;
        for(int i = 2; flag != 0; i++){
            power = pow(2,i);
            if(power < num)
                flag = 1;
            else
                flag = 0;
        }
        return power;
    }
}
char* decimalToBinaryStatic(int decimal, int bitNumber){
    static char binString[65];  
    binString[bitNumber] = '\0';
    for (int i = 0; i < bitNumber; i++) {
        binString[bitNumber - 1 - i] = (decimal & (1 << i)) ? '1' : '0';
    }
    return binString;
}
void reverseStr(char *bin){
    strrev(bin);
}
char* addBinary(char *a, char *b){
    int len_a = strlen(a);
    int len_b = strlen(b);
    int maxLen = (len_a > len_b) ? len_a : len_b;
    reverseStr(a);
    reverseStr(b);
    while (strlen(a) < maxLen) strcat(a, "0");
    while (strlen(b) < maxLen) strcat(b, "0");
    char result[maxLen + 2];
    int carry = 0;
    for (int i = 0; i < maxLen; i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result[i] = sum % 2 + '0';
        carry = sum / 2; 
    }
    if (carry) result[maxLen++] = '1'; 
    result[maxLen] = '\0';
    reverseStr(result);
    return strdup(result);
}
char* onesComplement(char *binary){
    int len = strlen(binary);
    char result[len + 1]; 
    for (int i = 0; i < len; i++) {
        result[i] = (binary[i] == '0') ? '1' : '0'; 
    }
    result[len] = '\0'; 
    return strdup(result); 
}
