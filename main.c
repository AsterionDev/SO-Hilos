#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
/**
 * @brief Parametros para el hilo que va arealizar la adicion
 */
typedef struct 
{
    double ** a;
    double ** b;
    double ** c;
    int n;
    int m;
}datos_sumar;
/**
 * @brief Hilo para realizar una parte de la adicion
 */
void * adicionar(void * arg);

int main(int argc,char * argv[]){

    double ** m_a=0;
    double ** m_b=0;
    double ** m_c=0;
    
    int n_hilos=6;
    int m,n;

    datos_sumar * datos;
    pthread_t * ids;
    datos=malloc(n_hilos * sizeof(datos_sumar));
    memset(datos,0,n_hilos * sizeof(datos_sumar));
    ids =malloc(n_hilos * sizeof(pthread_t));

    for (int i = 0; i < n_hilos; i++)
    {
        datos[i].a=m_a;
        datos[i].b=m_b;
        datos[i].c=m_c;
        datos[i].n=n;
        datos[i].n=m;
        if (pthread_create(&ids[i],NULL,adicionar,(void *)&datos[i])!=0)
        {
            printf("No se pudo crear el thread %d\n",i);
            exit(EXIT_FAILURE);
        }
        
    }
    
    for (int i = 0; i < n_hilos; i++)
    {
        pthread_join(ids[i],0);
    }
    //TODO crear las matrices
    //TODO inicializar las matrices

    //TODO marcar inicio
    //TODO Crear los hilos

    //TODO Esperar a que los hilos realicen la adicion
    //TODO calculoar el tiempo trascurrido en la ejecucion de hilos
    //TODO imprimir
    
    exit(EXIT_SUCCESS);
}

void * adicionar(void * arg){
    datos_sumar * datos=(datos_sumar *)arg;
    printf("bien\n");
}