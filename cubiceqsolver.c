#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex.h>
#include<string.h>
#include<stddef.h>
void line();
int main(void){
    printf("##Developer - Arijit Chowdhury##\nThis software can calculate the roots of cubic equation only!!!\nPoint Numbers are not allowed integers only!!\n");
    while(1){
        line();
        char ol[64];
        printf("\nEnter your choice - \n1. Run\n2. Stop\nChoice = ");
        if(fgets(ol, sizeof(ol), stdin) != NULL){
            size_t len = strlen(ol);
            if(len > 0 && ol[len - 1] == '\n'){
                ol[len - 1] = '\0';
            }
            int al = atoi(ol);
            switch(al){
                case 1:{
                    printf("General formula of cubic equation -\nax^3 + bx^2 + cx + d = 0\nEnter the a, b, c and d to calculate the three roots\n");
                    int a, b, c, d;
                    printf("a = ");
                    if(scanf("%d", &a) != 1){
                        printf("Invalid input for a\n");
                        exit(1);
                    }
                    fflush(stdin);
                    printf("b = ");
                    if(scanf("%d", &b) != 1){
                        printf("Invalid input for a\n");
                        exit(1);
                    }
                    fflush(stdin);
                    printf("c = ");
                    if(scanf("%d", &c) != 1){
                        printf("Invalid input for a\n");
                        exit(1);
                    }
                    fflush(stdin);
                    printf("d = ");
                    if(scanf("%d", &d) != 1){
                        printf("Invalid input for a\n");
                        exit(1);
                    }
                    fflush(stdin);
                    if(a == 0){
                        if(b == 0){
                            if(c == 0)
                                printf("Invalid Equation\n");
                            else if(c != 0 && d == 0)
                                printf("0");
                            else if(c == 0 && d == 0)
                                printf("Invalid Equation\n");
                            else{
                                float root;
                                root = -1*((float)d/(float)c);
                                d = fabs(d);
                                c = fabs(c);
                                double intp;
                                double frac = modf(root, &intp);
                                 double tolerance = 1e-7;
                                if(fabs(frac) < tolerance)
                                    printf("There is one solution - \n x = %d\n", (int)root);
                                else{
                                    printf("There is one solution - \n x = %.2f\n", root);
                                    root > 0.0 ?
                                    printf("In fraction - \n x = %d/%d\n", (int)d, (int)c):
                                    printf("In fraction - \n x = -(%d/%d)\n", (int)d, (int)c);
                                } 
                            } 
                        }
                        else{
                            
                        }
                    }
                    else{

                    }
                }
                break;
                case 2:
                    exit(0);
                default:
                    printf("!!Error please enter 1 or 2 as per given option!!\n");
                break;
            }
        }
        else{
            printf("###Error Reading Input!!!");
            exit(1);
        }
    }
    return 0;
}
void line(void){
    for(int i = 0; i < 50; i++)
        putchar('-');
}
