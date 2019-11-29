#include <pthread.h>
#include <stdio.h>
void* rtc_thread(void* data)
{
	printf("NEW THREAD\n");
}

int main()
{
	pthread_t id_rtc;

	pthread_create(&id_rtc, NULL, rtc_thread, NULL);
	pthread_join(id_rtc, NULL);
	printf("MAIN THREAD\n");

	return 0;
}


