#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

#include "../4__stack/stack.cpp"

string read_file(string filename)
{
  // solution from https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
  ifstream file(filename);
  string file_content;
  stringstream file_stream;
  if (file.is_open())
  {
    file_stream << file.rdbuf();
    file_content = file_stream.str();
    file.close();
  }
  else
  {
    file_content = "";
  }

  return file_content;
}
// Алгоритм для того чтобы узнать что все скобки корректно закрыты
void delimeter_matcher(string _file_content)
{
  Stack<char> *open_brackets = new Stack<char>();
  bool status = true;

  map<char, int> parenthesis = {
      {'(', 0},
      {')', 0},
      {'[', 1},
      {']', 1},
      {'{', 2},
      {'}', 2},
  };

  vector<char> file_content(_file_content.begin(), _file_content.end());

  int i = 0;
  while (i < file_content.size())
  {
    char temp_char = file_content[i];
    if (temp_char == '(' || temp_char == '[' || temp_char == '{')
    {
      open_brackets->Push(temp_char);
    }
    else if (temp_char == ')' || temp_char == ']' || temp_char == '}')
    {
      char open_bracket = open_brackets->Pop();
      if (parenthesis[open_bracket] != parenthesis[temp_char])
      {
        cout << "Error, expected" << open_bracket << " Got: " << temp_char << "\n";
        status = false;
        break;
      }
    }
    else if (temp_char == '/')
    {
      char next_char = file_content[i + 1];
      if (next_char == '*')
      {
        i += 1;
        // пока не будет найдена строка */
        // или не достигнут конец файла выполнять поиск
        while (((int)(file_content[i] == '*') + (int)(file_content[i + 1] == '/')) != 2 &&
               i < file_content.size())
          i += 1;

        if (i >= file_content.size())
        {
          cout << "Error: comment block isn't closed"
               << "\n";
          status = false;
          break;
        }
        i += 1;
      }
    }
    i += 1;
  }

  if (status && open_brackets->IsEmpty())

    cout << "Everything ok"
         << "\n";

  else
    cout << "Parenthesis don't match"
         << "\n";
}

int main()
{
  string file_content = read_file("./test_cpp_file");
  delimeter_matcher(file_content);
}