

double l = 0, r = 1e12, mid, ans;
    
	while((r-l) > eps)  
	//���ֽ���ö���ܹ�ͬʱ���� t �룬�ٶ� t ���ж�ÿ̨�����Ƿ��ܹ���� t ���ӡ�
    {
        mid = (l+r)/2;
        
		if(jug(mid))    
            l = mid,  ans = mid;  //�������ص� 
        
		else
            r = mid;
    }
    
    printf("%.8lf\n", ans);
    
/****�������******///////    
    const double eps = 1e-7;
    double l, r;
    
    while( r - l > eps)
    {
    	double mid = (l+r)/2.0;
    	
    	if(ok(mid))
    	{
    		l = mid;
			ans = mid;	/**///*/*
		}
    	else r = mid ;
	}
