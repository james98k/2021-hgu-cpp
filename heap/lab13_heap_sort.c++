#include <iostream>
using namespace std;
#define S_SIZE 100

class s_record
{
public:
    string s_id;
    string l_name;
    double score;
    s_record();
    s_record(string s_id, string l_name, double score);
    void set_s_record(string s_id, string l_name, double score);
    void adjust(s_record h[], int t_root, int size);
    void quick_sort(s_record a[], int left, int right);
    void heap_sort(s_record a[], int n);
    void heap_sort2(s_record a[], int n);
    void merge_sort(s_record a[], int n);
    void merge_pass(s_record a[], s_record b[], int n, int s);
    void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4);
    void show_thelist(s_record s_list, int n);
};
s_record::s_record()
{
    s_id = "";
    l_name = "";
    score = 0.0;
}
s_record ::s_record(string s_id, string l_name, double avaerage)
{
    this->s_id = s_id;
    this->l_name = l_name;
    this->score = avaerage;
}
void s_record::set_s_record(string s_id, string l_name, double score)
{
    this->s_id = s_id;
    this->l_name = l_name;
    this->score = score;
}

void s_record::adjust(s_record h[], int t_root, int size)
{

    int child;
    s_record tmp;
    string key;

    tmp = h[t_root];       //1번 element 저장
    key = h[t_root].score; //key 값을 기반으로 정렬이 되기 때문에 첫번째 element의 key 저장
    child = 2 * t_root;    //왼쪽 child
    // std::cout << "child value :" << child << "\n";

    while (child <= size)
    {
        if ((child < size) && (h[child].s_id < h[child + 1].s_id))
            child++;
        if (key > h[child].s_id)
            break;
        else
        {
            h[child / 2] = h[child];
            child *= 2;
        }
    }
    h[child / 2] = tmp;
}
void s_record::quick_sort(s_record a[], int left, int right)
{
    s_record pivot, temp;
    int i, j;
    if (left >= right)
        return;
    i = left;
    j = right + 1;
    pivot = a[left];
    do
    {
        do
        {
            i++;
        } while ((i <= right) && (a[i].s_id < pivot.s_id));
        do
        {
            j--;
        } while (a[j].s_id > pivot.s_id);
        if (i < j)
            swap(a[i], a[j]);
    } while (i < j);
    swap(a[left], a[j]);
    quick_sort(a, left, j - 1);
    quick_sort(a, j + 1, right);
}

void s_record::heap_sort(s_record a[], int n)
{
    int i;
    s_record b[S_SIZE], temp;
    for (i = 0; i < n; i++) // 1부터 n번째까지로 위치 조정
        b[i + 1] = a[i];
    for (i = n / 2; i > 0; i--) // 주어진 입력에 대하여 heap 구성
        adjust(b, i, n);
    for (i = n - 1; i > 0; i--)
    {
        temp = b[1];
        b[1] = b[i + 1];
        b[i + 1] = temp;
        adjust(b, 1, i);
    }
}

void s_record::heap_sort2(s_record a[], int n)
{
    int i;
    s_record temp;
    int size = n - 1;
    for (i = (size - 1) / 2; i >= 0; i--)
        adjust(a, i, size);
    for (i = size - 1; i >= 0; i--)
    {
        temp = a[0];
        a[0] = a[i + 1];
        a[i + 1] = temp;
        adjust(a, 0, i);
    }
}
void s_record::merge_sort(s_record a[], int n)
{
    int s = 1;
    s_record b[S_SIZE];
    while (s < n)
    {
        merge_pass(a, b, n - 1, s);
        s *= 2;
        merge_pass(b, a, n - 1, s);
        s *= 2;
    }
}

// void show_thelist(s_record s_list[], int n){

// };
void s_record::merge_pass(s_record a[], s_record b[], int n, int s)
{
    int i, j;
    for (i = 0; i < (n - 2 * s + 1); i += 2 * s)
        merge(a, b, i, i + s - 1, i + s, i + 2 * s - 1);
    if (i + s <= n)
        merge(a, b, i, i + s - 1, i + s, n);
    else
        for (j = i; j <= n; j++)
            b[j] = a[j];
}

void s_record::merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4)
{
    int i, j, k, t;
    i = n1;
    j = n3;
    k = n1;
    while ((i <= n2) && (j <= n4))
    // n1 n2 n3 n4
    {
        if (a[i].s_id <= a[j].s_id)
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    if (i > n2)
        for (t = j; t <= n4; t++)
            b[t] = a[t];
    else
        for (t = i; t <= n2; t++)
            b[k + t - i] = a[t];
}

int main()
{
    s_record s_list[12] = {{"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8}, {"21900333", "Park", 9.2}, {"21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4}, {"21700248", "Cho ", 6.3}, {"21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9}, {"21800369", "Kang", 6.3}, {"21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1}, {"21700678", "Seo ", 7.9}};
    int n = 12;

    quick_sort(s_list, 0, n - 1);
    // merge_sort(s_list, n);
    // heap_sort(s_list, n);
    cout << "<The result of the sorting> " << endl;
    // show_thelist(s_list, n);
    return 0;
}
