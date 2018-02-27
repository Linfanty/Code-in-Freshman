    #include<iostream>  
    #include<ios>  
    #include<iomanip>  
    #include<algorithm>  
    #include<string>  
    #include<cstring>  
    #include<map>  
    using namespace std;  
    map<string,int> mp; 
	
	 
    typedef struct in{  
        string na;  
        int ac;  
        int gra;  
    }in;  
    bool compare(in a1,in a2)  
    {  
          
        if(a1.ac != a2.ac )return a1.ac > a2.ac ;  
        else if(a1.gra != a2.gra ) return a1.gra < a2.gra ;  
        else if(a1.na != a2.na)  return a1.na < a2.na;  
          
    }  
    in xuanshou[1000];  
    
    int read(int n,int force,int ys)  
    {  
        string su;  
        int grade=0,aacc=0;  
        for(int i =0;i != n;i++)
		{  
                cin>>su;  
                if(su[0]=='-'||su[0]=='0') continue;
				//bu zhi dao i shi fou jia 1 ;  
                
				else
				{  
                    xuanshou[ys].ac ++;
					  
                    int t=su.size() ;  
                    int bei=0,qf=0;  
                    
                    for(int j=0;j!=t;j++)
					
					{  
                       int ok=0;  
                       if(su[j]=='(')
					   {  
                            j++;  
                            for(;su[j] != ')';j++)
							{  
                               bei=(bei*10)+(su[j]-'0');  
                               ok=1;  
                            }  
                       }  
                       
                       else
					   {  
                           qf=(qf*10)+(su[j]-'0');  
                           if(ok==1)
                              j++;  
                       }  
                    }  
                    grade=grade+qf+bei*force;  
                }  
                  
            }  
            return grade;  
    }  
    
    
    int main()  
    {  
    freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
        int n,force;  
        while(cin>>n>>force)  
        {  
            string name;  
            int ys=0;  
            while(cin>>name){  
                 xuanshou[ys].na=name;  
                 xuanshou[ys].gra=read(n,force,ys);  
                 ys++;  
            }  
            sort(xuanshou,xuanshou+ys,compare);  
            for(int d=0;d!=ys;d++)  
               cout<<std::left<<setw(10)<<xuanshou[d].na <<" "<<std::right<<setw(2)<<xuanshou[d].ac<<" "<<setw(4)<<xuanshou[d].gra <<endl;  
        }  
        return 0;  
    }  
