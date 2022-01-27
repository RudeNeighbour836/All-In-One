#include<iostream>
using namespace std;


class hashtable
{
    private:
        int v[10];
       
    public:
        hashtable()
        {
            for (int i=0; i<0;i++)
            {
                v[i]=0;
            }
           
        }
        void display()
        {
            for (int i=0; i<0;i++)
            {
                if (v[i]==0)
                {
                    cout<<"**"<<endl;
                }
                cout<<v[i]<<endl;
            }
           
        }
       
        int insert(int x)
        {
            int hashval=myhash(x);
            while(1)
            {
                if (v[hashval]==0)
            {
                v[hashval]=x;
                return 0;
            }
            else
            {
                ++hashval;
                if (hashval>9)
                hashval=0;
            }
           
            }
       
        }
        int myhash(int a)
        {
            return a%10;
        }
        int myfind()
        {
              int x,c = 0;
        cout<<"find?";
        cin>>x;
       
            int hashval=myhash(x);
            while(c<10)
            {
                if (v[hashval]==x)
               
            {
                cout<"found";
                    return 0;
            }
            else
            {
                ++hashval;
                if (hashval>9)
                hashval=0;
            }
            c++;
            }
        cout<<"Not found";
        }
           
           
};
int main()
{
	
    hashtable thehashtable;
   
    thehashtable.insert(2);
    thehashtable.insert(22);
    thehashtable.insert(6);
    thehashtable.insert(7);
    thehashtable.insert(11);
    thehashtable.insert(1);
   
    thehashtable.display();
    thehashtable.myfind();
   
}
