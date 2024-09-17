#include <iostream>
using namespace std;
class triplets
{
	private:
		int t1, t2, t3;
	public:
        // a zero constructor is necessary, otherwise compile time error will be there
        // triplets(){}
		triplets(int x, int y, int z)
		{
			t1 = x;
			t2 = y;
			t3 = z;
		}
		void display()
		{
			cout << endl << t1 << t2 << t3;
		}
};

int main()
{
	triplets r(2,3,4), s;
	r.display();
	s.display();
	return 0;
}