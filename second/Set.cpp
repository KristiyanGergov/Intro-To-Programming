#include "Set.h"
#include <iostream>

using namespace std;

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