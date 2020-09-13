//  Created by Дарья Землянская on 13.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string getLongestCommonSubsequence(const std::string& a, const std::string& b)
{
    std::vector<std::vector<int>> max_len;
    max_len.resize(a.size() + 1);
    for(int i = 0; i <= a.size(); i++){
        max_len[i].resize(b.size() + 1);
    }
    for(int i = static_cast<int>(a.size()) - 1; i >= 0; i--)
    {
        for(int j = static_cast<int>(b.size()) - 1; j >= 0; j--)
        {
            if(a[i] == b[j])
            {
                max_len[i][j] = 1 + max_len[i+1][j+1];
            }
            else
            {
                max_len[i][j] = std::max(max_len[i+1][j], max_len[i][j+1]);
            }
        }
    }
    std::string result;
    for(int i = 0, j = 0; max_len[i][j] != 0 && i < (a.size()) && j < (b.size()); )
    {
        if(a[i] == b[j])
        {
            result.push_back(a[i]);
            i++;
            j++;
        }
        else
        {
            if(max_len[i][j] == max_len[i+1][j])
                i++;
            else
                j++;
        }
    }
    std::cout << result << std::endl;
    return result;
}


int main(int argc, const char * argv[]) {
    std::string a;
    std::cout << "a: ";
    std::cin >> a;
    std::string b;
    std::cout << "b: ";
    std::cin >> b;
    getLongestCommonSubsequence(a, b);
    return 0;
}

