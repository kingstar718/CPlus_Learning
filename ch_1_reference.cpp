//
// Created by wujinxing on 2019/9/29.
//
#include <iostream>
#include "Sales_data.h"

using namespace std;

void reference() {

    int iVal = 1024;
    int &refVal = iVal;
    //int &refVal; //���ñ��뱻��ʼ��
    refVal = 2;
    cout << iVal << endl;

    //ָ�뱾�����һ������ָ�������ڶ���ʱ����ʼֵ

    int *ip1, *ip2; //����ָ��int�Ͷ����ָ��
    double dp, *dp2; //dp2��ָ��double�Ͷ����ָ�룬dp��double�Ͷ���

    //��ȡ����ĵ�ַ ָ������ĳ������ĵ�ַ��Ҫ���ȡ�õ�ַ����Ҫʹ��ȡ��ַ��&
    int *p = &iVal; //p��ű���iVal�ĵ�ַ������˵p��ָ�����iVal��ָ��
    cout << "iVal�ĵ�ַ" << &iVal << endl;

    //����ָ����ʶ���
    cout << "ʹ��ָ����ʶ���*p��" << *p << endl;

    //ֱ�����ָ����Ϊ��ַ
    cout << "ֱ�����ָ����Ϊ��ַ��p��" << p << endl;

    //ָ����ȡ&���ǵ�ǰָ�����ĵ�ַ����&p��
    cout << "ָ����ȡ&���ǵ�ǰָ�����ĵ�ַ����&p��" << &p << endl;

    /**
     * ��ͬ�㣺ָ������ö����ṩ����������ļ�ӷ��ʡ�
     * ����㣺1.���ñ������Ƕ���
     *        2.һ���������ã��޷��ٽ���󶨵�����Ķ�������
     *        3.ָ�����������ƣ���ָ�븳ֵ�����������һ���µĵ�ַ���Ӷ�ָ��һ���µĶ���
     */
    int i = 42;
    int *pi = 0;   //pi����ʼ������û��ָ���κζ���
    int *pi2 = &i; //pi2����ʼ��������i�ĵ�ַ
    int *pi3;   // ���pi3�����ڿ��ڣ���pi3��ֵ���޷�ȷ����

    pi3 = pi2;  // pi3��pi2ָ��ͬһ������
    pi2 = 0;    //����pi2��ָ���κζ�����

    /**
     * ���Ū��һ����ֵ����Ǹı���ָ���ֵ���Ǹı���ָ����ָ�����ֵ��̫����
     * �취����ס��ֵ��Զ�ı���ǵȺ����Ķ���
     */
    pi = &iVal;  //pi��ֵ���ı䣬����piָ����iVal
    *pi = 0;  // iVal��ֵ���ı䣬ָ��pi��û�иı�

    // void* ָ��
    double obj = 3.14, *pd = &obj;

    void *pv = &obj;
    pv = pd;

    //��⸴�����͵�����
    int ip = 1024, *ipp = &i, &r = i;
}

void refer2() {
    //ָ��ָ���ָ��
    int iVal = 1024;
    int *pi = &iVal;  //piָ��һ��int�͵���
    int **ppi = &pi;  //ppiָ��һ��int�͵�ָ��
    // ppi->pi->iVal(1024)
    cout << "The value of iVal\n"
         << "direct value: " << iVal << "\n"
         << "indirect value: " << *pi << "\n"
         << "doubly indirect value: " << **ppi
         << endl;

    //ָ��ָ�������
    int i = 42;
    int *p;  //p��һ��int��ָ��
    int *&r = p; // r��һ����ָ��p������

    r = &i; //r������һ��ָ�룬��˸�r��ֵ&i������pָ��i
    *r = 0; //������r�õ�i��Ҳ����pָ��Ķ��󣬽�i��ֵ��Ϊ0

    //const
    const int ci = 1024;
    const int &r1 = ci; //���ü����Ӧ�Ķ����ǳ���

    //����
    typedef double wages; //wages��double��ͬ���
    typedef wages base, *p1; //base��double��ͬ��ʣ� p1��double*��ͬ���
}

int defStruct() {

    Sales_data data1, data2;

    //����data1��data2�Ĵ���
    double price = 0;
    //�����һ�ʽ��ף�ISBN����������������
    cin >> data1.bookNo >> data1.units_sold >> price;
    //������������
    data1.revenue = data1.units_sold * price;

    //����ڶ��ʽ���
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    //���data1��data2��ISBN�Ƿ���ͬ�Ĵ���
    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        //�����ISBN�����������������۶ƽ���۸�
        cout << data1.bookNo << " " << totalCnt
             << " " << totalRevenue << " ";

        if (totalCnt != 0) {
            cout << totalRevenue / totalCnt << endl;
        } else {
            cout << "(no sales)" << endl;
        }
        return 0;
    } else{
        cerr << "Data must refer to the same ISBN"
             << endl;
        return -1;
    }
}


