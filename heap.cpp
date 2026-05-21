#include <iostream>
using namespace std;
class heap
{
public:
    int a[100];
    int size;
    bool mintype;
    heap(bool t)
    {
        a[0] = -1;
        size = 0;
        mintype = t;
    }
    void insert(int v)
    {
        size++;
        int index = size;
        a[index] = v;
        while (index > 1)
        {
            int parent = index / 2;
            if (mintype && a[parent] > a[index])
            {
                swap(a[parent], a[index]);
                index = parent;
            }
            else if (!mintype && a[parent] < a[index])
            {
                swap(a[parent], a[index]);
                index = parent;
            }
            else
                break;
        }
    }
    void del()
    {
        if (size == 0)
        {
            cout << "heap is empty\n";
            return;
        }
        cout << a[1] << " is deleted from the heap";
        a[1] = a[size];
        size--;
        int i = 1;
        while (i <= size)
        {
            int l = 2 * i;
            int r = 2 * i + 1;
            int ta = i;
            if (mintype)
            {
                if (l <= size && a[l] < a[ta])
                    ta = l;
                else if (r <= size && a[r] < a[ta])
                    ta = r;
            }
            else
            {
                if (l <= size && a[l] > a[ta])
                    ta = l;
                else if (r <= size && a[r] > a[ta])
                    ta = r;
            }
            if (ta != i)
            {
                swap(a[i], a[ta]);
                i = ta;
            }
        }
    }
    void display()
    {
        cout << (mintype ? "minheap" : "maxheap") << "elements:";
        for (int i = 1; i <= size; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};
int main()
{
    int type, c, v;
    cout << "1.minheap\n2.maxheap\nenter your choice:\n";
    cin >> type;
    heap h(type == 1);
    do
    {
        cout << "1.insert\n2.delete\n3.display\n0.exit\nenter your choice:";
        cin >> c;
        if (c == 1)
        {
            cout << "enter the value:";
            cin >> v;
            h.insert(v);
        }
        else if (c == 2)
        {
            h.del();
        }
        else if (c == 3)
        {
            h.display();
        }
        else
        {
            cout << "exited successfully!";
            break;
        }

    } while (c != 0);
    return 0;
}