// Nathan Wheeler N00871989@unf.edu
#include "my.h"
main(int argc, char* argv[])
{	

	if (argc != 2)
	{
		printf("Incorrect syntax. Format: programName fileName\n");
	}

	else
	{
		FILE *fp = fopen(argv[1], "r");
		if (fp != NULL){
		int n, i =0, j, k, l;
		size_t intSize = sizeof(int);
		fscanf(fp, "%d", &n);
		printf ("The number of elements in your file is: %d\n", n);
		int *a;
		a = calloc(n, intSize);
		
		//Read Array into memory from file
		for (i=0; i<n; i++){
		fscanf(fp, "%d", &a[i]);
		}
		int swaps = 1;
		while (swaps > 0){
			swaps = 0;
			for(j = 0; j < n -1; j+=2){

				if (a[j] > a[j+1])
				{
					int temp =	a[j]; 
					a[j] = a[j + 1];
					a[j + 1] = temp;
					swaps +1;
				}
		}
			for(k = 1; k < n -1; k+=2){
					if (a[k] > a[k+1])
					{
						int temp =	a[k]; 
						a[k] = a[k + 1];
						a[k + 1] = temp;
						swaps++;
					}
			}
		}
    int key;
	do{
	printf("Enter an index number. The number stored in that index will be displayed. Or, enter -1 to exit.");
	scanf("%d", &key);
	printf("The sorted number at index %d is %d\n", key, a[key]);
	}
	while(key != -1);
	   		free( a );
			fclose(fp);
	return 0;
		}	
	}
}
