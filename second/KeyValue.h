#pragma once
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