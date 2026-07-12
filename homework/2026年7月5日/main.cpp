//------------------------------------------------
//  2026年7月5日 10:32
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include "awsf.h"

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "作业内容: 创建一个链表 元素 {1,3,6,4,7} 查询 4 的位置" << endl;
    cout << "--------------------------------" << endl
         << endl;

    prinths(head);
    
    ListNude *p = head;
    int nl = 0;
    while (p)
    {
        nl += 1;
        if (p->val == 4)
        {
            clog << "已找到4,终止循环!" << endl;
            break;
        }
        else
        {
            cerr << "未找到!" << endl;
        }
        p = p -> next;
    }

    cout << "----------------------------" << endl;
    cout << "4的位置是: " << nl << endl ;
    cout << "----------------------------" << endl;
}
