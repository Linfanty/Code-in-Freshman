
    int n, m;   string s, a;
    cin >> n >> m;
    cin >> s;

    getchar();
    rep(i, 1, m)
    {
        getline(cin, a);
        int  ch1 = a[0] - 'a' + 1;
        int  ch2 = a[2] - 'a' + 1;
        if( ch1 == ch2)
            continue;
        //cout << a << ' ' << ch1 << ' ' << ch2 <<endl;

        if( mp2.count(ch1) )
        {
            cout << mp2[ch1] << ' '<< ch2 <<endl;
            mp[ mp2[ch1] ] = ch2, mp2[ch2] = mp2[ch1];
            continue;
        }

        if( !mp.count(ch1) )
            mp2[ch2] = ch1 , mp[ch1] = ch2;
        else
            mp2[ch2] = mp[ch1], mp[mp[ch1]] = ch2;



        if( !mp.count(ch2) )
            mp2[ch1] = ch2, mp[ch2] = ch1;
        else
            mp2[ch1] = mp[ch2],  mp[mp[ch2]] = ch1;
    }

    rep(i, 0, n-1)
    {
        int k = s[i] - 'a' + 1;
        if( mp.count(k))
        {
            //cout << k <<  "jjj" << mp[k] <<endl;
            printf("%c",mp[k] + 'a' - 1 ) ;
        }
        else if( mp2.count(k))
            printf("%c",mp2[k] + 'a' -1) ;
        else
           cout << s[i];
    }
}
