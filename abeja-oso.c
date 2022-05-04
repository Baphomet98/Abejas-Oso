#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>

sem_t sem_abeja, sem_oso;
int nabeja = 0, frasco = 0;

void *producir(void *arg);
void *comer(void *arg);

int main()
{
    // int i=0;
    pthread_t hiloabeja[15], hiloso;
    // iniciar semaforos
    sem_init(&sem_abeja, 0, 1);
    sem_init(&sem_oso, 0, 0);
    // crear hilos

    for (int i = 0; i < 15; i++)
    {
        pthread_create(&hiloabeja[i], NULL, (void *)producir, NULL);
    }
    pthread_create(&hiloso, NULL, (void *)comer, NULL);
    // joins
    for (int i = 0; i < 15; i++)
    {
        pthread_join(hiloabeja[i], NULL);
    }
    pthread_join(hiloso, NULL);
    sem_destroy(&sem_abeja);
    sem_destroy(&sem_oso);
    exit(0);
}

void *producir(void *arg)
{
    printf("soy productor %i\n", pthread_self());
}

void *comer(void *arg)
{
    printf("soy el oso %i\n", pthread_self());
}

/*
[14:04] Diego Flores Chavarria
    int main(){​​​
int i = 0;
pthread_t hiloEscritores[3];
pthread_t hiloLectores[2];
sem_init(&sem_mutex,0,1);
sem_init(&sem_bd,0,1);
for ( i = 0; i < 2; i++){​​​
pthread_create(&hiloEscritores[i],NULL,(void*)escritor,NULL);
}​​​
for ( i = 0; i < 3; i++){​​​
pthread_create(&hiloLectores[i],NULL,(void*)lector,NULL);
}​​​

 for ( i = 0; i < 2; i++){​​​
pthread_join(hiloEscritores[i],NULL);
}​​​
 for ( i = 0; i < 3; i++){​​​
pthread_join(hiloLectores[i],NULL);
}​​​
 sem_destroy(&sem_mutex);
sem_destroy(&sem_bd);
printf("\n");
exit(0);
}​​​

*/