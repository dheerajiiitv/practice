#include <pthread.h>
#include <stdio.h>
void PrintHello()
int main(int argc, char const *argv[])
{
	pthread_t threads[5];
	int rc;
	for (int i = 0; i < 5; ++i)
	{
		/* code */
		float a[6],b[6],c[6];
		a[i]=b[i]=c[i];
		pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		printf("%f\n",a[i] );
	}
	return 0;
}