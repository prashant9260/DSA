#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

        ArrayX(int no)
        {
            cout<<"Inside constructor\n";
            iSize = no;
            Arr = new int[iSize];
        }

        ~ArrayX()
        {
            cout<<"Inside destructor\n";
            delete [] Arr;
        }

        void Accept()
        {
            int iCnt = 0;

            cout<<"Enter the elements : \n";

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display()
        {
            int iCnt = 0;

            cout<<"Elements of the array are : \n";

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<"\n";
        }

        bool LinearSearch(int iNo)
        {
            bool bFlag = false;
            int i = 0;

            for(i = 0; i < iSize; i++)
            {
                if(Arr[i] == iNo)
                {
                    bFlag = true;
                    break;
                }
            }

            return bFlag;
        }

        bool BiDirectionalSearch(int iNo)
        {
            bool bFlag = false;
            int iStar = 0;
            int iEnd = 0;

            for(iStar = 0, iEnd = iSize-1; iStar <= iEnd; iStar++, iEnd++)
            {
                if(Arr[iStar] == iNo || Arr[iEnd] == iNo)
                {
                    bFlag = true;
                    break;
                }
            }

            return bFlag;
        }
};

int main()
{   
    int iValue = 0;

    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    ArrayX aobj(iValue); 
    
    aobj.Accept();

    aobj.Display();

    if(aobj.LinearSearch(21))
    {
        cout<<"Element is present\n";
    }
    else
    {
        cout<<"Element is not present\n";
    }

    if(aobj.BiDirectionalSearch(21))
    {
        cout<<"Element is present\n";
    }
    else
    {
        cout<<"Element is not present\n";
    }

    return 0;
}