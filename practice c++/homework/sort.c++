#include <iostream>
using namespace std;

int my_sort(int list[], int listSize)
{

    int lowestList[listSize] = {};
    int lowTemp;

    for (int i = 0; i < listSize; i++)
    {
        std::cout << list[i] << +" ";
    }

    //looping the whole array
    for (int i = 0; i < listSize; i++)
    {
        // searching the lowest number of the array
        for (int j = 0; j < listSize; j++)
        {

            if (list[j] < list[j + 1])
            {
                lowTemp = list[j];
            }
            else
            {
                continue;
            }
            std::cout << lowTemp;
        }
        lowestList[i] = lowTemp;
        std::cout << "lowtemp" << lowTemp << "\n";
        std::cout << "\n";
    }

    for (int i = 0; i < listSize; i++)
    {
        std::cout << lowestList[i] << +" ";
    }
}

int sort(int list[], int listSize)
{

    int min, temp;

    for (int i = 0; i < listSize; i++)
    {
        min = i; //가장 작은 수는 배열의 0번째다

        //배열의 두번째 값을
        for (int j = i + 1; j < listSize; j++)
        {
            if (list[j] < list[min])
            {
                min = j;
            }
        }
        // swap
        temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
}

int selection_sort(int list[], int n)
{
    int i, j, min, t;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (list[j] < list[min])
                min = j;
        t = list[i];
        list[i] = list[min];
        list[min] = t;
    }
}

int sort_new(int list[], int n)
{
    int i, j, min, t;

    for (i = 0; i < n; i++)
    {
        // min == 0;
        min = i;

        // j == 1;
        for (j = i + 1; j < n; j++)
            // list[1] < list[0]
            if (list[j] < list[min])
                min = j;

        // 0번째에 가장 작은 수가 가야함
        t = list[i];
        list[i] = list[min];
        list[min] = t;
    }
}

int main()
{
    int list[10] = {23, 11, 15, 8, 17, 33, 7, 14, 19, 21};

    int i;

    sort_new(list, 10);

    for (i = 0; i < 10; i++)
        std::cout << list[i] << "\n";
    return 0;
    return 0;
}