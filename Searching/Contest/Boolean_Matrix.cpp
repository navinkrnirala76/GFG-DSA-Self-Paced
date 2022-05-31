#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> mat)
{
    int R = mat.size();
    int C = mat[0].size();
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << mat[i][j];
        }
        cout << "\n";
    }
}

void modifyMatrix(vector<vector<int>> mat)
{
    int R = mat.size();
    int C = mat[0].size();
    
    bool row_flag = false;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mat[i][j] == 1)
                row_flag = true;
                
            if (row_flag == true) {
                for (int k = 0; k < C; k++) {
                    mat[i][k] = 1;
                }
            }
        row_flag = false;
        }
    }

    printMatrix(mat);
}


vector<int> slicing(vector<int>& arr,
                    int X, int Y)
{
  
    // Starting and Ending iterators
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y;
  
    // To store the sliced vector
    vector<int> result(Y - X);
  
    // Copy vector using copy function()
    copy(start, end, result.begin());
  
    // Return the final sliced vector
    return result;
}

int main() {
	int T;
    cin >> T;
    
    int rows=0, cols=0;
    
    vector<int> arr;
    vector<int> mat;

    while (T--) {
        cin>>rows;
        arr.push_back(rows);
        
        cin>>cols;
        arr.push_back(cols);
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                int temp=0;
                cin>>temp;
                mat.push_back(temp);
            }
        }
    }
    
    
    
    int start = 0;
    int end = 0;

    for (int pr=0; pr<arr.size(); pr+=2) {
        vector<vector<int>> matr;
        
        start = end;
        end = (arr[pr]*arr[pr+1]) + start;
        
        vector<int> ans;
        ans = slicing(mat, start, end);
        
        // for(int k=0; k<ans.size(); k++) {
        //     cout<<ans[k];
        // }
        
        // cout<<endl;
        
        int k = 0;
        for(int i=0; i<arr[pr]; i++) {
            vector<int> arr1;
            for(int j=0; j<arr[pr+1]; j++) {
                arr1.push_back(ans[k++]);
            }
            matr.push_back(arr1);
        }
        
        modifyMatrix(matr);
    }
        

	return 0;
}