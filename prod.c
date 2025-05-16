#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 2
#define ITEMS_PER_PRODUCER 10

typedef enum { TEMPERATURE, HUMIDITY } sensor_type_t;
const char *sensor_names[] = { "Temperature", "Humidity" };

/* Shared buffer and indices */
int buffer[BUFFER_SIZE];
int in = 0, out = 0, count = 0;

/* Synchronization primitives */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;        // protects buffer, in, out, count
pthread_cond_t not_full  = PTHREAD_COND_INITIALIZER;      // signaled when count < BUFFER_SIZE
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;      // signaled when count > 0

/* Simulate a sensor reading */
int read_sensor_data(sensor_type_t type) {
    if (type == TEMPERATURE) return rand() % 40 + 10;  // 10–49 °C
    else                    return rand() % 100;      // 0–99 %RH
}

/* Producer: generates ITEMS_PER_PRODUCER readings */
void *producer(void *arg) {
    sensor_type_t type = *(sensor_type_t *)arg;
    for (int i = 0; i < ITEMS_PER_PRODUCER; ++i) {
        int data = read_sensor_data(type);
        /* Entry section */
        pthread_mutex_lock(&mutex);                           // mutual exclusion :contentReference[oaicite:6]{index=6}
        while (count == BUFFER_SIZE)                           // buffer full → wait :contentReference[oaicite:7]{index=7}
            pthread_cond_wait(&not_full, &mutex);
        /* Critical section */
        buffer[in] = data;
        printf("[Producer-%s] Put %d at %d\n", sensor_names[type], data, in);
        in = (in + 1) % BUFFER_SIZE;
        count++;
        /* Exit section */
        pthread_cond_signal(&not_empty);                       // wake a consumer :contentReference[oaicite:8]{index=8}
        pthread_mutex_unlock(&mutex);
        usleep((rand() % 500) * 1000);                         // simulate sensor interval
    }
    return NULL;
}

/* Consumer: runs indefinitely */
void *consumer(void *arg) {
    (void)arg;
    while (1) {
        /* Entry section */
        pthread_mutex_lock(&mutex);
        while (count == 0)                                     // buffer empty → wait :contentReference[oaicite:9]{index=9}
            pthread_cond_wait(&not_empty, &mutex);
        /* Critical section */
        int data = buffer[out];
        printf("    [Consumer] Got %d from %d\n", data, out);
        out = (out + 1) % BUFFER_SIZE;
        count--;
        /* Exit section */
        pthread_cond_signal(&not_full);                        // wake a producer :contentReference[oaicite:10]{index=10}
        pthread_mutex_unlock(&mutex);
        usleep((rand() % 800) * 1000);                         // simulate processing time
    }
    return NULL;
}

int main() {
    srand((unsigned)time(NULL));
    pthread_t producers[NUM_PRODUCERS], consumers[NUM_CONSUMERS];
    sensor_type_t types[NUM_PRODUCERS] = { TEMPERATURE, HUMIDITY, TEMPERATURE };

    /* Launch all producer threads */
    for (int i = 0; i < NUM_PRODUCERS; ++i)
        pthread_create(&producers[i], NULL, producer, &types[i]);

    /* Launch all consumer threads */
    for (int i = 0; i < NUM_CONSUMERS; ++i)
        pthread_create(&consumers[i], NULL, consumer, NULL);

    /* Wait for producers to finish */
    for (int i = 0; i < NUM_PRODUCERS; ++i)
        pthread_join(producers[i], NULL);

    /* In a real system, signal consumers to exit here */
    printf("All producers done; exiting.\n");
    return 0;
}
