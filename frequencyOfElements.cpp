#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter Array size: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements of Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Frequency of elements check
    // here res_array[][] will help us to determine whether the element has already been visited or not
    //(i.e, count has/hasn't been done for the selected element)
    // and will store the elements and its count/frequency.
    int res_array[size][size];
    int c = 0; // Counter/index for res_array[][]/ for assigning values to it.
    for (int i = 0; i < size; i++)
    {
        bool visited = false;
        for (int x = 0; x < size; x++)
        { // this loop checks whether we already visited the element arr[i] or not.
            // that is, whether it is present in our result array or not.
            if (arr[i] == res_array[x][0])
            {
                visited = true;
                break;
            }
        }

        int count = 0;
        if (!visited)
        { // only if the element (arr[i]) is not present in our result array, i.e, not visited
            for (int j = 0; j < size; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            // index [c][0] contains elements itself
            // index [c][1] contains the count
            res_array[c][0] = arr[i];
            res_array[c][1] = count;
            c++;

            // cout << arr[i] << " : " << count << endl;
        }
    }
    // Printing on the screen
    cout << "Frequency of elements: " << endl;
    for (int i = 0; i < c; i++)
    {
        cout << res_array[i][0] << " : " << res_array[i][1] << endl;
        ;
    }
}