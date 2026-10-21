
#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int **data;

public:
    Matrix(int m, int n)
    {
        rows = m;
        cols = n;

        data = new int*[rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    // Deep copy constructor
    Matrix(const Matrix &obj)
    {
        rows = obj.rows;
        cols = obj.cols;

        data = new int*[rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++)
            {
                data[i][j] = obj.data[i][j];
            }
        }
    }

    void input()
    {
        cout << "Enter matrix elements:" << endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> data[i][j];
            }
        }
    }

    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }

            cout << endl;
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }

        delete[] data;

        cout << "Matrix memory released." << endl;
    }
};

int main()
{
    int m, n;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    if (m <= 0 || n <= 0)
    {
        cout << "Invalid matrix dimensions." << endl;
        return 1;
    }

    Matrix A(m, n);

    A.input();

    cout << "\nOriginal Matrix:" << endl;
    A.display();

    Matrix B = A;  // Calls deep copy constructor

    cout << "\nCopied Matrix:" << endl;
    B.display();

    return 0;
}
