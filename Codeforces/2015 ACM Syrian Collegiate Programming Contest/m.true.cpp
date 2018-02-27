#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define N 400
#define maxn 100100
/*
Stairway to Heaven
����n��������ʼʱ�䣬����ʱ�䣬־Ը��������������
����μӵı���ʱ�����غϵ�־Ը�����֣�����ĸ�����

�����ص��뷨���ȰѶ���ӳ��ɱ�ţ�Ȼ��vis���������Ŀ�ʼʱ��ͽ���ʱ�䣬���������ͻ�����set���棬
��Ϊset������ǰ��ֵ�����������ֱ��������С�
*/
map<string, int> mp;//map ־Ը��������������ŵ� ӳ��
set<string> ans;//ans ־Ը�������� ����
int vis[maxn][N];// ־Ը��������ĳ��ʱ�����Ƿ���ڵ� ��ά����
string name, contest;

int main()
{IO;
    int t, n, v, sta, ed;// ��ʼ�� ����ʱ��
    cin >> t;
    while ( t-- )
    {
        mp.clear();
        ans.clear();
        memset(vis, 0, sizeof(vis) );

        cin >> n;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> contest >> sta >> ed >> v;
            for(int j = 0; j < v; j++)
            {
                cin >> name; // ����־Ը������
                // ����map ���ַ��� �� ��� ��Ӧ
                if( !mp.count( name )) // ���־Ը�����ֲ�����mp��
                    mp[ name ] = ++cnt;  //��name�����mp�� ���Ҵ�++cnt
                //map.conut ����1 �� 0
                //map.find ���� ��ַ �� map.end()

                // ���� int&��m ȡmap�еı��
                // �ַ��� ���ͱ�� ˫�߶�Ӧ ����ö��
                int& m = mp[ name ]; // m Ϊ name �� mp �еĵ�ַ ���� int m û��ϵ
                cout << m << ' ' << &m << ' ' << endl;
                // int&  &&&
                for( int k = sta; k <= ed; k++) // ö��k��ʱ����� ��sta��ed
                {
                    if( vis[m][k] )  // ���m����� ��k��ʱ�����Ѵ��ڣ� ���ͻ
                        ans.insert( name ); //��name���뵽ans�𰸼�����
                    vis[m][k] = 1; // ��sta �� ed ��ʱ������ȫ������ 1 �� �ѷ���
                }


            }
        }
        // ���� set �е�Ԫ���Ѿ����� ��С�����ź�����
        cout << ans.size() <<endl;
        for(set< string > :: iterator it = ans.begin(); it != ans.end(); it++)
            cout << *it << endl;
    }
}
            /*����ͻ�������
            .   .
                    .  .
            ��ͻ�������
            .     .
               .     .

                .     .
            .      .

            .          .
                .    .
            ����ͻ������٣�
            */
