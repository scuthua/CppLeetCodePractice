#include "assert.h"
#include<iostream>

// string [] �ں�������������˻��� string *������sizeof�����С��ʧ�ܡ�������Ҫ��ߴ���size
void Assert::assertVector(vector<string> source, string dst[], int size) {
    if (source.size() != size) {
        cout << "assertVector fail. length is diff." << " source.length=" << source.size() << ",dst,length=" << size << endl;
        exit(1);
    }
    for (int i = 0; i < source.size(); i++) {
        for (int j = 0; j < size; j++)
        {
            if (source[i] == dst[j]) {
                goto find;
            }
        }
        // cout << "assertVector fail. index = " << i << ",source=" << source[i] << ",dst=" << dst[j] << endl;
        cout << "assertVector fail. not find ,source=" << source[i] << endl;
        exit(2);
        continue;
    find:;
    }
}

void Assert::assertInt(int src, int dst)
{
    if (src != dst)
    {
        cout << "assertInt fail. src=" << src << " ,dst=" << dst << endl;
        exit(2);
    }
}