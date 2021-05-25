#include <iostream>
using namespace std;
//Column Major
struct Matrix
{
    int *A;
    int n;// order of the square matrix.
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i>=j)
    {
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+(i-j)]=x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i>=j)
    {
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+(i-j)];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i>=j)
            {
                cout <<m.A[m.n*(j-1)+(j-2)*(j-1)/2+(i-j)]<<" ";
            }
            else
            {
                cout <<"0 ";
            }
        }
        cout <<"\n";
    }
}

int main()
{
    struct Matrix m;
    int x;
    cout <<"Enter the dimension\n";
    cin >>m.n;
    m.A= new int[(m.n)*(m.n+1)/2];// Size of the array A is number of the non zero numbers in the lower matrix.
    cout <<"Enter all the elements of the matrix\n";
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            cin >>x;
            Set(&m, i, j, x);
        }
    }
    cout <<"\n\n";
    Display(m);
    return 0;
}