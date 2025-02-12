#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

pthread_t tid[3];

void *thread0(void *);
void *thread2(void *);

typedef struct PARAM{
    int order;
    char name[30];
}param_t;

int main(){
    param_t param[2];

    param[0].order = 0;

    strcpy(param[0].name, "Thread0");

    param[1].order = 1;

    strcpy(param[1].name, "Thread1");

    for (int i = 0; i < 2; i++) {
        pthread_create(&tid[i], NULL, thread0, &param[i]);
    }

    pthread_create(&tid[2], NULL, thread2, NULL);

    for (int i = 0; i < 3; i++){
        pthread_join(tid[i], NULL);
    }

    exit(0);
}

void *thread0(void *arg){
    param_t *param = (param_t*)arg;

    printf("This is %s\n", param->name);

    printf("My order is is %d\n", param->order);

    pthread_exit(NULL);
}

void *thread2(void *arg){
    int num;

    printf("Please enter a number \n: ");

    scanf("%d", &num);

    printf("Sum of your number and 4 is %d\n", num + 4);

    pthread_exit(NULL);
}
