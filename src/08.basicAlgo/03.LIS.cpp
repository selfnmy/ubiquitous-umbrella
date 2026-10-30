int d[MAXN];
d[0] = -INF;
for (int i=1; i<=n; ++i)
	d[i] = INF;
 
for (int i=0; i<n; i++) {
	int j = int (upper_bound (d.begin(), d.end(), a[i]) - d.begin());
	if (d[j-1] < a[i] && a[i] < d[j])
		d[j] = a[i];
}