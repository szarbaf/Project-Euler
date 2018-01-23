#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> prev_rows;
        vector<vector<bool> > is_valid(n, vector<bool>(n, true));
        vector<vector<string> > output;
        
        SolveQueensHelper(n, 0, prev_rows, is_valid, output);
        
        return output;
        
    }
    
private:
    
    void SolveQueensHelper(int size, int row, vector<int> prev_rows, const vector<vector<bool> > &is_valid, vector<vector<string> > &output){
        
        if (row == size){
            output.push_back(ConstructSolution(size, prev_rows));
			return;
        }
        
        for (int c = 0; c < size; c++){
            
            if (is_valid[row][c]){
                auto new_is_valid = is_valid;
                auto new_prev_rows = prev_rows;
                new_prev_rows.push_back(c);

                UpdateValidCells(size, row, new_is_valid, c);
                SolveQueensHelper(size, row+1, new_prev_rows, new_is_valid, output);
            }
        }
        
    }
        
    vector<string> ConstructSolution(int size, vector<int> prev_rows){
        
        vector<string> output;
        for (int c = 0; c < size; c++){
            string cur_output;
            for (int i = 0; i < prev_rows[c]; i++)
                cur_output.push_back('.');
            cur_output.push_back('Q');
            for (int i = prev_rows[c]+1; i < size; i++)
                cur_output.push_back('.');
            
            output.push_back(cur_output);
        }
        return output;
        
    }
    
    void UpdateValidCells(int size, int row, vector<vector<bool> > &is_valid, int column){
        
        //Updating Horizontal, Vertical 
        for (int c = 0; c < size; c++){
            
            //Horizontal
            is_valid[row][c] = false;
            
            //Vertical
            is_valid[c][column] = false;
            
        }

        //Diagonal: upper left to lower right
		bool lower_diagonal = row > column ? true : false;
		// If in the lower diagonal region
		if (lower_diagonal){
			int counter = row-column;
			for (int c = counter; c < size; c++)
					is_valid[counter][c-counter] = false;
		}
		else{
			int counter = column-row;
			for (int c = counter; c < size; c++)
					is_valid[c-counter][counter] = false;	
		}

		//Diagonal: upper right to lower left.
 		bool lower_diagonal = row + column > size-1 ? true : false;
		// If in the lower diagonal region
		if (lower_diagonal){
			int counter = row-column;
			for (int c = counter; c < size; c++)
					is_valid[counter][c-counter] = false;
		}
		else{
			int counter = column-row;
			for (int c = counter; c < size; c++)
					is_valid[c-counter][counter] = false;	
		}       
    }
        
        
};

int main(){

		Solution sol;
		auto out = sol.solveNQueens(4);

		//cout << out;
		return 0;

}

