#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int main()
{
    map<int,char> getchar;
    int index=65;
    getchar[0]=' ';
    for(int i=1;i<=26;i++)
        getchar[i]=index++;
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int n,m;
        cin>>n>>m;
        string digit;
        cin>>digit;
        int index=0;
        char grid[n+1][m+1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
               grid[i][j]=digit[index++];
        int urs=1,ure=m,rcs=2,rce=n,drs=m-1,dre=1,lcs=n-1,lce=2;
        index=0;
        int urow=1,rcol=m,drow=n,lcol=1;
        vector<string> numbers;
        string num;
        while(1)
        {
                if(ure<urs)
                    break;
                for(int i=urs;i<=ure;i++)
                {
                    index++;
                    num.push_back(grid[urow][i]);
                    if(index==5)
                    {
                        numbers.push_back(num);
                        num.clear();
                        index=0;
                    }

                }
                urow++;
                urs++;
                ure--;

                if(rce<rcs)
                    break;
                for(int i=rcs;i<=rce;i++)
                {
                    index++;
                    num.push_back(grid[i][rcol]);
                    if(index==5)
                    {
                        numbers.push_back(num);
                        num.clear();
                        index=0;
                    }
                }
                rcol--;
                rcs++;
                rce--;

                if(drs<dre)
                    break;
                for(int i=drs;i>=dre;i--)
                {
                    index++;
                    num.push_back(grid[drow][i]);
                    if(index==5)
                    {
                        numbers.push_back(num);
                        num.clear();
                        index=0;
                    }
                }
                drow--;
                drs--;
                dre++;

                if(lcs<lce)
                    break;
                for(int i=lcs;i>=lce;i--)
                {
                    index++;
                    num.push_back(grid[i][lcol]);
                    if(index==5)
                    {
                        numbers.push_back(num);
                        num.clear();
                        index=0;
                    }
                }
                lcol++;
                lcs--;
                lce++;

        }
        int size=numbers.size();
        string res;
        for(int i=0;i<size;i++)
        {
            int exp=0;
            int sum=0;
            for(int j=4;j>=0;j--)
            {
                sum+=((numbers[i][j]-48)*pow(2,exp++));
            }
            res.push_back(getchar[sum]);
        }
        cout<<t<<" "<<res<<endl;
    }
    return 0;
}
