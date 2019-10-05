/*
 ============================================================================
 Name        : CGOLUsing.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main() {
	setbuf(stdout,NULL);
	int i, j, m, n, l, k;
	printf("Enter the natural numbers for the number of rows and columns:\n");

	scanf("%d%d",&m,&n); // scanning m and n for getting
	                     //the number of rows and columns
	int arr[m][n];        // array with m rows and n columns


	printf("Only 0 and 1 are allowed for scanning!!\n");

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &arr[i][j]); // scanning the elements of array
			}
	}
	printf("\nInput\n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d", arr[i][j]); //printing the array given as input
		}
		printf("\n");
	}

	//Rules of CGOL
	//1. if dead cell has 3 living neighbours, it lives again;
	//2. if living cell has less than 2 living neighbours, it dies of loneliness;
	//3. if living cell has more than 3 living neighbours, it dies of overpopulation;
	//4. if living cell has exactly 3 or exactly 2 neighbours, it lives on;

	printf("Enter the number of generations you want to be printed:\n");

	scanf("%d", &l); // scanning number of generations

	for(k=0; k<l; k++){
	for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					int total=0;
					total= total+arr[i-1][j-1];
					total= total+arr[i-1][j];
					total= total+arr[i-1][j+1];
					total= total+arr[i][j-1];
					total= total+arr[i][j+1];
					total= total+arr[i+1][j-1];
					total= total+arr[i+1][j];
					total= total+arr[i+1][j+1];

					if(arr[i][j]==1)     //if cell is alive
					{
						switch(total)
						{
						case 0:
						case 1:
							arr[i][j]=0;  // if it has less than 2 live
							              // neighbours, it dies
							break;
						case 2:
						case 3:
							arr[i][j]=1;  // if it has 2 or 3 live
							              //neighbours, it remains alive
							break;
						case 4:
						case 5:
						case 6:
						case 7:
						case 8:
							arr[i][j]=0;  // if more than 3 live, it dies
						    break;
						    default:
						    	arr[i][j]=0;
						}
					}

					else if(arr[i][j]==0){  // when cell is dead
						switch(total){
						case 3:
						arr[i][j]=1;      // gets alive when it has exactly 3 live neighbours
						break;
						default:
						arr[i][j]=0;
						}
						}

					else{
						printf("Only 0 and 1 are allowed");
					}
					}

			}

	printf("Generation %d:", k+1);

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d", arr[i][j]);// printing the array
				                    //after implementation of CGOL rules
		}
		printf("\n");
	}
	}
}
