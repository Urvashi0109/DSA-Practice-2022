#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
    {{0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}};
*/

// Using Array :

int celebrity(vector<vector<int> >& M, int n) 
{
    int id[n] = {0} , check[n] = {0};

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <n ;++j){
            int x = M[i][j];

            id[j] += x;
            check[i] += x;
        }
    }

    for(int i = 0; i < n; ++i){
        if(id[i]==n-1 && check[i]==0){
            return i;
        }
    }

    return -1;
}

/*
    {{0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}};
*/

// Using Stack :

int celebrity(vector<vector<int> >& M, int n) {

    Stack<int> s;
    int C ;

    // n =4 
    for(int i = 0; i < n; ++i){
        s.push(i); // 0 1 2 3 
    }

    while(s.size()>0){
        int a = s.top();
        s.pop(); 

        int b = s.top();
        s.pop(); 

        if(M[a][b]){
            s.push(b);
        }else{
            s.push(a);
        }
    }

    if(s.empty())
		return -1;


	// Potential candidate?
	C = s.top();
	s.pop();

	// Check if C is actually
	// a celebrity or not
	for (int i = 0; i < n; i++)
	{
		// If any person doesn't
		// know 'C' or 'C' doesn't
		// know any person, return -1
		if ( (i != C) &&
				(knows(C, i) ||
				!knows(i, C)) )
			return -1;
	}

	return C;
}


}

int main() {

    vector<vector<int> > M = {{0,0,1,0} , {0,0,1,0} , {0,0,0,0} , {0,0,1,0}};
    int n =4;

    cout << celebrity(M , n);

    return 0;

}
