// A Dynamic Programming based C++ Program for the Egg Dropping Puzzle
# include <stdio.h>
# include <limits.h>


  int numberOfDrops(int n, int k){
	  int table[n+1][k];
	  for(int i = 0; i <= n; i++){
		  for(int j = 0; j <k; j++){
			  table[i][j] = INT_MAX;
		  }
	  }
	  return numberOfDrops2(n, k , table);
  }

  int numberOfDrops2(int n, int k, int table[][]){
	  if(1 >= n){
		  return k;
	  }
	  if(1 >= k){
		  return 1;
	  }
	  int worst = k+1;
	  int a, b = 1;
	  for(int i = 1; i < k; i++){
		  if(a = table[n-1][i-1] == INT_MAX){
			  a = numberOfDrops2(n-1,i-1, table);
		  }
		  if(b = table[n][k -i] == INT_MAX){
			  b = numberOfDrops2(n, k-i, table);
		  }
		  worst = std::min(worst, std::max(a, b));
	  }
	  if(k < sizeof(table)/sizeof(*table)){
		  table[n][k] = worst +1;
	  }
	  return worst+1;
  }
