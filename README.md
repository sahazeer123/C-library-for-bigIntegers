C Library for big Integer : As in Java and cpp, which has separate library for dealing with big integers, c doesen't
have any separate libaray.Largest number it can store is in data type long long int which can hold upto 10^18 digits.
So the result of 100! which has digits 152 can't be handled using long long int.So I developed separte libarary to deal
with such large number.Intal is basically a character array which stores digits as char type.So using intal type we can
deal with any large number.


IMPLEMENTATION:
char *intal_add(char*,char*): for addition first I reverse both intals given as parameter as it is easy to deal.Then traverse the both intals update the sum and while returning the answer the result has to be reversed again as we have 
reversed the parameter

char *intal_compare(char*,char*):it is done by matching character by character from most signigicat digit.Whenever I get
digit greater than other digit,that number will be largest

char *intal_diff(char*,char*):substraction is done by using normal method, where I traverse the both intals till the end and
update the difference accordingly.Both parameters are reversed at the beginning so that it would be easier to deal.

char *intal_multiply(char*,char*):start from last digit of second number multiply with first number.Then multiply second digit of second number, and so on.We add all these multiplication.

char *intal_mod(char*,char *):for mod I used intersting algorithm. a= bq +r ,remainder = a - bq; for this equation I need to find the quotient. So I used binary search for division using equation a/b <= target ,a <= (b * target).which gives quotient in most efficient time;

char* intal_pow(const char* intal1, unsigned int n):for power function internally uses multiply function n times

char* intal_gcd(const char* intal1, const char* intal2):for gcd I used euclid algorithm gcd(a,b) = gcd(b,a%b), So this function internally uses mod function

char* intal_fibonacci(unsigned int n) : for fibonacci number it is just using intal_add function and strcpy function for moving values between temporary varibles

char* intal_bincoeff(unsigned int n, unsigned int k) : uses o(k) space.

int intal_max(char **arr, int n) : traverse the entire array . keep track of largest number using intal_compare function

int intal_min(char **arr, int n) : traverse the entire array . keep track of smallest number using intal_compare function

int intal_search(char **arr, int n, const char* key): linear search algorithm.Traverse the array and check if current element equals key using intal_compare function

int intal_binsearch(char **arr, int n, const char* key): binary search algorithm.Classical binary search only change is we are dealing with intals here

void intal_sort(char **arr, int n): I used quick sort to sort the array .which takes o(nlogn) on average and o(n^2) in the worst case.constant space

char* coin_row_problem(char **arr, int n):coin row problems uses O(1) constant space
