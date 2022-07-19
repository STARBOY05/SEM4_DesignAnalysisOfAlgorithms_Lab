// Knapsack Problem (Greedy Algorithm)
#include <stdio.h>
#define MAX 10

// This structure stores Item_no, Item_wgt, Item_value, Item_ratio.
typedef struct item
{
	int num, weight;
	float value, ratio;
} item;
// This structure stores the list of items in array.
typedef struct Item_list
{
	item data[MAX];
	int n;
} Item_list;

Item_list L1;
// m_c=>Max Capacity of Knapsack, Items[]=>stores the selected items, x=>indexing for Items[]
int max_capacity, items[MAX], x = 0, n;
// Fraction=>Answer of Fractional Knapsack formula, p=sum of all profits
float fraction = 0.0, p = 0.0;
// Taking the Input
void get_input()
{
	int i;
	item temp;
	printf(" Enter the number of items: ");
	scanf("%d", &n);
	printf(" Enter the maximum capacity: ");
	scanf("%d", &max_capacity);
	L1.n = 0;
	for (i = 0; i < n; i++)
	{
		L1.data[i].num = i + 1;
		printf(" Enter the value and weight for Item-%d: ", i + 1);
		scanf("%f %d", &L1.data[L1.n].value, &L1.data[L1.n].weight);
		L1.data[L1.n].ratio = (float)L1.data[L1.n].value / (float)L1.data[L1.n].weight;
		L1.n++;
	}
}
// Sorting data according to the ratio in desc. order
void sort()
{
	int i, j;
	item temp;
	for (i = 0; i < L1.n - 1; i++)
	{
		for (j = 0; j < L1.n - i - 1; j++)
		{
			if (L1.data[j].ratio < L1.data[j + 1].ratio)
			{
				temp = L1.data[j];
				L1.data[j] = L1.data[j + 1];
				L1.data[j + 1] = temp;
			}
		}
	}
}
// To display the table
void display()
{
	int i;
	printf("\n");
	printf("Items\tValue\tWeight\tV / W");
	printf("\n");
	for (i = 0; i < L1.n; i++)
	{
		printf("%d\t", L1.data[i].num);
		printf("%.2f\t", L1.data[i].value);
		printf("%d\t", L1.data[i].weight);
		printf("%.2f\t", L1.data[i].ratio);
		printf("\n");
	}
}
// Knapsack Function
void knapsack()
{
	int i = 0, w = 0, M, x = 0;
	M = max_capacity;
	printf("Adding Items..");
	//	While current weight < Max Capacity
	while (L1.data[i].weight <= M)
	{
		//	If adding the next weight leads to excess => break
		if ((w + L1.data[i].weight) > M)
			break;
		//	else keep adding weight, profit, decrease max_capacity and add item_num to selected item_list (items[])
		else
		{
			w += L1.data[i].weight;
			p += L1.data[i].value;
			M -= L1.data[i].weight;
			items[x] = L1.data[i].num;
			x++;
		}
		i++;
	}
	//	Finally, when excess condition is met, use fractional formula
	fraction = (float)M / (float)(L1.data[i].weight);
	w += L1.data[i].weight * fraction;
	p += L1.data[i].value * fraction;
	items[x] = L1.data[i].num;
}
// Final Output (Selected Items & Max Profit)
void final_output()
{
	int i;
	printf("\n\nSelected Items: ");
	for (i = 0; i < x; i++)
		printf("I%d ", items[i]);
	printf("I%d*%.2f", items[x], fraction);

	printf("\n\nMaximum Profit = %.2f", p);
}
int main()
{
	//  INPUT
	get_input();
	//  DISPLAY
	printf("\nBefore sorting");
	display();
	//  SORTING WITH RESPECT TO RATIO
	sort();
	printf("\nAfter sorting");
	display();
	//  KNAPSACK
	knapsack();
	//	FINAL OUTPUT
	final_output();
}
