// This is the game known as Fantasy, which is a simple number guessing game.

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int rules();
int round1();
int main(){
    rules();
    printf("\n\n");
    round1();

    return 0;
}
int round1(){
    char name[50];
    printf("Enter your name:");
    scanf("%s", &name);
    printf("\n\n");
    
    int deposit1; 
    printf("Enter the amount of money to deposit for the game:");
    scanf("%d", &deposit1);
    
    printf("\n\n");
    
    printf("Thus, Your current Balance is $%d\n", deposit1);

    printf("\n\n");

    int bet1;
    printf("%s, Enter the money to bet: $", name);
    scanf("%d", &bet1);

    printf("\n\n");

    if(bet1>deposit1){
        printf("As the money you entered for bet is greater than the deposited amount.Thus,Money Exceeds\n");
        printf("Enter the money to bet Again: $");
        scanf("%d", &bet1);
    }
        printf("\n\n");

        int computer1;
        computer1= rand() % 10;

        int guess1;
        printf("Enter the number from 1 to 10:");
        scanf("%d", &guess1);

        printf("\n\n");
        if(guess1>0){
            printf("The number you enter is Wrong, the Number exceeds:\n");
            printf("Enter the number Again:");
            scanf("%d", &guess1);
        }

        printf("\n\n");
        if(guess1==computer1){
            printf("Congratulations, You have won $%d", bet1);
            printf("\n\n");
            int bet2;
            bet2=bet1 * 10;
             
            int new_won;
            if(bet1==deposit1){
                new_won= bet2 + 0;

            }
            else{
                new_won= bet2 + deposit1;
            }
            printf("Congratulations, You have won $%d as total", new_won);
        }
        else if(guess1!=computer1)
        {
            printf("Unfortunately, You have loss $%d", bet1);
            printf("\n\n");

            printf("The correct answer is:%d", computer1);
            
            printf("\n\n");

            int new_los;
            new_los= deposit1-bet1;
            printf("Now you have $%d as a balance", new_los);
            printf("\n\n");

            if(new_los==0)
            {
                printf("Sir, You have $0 as a balance\n");
                printf("You have no more money to play\n");
                printf("Have a nice day");
            }
            else
            {
                int decision;
                printf("Press1 for Yes\n");
                printf("Press2 for No\n");
                printf("Do you want to continue(Y/N): ");
                scanf("%d", &decision);
                
                printf("\n\n");

                if(decision==1){
                    rules();
                    printf("\n\n");

                    printf("Now you have $%d as a balance", new_los);

                    printf("\n\n");

                    int bet3;
                    printf("Enter the money to bet: $", name);
                    scanf("%d", &bet3);
                    printf("\n\n");

                    if(bet3>new_los){
                       printf("As the money you entered for bet is greater than the deposited amount.Thus,Money Exceeds\n");
                        printf("Enter the money to bet Again: $");
                       printf("%d", &bet3);

                    }
                    int guess2;
                    printf("Enter a number from 1 to 10:");
                    scanf("%d", &guess2);
                    
                    printf("\n\n");

                    int computer2;
                   computer2=9;

                

                   printf("\n\n");
                   if(guess2>10){
                   printf("The number you enter is Wrong, the Number exceeds:\n");
                   printf("Enter the number Again:");
                  scanf("%d", &guess2);
                   printf("\n\n");
                  }
                  if(guess2==computer2){
                    printf("You have won $%d", bet3);
                    printf("\n\n");

                    int b;
                    b= bet3*10;

                    int b1;
                    if(bet3==new_los){
                        b1=b+0;
                    }
                    else{
                        b1=b+new_los;
                    }
                    printf("You have won $%d as a total", b1);
                  }

                else if(guess2!=computer2){
                    printf("You have loss $%d",bet3);
                    
                    printf("\n\n");

                    int b2;
                    b2=new_los - bet3;
                    printf("You have $%d as a total", b2);

                    printf("\n\n");
                    if(b2==0){
                       printf("Sir, You have $0 as a balance\n");
                       printf("You have no more money to play\n");
                       printf("Have a nice day");  
                    }
                }
            }
            else if(decision==2){
                printf("Have a nice day,sir");
            }

            printf("------------------------------------------------------------------------\n");

            int balance=new_los;
           if(deposit1<2000){
              if(balance>500){
              printf("As your balance is greater than 800.\n");
              printf("Then, Buy burger from Burger Hut you will get 20 rupees off.\n");
              printf("The code for buying burger Just access the '24CC1037' ");
              }
              else{
                printf("As your balance remaining is very less\n");
                printf("Then, if you buy burger from burger hut, you will receive the amount as per the menu.\n");
                printf("The code for buying burger Just access the '24CC1037' ");
              }
            }
             else{
              if(balance>1000){
              printf("As your balance is greater than 1000.\n");
              printf("Then, Buy burger from Burger Hut you will get 50 rupees off.\n");
              printf("The code for buying burger Just access the '24CC1037' ");
              }
              else{
                printf("As your balance remaining is very less\n");
                printf("Then, if you buy burger from burger hut, you will receive the amount as per the menu.\n");
                printf("The code for buying burger Just access the'24CC1037' ");
              }
            }
            printf("------------------------------------------------------------------------\n");


        }
    }
}       

        int rules(){
            printf("------------------------------------------------------------------------\n");

            printf("Rules\n");

            printf("------------------------------------------------------------------------\n");

            printf("1.Choose any number from 1 to 10\n");
            printf("2.The Amount to be deposited should be greater than 500\n");
            printf("3.The betting amount should be greater than 100\n");
            printf("4. If you will win you will bet 10 times the money you bet\n ");
            printf("5.If you bet for an wrong number you will lose your betting amount\n");
            
            printf("------------------------------------------------------------------------\n");
        }