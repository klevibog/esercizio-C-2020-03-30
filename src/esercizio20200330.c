#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



void swap(unsigned long*x, unsigned long *y) {
	int t = *x;
	*x = *y;
	*y = t;
}


unsigned long* reverse_array(unsigned long* array, unsigned int i, unsigned int j){
//	while (i < j)
//		swap(&array[i++], &array[--j]);

	while (i < j) {
		j--;
		swap(&array[i], &array[j]);
		i++;
	}

	return array;
}


unsigned long * complete_reverse(unsigned long * array, unsigned int array_len) {
	return reverse_array(array, 0, array_len);
}

long * make_copy_of_array(unsigned long src_array [] /* long * src_array */, unsigned int array_dimension) {

	/*
	 * in Java, quando passo un array come argomento di una funzione, oltre al riferimento all'oggetto
	 * viene passato "automaticamente" anche la lunghezza dell'array.
	 *
	 * in C l'array non si porta dietro "automaticamente" la lunghezza di se stesso:
	 * bisogna passare l'indirizzo dell'array E la lunghezza dell'array, in due parametri distinti
	 */

	if (src_array == NULL)
		return NULL;

	long * result;

	// allochiamo lo spazio di memoria per la copia
	result = malloc(array_dimension * sizeof(long));

	if (result == NULL) {
		return NULL;
	}

	memcpy(result, src_array, array_dimension * sizeof(long));

	return result;
}



unsigned long fibonacci(unsigned int n){
switch(n){

case 0:
	return 1;
case 1:
	return 1;
default:
//fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)  per n > 1
	return (fibonacci(n-1)+fibonacci(n-2));
	}

}
unsigned long* fibonacci_array(unsigned int n){

	unsigned long* fib_array;
	fib_array=malloc(n*sizeof(long));
	for(unsigned int i=0;i<n;i++){
		fib_array[i]=fibonacci(i);
	}
	return fib_array;

}

void bubble_sort(unsigned long* array, int array_dimension){

		// ESERCIZIO: implementare bubble sort (pseudocodice riportato sotto)
		int n, newn;

		n = array_dimension;


		//do {
		while (n > 1) {

			newn = 0;

			for (int i = 1; i < n; i++) {
				if (array[i-1] > array[i]) {
					swap(&array[i-1], &array[i]);
					newn = i;
				}
			}

			n = newn;
		}
}


int main(int argc, char *argv[]) {

	unsigned long* fibonacci_result;
	unsigned long* fibonacci_result_copy;
	fibonacci_result=malloc(39*sizeof(long));
	fibonacci_result_copy=malloc(39*sizeof(long));
	for(int i=0;i<39;i++){
		fibonacci_array(i);
	}

	memcpy(fibonacci_result,fibonacci_array(39),39*sizeof(long));
	//fibonacci_result=fibonacci_array(unsigned int 39);
	memcpy(fibonacci_result_copy,make_copy_of_array(fibonacci_result,39),39*sizeof(long));
	printf("FIB_ARRAY\n");
	for(int i=0;i<39;i++){
		printf("\n fib_arr[i]=%lu",fibonacci_result[i]);
		}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("FIB_REV\n");
	memcpy(fibonacci_result_copy,complete_reverse(fibonacci_result_copy,39),39*sizeof(long));
	//fibonacci_result_copy=reverse_array(fibonacci_result,0,39);
	for(int i=0;i<39;i++){
			printf("\n fib_arr_reverse[i]=%lu",fibonacci_result_copy[i]);
			}

	bubble_sort(fibonacci_result_copy,39);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("FIB_REV_BUBBLE\n");
	for(unsigned int i=0;i<39;i++){
				printf("\n fib_REV_bubble[i]=%lu",fibonacci_result_copy[i]);
				}

//confrontare fibonacci_result e fibonacci_result_copy, verificare che i due array siano uguali (scrivere su stdout il risultato).
		printf("\n");
		printf("\n");
if(memcmp(fibonacci_result_copy,fibonacci_result,39*sizeof(long))==0){

	printf("FIB_REV_BUB==FIB,memcmp restituisce: %d",memcmp(fibonacci_result_copy,fibonacci_result,39*sizeof(long)));
}else
	printf("FIB_REVBUB!=FIB,memcmp restituisce: %d",memcmp(fibonacci_result_copy,fibonacci_result,39*sizeof(long)));
free(fibonacci_result);
free(fibonacci_result_copy);

	return 0;
}
