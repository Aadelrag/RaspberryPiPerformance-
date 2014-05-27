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

int main() {
int i,j,k, outer_i, outer_j,image_i,image_j;
float sum; 
int tile_height = 120;
int tile_width = 160;
int n = 7;
float g[7] = {0.0111, 0.1353, .6065, 1.0000, .6065, .1353, .0111};
int rows = 480;
int columns = 640; 
 
unsigned short image[480][640];
unsigned short blurred[480][640];
unsigned short blurred2[480][640];

for(outer_i = 0; outer_i < rows / tile_height; outer_i++){

	for(outer_j = 0; outer_j < columns / tile_width; outer_j++){

		

		//Row Pass

		for(i = 0; i < tile_height; i++){



			image_i = outer_i * tile_height	+ i;



			for(j = 0; j < tile_width; j++){

				

				sum = 0;

				for(k = 0; k < n; k++){



					image_j = outer_j * tile_width + j + k - (int)(floor(n/2));

					if((image_j > 0) && (image_j < columns)){
						//printf("ITER i %d and Iter j %d", image_i, image_j);

						sum = sum + test_val[image_i][image_j]*g[k];

					}



				}
                ((unsigned short) (sum));
				blurred[i][j] = sum;

			} 	

		}



		//Columns Pass

		for(i = 0; i < tile_height; i++){

			for(k = 0; k < n; k++){

				for(j = 0; j < tile_width; j++){



					image_j = outer_j * tile_width + j;

					sum = 0;

					image_i = outer_i * tile_height + i + k - (int)(floor(n/2));

					if((image_i > 0) && (image_i < rows)){

						sum = sum + test_val[image_i][image_j]*g[k];

					}



				}
((unsigned short) (sum));

				blurred2[i][j] = sum;

			} 	

		}

	}

}

 for(i = 0; i < 15;i++){

	printf("%d ",test_val[0][i]);

}
printf("\n");
 for(i = 0; i < 15;i++){

	printf("%d ",blurred[0][i]);

}
printf("\n");
}



