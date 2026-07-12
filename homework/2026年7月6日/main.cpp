//------------------------------------------------
//  2026年7月6日 10:21:50
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include "awsf.h"

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    prinths(head);
    ListNude *p = head;
    int nq = 0;
    while (p)
    {
        nq += 1;
        if (p->val == 7)
        {
            cout << "已找到7,位于: " << nq << endl;
            break;
        }
        p = p->next;
    }
}