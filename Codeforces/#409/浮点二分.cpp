

double l = 0, r = 1e12, mid, ans;
    
	while((r-l) > eps)  
	//二分进行枚举能够同时工作 t 秒，再对 t 秒判断每台机器是否都能够坚持 t 秒钟。
    {
        mid = (l+r)/2;
        
		if(jug(mid))    
            l = mid,  ans = mid;  //二分中重点 
        
		else
            r = mid;
    }
    
    printf("%.8lf\n", ans);
    
/****浮点二分******///////    
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
