#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

// List of prime numbers
vector<int> primes;
// Create bitset for 1000 numbers
bitset<10010> bs;

// Create a list of prime numbers in range[1..N]
void listOfPrime(int N)
{
    primes.push_back(1);
    for (int i = 2; i <= N; i++)
    {
        if (bs[i])
        {
            for (int j = i * i; j <= N; j+=i)
            {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

// Print to console
void Printing(int N, int C)
{
    cout << N << " " << C << ":";
    int size = primes.size();
    int numbers = 2 * C;
    if (numbers-1 > size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << " " << primes[i];
        }
        cout << "\n\n";
        return;
    }
    else if (size % 2 == 0)
    {
        int startPos = 0 + (size - numbers) /2;
        int endPos = startPos + numbers - 1;
        for (int i = startPos; i <= endPos; i++)
        {
            cout << " " << primes[i];
        }
        cout << "\n\n";
        return;
    }
    else
    {
        int startPos = 0 + (size - numbers + 1)/2;
        int endPos = startPos + numbers - 2;
        for (int i = startPos; i <= endPos; i++)
        {
            cout << " " << primes[i];
        }
        cout << "\n\n";
        return;
    }
}

int main()
{
    int N, C;
    while(scanf("%d %d", &N, &C) == 2)
    {
        primes.clear();
        // set all bits equal 1
        bs.set();
        // 0 and 1 are not prime numbers
        bs[0] = 0;
        bs[1] = 0;
        // Create a list of prime numbers
        listOfPrime(N);
        // STDOUT
        Printing(N,C);
    }
    return 0;
}