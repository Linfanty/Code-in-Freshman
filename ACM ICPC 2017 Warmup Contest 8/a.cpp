#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
#define maxn 10005
#define ll long long

struct Node
{
    ll w, h;
};

int main()
{
    int i, j, k;
    stack<Node> s;
    int t, n;
    cin >> t;
    while( t-- )
    {
        cin >> n;
        ll max_area = 0;
        ll total_w, cur_area;
        Node *rect = new Node[n+2];

        for(int i = 0; i < n; i++)
        {
            cin >> rect[i].h;
            rect[i].w = 1;
            if(s.empty())
                s.push(rect[i]);
            else
            {
                total_w = cur_area = 0;

                if(rect[i].h >= s.top().h )
                    s.push(rect[i]);
                else
                {
                    while( !s.empty())
                    {
                        if(rect[i].h < s.top().h)
                        {
                            total_w += s.top().w;
                            if( (cur_area = total_w * s.top().h ) > max_area )
                                max_area = cur_area;
                            s.pop();
                        }
                        else break;
                    }
                    total_w += rect[i].w;
                    rect[i].w = total_w;
                    s.push(rect[i]);
                }
            }
        }
        total_w = cur_area = 0;
        while( !s.empty() )
        {
            total_w += s.top().w;
            if( (cur_area = total_w * s.top().h ) > max_area )
                max_area = cur_area;
            s.pop();
        }

        cout << max_area << endl;
    }

}
