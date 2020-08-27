#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cctype>
#include<string.h>
struct people{                                  // <------------ struct
	char name[25];
	char last[25];
};
float averageWeight(float* p,int count)            //<--------------Function
{
	float sum=0, av=0;
	for(int i=0;i<count;i++)
	{ 
		sum += *(p + i);
	}
	av = sum/count;
	return av;
}
float averageHeight(float* p, int count)
{
	float sum = 0, av = 0;
	for (int i = 0; i < count; i++)
	{
		sum += *(p + i);
	}
	av = sum / count;
	return av;
}
int main()														
{
	struct people x[50];			
	char temp[25];
	float height[50], weight[50];
	int count, temp1;	
	printf("Enter number of people = ");
	scanf("%d", &count);
	if (count < 1 || count>50)	//Expression and or
	{
		printf("ERROR");
		return 0;
	}
	printf("\n\nName lastname weight height\n\n");
	for (int i = 0; i < count; i++)													//<------------------loop
	{
		scanf("%s %s %f %f", x[i].name, x[i].last, &weight[i], &height[i]);
		x[i].name[0] = toupper(x[i].name[0]);
		x[i].last[0] = toupper(x[i].last[0]);
	}
	for (int i = 0; i < count-1; i++)										//<----------Nested loop
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (strcmp(x[j].name, x[j + 1].name) > 0)
			{
				strcpy(temp, x[j].name);
				strcpy(x[j].name, x[j + 1].name);
				strcpy(x[j + 1].name, temp);
				strcpy(temp, x[j].last);
				strcpy(x[j].last, x[j + 1].last);
				strcpy(x[j + 1].last, temp);
				temp1 = weight[j];
				weight[j] = weight[j+1];
				weight[j+1] = temp1;
				temp1 = height[j];
				height[j] = height[j+1];
			}
		}
	}
	printf("\n-----------------------------------------------\n");
	for (int i = 0; i < count; i++)
	{
		printf("%s %s %.1f %.1f\n", x[i].name, x[i].last,weight[i],height[i]);
	}
	float* pw = &weight[0];        // <---------------------------------------------------------pointer!
	float* ph = &height[0];
	printf("\n\n-----------------------------------------------\n\n");
	printf("Average weight is %.2f\n",averageWeight(pw,count));
	printf("Average height is %.2f\n", averageHeight(ph, count));
}