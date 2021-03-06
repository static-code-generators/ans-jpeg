#include <stdint.h>
#include <stdio.h>
#include <math.h>

int main(){

	uint8_t Q, S;

	uint8_t base[8][8] = {16, 11, 10, 16, 24, 40, 51, 61,
							12, 12, 14, 19, 26, 58, 60, 55,
							14, 13, 16, 24, 40, 57, 69, 56,
							14, 17, 22, 29, 51, 87, 80, 62,
							18, 22, 37, 56, 68, 109, 103, 77,
							24, 35, 55, 64, 81, 104, 113, 92,
							49, 64, 78, 87, 103, 121, 120, 101,
							72, 92, 95, 98, 112, 100, 103, 99 
							}; //Base matrix, quality factor = 50
 
	uint8_t quantMat[8][8]; //Quantization matrix, Quality factor = Q;
	int originDCT[8][8];

	scanf("%u", &Q);

	int a;
	if(Q == 50){
		/* Calculate original DCT coefficients */
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				scanf("%d", &a);
				originDCT[i][j] = a * base[i][j];	
			}
		}
	}
	else{
		/* Calculate S based on quality factor*/
		if(Q < 50)
			S = 5000 / Q;
		else
			S = 200 - 2 * Q;

		/*Calculate quantization matrix*/
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				quantMat[i][j] = floor((S * base[i][j] + 50) / 100);

				if(quantMat[i][j] == 0)
					quantMat[i][j] = 1;
			}
		}	

		/* Calculate original DCT coefficients */
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				scanf("%d", &a);
				originDCT[i][j] = a * quantMat[i][j];	
			}
		}
	}

	/* Print recalculated DCT coeff matrix */
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			printf("%d ", originDCT[i][j]);	
		}
		printf("\n");
	}


	return 0;
}