#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>

   struct Quiz{
    char question[1000];
    char correctAnswer[1000];
    char firstAnswer[1000];
    char secondAnswer[1000];
    char thirdAnswer[1000];
    char fourthAnswer[1000];
    bool result;
};

void line(){
    printf("\n======================\n");
}

void createQuiz(struct Quiz *Test,int *numberOfSentences, int *lastIndex){
    system("cls");  
    int choice;
    // to create quiz and then append it at next index (not back to 0)
    if((*lastIndex) > 0){        
       (*numberOfSentences)++;
    } 
    
    for(; *lastIndex < *numberOfSentences; (*lastIndex)++){
        printf("Enter the question %d: ",(*numberOfSentences)); fflush(stdin); 
        fgets(Test[(*lastIndex)].question, sizeof(Test[(*lastIndex)].question), stdin); 
        printf("\nEnter correct answer:"); 
        fgets(Test[(*lastIndex)].correctAnswer, sizeof(Test[(*lastIndex)].correctAnswer), stdin);
        printf("\nEnter answer 1: "); 
        fgets(Test[(*lastIndex)].firstAnswer, sizeof(Test[(*lastIndex)].firstAnswer), stdin);
        printf("\nEnter answer 2: ");
        fgets(Test[(*lastIndex)].secondAnswer, sizeof(Test[(*lastIndex)].secondAnswer), stdin);
        printf("\nEnter answer 3: ");
        fgets(Test[(*lastIndex)].thirdAnswer, sizeof(Test[(*lastIndex)].thirdAnswer), stdin);
        printf("\nEnter answer 4: ");
        fgets(Test[(*lastIndex)].fourthAnswer, sizeof(Test[(*lastIndex)].fourthAnswer), stdin);

        line();
            printf("1. Done\n");
            printf("2. More quiz\n");
        do{            
            printf("Enter your choice: "); scanf("%d", &choice);
            if(choice != 1 && choice != 2){
                printf("Please, Enter 1 or 2 !");
            }
        }while(choice != 1 && choice != 2);
        if(choice == 2){
            system("cls");
          (*numberOfSentences)++;
        }
    }
}
// should use to do a particular thing
int displayAParticular(struct Quiz* Test, int position){
   system("cls");
   int index = --position; 
       line();
       printf("[1]Question: %s", Test[index].question);
       printf("[2]Correct answer: %s\n", Test[index].correctAnswer);
       printf("[3]First answer: %s\n", Test[index].firstAnswer);
       printf("[4]Sencond answer: %s\n", Test[index].secondAnswer);
       printf("[5]Third answer: %s\n", Test[index].thirdAnswer);
       printf("[6]Fourth answer: %s", Test[index].fourthAnswer);
       line();
       return index;
}

void displayAllQuizzes(struct Quiz Test[],int  sentenceNumber,int lastIndex){
    system("cls");
    int count = 0;
    if(lastIndex == 0){
        printf("There isn't question ! please create");
        getch();
    }else{
        for(int i = 0 ; i < sentenceNumber; i++){
        line();
        printf("Question [%d]: %s\n", ++count, Test[i].question);
        printf("Correct answer: %s\n", Test[i].correctAnswer);
        printf("The first answer: %s\n", Test[i].firstAnswer);
        printf("The second answer: %s\n", Test[i].secondAnswer);
        printf("The Third answer: %s\n", Test[i].thirdAnswer);
        printf("The fourth answer: %s", Test[i].fourthAnswer);
    }
    }
    getch();
}

void updateQuiz(struct Quiz* Test, int sentenceNumber, int lastIndex){
    system("cls");
    int remake = 1;
    int position;
    int choice;
    if(lastIndex == 0){
        printf("There isn't question ! please create.");
        getch();
    }else{
        for(int i = 0; i < remake; i++){
        system("cls");
        do{
            printf("Enter the position of sentence to remake: "); scanf("%d", &position);
            if(position <= 0 || position > sentenceNumber){
                printf("\nplease ! Enter suitable number from 1 to the max sentence number is [%d] !\n", sentenceNumber);
            }
        }while(position <= 0 || position > sentenceNumber);       
        int index = displayAParticular(Test, position);
        
    do{ 
        printf("[0]Back\n");
        printf("Enter position you want to remake: "); scanf("%d", &choice);

        if(choice !=1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 0){
            printf("\nPls ! Enter the number 0 - 6.\n");
        }       
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 0);
        
        switch(choice){
        case 1:
        fflush(stdin);
        printf("Remake the question: "); fgets(Test[index].question,sizeof(Test[index].question), stdin);
        break;
        case 2:
        fflush(stdin);
        printf("Remake the correct answer: "); fgets(Test[index].correctAnswer, sizeof(Test[index].correctAnswer),stdin);
        break;
        case 3:
        fflush(stdin);
        printf("Remake the answer 1: "); fgets(Test[index].firstAnswer, sizeof(Test[index].firstAnswer),stdin);
        break;
        case 4:
        fflush(stdin);
        printf("Remake the answer 2: "); fgets(Test[index].secondAnswer, sizeof(Test[index].secondAnswer),stdin);
        break;
        case 5:
        fflush(stdin);
        printf("Remake the answer 3: "); fgets(Test[index].thirdAnswer, sizeof(Test[index].thirdAnswer),stdin);
        break;
        case 6:
        fflush(stdin);
        printf("Remake the answer 4: "); fgets(Test[index].fourthAnswer, sizeof(Test[index].fourthAnswer),stdin);
        break;
    }
    }
    }   
}

void removeQuiz(struct Quiz *Test, int  *sentenceNumber,int *lastIndex){
    system("cls");
    int position;
    if(lastIndex == 0){
        printf("There isn't question ! please create.");
        getch();
    }else{
        do{
            printf("Press [0] to back to menu!\n");
            printf("Enter the position of sentence to remove: "); scanf("%d", &position);
             if(position <=0 || position > *sentenceNumber){
                 printf("Please ! Enter from [0] to [%d].", (*sentenceNumber));
             }
        }while(position < 0 || position > *sentenceNumber);
       if(position != 0){
           for(int i = position; i <= sentenceNumber; i++){
        strcpy(Test[position - 1].question,Test[position].question);
        strcpy(Test[position - 1].correctAnswer,Test[position].correctAnswer);
        strcpy(Test[position - 1].firstAnswer,Test[position].firstAnswer);
        strcpy(Test[position - 1].secondAnswer,Test[position].secondAnswer);
        strcpy(Test[position - 1].secondAnswer,Test[position].secondAnswer);
        strcpy(Test[position - 1].thirdAnswer,Test[position].thirdAnswer);
        strcpy(Test[position - 1].fourthAnswer,Test[position].fourthAnswer);
    }
        (*sentenceNumber)--;
        (*lastIndex)--;
        // ? to return normal status
        // ! because it's both equal in function createQuiz when it's done
        if((*lastIndex) == 0 && (*sentenceNumber) == 0){
            (*sentenceNumber) = 1;
            (*lastIndex) = 0;
        }
       }
    }
}

void checkAnswer(struct Quiz Test[], int sentenceNumber, int score){
    system("cls");
    printf("Your score is %d/%d", score, sentenceNumber);
    line();
    for(int i = 0; i < sentenceNumber; i++){
        line();
        if(Test[i].result){
            printf("%s:[CORRECT]", Test[i].question);
        }else{
            printf("%s:[WRONG]\n", Test[i].question);
            printf("The correct answer is %s", Test[i].correctAnswer);
        }
    }
    getch();
}

void Exercise(struct Quiz Test[], int sentenceNumber,int  lastIndex){
    system("cls");
    int score = 0;
    int count = 0;
    char choice;
    if(lastIndex == 0){
        printf("There isn't question ! please create.");
        getch();
    }else{
        for(int i = 0; i < sentenceNumber; i++){
        system("cls");
        printf("%d.%s",++count, Test[i].question);
        line();
        printf("A.%s\n", Test[i].firstAnswer);
        printf("B.%s\n", Test[i].secondAnswer);
        printf("C.%s\n", Test[i].thirdAnswer);
        printf("D.%s\n", Test[i].fourthAnswer);
        line();
        do{
            fflush(stdin);
            printf("Enter your choice: "); scanf("%c", &choice);
            if(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd'){
                printf("please Enter a, b, c, d !");
            }
        }while(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd');
        switch(choice){
            case 'a':
            if(strcmp(Test[i].correctAnswer, Test[i].firstAnswer) == 0){
                Test[i].result = true;
                score++;
            }else{
                Test[i].result = false;
            }
            break;
            case 'b':
            if(strcmp(Test[i].correctAnswer, Test[i].secondAnswer) == 0){
                Test[i].result = true;
                score++;
            }else{
                Test[i].result = false;
            }
            break;
            case 'c':
            if(strcmp(Test[i].correctAnswer, Test[i].thirdAnswer) == 0){
                Test[i].result = true;
                score++;
            }else{
                Test[i].result = false;
            }
            break;
            case 'd':
            if(strcmp(Test[i].correctAnswer, Test[i].fourthAnswer) == 0){
                Test[i].result = true;
                score++;
            }else{
                Test[i].result = false;
            }
            break;
        }
    }
    checkAnswer(Test, sentenceNumber, score);
    }   
}

void saveFile(struct Quiz test[], int sentenceNumber, int lastIndex, char fileName[30]){
    FILE *fin = fopen(fileName,"wb");
    fwrite(&lastIndex, sizeof(lastIndex), 1, fin);
    fwrite(&sentenceNumber, sizeof(sentenceNumber), 1, fin);
    for(int i = 0; i < sentenceNumber; i++){
    fwrite(&test[i].question, sizeof(test[i].question),1,fin);
        fwrite(&test[i].correctAnswer, sizeof(test[i].correctAnswer),1,fin);
        fwrite(&test[i].firstAnswer, sizeof(test[i].firstAnswer),1,fin);
        fwrite(&test[i].secondAnswer, sizeof(test[i].secondAnswer),1,fin);
        fwrite(&test[i].thirdAnswer, sizeof(test[i].thirdAnswer),1,fin);
        fwrite(&test[i].fourthAnswer, sizeof(test[i].fourthAnswer),1,fin);
    }             
    fclose(fin);
}

int main(){
    int choice;
    int sentenceNumber = 1;
    int lastIndex = 0;
    char fileName[30];
    struct Quiz test[100];
    // to save quiz 
    printf("Create a new file (fileName.bin) or review your old file: "); scanf("%s", &fileName);

    FILE *f = fopen(fileName, "rb");
    if(f == NULL){
        FILE *f = fopen(fileName, "wb");
    }else{
        fread(&lastIndex, sizeof(lastIndex), 1, f);
        fread(&sentenceNumber, sizeof(sentenceNumber),1, f);
        for(int i = 0 ; i < sentenceNumber; i++){
            fread(&test[i].question, sizeof(test[i].question),1,f);
            fread(&test[i].correctAnswer, sizeof(test[i].correctAnswer),1,f);
            fread(&test[i].firstAnswer, sizeof(test[i].firstAnswer),1,f);
            fread(&test[i].secondAnswer, sizeof(test[i].secondAnswer),1,f);
            fread(&test[i].thirdAnswer, sizeof(test[i].thirdAnswer),1,f);
            fread(&test[i].fourthAnswer, sizeof(test[i].fourthAnswer),1,f);
        }       
    }

    do{
    system("cls");
    line();
    printf("[1]. CREATE AND ADD QUIZZES.\n");
    printf("[2]. DO EXERCISE.\n");
    printf("[3]. UPDATE QUIZ.\n");
    printf("[4]. DISPLAY ALL QUIZZES.\n");
    printf("[5]. REMOVE A QUIZZES.\n");
    printf("[6]. SAVE FILE AND EXIT.");
    line();
    do{
         printf("Enter your choice: "); scanf("%d", &choice);
         if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6){
             printf("\nPlease Enter the number above!\n");
         }
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);

    switch(choice){
        case 1:
        createQuiz(&test,&sentenceNumber, &lastIndex);
        break;
        case 2: 
        Exercise(test, sentenceNumber, lastIndex);
        break;
        case 3:
        updateQuiz(&test, sentenceNumber, lastIndex);
        break;
        case 4:
        displayAllQuizzes(test, sentenceNumber, lastIndex); 
        break;
        case 5:
       removeQuiz(&test, &sentenceNumber, &lastIndex);
        break;
        case 6:
        saveFile(test,sentenceNumber,lastIndex,fileName);
        fclose(f);
        break;
    }
    }while(choice != 6);
}