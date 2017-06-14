#include <vector>
#include <iostream>
using namespace std;

void Printing (vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        for (int j = i-1; j >= 0; j--)
        {
            if (arr[j] > value)
            {
                arr[j+1] = arr[j];
                if (j == 0)
                {
                    arr[0] = value;
                }
            }
            else 
            {
                arr[j+1] = value;
                break;
            }
        }
    }
    Printing (arr,n);
}
