#include<iostream>
using namespace std;

class Arithematic
{
    private:
        int No1, No2;

    public:
        Arithematic(int A, int B)
        {
            this->No1 = A;
            this->No2 = B;
        }
        
        int Addition()
        {
            return No1+No2;
        }
        
        int Substraction()
        {
            return No1 - No2;
        }
};

int main()
{
    Arithematic aobj(11,10);

    cout<<aobj.Addition()<<"\n";
    cout<<aobj.Substraction()<<"\n";

    return 0;
}