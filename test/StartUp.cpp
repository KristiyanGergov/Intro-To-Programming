#include <iostream>

class Test {
private:
	int a;
public:
	Test(int a);
	int getA();
};

Test::Test(int a)
{
}

int Test::getA()
{
	return a;
}



int main() {
	Test test = Test(5);
	
	std::cout << test.getA(); 

	return 0;
}

