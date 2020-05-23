#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* intal_add(char* intal1, char* intal2);
static void reverse(char*intal,int n);
int intal_compare(char* intal1, char* intal2);
char* intal_diff(char* intal1, char* intal2);
static int max(int a,int b);
char* intal_mod(char* intal1, char* intal2);
char* intal_pow(char* intal1, int pow);
char* intal_multiply(char* intal1, char* intal2);
char* intal_gcd(char* intal1, char* intal2);
static char *devideBytwo(char *intal1,int num);
char* intal_fibonacci(unsigned int n);
static char *devide(char*intal1,char*intal2);
char* intal_factorial(unsigned int n);
int intal_max(char **arr, int n);
int intal_min(char **arr, int n);
char* coin_row_problem(char **arr, int n);
char* intal_bincoeff(unsigned int n, unsigned int k);
int intal_search(char **arr, int n, char* key);
void intal_sort(char **arr, int n);
static void mergeSort(char **arr,int start,int end);
int intal_binsearch(char **arr, int n, char* key);
static void merge(char **arr,int start,int end);
char* coin_row_problem(char **arr, int n);
static int partition(char **a,int start,int end);
static void quickSort(char **a,int start,int end);
static int partition(char **a,int start,int end)
{
	int i = start - 1;
	int j = start;
	char *pivot = (char*)malloc(sizeof(char)*1005);
	char *temp = (char*)malloc(sizeof(char)*1005);
	strcpy(pivot,a[end]);
	for(;j <= end - 1;++j)
	{
		int comp = intal_compare(a[j],pivot);
		if(comp == 0 || comp == -1)
		{
			++i;
			strcpy(temp,a[i]);
			strcpy(a[i],a[j]);
			strcpy(a[j],temp);
		}
	}
	strcpy(temp,a[i+1]);
	strcpy(a[i+1],a[end]);
	strcpy(a[end],temp);
	free(pivot);
	free(temp);
	return i+1;
}
static void quickSort(char **a,int start,int end)
{
	if(start >= end)
		return ;
	int pivot = partition(a,start,end);
	quickSort(a,start,pivot-1);
	quickSort(a,pivot+1,end);
}
void intal_sort(char **a,int n)
{
	return quickSort(a,0,n-1);
}
char* intal_mod(char* intal1, char* intal2)
{
	char *result = (char*)malloc(sizeof(char)*1005);
	if(intal_compare(intal1,intal2) == -1)
	{
		int i = 0;
		for(;i<strlen(intal1);++i)
			result[i] = intal1[i];
		result[i] = '\0';
		return result;
	}
	char *temp1 = (char*)malloc(sizeof(char)*1005);
	char*temp2 = (char*)malloc(sizeof(char)*1005);
	temp1 = devide(intal1,intal2);
	temp2 = intal_multiply(intal2,temp1);
	result = intal_diff(intal1,temp2);
	free(temp1);
	free(temp2);
	return result;
}
static char *devide(char*intal1,char*intal2)
{
	char one[] = "1";
	char *start = (char *)malloc(sizeof(char)*1005);
	char *end = (char*)malloc(sizeof(char)*1005);
	start[0] = '0';
	start[1] = '\0';
	char ten[] = "10";
	end = intal_add(intal1,ten);
	char *result = (char*)malloc(sizeof(char)*1005);
	char *mid = (char*)malloc(sizeof(char)*1005);
	char *temp = (char*)malloc(sizeof(char)*1005);
	char *temp1 = (char*)malloc(sizeof(char)*1005);
	while(intal_compare(start,end) == -1 || intal_compare(start,end) == 0)
	{
		temp = intal_diff(end,start);
		temp = devideBytwo(temp,2);
		mid = intal_add(start,temp);
		temp1 = intal_multiply(intal2,mid);
		int index = intal_compare(temp1,intal1);
		if(index == -1 || index == 0)
		{
			result = mid;
			start = intal_add(mid,one);
		}
		else
			end = intal_diff(mid,one);
	}
	free(mid);
	free(temp);
	free(temp1);
	free(start);
	free(end);
	return result;
}
char* intal_multiply(char* intal1, char* intal2)
{
	char *intal3 = (char*)malloc(sizeof(char)*1005);
	char *intal4 = (char*)malloc(sizeof(char)*1005);
	strcpy(intal3,intal1);
	strcpy(intal4,intal2);
 	int n1 = strlen(intal3);
	int n2 = strlen(intal4);
	int index_1 = 0;
	int index_2 = 0;
	reverse(intal3,n1);
	reverse(intal4,n2);
	int *result = (int*)malloc(sizeof(int) * 1005);
	char*result1 = (char*)malloc(sizeof(char) *1005);
	for(int i = 0;i < 1005;++i)
		result[i] = 0;
	int mul = 0;
	int size = 0;
	int carry = 0;
	for(int i = 0;i < n1;++i)
	{
		carry = 0;
		int num1 = intal3[i]-'0';
		index_2 = 0;
		for(int j = 0;j < n2;++j)
		{
			int num2 = intal4[j]-'0';
			mul = num1 * num2 + result[index_1+index_2] + carry;
			result[index_1+index_2] = (mul %10);
			carry = mul / 10;
			++index_2;
		}
		if(carry > 0)
		     result[index_1+index_2] += carry;
		++index_1;
		size = max(size,index_1 + index_2);
	}
	int temp = size - 1;
	while(result[temp] == 0)
		--temp;
	size = temp + 1;
	int j= 0;
	for(int i = size-1;i >= 0;--i)
		result1[j++] = (result[i] + '0');
	result1[size] = '\0';
	free(intal3);
	free(intal4);
	free(result);
	return result1;
}
char* intal_pow(char* intal1, int pow)
{
	char *result = (char *)malloc(sizeof(char)*1005);
	int i = 0;
	for(;i < strlen(intal1);++i)
		result[i] = intal1[i];
	result[i] = '\0';
	for(int i = 1;i < pow;++i)
		result = intal_multiply(result,intal1);
	return result;
}
char* intal_add(char* intal1, char* intal2)
{
	char *intal3 = (char *)malloc(sizeof(char)*1005);
	char *intal4 = (char *)malloc(sizeof(char)*1005);
	strcpy(intal3,intal1);
	strcpy(intal4,intal2);
	int n1 = strlen(intal3);
	int n2 = strlen(intal4);
	reverse(intal3,n1);
	reverse(intal4,n2);
	int carry = 0;
	int sum = 0;
	char *result = (char*)malloc(sizeof(char)*1005);
	int i = 0;
	int j = 0;
	int k = 0;
	while(j < n1 || k < n2)
	{
		sum = 0;
		if(j < n1)
			sum += (intal3[j++]-'0');
		if(k < n2)
			sum += (intal4[k++]-'0');
		sum += carry;
		result[i++] = (sum % 10)+'0';
		carry = sum / 10;
	}
	while(carry)
	{
		result[i++] = (carry%10) + '0';
		carry = carry / 10;
	}
	reverse(result,i);
	result[i] = '\0';
	free(intal3);
	free(intal4);
	return result;
}
static void reverse(char*intal,int n)
{
	int start = 0;
	int end = n - 1;
	while(start < end)
	{
		char temp = intal[start];
		intal[start] = intal[end];
		intal[end] = temp;
		++start;
		--end;
	}
}
int intal_compare(char* intal1, char* intal2)
{
	int i = 0;
	int j = 0;
	int n1 = strlen(intal1);
	int n2 = strlen(intal2);
	if(n1 > n2)
		return 1;
	if(n2 > n1)
		return -1;
	while(i < n1 && j < n2)
	{
		int num1 = (intal1[i] - '0');
		int num2 = (intal2[j] - '0');
		if(num1 > num2)
			return 1;
		else if(num2 > num1)
			return -1;
		else
		{
			++i;
			++j;
		}
	}
	return 0;
}
char* intal_diff(char* intal1, char* intal2)
{
	int comp = intal_compare(intal1,intal2);
	if(comp == -1)
		return intal_diff(intal2,intal1);
	char *intal3 = (char*)malloc(sizeof(char)*1005);
	char *intal4 = (char*)malloc(sizeof(char)*1005);
	strcpy(intal3,intal1);
	strcpy(intal4,intal2);
	int n1 = strlen(intal3);
	int n2 = strlen(intal4);
	reverse(intal3,n1);
	reverse(intal4,n2);
	char *result = (char*)malloc(sizeof(char) * 1005);
	int i = 0;
	int j = 0;
	int k = 0;
	int carry = 0;
	int sub = 0;
	while(k < n2)
	{
		sub = (intal3[j++]-'0') - (intal4[k++] - '0') - carry;
		if(sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		} 
		else
			carry = 0;
		result[i++] = (sub + '0');
	}
	while(j < n1)
	{
		sub = (intal3[j++]-'0') - carry;
		if(sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
		  carry = 0;
		result[i++] = (sub + '0');
	}
	int temp = i-1;
	while(result[temp] == '0')
		--temp;
	i = temp+1;
	reverse(result,i);
	result[i] = '\0';
	char *zero = (char *)malloc(sizeof(char)*2);
	zero[0] = '0';
	zero[1] = '\0';
	if(i == 0)
		return zero;
	free(intal3);
	free(intal4);
	return result;
}
int intal_binsearch(char **arr, int n, char* key)
{
	int start = 0;
	int end =  n - 1;
	int ans = -1;
	while(start <= end)
	{
		int mid = start + (end - start) / 2;
		int compRes = intal_compare(key,arr[mid]);
		if(compRes == 0)
		{
			ans = mid;
			end = mid - 1;
		}
		else if(compRes == 1)
			start = mid+1;
		else
			end= mid - 1;
	}
	return ans;
}

static char *devideBytwo(char *intal1,int num)
{
	char*zero = (char*)malloc(sizeof(char)*5);
	zero[0] = '0';
	zero[1] = '\0';
	char * ans = (char*)malloc(sizeof(char)*1005);
	int idx = 0;
	int temp = intal1[idx] - '0';
	while(temp < num)
		temp = temp * 10 + (intal1[++idx] - '0');
	int n =strlen(intal1);
	int i = 0;
	while(n > idx)
	{
		ans[i++] = ((temp/num) + '0');
		temp = (temp % num)*10 + intal1[++idx] - '0';
	}
	if(i == 0)
		return zero;
	ans[i] = '\0';
	return ans;
}
static int max(int a,int b)
{
	return a > b ? a : b;
}

char* intal_gcd(char* intal1, char* intal2)
{
	char zero[] = "0";
	char *result = (char*)malloc(sizeof(char)*1005);
	if(intal_compare(intal2,zero) == 0)
	{
		int i = 0;
		for(;i < strlen(intal1);++i)
			result[i] = intal1[i];
		result[i] = '\0';
		return result;
	}
	char *temp = (char*)malloc(sizeof(char)*1005);
	temp = intal_mod(intal1,intal2);
	if(strlen(temp) == 0)
		return intal_gcd(intal2,zero);
	return intal_gcd(intal2,temp);
}

char* intal_fibonacci(unsigned int n)
{
	char *a = (char*)malloc(sizeof(char)*1005);
	char *b= (char*)malloc(sizeof(char)*1005);
	char *result = (char*)malloc(sizeof(char)*1004);
	strcpy(a,"0");
	strcpy(b,"1");
	if(n == 0)
		return a;
	if(n == 1)
		return b;
	for(int i = 2;i <= n;++i)
	{
		result = intal_add(a,b);
		a = b;
		b = result;
	}
	free(a);
	free(b);
	return result;
}
char* intal_factorial(unsigned int n)
{
	char*result = (char*)malloc(sizeof(char)*1005);
	char *temp = (char*)malloc(sizeof(char)*1005);
	strcpy(result,"1");
	for(int i = 1;i <= n ;++i)
	{
		int size = 0;
		int n = i;
		while(n)
		{
			int rem = n % 10;
			temp[size++] = (rem+'0');
			n/=10;
		}
		temp[size]= '\0';
		reverse(temp,size);
		result = intal_multiply(result,temp);
	}
	free(temp);
	return result;
}
char* intal_bincoeff(unsigned int n, unsigned int k)
{
	char *result = (char*)malloc(sizeof(char)*1005);
	char *temp1 = (char*)malloc(sizeof(char)*1005);
	char *temp2 = (char*)malloc(sizeof(char)*1005);
	strcpy(result,"1");
	if(k > n-k)
		k = n-k;
	for(int i = 0;i < k;++i)
	{
		int num1 = n - i;
		int num2 = i+1;
		int size1 = 0;
		int size2 = 0;
		while(num1)
		{
			int rem = num1 % 10;
			temp1[size1++] = (rem+'0');
			num1/=10;
		}
		temp1[size1] = '\0';
		reverse(temp1,size1);
		while(num2)
		{
			int rem = num2 % 10;
			temp2[size2++] = (rem + '0');
			num2 /= 10;
		}
		temp2[size2] = '\0';
		reverse(temp2,size2);
		result = intal_multiply(result,temp1);
		result = devide(result,temp2);
	}
	free(temp1);
	free(temp2);
	return result;
}
int intal_max(char **arr, int n)
{	
	int index=0;
	char *max_intal = (char*)malloc(sizeof(char)*1005);
	int i = 0;
	int size = strlen(arr[0]);
	for(;i < size;++i)
		max_intal[i] = arr[0][i];
	max_intal[i] = '\0';
	for(int j = 1;j < n;++j)
	{
		if(intal_compare(arr[j],max_intal) == 1)
		{
			index  = j;
			i = 0;
			for(;i < strlen(arr[j]);++i)
				max_intal[i] = arr[j][i];
			max_intal[i] = '\0';
		}
	}
	free(max_intal);
	return index;
}

int intal_min(char **arr, int n)
{
int index=0;
	char *max_intal = (char*)malloc(sizeof(char)*1005);
	int i = 0;
	int size = strlen(arr[0]);
	for(;i < size;++i)
		max_intal[i] = arr[0][i];
	max_intal[i] = '\0';
	for(int j = 1;j < n;++j)
	{
		if(intal_compare(arr[j],max_intal) == -1)
		{
			index  = j;
			i = 0;
			for(;i < strlen(arr[j]);++i)
				max_intal[i] = arr[j][i];
			max_intal[i] = '\0';
		}
	}
	free(max_intal);
	return index;	
}
int intal_search(char **arr, int n, char* key)
{
	int index = -1;
	for(int i = 0;i < n;++i)
	{
		if(intal_compare(arr[i],key) == 0)
			return i;
	}
	return -1;
}
char* coin_row_problem(char **arr, int n)
{
	char *prevNo = (char *)malloc(sizeof(char)*1005);
	char *prevYes = (char *)malloc(sizeof(char) *1005);
	char zero[] =  "0";
	strcpy(prevNo,zero);
	strcpy(prevYes,zero);
	char *temp = (char *)malloc(sizeof(char)*1005);
	char *temp2 = (char*)malloc(sizeof(char)*1005);
	int res;
	for(int i = 0;i < n;++i)
	{
		strcpy(temp,prevNo);
		res = intal_compare(prevNo,prevYes);
		if(res == 0 || res == -1)
			strcpy(prevNo,prevYes);
		temp2 = intal_add(arr[i],temp);
		strcpy(prevYes,temp2);
	}
	res = intal_compare(prevNo,prevYes);
	char *result = (char *)malloc(sizeof(char)*1005);
	if(res == 1)
		strcpy(result,prevNo);
	else
		strcpy(result,prevYes);
	free(prevNo);
	free(prevYes);
	free(temp);
	free(temp2);
	return result;
}
