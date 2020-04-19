#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<vector<int>> dump(board.size(), vector<int>(board[0].size(),0));
    vector<int> dump2;
    int count = 0;
    bool popcount = true;
    for (int i = 0; i < board.size(); i++) 
    {
        for (int j = 0; j < board[i].size(); j++) 
        {
            dump[count][j] = board[j][count];
        }
        count++;
    }

    count = 0;
    while (count < moves.size()) 
    {
       for (int i = 0; i < dump.size(); i++) 
       {
           if (dump[moves[count] - 1][i] != 0) 
           {
               dump2.push_back(dump[moves[count] - 1][i]);
               dump[moves[count] - 1][i] = 0;
               break;
           }
       }
        count++;
    }

    while (popcount) 
    {
        popcount = false;
        if (dump2.size() > 1) 
        {
            for (int i = 1; i < dump2.size(); i++)
            {
                if (dump2[i - 1] == dump2[i]) 
                {
                    dump2.erase(dump2.begin() + i - 1);
                    dump2.erase(dump2.begin() + i - 1);
                    answer += 2;
                    popcount = true;
                    break;
                }
            }
        }
    }



    return answer;
}
