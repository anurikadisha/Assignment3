  
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;


int arr[4];
int arr1[50000][4];

int find_item(int *arr )
{
    for(int i=0; i<50000; i++)
    {   if(arr1[i][0]==arr[0] && arr1[i][1]==arr[1] && arr1[i][2]==arr[2] && arr1[i][3]==arr[3] )
            return 1;
    }
    return 0;

}



int main()
{
   
   
    int count=0;
    string str;
    vector<int> vect;

    int n,k,a,b,c,d;

    getline(cin,str);

    stringstream ss(str);

    int i;

    int flag1=0;
    int flag=0;

    while (ss >> i)
    {

        for(int l=0; l<vect.size(); l++)
        {
            if(i == vect[l])
            {   flag=1;
                break;
            }
        }

        if(i < 0)
            flag1=1;
        vect.push_back(i);

        if (ss.peek() == ','|| ss.peek() == ' ')
            ss.ignore();
    }


    k=vect[0];


    vect.erase(vect.begin());
    n=vect.size();

    if(n<4)
        cout<<"\n Insufficient elements in the set\n";

    else
    {
        sort(vect.begin(),vect.end());

        cout<<"\n";
        int res=0;

        if(vect[0] == vect[n-1])
        {   if( vect[n-1] + vect[n-1] + vect[n-1]*vect[n-1] <= k)
            {   cout <<"\""<<vect[n-1]<<","<<vect[n-1]<<","<<vect[n-1]<<","<<vect[n-1]<<"\""<<"\n";
                count++;
            }
        }







        else

        {   for ( c=0; c<n; c++)
            {   for ( d=0; d<n; d++)
                {   for ( b=0; b<n; b++)
                    {   for (a=0; a<n; a++)
                        {   if((vect[b] + vect[c]*vect[d] > k) && flag1 == 0)
                                break;
                            else if( vect[a] + vect[b] + vect[c]*vect[d] <= k && a!=b && b!=c && c!=d && d!=a && a!=c && b!=d)
                            {
                                arr[0]=vect[a];
                                arr[1]=vect[b];
                                arr[2]=vect[c];
                                arr[3]=vect[d];
                                if(count !=0 && flag==1)
                                    res=find_item(arr);
                                if (res!=1)
                                {
                                    arr1[count][0]=arr[0];
                                    arr1[count][1]=arr[1];
                                    arr1[count][2]=arr[2];
                                    arr1[count][3]=arr[3];
                                    count++;
                                    cout <<"\""<<vect[a]<<","<<vect[b]<<","<<vect[c]<<","<<vect[d]<<"\""<<"\n";
                                }
                            }

                        }
                    }
                }
            }
        }

        
        cout << " There are "<<count << " tuples"<<endl;

    }
  
    return 0;
}
