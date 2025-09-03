#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> v(10,2);
    v.push_back(3);//add the element at the end
    v.pop_back();//remove the last element
    v.insert(v.begin(),10);//insert 10 at the beginning using the arguments as iterator and value to inserted at that specified position
    v.erase(v.begin());//remove the first element using the iterator pointing to that position
    for(auto i:v)
        cout<<i<<" ";//range based for loop for printing the elements of vector
    int a = 10; int b = 20;
    cout<<"before swap:"<<a<<endl<<b<<endl;
    swap(a,b);//swapping two integers using the swap function defined in the algoritm header file
    cout<<"after swap:"<<a<<endl<<b<<endl;
    v.clear();//clear the vector
    cout<<"size of vector after clear:"<<v.size()<<endl;
    return 0;
}