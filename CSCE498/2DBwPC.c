#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>
#include "array.h"

#define N               16*1024*1024
#define CLOCK_RATE      700.0e6

main(){
    unsigned int perf_counts[6];
    unsigned int cycles,us;
    float time,mbps;
    struct timeval time1,time2;
    static unsigned int a[N],b[N];
    
    FILE *myFile=fopen("/dev/perf_counter","rb");
    if (!myFile) {
        perror("opening performance counter");
        
        return 0; 
    }
    
    gettimeofday(&time1,0);
    fread ((void *)perf_counts,4,3,myFile);

/////////////////////////////////////////////////////////////////
 
int i,j,k;
float sum;
float g[7] = {0.0111, 0.1353, .6065, 1.0000, .6065, .1353, .0111};
int n = 7;
int image_j, image_i;
unsigned short image[480][640];
unsigned short blurred[480][640];
unsigned short blurred2[480][640];

//Row Pass


for (i = 0; i < 480; i++ ) {



	for(j = 0; j < 640; j++){

		

		sum = 0;

		for(k = 0; k < n; k++){



			image_j = j+k-(int)(floor(n/2));

			if((image_j > 0) && (image_j < 640)){
		//	printf("Iter %d ",i);
		//	printf(" Iter j %d \n",j);
			 sum = sum + test_val[i][image_j]*g[k];

			}



		}

((unsigned short) (sum));
		blurred[i][j] = sum;

	} 	

}



//Columns Pass 
 
for(i = 0; i < 480; i++){



	for(j = 0; j < 640; j++){

		

		sum = 0;

		for(k = 0; k < n; k++){



			image_i = i+k-(int)(floor(n/2));

			if((image_i > 0) && (image_i < 480)){

				sum = sum + test_val[image_i][j]*g[k];

			}



		}
((unsigned short) (sum));

		 blurred2[i][j] = sum;

	} 	

}
////////////////////////////////////////////////////////////////
    fread (((void *)perf_counts)+12,4,3,myFile);
    gettimeofday(&time2,0);
    
    cycles = perf_counts[3]-perf_counts[0];
    
    time = (float) (cycles/CLOCK_RATE);
    
    mbps = (float) ((N*2*sizeof(unsigned int)))/time/(1024.0*1024.0);
    
    us = time2.tv_sec*1000000 + time2.tv_usec - time1.tv_sec*1000000 - time1.tv_usec;
    
    printf("memory test\n-----------\n");
    printf("[perf_counter] cycles = %u (%0.0f us, %0.0f MB/s)\n", cycles,time*1.0e6,mbps);
    printf("[system_clock] time = %u us\n\n",us);
    fclose (myFile);

	
		for(j = 0; j < 15;j++){
			if(j == 16){
				printf("%d ", (int)test_val[0][j]);
				printf("\n");
			}
			else{
				printf("%d ", (int)test_val[0][j]);
			}
		}	 

 		
	 printf("\n \n \n");

	
		for(j = 0; j < 15;j++){
			if(j == 16){
				printf("%d ", (int)blurred2[0][j]);
				printf("\n");
			}
			else{
				printf("%d ", (int)blurred2[0][j]);
			}
		}	 

printf("\n");

}
