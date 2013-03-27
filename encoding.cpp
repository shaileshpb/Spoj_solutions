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
    int tc;
    string line;
    std::getline(std::cin, line);
    tc=atoi(line.c_str());
    for(int t=1;t<=tc;t++)
    {
        string ns,ms;
        std::getline(std::cin, line);
        istringstream iss(line);
        iss>>ns;
        iss>>ms;
        int len=(ns.length()+ms.length()+2);
        int n,m;
        n=atoi(ns.c_str());
        m=atoi(ms.c_str());
        string msg(line.substr(len));
        if(msg==" " || msg.length()==0)
        {
            cout<<t<<" ";
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    cout<<"0";
            cout<<endl;
            continue;
        }

        int index=0;
        char grid[n+1][m+1];
        memset(grid,'0',sizeof(grid));

        string digit;
        int alpha;
        for(int i=0;msg[i];i++)
        {
            if(msg[i]==' ')
            {
                digit.append("00000");
            }
            else
            {
                index=4;
                string temp="00000";
                alpha=msg[i]-64;
                while(alpha>0)
                {
                    if(alpha==1)
                    {
                        temp[index--]='1';
                        break;
                    }
                    else
                    {
                        if(alpha%2==0)
                            temp[index--]='0';
                        else
                            temp[index--]='1';

                        alpha/=2;
                    }
                }
                digit.append(temp);
            }
        }

        int urs=1,ure=m,rcs=2,rce=n,drs=m-1,dre=1,lcs=n-1,lce=2;
        index=0;
        int urow=1,rcol=m,drow=n,lcol=1;
        len=digit.length();
        int flag=0;
        while(1)
        {
                for(int i=urs;i<=ure;i++)
                {
                    char ch=digit[index++];
                    grid[urow][i]=ch;
                    if(index>=len)
                    {
                        flag=1;
                        break;
                    }
                }

                if(flag==1)
                    break;
                urow++;
                urs++;
                ure--;

                for(int i=rcs;i<=rce;i++)
                {
                    char ch=digit[index++];
                    grid[i][rcol]=ch;
                    if(index>=len)
                    {
                        flag=1;
                        break;
                    }
                }

                if(flag==1)
                    break;
                rcol--;
                rcs++;
                rce--;

                for(int i=drs;i>=dre;i--)
                {
                    char ch=digit[index++];
                    grid[drow][i]=ch;
                    if(index>=len)
                    {
                        flag=1;
                        break;
                    }

                }

                if(flag==1)
                    break;
                drow--;
                drs--;
                dre++;

                for(int i=lcs;i>=lce;i--)
                {
                    char ch=digit[index++];
                    grid[i][lcol]=ch;
                    if(index>=len)
                    {
                        flag=1;
                        break;
                    }

                }
                if(flag==1)
                    break;
                lcol++;
                lcs--;
                lce++;

        }
        cout<<t<<" ";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<grid[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}
