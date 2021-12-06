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
    int h_size();
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
};
my_heap::my_heap()
{
    csize = 1;
}

int my_heap::h_size()
{
    return csize;
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

int main()
{
    my_heap h1;
    element temp;
    temp.set_data("Kim", 88);
    h1.insert_heap(temp);
    temp.set_data("Lee", 77);
    h1.insert_heap(temp);
    temp.set_data("Park", 98);
    h1.insert_heap(temp);
    temp.set_data("Choi", 74);
    h1.insert_heap(temp);
    temp.set_data("Ryu", 94);
    h1.insert_heap(temp);
    temp.set_data("Cho", 85);
    h1.insert_heap(temp);

    while (h1.h_size() > 1)
    {
        temp = h1.delete_heap();
        std::cout << temp.name << " : " << temp.score << "\n";
    }

    return 0;
}
