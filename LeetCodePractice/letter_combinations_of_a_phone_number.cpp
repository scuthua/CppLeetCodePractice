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
        // ��������볤�����й�ϵ�ģ����Կ�����ǰ���úô�С�����ٺ����Զ�����
        ret.reserve(pow(4, digits.size()));

        /*
        * ����digits�ĳ��Ȳ��ǹ̶��ģ�����ֱ�Ӷ��forѭ��û��д��
        * ���ǿ�����whileģ�⣬ÿһ��whileѭ����ʱ��digits���һ��λ���ϵ�����չ����������ʱ������뵽�б��С���һ��ѭ����ʱ����б�������Ԫ�ص���һλ������չ����ֱ��indexԽ�硣
        */
        ret.push_back(digits);
        int index = 0;
        string seed;
        int length = 0;
        while (index <= digits.size() - 1) {
            length = ret.size();
            for (int i = 0; i < length; i++) {
                // �����Ӧ��������������map��ʵ�����ֺ�string���л�������key��2��value�ǡ�abc����abc��ֵ�������ֳ�������û��Ҫ����switch��ʡ�ռ��ء�
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