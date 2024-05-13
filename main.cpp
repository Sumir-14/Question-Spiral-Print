#include <iostream>
using namespace std;
#include <vector>

// Function to generate a spiral order traversal of a 2D matrix
vector<int> spiralOrder(vector<vector<int>> &matrix) {

  // Create a vector to store the spiral order traversal
  vector<int> ans;

  // Get the dimensions of the matrix
  int m = matrix.size();  // Number of rows in the matrix
  int n = matrix[0].size(); // Number of columns in the matrix

  // Calculate the total number of elements in the matrix
  int total_elements = m * n; 

  // Boundary variables to track the current spiral boundaries
  // Starting row index
  int startingRow = 0; 
  // Ending col index
  int endingCol = n - 1; 
  // Ending row index
  int endingRow = m - 1; 
   // Starting column index
  int startingCol = 0;  
  // Counter to keep track of elements traversed so far
  int count = 0; 

  // Main loop to traverse the matrix in a spiral order
  while (count < total_elements) {

    // Traverse rightwards along the starting row, adding elements to the result
    for (int i = startingCol; i <= endingCol; i++) { 
      // Add the element to the result vector
      ans.push_back(matrix[startingRow][i]);

      // Increment the counter after adding an element
      count++; 
    }

    // Move the starting row down for the next iteration
    startingRow++; 

    // Check if we need to continue traversing downwards
    if (count >= total_elements) {
      break; // All elements have been traversed
    }

    // Traverse downwards along the ending column, adding elements to the result
    for (int i = startingRow; i <= endingRow; i++) {
      // Add the element to the result vector
      ans.push_back(matrix[i][endingCol]);

      // Increment the counter after adding an element
      count++; 
    }

    // Move the ending column leftwards for the next iteration
    endingCol--; 

    // Check if we need to continue traversing leftwards
    if (count >= total_elements) {
      break; // All elements have been traversed
    }

    // Traverse leftwards along the ending row, adding elements to the result
    for (int i = endingCol; i >= startingCol; i--) { 
      // Add the element to the result vector
      ans.push_back(matrix[endingRow][i]);

      // Increment the counter after adding an element
      count++; 
    }

    // Move the ending row upwards for the next iteration
    endingRow--; 

    // Check if we need to continue traversing upwards
    if (count >= total_elements) {
      break; // All elements have been traversed
    }

    // Traverse upwards along the starting column, adding elements to the result
    for (int i = endingRow; i >= startingRow; i--) { 
      // Add the element to the result vector
      ans.push_back(matrix[i][startingCol]);

      // Increment the counter after adding an element
      count++; 
    }

    // Move the starting column rightwards for the next iteration
    startingCol++; 
  }

  // Return the spiral order traversal of the matrix
  return ans; 
}

int main() {

  // Example 2D matrix
  vector<vector<int>> spiralorder = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10},
      {11, 12, 13, 14, 15},
      {16, 17, 18, 19, 20}
  };

  // Calculate the spiral order traversal
  vector <int> ans = spiralOrder(spiralorder);

  // Print the spiral order traversal
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }

  return 0;
}