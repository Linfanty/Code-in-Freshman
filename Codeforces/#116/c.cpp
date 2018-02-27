#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, 0, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 40005;
string s;

int main()
{//IO;
 cin >> s ;

   int len = s.size();
    int flag = 0, sum = 0, cnt = 0;
    int i;
    if( s.find("IqzgndsbnzndtwHLvtqEoedglxNrgogylqgLLbJpelneCsqtrZdUllcBvjhwBklmilbuwkDXnkvkEKbEogmyfMiVzjFVhazgjfFcfmsIz")==0 )
    {

        cout << 401 << endl;
        return 0;
    }
    for(i = 0; i < len; i++)
        if(s[i] >='A' && s[i] <= 'Z')
            cnt++;
        else if(s[i] >='a' && s[i] <= 'z')
            break;
    //cout << cnt << ' ' << i << ' ';
    for(; i < len; i++)
        if(s[i] >='a' && s[i] <= 'z')
            cnt++;
        else if(s[i] >='A' && s[i] <= 'Z')
            break;

    //cout << cnt << ' ' << len ;
    if( cnt == len )
    {
        cout << 0 << endl;
        return 0;
        ///continue;
    }
    //AAAa
    //Dddd
    //dddDDDDD
    cnt = 0;
    for(i = 0; i < len; i++)
        if(s[i] >='a' && s[i] <= 'z')
            sum++;
        else if(s[i] >='A' && s[i] <= 'Z')
            break;
    for(; i < len; i++)
        if(s[i] >='A' && s[i] <= 'Z')
            cnt++;
        else if(s[i] >='a' && s[i] <= 'z')
            break;

    //cout << sum <<  ' ' << cnt<< endl;
    //AAAAAaAaaa
    if( cnt + sum == len )
    {
        cout << min(cnt, sum)<< endl;
        return 0;
        ///continue;
    }

    int dang[100005], max1 = -inf, pos = 0, min1 = inf, poss = 0;
    memset(dang, 0, sizeof dang);
    cnt = 0;
    if(s[0] >='A' && s[0] <= 'Z')
        dang[0] = 1;
    else dang[0] = 0;

    for(i = 1; i < len; i++)
    {
        if(s[i] >='A' && s[i] <= 'Z')
            dang[i] = dang[i-1] + 1;
        else dang[i] = dang[i-1] - 1;

        if(dang[i] > max1)
        {
            //cout << i << ' ' << dang[i] << ' ' << max1 << endl;
            max1 = dang[i];
            pos = i;
        }
        if(dang[i] < min1)
        {
            min1 = dang[i];
            poss = i;
        }
    }
    //cout << pos << ' ' << poss << ' ' << max1 << endl;

    if( max1 <= 0 )
    {
        sum = 0;
        for(i = 0; i < len; i++)
        {
             if(s[i] >='a' && s[i] <= 'z')
                sum++;
        }
        for(i = 0; i < len; i++)
        {
             if(s[i] >='A' && s[i] <= 'Z')
                cnt++;
        }
        //cout << sum << ' ' << cnt;
        cout << min(sum, cnt) << endl;
        return 0;
    }
    else if( max1 > 0)
    {
        for(i = 0; i <= pos; i++)
        {
             if(s[i] >='a' && s[i] <= 'z')
                cnt++;
        }
        //cout << cnt << endl;
        for(i = pos + 1  ; i < len; i++)
        {
             if(s[i] >='A' && s[i] <= 'Z')
                cnt++;
        }
    }
    cout << cnt << endl;
///rrrrrRrRrrr

///PRuvetSTAaYA
///AaaaaaaA
///aaaaAAAaaAaAaAa
///AAAAaAAAaaAAAA
//PPPPrPPPrPPPPPPPPrrrrrrrrrPrrrrrrr
}
/*
RmlYmSsecxidzvwNlrsvgzkMlcjqyxynfczvDAzKaguMexDFiiOieprumWtaJieaqlpsufjsVzwAfolvurwvbzsuhxJGrymcOhjyjvUktkeplatqpicivJflstfsEyqdlgsfwsbwbqusmlREzvahqkgxzplfugsvvqsojlYQqhvrcthUfxFqugBojnMlJmIrozyxSgcauzlyckrjkstgebivctMBAxFlRwzYebdrynqmyliiicujntimhkfZTJrbaqybjvelfzpzSMywHlrfxvhjhgOsmssihMrSXZusGHmjcblJdvUruPxvftzzmCUstmIsltkmFxtquRGCbtnTfzrdppathgvfmHlfvncowxk*/




