#include<iostream>
using namespace std;

#include<vector>
#include<math.h>
#include "assert.h"
/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.size() == 0 || digits == "") {
            return ret;
        }
        // 结果和输入长度是有关系的，所以可以提前设置好大小，减少后续自动扩容
        ret.reserve(pow(4, digits.size()));

        /*
        * 由于digits的长度不是固定的，所以直接多层for循环没法写。
        * 但是可以用while模拟，每一次while循环的时候将digits里的一个位置上的数字展开，并将临时结果加入到列表中。下一轮循环的时候对列表里所有元素的下一位的数字展开，直到index越界。
        */
        ret.push_back(digits);
        int index = 0;
        string seed;
        int length = 0;
        while (index <= digits.size() - 1) {
            length = ret.size();
            for (int i = 0; i < length; i++) {
                // 这道题应该是想让我们用map来实现数字和string的切换。比如key是2，value是“abc”或abc数值。但这种场景好像没必要，用switch还省空间呢。
                switch (ret[i][index])
                {
                case '2':
                    seed = "abc";
                    break;
                case '3':
                    seed = "def";
                    break;
                case '4':
                    seed = "ghi";
                    break;
                case '5':
                    seed = "jkl";
                    break;
                case '6':
                    seed = "mno";
                    break;
                case '7':
                    seed = "pqrs";
                    break;
                case '8':
                    seed = "tuv";
                    break;
                case '9':
                    seed = "wxyz";
                    break;
                default:
                    cout << "unknown digits" << endl;
                    exit(1);
                    break;
                }
                ret[i][index] = seed[0];
                for (int j = 1; j < seed.size(); j++)
                {
                    string add = (ret[i]);
                    add[index] = seed[j];
                    ret.push_back(add);
                }
            }
            ++index;
        }
        return ret;
    }
};




int main() {

    Solution  solution;
    vector<string> output;
    {
        output = solution.letterCombinations("23");
        string dst[] = { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
        Assert::assertVector(output, dst, sizeof(dst) / sizeof(dst[0]));
    }
    {
        output = solution.letterCombinations("2");
        string dst[] = { "a","b","c" };
        Assert::assertVector(output, dst, sizeof(dst) / sizeof(dst[0]));
    }
    {
        output = solution.letterCombinations("");
        Assert::assertInt(output.size(), 0);
    }
    cout << "success!" << endl;
    return 0;
}