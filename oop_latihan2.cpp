#include <iostream>
using namespace std;

class MHS {
    private:
        string MHSname;

	public:
        MHS(string n){
            MHSname = n;
        }
        string getName(){
            return MHSname;
        }
};

int main(){
    MHS mhs1("tes");
    cout << "MHS name is : " << mhs1.getName() << endl;

    MHS mhs2("Muhammad Ali");
    cout << "MHS name is : " << mhs2.getName() << endl;

    return 0;
}