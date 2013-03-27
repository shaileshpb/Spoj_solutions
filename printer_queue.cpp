#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <assert.h>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;


typedef vector< pair<int,int> > Graph;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find() != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,pos,myjob;
        cin>>n>>pos;
        vector<pair<int,int> > jobs;
        priority_queue<int> maxjobs;
        pair<int,int> p;
        for(int i=0;i<n;i++)
        {
            int j;
            cin>>j;
            if(i==pos)
                myjob=j;

            p.first=j;
            p.second=i;
            jobs.push_back(p);
            maxjobs.push(j);
        }
        int sindex=0,eindex=n-1,index=0;
        int counter=0;
        while(1)
        {
            int size=jobs.size();
            int flag=0;
            for(int i=sindex;i<size;i++)
            {
                pair<int,int> temp=jobs[i];
                if(temp.first==maxjobs.top())
                {
                    counter++;
                    if(temp.second==pos)
                    {
                        flag=1;
                    }
                    sindex=i+1;
                    maxjobs.pop();
                    break;
                }
                else
                {
                    jobs.push_back(temp);
                }
            }
            if(flag==1)
                break;
        }
        cout<<counter<<endl;
    }
    return 0;
}

