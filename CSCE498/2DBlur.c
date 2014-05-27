////////////////////////////////////////////////////////////////////////////////////////////

////////2D Gaussian Blur////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <linux/videodev2.h>
#include <string.h>
#include "array.h"

int main()

{

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


		
}

