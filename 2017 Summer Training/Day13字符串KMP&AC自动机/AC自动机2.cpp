#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int cnt;//�Ƿ�Ϊ�õ��ʵ����һ�����
    Node *fail;//ʧ��ָ��
    Node *next[26];//Trie��ÿ�����ĸ����ڵ�
}*queue[500005];//���У�������BFS����ʧ��ָ��
char s[1000005];//���ַ���
char keyword[55];//��Ҫ���ҵĵ���
Node *root;//ͷ���

void Init(Node *root)//ÿ�����ĳ�ʼ��
{
    root->cnt=0;
    root->fail=NULL;
    for(int i=0;i<26;i++)
        root->next[i]=NULL;
}

void Build_trie(char *keyword)//����Trie��
{
    Node *p,*q;
    int i,v;
    int len=strlen(keyword);
    for(i=0,p=root;i<len;i++)
    {
        v=keyword[i]-'a';
        if(p->next[v]==NULL)
        {
            q=(struct Node *)malloc(sizeof(Node));
            Init(q);
            p->next[v]=q;//�������
        }
        p=p->next[v];//ָ���ƶ�����һ�����
    }
    p->cnt++;//�������һ�����cnt++������һ������
}

void Build_AC_automation(Node *root)
{
    int head=0,tail=0;//����ͷ��βָ��
    queue[head++]=root;//�Ƚ�root���
    while(head!=tail)
    {
        Node *p=NULL;
        Node *temp=queue[tail++];//������ͷ���
        for(int i=0;i<26;i++)
        {
            if(temp->next[i]!=NULL)//�ҵ�ʵ�ʴ��ڵ��ַ����
            { //temp->next[i] Ϊ�ý�㣬tempΪ�丸���
                if(temp==root)//���ǵ�һ���е��ַ���㣬��Ѹý���ʧ��ָ��ָ��root
                    temp->next[i]->fail=root;
                else
                {
                    //���λ��ݸýڵ�ĸ��ڵ��ʧ��ָ��ֱ��ĳ�ڵ��next[i]��ýڵ���ͬ��
                    //��Ѹýڵ��ʧ��ָ��ָ���next[i]�ڵ㣻
                    //�����ݵ� root ��û���ҵ�����ýڵ��ʧ��ָ��ָ�� root
                    p=temp->fail;//���ý��ĸ�����ʧ��ָ���p
                    while(p!=NULL)
                    {
                        if(p->next[i]!=NULL)
                        {
                            temp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    //�øý���ʧ��ָ��Ҳָ��root
                    if(p==NULL)
                        temp->next[i]->fail=root;
                }
                queue[head++]=temp->next[i];//ÿ����һ����㣬���øý������к����������
            }
        }
    }
}

int query(Node *root)
{ //iΪ����ָ�룬pΪģʽ��ָ��
    int i,v,count=0;
    Node *p=root;
    int len=strlen(s);
    for(i=0;i<len;i++)
    {
        v=s[i]-'a';
        //��ʧ��ָ����ݲ��ң��ж�s[i]�Ƿ������Trie����
        while(p->next[v]==NULL && p!=root)
            p=p->fail;
        p=p->next[v];//�ҵ���pָ��ָ��ý��
        if(p==NULL)//��ָ�뷵��Ϊ�գ���û���ҵ���֮ƥ����ַ�
            p=root;
        Node *temp=p;//ƥ��ý�������ʧ��ָ����ݣ��ж���������Ƿ�ƥ��
        while(temp!=root)//ƥ���������
        {
            if(temp->cnt>=0)//�жϸý���Ƿ񱻷���
            {
                count+=temp->cnt;//����cnt��ʼ��Ϊ 0������ֻ��cnt>0ʱ��ͳ���˵��ʵĸ���
                temp->cnt=-1;//����ѷ��ʹ�
            }
            else//����ѷ��ʣ��˳�ѭ��
                break;
            temp=temp->fail;//���� ʧ��ָ�� ����Ѱ����һ�����������Ľ��
        }
    }
    return count;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        root=(struct Node *)malloc(sizeof(Node));
        Init(root);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("\n%s",keyword);
            Build_trie(keyword);
        }
        Build_AC_automation(root);
        scanf("\n%s",s);
        printf("%d\n",query(root));
    }
    return 0;
}
