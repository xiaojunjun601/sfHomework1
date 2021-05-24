#include<bits/stdc++.h>
using namespace std;

//���������Ĵ洢��ʾ
typedef struct
{
    int weight;    // Ȩֵ
    int parent, lChild, rChild;    // ˫�׼����Һ��ӵ��±�
}HTNode, *HuffmanTree;
// �����������Ĵ洢��ʾ
typedef struct
{
    char** code;    // �����
    int n;          // ������
}HuffmanCode;
// ѡ��Ȩֵ��С��������
void SelectMin(HuffmanTree hT, int n, int &s1, int &s2)
{
    s1 = s2 = 0;

    int i;
    for(i = 1; i < n; ++ i){
        if(0 == hT[i].parent){
            if(0 == s1){
                s1 = i;
            }
            else{
                s2 = i;
                break;
            }
        }
    }
    if(hT[s1].weight > hT[s2].weight){
        int t = s1;
        s1 = s2;
        s2 = t;
    }

    for(i += 1; i < n; ++ i){
        if(0 == hT[i].parent){
            if(hT[i].weight < hT[s1].weight){
                s2 = s1;
                s1 = i;
            }else if(hT[i].weight < hT[s2].weight){
                s2 = i;
            }
        }
    }
}
// ������n��Ȩֵ��Ҷ�ӽڵ㣩�Ĺ�������
void CreateHufmanTree(HuffmanTree &hT)
{
    int n, m;
    cout<<"������һ���м�����:";
    cin >> n;
    m = 2*n - 1;//�ܽڵ���

    hT = new HTNode[m + 1];    // 0�Žڵ㲻ʹ��
    
    //���
    for(int i = 1; i <= m; ++ i){
        hT[i].parent = hT[i].lChild = hT[i].rChild = 0;
    }
    
    cout<<"������������Ӧ��Ȩֵ"<<endl;
    for(int i = 1; i <= n; ++ i){
        cin >> hT[i].weight;    // ����Ȩֵ
    }
    hT[0].weight = m;    // ��0�Žڵ㱣��ڵ�����
    /****** ��ʼ�����, ������������ ******/
    for(int i = n + 1; i <= m; ++ i){
        int s1, s2;
        SelectMin(hT, i, s1, s2);

        hT[s1].parent = hT[s2].parent = i;
        hT[i].lChild = s1; hT[i].rChild = s2;    // ��Ϊ�½ڵ�ĺ���
        hT[i].weight = hT[s1].weight + hT[s2].weight;    // �½ڵ�Ϊ���Һ��ӽڵ�Ȩֵ֮��
    }
}
// ������ݹ�������������������
void CreateHuffmanCode(HuffmanTree hT, HuffmanCode &hC)
{
    hC.n = (hT[0].weight + 1)/2;
    hC.code = new char*[hC.n + 1];    // 0λ�ò�ʹ��

    char *cd = new char[hC.n];  // ��ʱ���ÿ������

    for(int i = 1; i <= hC.n; ++ i){

        // ÿ�δ�Ҷ�ӽڵ����ϻ��ݹ������
        int len = 0, child = i, parent = hT[i].parent;
        while(parent != 0){
            if(hT[parent].lChild == child){
                cd[len ++] = '0';
            }
            else{
                cd[len ++] = '1';
            }
            child = parent;
            parent = hT[parent].parent;
        }
        cd[len] = 0;

        reverse(cd, cd + len);    // �����з�ת
        hC.code[i] = new char[len];
        strcpy(hC.code[i], cd);
    }
    delete[] cd;
}

// �����������
void PrintHuffmanCode(HuffmanCode &hC)
{
    for(int i = 1; i <= hC.n; ++ i){
        cout <<i<<":"<< hC.code[i] << endl;
    }
}

// ���ٹ�������
void DestoryHuffmanTree(HuffmanTree &hT)
{
    delete[] hT;
    hT = NULL;
}

// ���ٹ����������
void DestoryHuffmanCode(HuffmanCode &hC)
{
    for(int i = 1; i <= hC.n; ++ i){
        delete[] hC.code[i];
    }
    delete[] hC.code;
    hC.code = NULL;
}

int main()
{
    HuffmanTree hT;
    CreateHufmanTree(hT);

    HuffmanCode hC;
    CreateHuffmanCode(hT, hC);
    PrintHuffmanCode(hC);

    DestoryHuffmanTree(hT);
    DestoryHuffmanCode(hC);
    return 0;
}
