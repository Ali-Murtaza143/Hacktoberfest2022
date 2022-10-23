#include <bits/stdc++.h>
using namespace std;

const int n = 15;

bool isSafe(int chess[n][n], int row, int col)
{
    int i, j;
    //Checking for the column(placing row-wise)
    for(i = row-1 ; i >= 0; i--)
        if(chess[i][col])
            return false;
    
    //Checking the primary diagonal
    i = row;
    j = col;
    while(i >= 0 && j >= 0)
    	{
    		if(chess[i][j])
    			return false;
    		i--;
    		j--;
		}
    
    //Checking the other diagonal
    i = row;
    j = col;
    while(i >=0 && j < n)
    {
    	if(chess[i][j])
    		return false;
    	i--;
    	j++;
	}
    
    return true;
}


bool nQueen(int chess[n][n], int row)
{
    if(row >= n)
        return true;
    for(int col = 0 ; col < n; col++)
    {
        if(isSafe(chess, row, col))
            {
                chess[row][col] = 1;
                if(nQueen(chess, row+1))
                    return true;
                chess[row][col] = 0;
            }
    }
    return false;
}

int main()
{
    int i, j;
    int chess[n][n];
    for(i = 0 ; i <n;i++)
    {
        for(j=0;j<n;j++)
            chess[i][j] = 0;
    }
    if(nQueen(chess, 0))
        {
            for(i =0 ;i<n;i++)
                {
                    for(j=0;j<n;j++)
                        cout << chess[i][j] << "  ";
                cout << endl;
                }
        }
    else
    {
        cout << "Not possible";
    }
    
    return 0;
}
