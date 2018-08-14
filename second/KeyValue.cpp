#include "KeyValue.h"
#include "cstring"

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