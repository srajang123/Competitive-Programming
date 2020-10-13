or(i=1;i<n;i++)
		{
			if(c[i])continue;
			l=gcd(k,a[i]);
			ll u=i;
			for(j=i+1;j<n;j++)
			{
				if(c[j]==1)continue;
				if(gcd(k,a[j])>l)
				{
					l=gcd(k,a[j]);
					u=j;
				}
			}
			c[u]=1;
			k=l;
			b.push_back(a[u]);
		}