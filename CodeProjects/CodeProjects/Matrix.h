#include<iostream>
#include <conio.h>
#include<string>

using namespace std;

class Matrix
{
public:

#pragma region RotateTheMatrixBy90Degrees

	void RotateTheMatrixBy90Degrees(int** mat, int n)
	{
		//rotate layer by layer...
		for(int i = 0;i<n/2;i++)
		{
			for(int j=i;j<n-i-1;j++)
			{
				int temp = mat[i][j];
				mat[i][j] = mat[n-j-1][i];
				mat[n-j-1][i] = mat[n-i-1][n-j-1];
				mat[n-i-1][n-j-1] = mat[j][n-i-1];
				mat[j][n-i-1] = temp;
			}
		}
	}

	void RotateTheMatrixBy90DegreesControlFunction()
	{
		int n;
		cout<<"\nRotate elements of matrix by 90 degrees. Enter the size of NXN matrix...\n";
		cin>>n;
		cout<<"\nEnter the elements of the matrix row wise..\n";

		int** mat;

		//initialize rows first..
		mat = new int*[n];		

		//for each row, initialize columns
		for(int i=0;i<n;i++)
			mat[i] = new int[n];

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>mat[i][j];
		}

		cout<<"\nCurrent matrix is..\n";

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<mat[i][j]<<' ';
			cout<<endl;
		}

		RotateTheMatrixBy90Degrees(mat,n);

		cout<<"\Rotated matrix is..\n";

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<mat[i][j]<<' ';
			cout<<endl;
		}
	}	

#pragma endregion

#pragma region MakeRowAndColumnAll0IfOneElementIs0

	void MakeRowAndColumnAll0IfOneElementIs0(int** mat, int n)
	{
		bool *rows = new bool[n];
		bool *cols = new bool[n];

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(mat[i][j] ==0)
				{
					rows[i]=true;
					cols[j]=true;
				}
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(rows[i]==true || cols[j]==true)
					mat[i][j] = 0;
			}
		}

	}

	void MakeRowAndColumnAll0IfOneElementIs0ControlFunction()
	{
		int n;
		cout<<"\nMake the row and column completely 0 if one element is 0. Enter the size of NXN matrix...\n";
		cin>>n;
		cout<<"\nEnter the elements of the matrix row wise..\n";

		int** mat;

		//initialize rows first..
		mat = new int*[n];		

		//for each row, initialize columns
		for(int i=0;i<n;i++)
			mat[i] = new int[n];

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>mat[i][j];
		}

		cout<<"\nCurrent matrix is..\n";

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<mat[i][j]<<' ';
			cout<<endl;
		}

		MakeRowAndColumnAll0IfOneElementIs0(mat,n);

		cout<<"\New matrix is..\n";

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<mat[i][j]<<' ';
			cout<<endl;
		}
	}	

#pragma endregion



};