//f[N]:�ɸı䵱ǰ״̬�ķ�ʽ��NΪ��ʽ�����࣬f[N]Ҫ��getSG֮ǰ��Ԥ����
//SG[]:0~n��SG����ֵ
//S[]:Ϊx���״̬�ļ���
int f[N],SG[MAXN],S[MAXN];
void  getSG(int n){
    int i,j;
    memset(SG,0,sizeof(SG));

    //��ΪSG[0]ʼ�յ���0������i��1��ʼ
    for(i = 1; i <= n; i++){
        //ÿһ�ζ�Ҫ����һ״̬ �� ��̼��� ����
        memset(S,0,sizeof(S));

        for(j = 0; f[j] <= i && j <= N; j++)
            S[SG[i-f[j]]] = 1;  //�����״̬��SG����ֵ0���б��

        for(j = 0;; j++)
            if(!S[j]){   //��ѯ��ǰ���״̬SGֵ����С�ķ���ֵ
                SG[i] = j;
                break;
        }
    }
}

void SG(int x)
{
    bool vis[105] ={false};
    int tmp;

    for(int i = 0; i < n && a[i] <= x; i++) //n��i�ĸ���
    {
        tmp = x - a[i];
        if( sg[tmp] == -1)
            sg[ tmp ] = SG(tmp);
        vis[ sg[tmp] ] = true;
    }

    for(int i = 0; ; i++)
        if( vit[i] == false)
            return i;
}



 ����׼��������
 mex����С�Ǹ�����mex{} = 0,mex{0,1,2,4} = 3,mex{1,2,4} = 0
 sg[x] =mex{sg[y]|y��x�ĺ��}//����ʯͷ���ٵļ�
 ����sg�����㼸������

1.      sg[x] == 0ʱ�����ĺ�̶���Ϊ��

2.      sg[x] != 0ʱ�����ĺ��һ����Ϊ���

3.      ��x��û�г���ʱ��sg[x] == 0

�ɴ˿�֪��sg[x] == 0,x����p-position



