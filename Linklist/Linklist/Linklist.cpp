#include <iostream>
using namespace std;

class list {
private:
	int number;
	int *arr;
public:
	list()
	{
		number = 0;
		arr = nullptr;
	}
	void add(int num)
   {   
	    number++;
		int*temp = arr;
		arr = new int[number];
		for (int i = 0; i < number-1; i++) {
			arr[i] = temp[i];
		}
		delete[] temp;
		arr[number - 1] = num;
	}
	void display()
	{
		for (int i = 0; i < number; i++) {
			cout << arr[i] << "\t";
		}
	}
};

int main() {
	list a;
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(1);
	a.display();
	return 0;

}