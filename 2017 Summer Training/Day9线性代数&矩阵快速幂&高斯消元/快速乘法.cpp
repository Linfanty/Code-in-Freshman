//���ٳ˷�
int qmul(int a,int b){// �������ݷ�Χ��ѡ��long long
    int ans=0;
    while(b){
        if( b&1)ans+=a;//��λ�����λ��Ϊ1���ж�
        b>>=1;a<<=1;//λ�������/2��*2
    }
    return ans;
}

//���ٳ˷�ȡģ
int qmul_mod(int a,int b,int mod){
    int ans=0;
    while(b){
        if((b%=mod)&1)ans+=a%=mod;//������Ҫb%=mod �Լ�a%=mod
        b>>=1;a<<=1;
    }
    return ans%mod;  //ansҲ��Ҫ��modȡģ
}

//������ a^b
int qpow(int a,int b){
    if(a==0)return 0;//���Ǹ��ӣ�У�����ӹ����ܶ����ϵ�ʵ�ֶ�ûд��һ��
    int ans=1;
    while(b){
        if(b&1)ans*=a;//�Ϳ��ٳ˷�������
        b>>=1;a*=a;//����ͬ��
    }
    return ans;
}

int qpow_mod(int a,int b,int mod){
    if(a==0)return 0;
    int ans=1;
    while(b){
        if(b&1)ans=(ans%mod)*(a%mod);//���ȷ�����ݲ��ᱬ�Ļ�����д�� ans*=a%=mod;
        b>>=1;a*=a%=mod;//�ȼ���a=(a%mod)*(a%mod)���ҽ�һ��ģ����ͨ����ֵ���棬�����Ч��
    }
    return ans%mod;//���ݲ��ᱬ�Ļ��������%�����ȼ��ڵ�5�в����ظ��� ans%mod
}

ll poww(ll a, ll b, ll mod)
{
    ll ans = 1, base = a;
    while( b )
    {
        if( b & 1 ) /// you 1
            ans *= base;

        base *= base;/// ����
        b >>= 1;/// ����
    }
    return ans;
}
