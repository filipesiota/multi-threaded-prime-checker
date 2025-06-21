#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "utils.h"

int currentNumber = 1;
int totalPrimeNumbers = 0;
int numbersToProcess;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int isPrime(int number);
void *checkPrimes(void *arg);

int main() {
  pthread_t *threads;
  int *threadIds;
  int numberOfThreads;

  sysCommand("clear_terminal");
  printf("Digite a quantidade de numeros a processar: ");
  scanf("%d", &numbersToProcess);

  printf("Digite a quantidade de threads a criar: ");
  scanf("%d", &numberOfThreads);

  threads = malloc(sizeof(pthread_t) * numberOfThreads);
  threadIds = malloc(sizeof(int) * numberOfThreads);

  for (int i = 0; i < numberOfThreads; i++) {
    threadIds[i] = i;
    pthread_create(&threads[i], NULL, checkPrimes, &threadIds[i]);
  }

  for (int i = 0; i < numberOfThreads; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("\n\nO numero total de números primos encontrados foi: %d\n\n", totalPrimeNumbers);

  free(threads);
  free(threadIds);

  sysCommand("pause_terminal");
  return 0;
}

int isPrime(int number) {
  /* # Without optimization
  if (number < 2) return 0;

  for (int i = 2; i < number; i++) {
    if (number % i == 0) return 0;
  }

  return 1;
  */

  /* # With optimization */
  if (number < 2) return 0;
  if (number == 2) return 1;
  if (number % 2 == 0) return 0;

  for (int i = 3; i * i <= number; i += 2) {
    if (number % i == 0) return 0;
  }

  return 1;
}

void *checkPrimes(void *arg) {
  int threadId = *(int*)arg;

  while (1) {
    pthread_mutex_lock(&mutex);

    if (currentNumber > numbersToProcess) {
      pthread_mutex_unlock(&mutex);
      break;
    }

    if (isPrime(currentNumber)) {
      printf("\nThread %d: O numero %d e primo.", threadId, currentNumber);
      totalPrimeNumbers++;
    } else {
      printf("\nThread %d: O numero %d nao e primo.", threadId, currentNumber);
    }

    currentNumber++;
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}
