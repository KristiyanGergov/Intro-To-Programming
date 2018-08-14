#include <iostream>
#include "StartUp.h"
#include <math.h>
#include "cstring"

using namespace std;

class KeyValue
{
public:
	KeyValue() = default;
	KeyValue(const int key, const char* value);
	int getKey() const;
	int getValueCount() const;
private:
	int key;
	char value[50];
};

class Set
{
public:
	Set() = default;
	const KeyValue operator[](int key) const;
private:
	int findIndex(int key) const;
};

const int setSize = 30;

const KeyValue set[setSize] = {
	KeyValue(1, "one"),
	KeyValue(2, "two"),
	KeyValue(3, "three"),
	KeyValue(4, "four"),
	KeyValue(5, "five"),
	KeyValue(6, "six"),
	KeyValue(7, "seven"),
	KeyValue(8, "eight"),
	KeyValue(9, "nine"),
	KeyValue(10, "ten"),
	KeyValue(11, "eleven"),
	KeyValue(12, "twelve"),
	KeyValue(13, "thirteen"),
	KeyValue(14, "fourteen"),
	KeyValue(15, "fifteen"),
	KeyValue(16, "sixteen"),
	KeyValue(17, "seventeen"),
	KeyValue(18, "eighteen"),
	KeyValue(19, "nineteen"),
	KeyValue(20, "twelve"),
	KeyValue(30, "thirty"),
	KeyValue(40, "forty"),
	KeyValue(50, "fifty"),
	KeyValue(60, "sixty"),
	KeyValue(70, "seventy"),
	KeyValue(80, "eighty"),
	KeyValue(90, "ninety"),
	KeyValue(100, "hundred"),
	KeyValue(1000, "thousand"),
	KeyValue(10000, "tenthousand")
};

const KeyValue Set::operator[](int key) const
{
	int index = findIndex(key);
	if (index != -1)
		return set[index];
	cout << "Key: " << key << " does not exist in current database" << endl;
	return KeyValue();
}

int Set::findIndex(int key) const {
	for (size_t i = 0; i < setSize; i++)
		if (set[i].getKey() == key)
			return i;
	return -1;
}


KeyValue::KeyValue(const int key, const char * value)
{
	this->key = key;
	strcpy(this->value, value);
}

int KeyValue::getKey() const
{
	return this->key;
}

int KeyValue::getValueCount() const
{
	return strlen(this->value);
}

Set numbers = Set();

int getNumberWordsCount(int number) 
{
	int count = -1;
	int result = 0;

	while (number != 0)
	{
		int lastDigit = number % 10;
		number /= 10;
		count++;

		//0 is not pronounced so we just go ahead
		if (lastDigit == 0)
			continue;

		//logic for two-digit numbers
		if (count == 1) {
			result += numbers[lastDigit * 10].getValueCount();
			continue;
		}

		//logic for more tha two-digit numbers
		if (count > 1)
		{
			int index = (int)pow(10, count);
			result += numbers[index].getValueCount();
		}

		result += numbers[lastDigit].getValueCount();
	}
	return result;
}

int main() {
	int number;
	cout << "Enter number (1 <= number <= 10 000): ";
	cin >> number;

	// validation
	if (1 > number || number > 10000)
	{
		cout << "Number '" << number << "' not in range!" << endl;
		return 0;
	}

	//logic for 10000 is different so we just make manual check
	if (number == 10000)
	{
		cout << numbers[1000].getValueCount() + numbers[10].getValueCount() << endl;
		return 0;
	}

	cout << getNumberWordsCount(number) << endl;
	return 0;
}