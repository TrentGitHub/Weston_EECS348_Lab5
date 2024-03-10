#include <stdio.h>
#include <string.h>

#define NUMMONTHS 12

char months[12][11] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
double sales[NUMMONTHS];
int monthIndex[NUMMONTHS];

void get_sales() {
FILE *file = fopen("sales.txt", "r");
if (file != NULL) {
	for(int i = 0; i < NUMMONTHS; ++i){
		fscanf(file, "%lf", &sales[i]);
		monthIndex[i] = i;
		}
fclose(file);
} else {
	perror("Error opening file");
}
}

void salesSummaryMin(){
	double currMin = sales[0];
	char currMinMonth[11];
	strcpy(currMinMonth, months[0]);
	for (int i = 0; i < NUMMONTHS; i++) {
		if (sales [i] < currMin) {
			currMin = sales[i];
			strcpy(currMinMonth, months[i]);
		}
	}
	printf("Minimum sales:\t");
	printf("$%.2f\t", currMin);
	printf("%s\t", currMinMonth);
}

void salesSummaryMax(){
	double currMax = sales[0];
	char currMaxMonth[11];
	strcpy(currMaxMonth, months[0]);
	for (int i = 0; i < NUMMONTHS; i++) {
		if (sales [i] > currMax) {
			currMax = sales[i];
			strcpy(currMaxMonth, months[i]);
		}
	}
	printf("Maximum sales:\t");
	printf("$%.2f\t", currMax);
	printf("%s\t", currMaxMonth);
}

void salesSummaryAverage(){
	double average = 0;
	for (int i = 0; i < NUMMONTHS; i++) {
		average += sales[i];
		}
	average /= NUMMONTHS;
	printf("Average sales:\t");
	printf("$%.2f\t", average);
}

void movingAverage(){
	printf("\n");
	printf("Six-Month Moving Average Report:\n");
	for (int i = 5; i < NUMMONTHS; i++) {
		double sum = 0;
		for (int j = i - 5; j <= i; j++) {
			sum += sales[j];
		}
		double movAvg = sum/6;
		printf("%-11s - %-11s $%.2f\n", months[i-5], months[i], movAvg);
	}
}


void sortSalesDescending() {
    for (int i = 0; i < NUMMONTHS - 1; i++) {
        for (int j = 0; j < NUMMONTHS - i - 1; j++) {
            if (sales[j] < sales[j + 1]) {
                // Swap sales
                double temp = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = temp;
                
                // Swap corresponding month indices
                int tempIndex = monthIndex[j];
                monthIndex[j] = monthIndex[j + 1];
                monthIndex[j + 1] = tempIndex;
            }
        }
    }
}

void printSalesReportDescending() {
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < NUMMONTHS; i++) {
        printf("%-11s $%.2f\n", months[monthIndex[i]], sales[i]);
    }
}


int main() {
	get_sales();
    printf("Monthly sales report for 2022:\n");
    int i;
    for(i=0; i < NUMMONTHS; i++){
        printf("$%.2f\t", sales[i]);
        printf("%s", months[i]);
		printf("\n");
		}
	printf("\n");
	printf("Sales Summary:\n");
	salesSummaryMin();
	printf("\n");
	salesSummaryMax();
	printf("\n");
	salesSummaryAverage();
	printf("\n");
	movingAverage();
	printf("\n");
	sortSalesDescending();
	printSalesReportDescending();
	printf("\n");
	}








