#pragma once
#include "Combi.h"
namespace combi {
    //������������ ���������
	struct subset {
        short n, sn, *sset;
        unsigned __int64 mask;
        subset(short n = 1);
        subset();
        void reset();
        short getfirst();
        short getnext();
        short ntx(short i);
        unsigned __int64 count();
	};

    //���������
    struct xcombination
    {
        short  n,                  // ���������� ��������� ��������� ���������  
            m,                  // ���������� ��������� � ���������� 
            *sset;            	  // ������ �������� �������� ���������  

        xcombination(
            short n = 1, //���������� ��������� ��������� ���������  
            short m = 1  // ���������� ��������� � ����������
        );
        void reset();              // �������� ���������, ������ ������� 
        short getfirst();          // ������������ ������ ������ ��������    
        short getnext();           // ������������ ��������� ������ ��������  
        short ntx(short i);        // �������� i-� ������� ������� ��������  
        unsigned __int64 nc;       // ����� ���������  0,..., count()-1   
        unsigned __int64 count() const;  // ��������� ���������� ���������     
    };

    //������������
    struct  permutation    // ���������   ������������     
    {
        const static bool L = true;  // ����� ������� 
        const static bool R = false; // ������ �������   

        short  n,              // ���������� ��������� ��������� ��������� 
            * sset;           // ������ �������� ������� ������������
        bool* dart;           // ������  ������� (�����-L � ������-R) 
        permutation(short n = 1); // ����������� (���������� ��������� ��������� ���������) 
        void reset();                // �������� ���������, ������ ������� 

        __int64 getfirst();          // ������������ ������ ������ ��������    
        __int64 getnext();           // ������������ ��������� ������ ��������  

        short ntx(short i);          // �������� i-� ������� ������ �������� 
        unsigned __int64 np;         // ����� ������������ 0,... count()-1 

        unsigned __int64 count() const;  // ��������� ����� ���. ������������    
    };   

    //����������
    struct  accomodation  // ��������� ���������� 
    {
        short  n,      // ���������� ��������� ��������� ���������  
            m,      // ���������� ��������� � ���������� 
            * sset;      // ������ ������� �������� ����������  
        xcombination* cgen;   // ��������� �� ��������� ���������
        permutation* pgen;   // ��������� �� ��������� ������������
        accomodation(short n = 1, short m = 1);  // �����������  
        void reset();     // �������� ���������, ������ ������� 
        short getfirst();     // ������������ ������ ������ ��������   
        short getnext();      // ������������ ��������� ������ ��������  
        short ntx(short i);   // �������� i-� ������� ������� ��������  
        unsigned __int64 na;  // ����� ���������� 0, ..., count()-1 
        unsigned __int64 count() const;  // ����� ���������� ���������� 
    };
}