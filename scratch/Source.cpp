#include <iostream>

int GetValue()
{
	return 10;
}

int& GetValueReference()
{
	static int value = 10;
	return value;
}

void SetValue(int value)
{

}
// can be given an r value or l value

void SetValue(int& value)
{

}
// can be given only an l value
//l value reference

void SetValue(int&& value)
{

}
// can be given only an r value
// r value reference

void SetValue(const int& value)
{

}
// can be given an r value or l value

int main()
{
	//l values are references to a location in memory
	//r values are values
	//l values can be assigned a new value
	//while r values cant


	int i = 10; 

	// i is an l value - contains a reference in memory
	// 10 is an r value - is a value

	int a = 10;
	int b = a;

	// both a and b are l value

	int c = GetValue();

	//GetValue is still an r value given that even if it return an int, it just return one value

	int d = GetValueReference();

	//GetValueReference is an l value reference and can be assigned too

	SetValue(i);
	SetValue(10);

}