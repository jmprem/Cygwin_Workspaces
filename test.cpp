#include <stdio.h>

//#define my_sizeof(T)	((((typeof(T)*) 0) + 1) - ((typeof(T)*) 0))
#define my_sizeof(T)	((char*)(((typeof(T)*) 0) + 1) - (char*)((typeof(T)*) 0))

#define my_offset(T,E)    (size_t)(&(((typeof(T)*)(0))->E))

struct test{
	int d11;
	int d12;
	int d13;
	int d14;
	char c;
//	short s;
	long double d2;
};

int main()
{
	int i = 0;
	int k = 10;
	char c;
	short  s = 10;
	long int l = 40;
	long long int ll = 100;
	float f = 1.0f;
	double d = 4.0;
	long double ld = 5.0;
	struct test mytest;
	
	//printf("Offset of s = %d\n", my_offset(struct test, s));
	printf("Offset of d2 = %d\n", my_offset(mytest, d2));
	printf("size of mytest = %d\n", my_sizeof(mytest));
	printf("size of struct test = %d\n", my_sizeof(struct test));
	
	typeof(s)* s2 = &s;
	s = 20;
	printf ("i = %d\n", i);
	printf ("s = %d\n", *s2);
	
	i = my_sizeof(k);
	printf("Size of int = %d\n", i);

	i = my_sizeof(l);
	printf("Size of long = %d\n", i);

	i = my_sizeof(ll);
	printf("Size of long long = %d\n", i);

	i = my_sizeof(f);
	printf("Size of float = %d\n", i);

	i = my_sizeof(d);
	printf("Size of double = %d\n", i);

	i = my_sizeof(ld);
	printf("Size of long double = %d\n", i);

	return 0;
}