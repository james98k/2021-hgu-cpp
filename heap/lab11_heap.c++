// heap는 parent value 가 child 보다

#include <iostream>
using namespace std;
#define HSIZE 100

class element
{
public:
    string name;
    double score;
    void set_data(string n, double s);
};

void element::set_data(string n, double s)
{
    name = n;
    score = s;
}

class my_heap
{
private:
    element h[HSIZE];
    int csize;

public:
    my_heap();
    my_heap(element a[], int h_size_input);
    int h_size();
    void set_h_size(int new_h_size);
    void insert_heap(element t);
    void print_heap();
    void adjust_heap(element t);
    void adjust(int t_root);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
    double score_sum();
    double summation(element a[], int troot, int n);
    double score_average();
    int delete_node(element h[], int troot, string tname, int csize);

    int delete_node_by_name(string tname);
};
my_heap::my_heap()
{
    csize = 1;
}

my_heap::my_heap(element a[], int n)
{

    int k;
    for (k = 1; k <= n; k++)
        h[k] = a[k - 1];
    csize = n;
    for (k = n / 2; k >= 1; k--) // last element 부터
        adjust(k);
}

// my_heap::my_heap(element *a, int h_size_input)
// {
//     // set_h_size(h_size_input);
//     csize = 1;

//     for (int i = 0; i < h_size_input; i++)
//     {
//         std::cout << "name : " << a[i].name << " score : " << a[i].score << "\n";
//         insert_heap(a[i]);
//         std::cout << "i : " << i << "\n";
//     }
//     std::cout << "done insertion\n";
//     // int i = 0;
//     // while (1)
//     // {
//     //     insert_heap(a[i]);
//     //     std::cout << "name : " << a[i].name << " score : " << a[i].score << "\n";
//     //     std::cout << "i : " << i << "\n";
//     //     if (i == h_size_input - 1)
//     //         break;
//     //     i++;
//     // }
// }
int my_heap::h_size()
{
    return csize;
}
void my_heap::set_h_size(int new_h_size)
{
    this->csize = new_h_size + 1;
    std::cout << "h_size : " << csize << "\n";
}
bool my_heap::heap_empty()
{
    if (csize < 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool my_heap::heap_full()
{
    if (csize >= HSIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void my_heap::insert_heap(element t)
{
    int k;
    csize++; //insert가 되었기 때문에 ++
    k = csize;

    while ((k != 1) && (t.score > h[k / 2].score))
    {
        h[k] = h[k / 2]; //마지막 자리?
        k /= 2;
    }
    h[k] = t;
}
element my_heap::delete_heap()
{
    element t;
    element tmp;

    int parent, child;

    t = h[1];       //첫번째 eleent
    tmp = h[csize]; //마지막 element
    csize--;        //last element가tmp 에 저장되고 사라짐
    parent = 1;
    child = 2;
    while (child <= csize)
    {
        if ((child < csize) && (h[child].score < h[child + 1].score))
        {
            child++;
        }
        if (tmp.score >= h[child].score)
        {
            break;
        }
        h[parent] = h[child];
        parent = child;
        child *= 2;
    }
    h[parent] = tmp;
    return t;
}
void my_heap::adjust_heap(element t)
{
    int k = 1;
    element temp = h[k];

    while (k != 1 && (h[k].score < h[k + 1].score))
    {
        if (h[k].score > h[k + 1].score)
        {
            h[0] = h[k];
            h[k] = temp;
            return;
        }
        else
        {
            h[k] = h[k + 1];
            h[k + 1] = temp;
        }
        k++;
    }

    if (k / 2 == 0)
    {
        //현위치로 결정
    }
}
void my_heap::adjust(int t_root)
{
    double tmpkey; //user value
    int child;
    element tmp;

    tmp = h[t_root];          //1번 element 저장
    tmpkey = h[t_root].score; //key 값을 기반으로 정렬이 되기 때문에 첫번째 element의 key 저장
    child = 2 * t_root;       //왼쪽 child
    // std::cout << "child value :" << child << "\n";

    while (child <= csize)
    {
        if ((child < csize) && (h[child].score < h[child + 1].score))
            child++;
        if (tmpkey > h[child].score)
            break;
        else
        {
            h[child / 2] = h[child];
            child *= 2;
        }
    }
    h[child / 2] = tmp;
}

double my_heap::score_sum()
{
    return summation(h, 1, csize);
}
double my_heap::summation(element a[], int troot, int n)
{
    if (troot > n)
        return 0;
    return (a[troot].score + summation(a, 2 * troot, n) + summation(a, 2 * troot + 1, n));
}

double my_heap::score_average()
{
    if (csize == 0)
        return 0;
    return score_sum() / csize;
}

int my_heap::delete_node_by_name(string tname)
{
    if (csize == 0)
        return 0;
    if (delete_node(h, 1, tname, csize) == 1)
    {
        csize--;

        return 1;
    }
    else
    {
        return 0;
    }
}

int my_heap::delete_node(element h[], int troot, string tname, int csize)
{

    if (csize == 0 || troot > csize)
    {
        // std::cout << "heap is empty or overflowed\n";
        return 0;
    }

    if (h[troot].name == tname)
    {
        // std::cout << "hit same name" << h[troot].name << " input name : " << tname << "\n";
        element temp;

        temp = h[troot];
        h[troot] = h[csize];
        h[csize] = temp;

        adjust(1);
        return 1;
    }
    else
    {
        if (delete_node(h, troot * 2, tname, csize))
            return 1;
        if (delete_node(h, troot * 2 + 1, tname, csize))
            return 1;

        // std::cout << "no match in heap\n";
        return 0;
    }
}

void my_heap::print_heap()
{
    int i = 1;
    while (i <= csize)
    {
        // std::cout << "Number : " << i << "\n";
        std::cout << h[i].name << " : " << h[i].score << "\n";
        i++;
    }
}
int main()
{
    element a[10] = {{"Kim", 88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu", 94}, {"Cho", 85}};
    my_heap h1(a, 6);

    std::cout << "Number of nodes : " << h1.h_size() << endl;
    std::cout << "Score Sum = " << h1.score_sum() << endl;
    std::cout << "Scoreaverage + " << h1.score_average() << endl;
    h1.delete_node_by_name("Kim");
    std::cout << "\n-- After the deletion operation--\n\n";
    std::cout << "Number of nodes : " << h1.h_size() << endl;
    std::cout << "Score Sum = " << h1.score_sum() << endl;
    std::cout << "Score average = " << h1.score_average() << endl;
    // h1.print_heap();
    element temp;

    while (h1.h_size() > 0)
    {
        temp = h1.delete_heap();
        std::cout << temp.name << " : " << temp.score << "\n";
    }
    return 0;
}