#pragma once

#include <vector>
#include <string>

class Solution {
public:
   bool exist(std::vector<std::vector<char>>& board, std::string word) {
      using namespace std;
      vector<vector<bool>> visitedCells(board.size(), vector<bool>(board.front().size(), false));
      for (int i = 0; i < board.size(); ++i)
      {
         for (int j = 0; j < board.front().size(); ++j)
         {
            string currentWord;
            currentWord.push_back(board[i][j]);
            visitedCells[i][j] = true;
            bool result = exist(board, visitedCells, currentWord, i, j, word);
            visitedCells[i][j] = false;
            if (result)
               return result;
         }
      }
      return false;
   }

   bool exist(const std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, std::string& currentWord, int i, int j, const std::string& word)
   {
      if (currentWord.size() == word.size())
      {
         return currentWord == word;
      }
      bool result = false;
      if (i > 0 && !visited[i - 1][j])
      {
         visited[i - 1][j] = true;
         currentWord.push_back(board[i - 1][j]);
         result = exist(board, visited, currentWord, i - 1, j, word);
         currentWord.pop_back();
         visited[i - 1][j] = false;
      }
      if (result)
         return result;
      if (i < board.size() - 1 && !visited[i + 1][j])
      {
         visited[i + 1][j] = true;
         currentWord.push_back(board[i + 1][j]);
         result = exist(board, visited, currentWord, i + 1, j, word);
         currentWord.pop_back();
         visited[i + 1][j] = false;
      }
      if (result)
         return result;
      if (j > 0 && !visited[i][j - 1])
      {
         visited[i][j - 1] = true;
         currentWord.push_back(board[i][j - 1]);
         result = exist(board, visited, currentWord, i, j - 1, word);
         currentWord.pop_back();
         visited[i][j - 1] = false;
      }
      if (result)
         return result;
      if (j < board.front().size() - 1 && !visited[i][j + 1])
      {
         visited[i][j + 1] = true;
         currentWord.push_back(board[i][j + 1]);
         result = exist(board, visited, currentWord, i, j + 1, word);
         currentWord.pop_back();
         visited[i][j + 1] = false;
      }
      return result;
   }
};