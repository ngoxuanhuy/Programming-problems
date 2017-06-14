#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<char> inputVector;
    string input;
    while (1)
    {
        cin >> input;
        if (input == "#")
        {
            break;
        }
        inputVector.clear();
        for (int i = 0; i < input.size(); i++)
        {
            inputVector.push_back(input[i]);
        }
        if (next_permutation(inputVector.begin(),inputVector.end()))
        {
            for (int i = 0; i < input.size(); i++)
            {
                cout << inputVector[i];
            }
            cout << endl;
        }
        else 
        {
            cout << "No Successor" << endl;
        }
    }
    return 0;
}