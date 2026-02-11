#include <iostream>

using namespace std;

int main()
{

    int arr[] = {10,20,90,30,80,40,70,50,60};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min= arr[0];
    int max= arr[0];

    for(int i=1; i<n; i++)
    {
        if(arr[i] > max)
        max = arr[i];

        if(arr[i] < min)
        min = arr[i];
    }
    cout << "Max: " << max<<endl;
    cout << "Min: " << min;

    //cout << "Hello world!" << endl;
    return 0;
}
