#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Search(int *a, int n, int key);
void Search_Seq(int *a, int n, int key);
void Search_Bin(int *a, int n, int key);
void BInsertSort(int a[], int n);

#define Row 5
#define Column 10
#define MaxInt 32767

int main()
{
    FILE *fp;
    int a[Row][Column], i, j, rand_num, choice, key, data_chosen[Column];
    if ((fp = fopen("SourceFile.txt", "r")) == NULL)
    {
        printf("The program fails to open ¡°SourceFile.txt¡±. \n");
        exit(-1);
    }
    for (i = 0; i < Row; i++)
    {
        for (j = 0; j < Column; j++)
        {
            fscanf(fp, "%d", a[i] + j);
            if (*(a[i] + j) == MaxInt)
                break;
        }
    }
    printf("The row chosen randomly is ");
    srand(time(NULL));
    rand_num = rand() % 4;
    for (i = 1; i <= a[rand_num][0]; i++)
        printf("%d ", a[rand_num][i]);
    printf("\n");
    for (i = 0; i < a[rand_num][0]; i++)
        data_chosen[i] = a[rand_num][i + 1];
    printf("Which number do you want to search? ");
    scanf("%d", &key);
    Search(data_chosen, a[rand_num][0], key);
    free(a);
    fclose(fp);
    return 0;
}

void Search(int *a, int n, int key) {
	int rand_num;
	srand(time(NULL));
	rand_num = rand() % 2 + 1;
	switch (rand_num) {
	case 1:
		Search_Seq(a, n, key);
		break;
	case 2:
		Search_Bin(a, n, key);
		break;
	}
}

void Search_Seq(int *a, int n, int key) {
	int i;
	printf("This is sequential search.\n");
	for (i = 0; i < n; i++) {
		if (*a != key) {
			printf("The location at No.%d isn't the number we wanted to find.\n", i + 1);
		}
		if (*a == key) {
			printf("Find %d successfully. It is at No.%d .\n", key, i + 1);
			break;
		}
		a++;
	}
	printf("\n");
}

void Search_Bin(int *a, int n, int key) {
	int low, mid, high, counter = 1;
	printf("This is binary search.\n");
	BInsertSort(a, n);
	low = 1;
	high = n;
	while (low <= high) {
		mid = (low + high) / 2;
		if (*(a + mid) == key) {
			break;
		} else if (*(a + mid) > key) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
		printf("The %d step: No found.\n", counter);
		counter++;
	}
	if (low <= high) {
		printf("The %d step: Find %d successfully.\n", counter, key);
	} else {
		printf("Can't find %d.\n", key);
	}
	printf("\n");
}

void BInsertSort(int a[], int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < i + 1; j++) {
			if (a[i + 1] < a[j]) {
				temp = a[i + 1];
				a[i + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

