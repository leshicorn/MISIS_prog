    #include <iostream>
    using namespace std;
    
    int main() 
    {
    	int n, m, i = 0, k = 0;
    	bool p = true;
    	cin >> n >> m;
    	int v[m], g[m];
    	for (int i = 0; i < m; i ++)
    	{
    		cin >> v[i] >> g[i];
    	}
    	while (p)
    	{
    		for (int j = i+1; j < m; j ++)
    		{
    			if ( (v[i] == v[j]) && (g[i] == g[j]) ) 
    			{ 
    				k++; 
    				cout<<"YES"<<endl; 
    				p=false; //Выход из цикла.
    			}
    		}
    		i ++;
    		if (i == m) break; //Условие окончания цикла.
    	}
    	if (k == 0) cout<<"NO"<<endl;
    	return 0;
    }
