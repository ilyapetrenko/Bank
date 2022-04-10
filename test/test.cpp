#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

static LPCSTR filePath = "table.txt";
typedef struct Bank {
    char name[20];
    int mfo;
}B;

typedef struct node {
    B inf;
    struct node* next;
}NODE;
int counter = 0;

NODE* AddFirst(NODE* head) {
    NODE* q = new NODE;
    cout << "enter name of Bank" << endl;
    cin >> q->inf.name;
    cout << "enter mfo" << endl;
    cin >> q->inf.mfo;
    q->next = head;
    head = q;
    counter++;

    return q;

}

void Output(NODE* head) {
    FILE* fout;
    fopen_s(&fout, filePath, "wt");
    if (fout)
    {
        fprintf(fout, "");
        fclose(fout);
    }
    NODE* q = head;
    while (q) {
        cout << "Bank: " << q->inf.name << " MFO: " << q->inf.mfo << endl;
        std::string sString(q->inf.name);
        sString += std::string("  ");
        sString += std::string(to_string(q->inf.mfo));
        std::ofstream myTableFile;
        myTableFile.open(filePath, std::ofstream::app);

        if (myTableFile.is_open())
        {
            myTableFile << sString << std::endl;
        }

        myTableFile.close();
        q = q->next;
    }
}

void edit(NODE* head, int x) {

    cin >> x;
    NODE* q = head;
    int count2 = 1;
    if (x <= counter) {
        while (count2 < x) {
            q = q->next;
            count2++;
        }
    }
    cout << "enter name of Bank" << endl;
    cin >> q->inf.name;
    cout << "enter mfo" << endl;
    cin >> q->inf.mfo;
    count2 = 1;
}

NODE* AddBefore(NODE* head, int k) {
    cin >> k;
    NODE* q = new NODE;
    NODE* p = head;
    int count2 = 1;
    if (k <= counter) {
        while (count2 < (k - 1)) {
            p = p->next;
            count2++;
        }
    }

    cout << "enter name of Bank" << endl;
    cin >> q->inf.name;
    cout << "enter mfo" << endl;
    cin >> q->inf.mfo;
    q->next = p->next;
    p->next = q;
    counter++;
    return q;
}

NODE* DelBefore(NODE* head, int k) {
    cin >> k;
    NODE* q;
    NODE* p = head;
    int count2 = 1;
    if (k <= counter) {
        while (count2 < (k - 2)) {
            p = p->next;
            count2++;
        }
    }
    q = p;
    q->next = p->next->next;
    counter--;
    return q;
}



int main()
{
    cout << "(1) add element in the beginning" << endl << "(2) output list" << endl << "(3) edit element №k" << endl << "(4) add before element №k" << endl << "(5) delete before element №k" << endl << "(6) end of work" << endl;
    NODE* head = NULL;
    int c;
    do {
        cin >> c;
        switch (c) {

        case 1: head = AddFirst(head); break;
        case 2: Output(head); break;
        case 3: edit(head, 3); break;
        case 4: AddBefore(head, 1); break;
        case 5: DelBefore(head, 1); break;
        }
    } while (c != 6);
    
    return 0;
}