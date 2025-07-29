void mySort(int d[], unsigned int n)
{
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			if (d[i] < d[j]){
				int temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			}
		}
	}
}