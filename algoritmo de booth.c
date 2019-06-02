#include <stdio.h>
#include <math.h>

#define BITS 5
    int a = 0,b = 0, c = 0, num1 = 0, num2 = 0, com[BITS] = { 1, 0, 0, 0, 0};
    int arraynum1[BITS] = {0}, anumcp[BITS] = {0}, arraynum2[BITS] = {0};
    int acomp[BITS] = {0}, bcomp[BITS] = {0}, pro[BITS] = {0}, res[BITS] = {0};

    void bin(){
         num1 = fabs(a); //Absoluto de um numero
         num2 = fabs(b); //Absoluto de um numero
         int resultado1, resultado2, i, temp;
         for (i = 0; i < BITS; i++){
               resultado1 = num1 % 2;
               num1 = num1 / 2;

               resultado2 = num2 % 2;
               num2 = num2 / 2;

               arraynum1[i] = resultado1;

               anumcp[i] = resultado1;

               arraynum2[i] = resultado2;

               if(resultado2 == 0){

                    bcomp[i] = 1;

               }

               if(resultado1 == 0){

                    acomp[i] =1;

               }

         }

       //complemento de dois

       c = 0;

       for ( i = 0; i < BITS; i++){

               res[i] = com[i]+ bcomp[i] + c;

               if(res[i] >= 2){

                    c = 1;

               }

               else

                    c = 0;

               res[i] = res[i] % 2;

         }

       for (i = 4; i >= 0; i--){

         bcomp[i] = res[i];

       }

       //negativos

       if (a < 0){

          c = 0;

         for (i = 4; i >= 0; i--){

               res[i] = 0;

         }

         for ( i = 0; i < 5; i++){

               res[i] = com[i] + acomp[i] + c;

               if (res[i] >= 2){

                    c = 1;

               }

               else

                    c = 0;

               res[i] = res[i]%2;

         }

         for (i = 4; i >= 0; i--){

               arraynum1[i] = res[i];

               anumcp[i] = res[i];

         }

     

       }

       if(b < 0){

         for (i = 0; i < 5; i++){

               temp = arraynum2[i];

               arraynum2[i] = bcomp[i];

               bcomp[i] = temp;

         }

       }

    }

    void add(int num[]){

        int i;

        c = 0;

        for ( i = 0; i < 5; i++){

               res[i] = pro[i] + num[i] + c;

               if (res[i] >= 2){

                    c = 1;

               }

               else{

                    c = 0;

               } 

               res[i] = res[i]%2;

         }

         for (i = 4; i >= 0; i--){

             pro[i] = res[i];

             printf("%d",pro[i]);

         }

       printf(":");

       for (i = 4; i >= 0; i--){

               printf("%d", anumcp[i]);

         }

    }

    void arshift(){//for arithmetic shift right

        int temp = pro[4], temp2 = pro[0], i;

        for (i = 1; i < 5  ; i++){//shift the MSB of product

           pro[i-1] = pro[i];

        }

        pro[4] = temp;

        for (i = 1; i < 5  ; i++){//shift the LSB of product

            anumcp[i-1] = anumcp[i];

        }

        anumcp[4] = temp2;

        printf("\nAR-SHIFT: ");//display together

        for (i = 4; i >= 0; i--){

            printf("%d",pro[i]);

        }

        printf(":");

        for(i = 4; i >= 0; i--){

            printf("%d", anumcp[i]);

        }

    }

     

    void main(){

       int i, q = 0;

       printf("\t\tBOOTH'S MULTIPLICATION ALGORITHM");

       printf("\nEnter two numbers to multiply: ");

       printf("\nSomente números entre -16 e 15");

       //simulating for two numbers each below 16

       do{

            printf("\nEnter A: ");

            scanf("%d",&a);

            printf("Enter B: ");

            scanf("%d", &b);

         }while(a >=16 || b >=16);

     

        printf("\nExpected product = %d", a * b);

        bin();

        printf("\n\nBinary Equivalents are: ");

        printf("\nA = ");

        for (i = 4; i >= 0; i--){

            printf("%d", arraynum1[i]);

        }

        printf("\nB = ");

        for (i = 4; i >= 0; i--){

            printf("%d", arraynum2[i]);

        }

        printf("\nB'+ 1 = ");

        for (i = 4; i >= 0; i--){

            printf("%d", bcomp[i]);

        }

        printf("\n\n");

        for (i = 0;i < 5; i++){

               if (arraynum1[i] == q){//just shift for 00 or 11

                   printf("\n-->");

                   arshift();

                   q = arraynum1[i];

               }

               else if(arraynum1[i] == 1 && q == 0){//subtract and shift for 10

                  printf("\n-->");

                  printf("\nSUB B: ");

                  add(bcomp);//add two's complement to implement subtraction

                  arshift();

                  q = arraynum1[i];

               }

               else{//add ans shift for 01

                  printf("\n-->");

                  printf("\nADD B: ");

                  add(arraynum2);

                  arshift();

                  q = arraynum1[i];

               }

         }

     

         printf("\nProduct is = ");

         for (i = 4; i >= 0; i--){

               printf("%d", pro[i]);

         }

         for (i = 4; i >= 0; i--){

               printf("%d", anumcp[i]);

         }

    }
