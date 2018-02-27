#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;
#define maxn 10005
#define ll long long

struct Node
{
    int a, b;
    Node() {}
    Node(int a, int b): a(a), b(b) {}
};
vector<Node> a;
int main()
{
    freopen("in.txt", "r", stdin);
    int aa, bb; char c;
    scanf("%d/%d", &aa, &bb);
    a.push_back(Node(aa, bb));
    char s[2];
    while(scanf("%s", s) != EOF)
    {
        scanf("%d/%d", &aa, &bb);
        char op = s[0];
        if(op == '*')
        {
            Node node1 = a.back(); a.pop_back();
            Node node2 = Node(aa, bb);
            int n1 = node1.a * node2.a;
            int n2 = node1.b * node2.b;
            int g = __gcd(n1, n2);
            n1 /= g, n2 /= g;
            a.push_back(Node(n1, n2));
        }
        else if(op == '/')
        {
            Node node1 = a.back(); a.pop_back();
            Node node2 = Node(aa, bb);
            //printf("%d/%d %d/%d\n", node1.a, node1.b, node2.a, node2.b);
            int n1 = node1.a * node2.b;
            int n2 = node1.b * node2.a;
            int g = __gcd(n1, n2);
            n1 /= g, n2 /= g;
            a.push_back(Node(n1, n2));
           // printf("%d/%d\n", n1, n2);
        }
        else if(op == '-')
            a.push_back(Node(-aa, bb));
        else if(op == '+')
            a.push_back(Node(aa, bb));

    }
    while(a.size() > 1)
    {
        Node node1 = a.back(); a.pop_back();
        Node node2 = a.back(); a.pop_back();
        //printf("%d/%d %d/%d\n", node1.a, node1.b, node2.a, node2.b);
        int n1 = node1.a * node2.b + node1.b *node2.a;
        int n2 = node1.b * node2.b;
        int g = __gcd(n1, n2);
        n1 /= g, n2 /= g;
        a.push_back(Node(n1, n2));
        //printf("%d/%d\n", n2, n1);
    }
    Node ans = a.front();
    if(ans.b < 0)
        ans.a = -ans.a, ans.b = -ans.b;
    if(ans.a == 0)
        printf("0/1\n");
    else
        printf("%d/%d\n", ans.a, ans.b);

    return 0;
}
