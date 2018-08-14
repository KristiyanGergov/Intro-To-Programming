#pragma once
#include "KeyValue.h"
class Set
{
public:
	Set() = default;
	const KeyValue operator[](int key) const;
private:
	int findIndex(int key) const;
};