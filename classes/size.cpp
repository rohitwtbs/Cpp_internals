#include <iostream>

using namespace std;

class User {
    private:
    int i;
    float f;
    char c;
    public:
    void displayData(){
        cout<<i<<"\n"<<f<<"\n"<<c<<endl;
    }
};

int main(){
    cout << sizeof(User)<<endl;
    User u1;
    cout << sizeof(u1)<<endl;
    u1.displayData();
    return 0;
}



// dummy output

// 12
// 12
// 12677116
// 1.4013e-45
// �