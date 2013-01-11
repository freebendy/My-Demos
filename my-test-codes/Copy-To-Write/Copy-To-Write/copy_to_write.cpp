#include <iostream>

using namespace std ;

class CLargeObject
{
public:
	CLargeObject(int nVal) ;
	CLargeObject(const CLargeObject &ob) ;
	~CLargeObject() ;
	CLargeObject& operator = (const CLargeObject &ob) ;
	void SetVal(int nNewVal) ;
	int GetVal() const ;
private:
	struct CData
	{
	public:
		CData(int nVal) : m_nVal(nVal),m_nReferenceCount(1) {}
	private:
		friend class CLargeObject ;
		CData* get_own_copy() //clone if necessary
		{
			if(m_nReferenceCount == 1)
				return this ;
			m_nReferenceCount -- ;
            cout<<"clone!\n" ;
			return new CData(m_nVal) ;
		}
		//actual data portion
		int m_nVal ;
		//control variables
		int m_nReferenceCount ;
	};
	CData *m_pData ;
};

CLargeObject::CLargeObject(int nVal)
{
	m_pData = new CData(nVal) ;
}

CLargeObject::CLargeObject(const CLargeObject &ob)
{
	ob.m_pData->m_nReferenceCount ++ ;
	m_pData = ob.m_pData ;
}

CLargeObject::~CLargeObject()
{
	if(--m_pData->m_nReferenceCount == 0)
		delete m_pData ;
}

CLargeObject& CLargeObject::operator = (const CLargeObject &ob) //copy assignment
{
	ob.m_pData->m_nReferenceCount ++ ;
	if (--m_pData->m_nReferenceCount == 0)
	{
		delete m_pData ;
	}
	m_pData = ob.m_pData ;

	return *this ;
}

void CLargeObject::SetVal(int nNewVal)
{
	m_pData = m_pData->get_own_copy() ;
	m_pData->m_nVal = nNewVal ;
}

int CLargeObject::GetVal() const
{
	return m_pData->m_nVal ;
}

int main()
{
    CLargeObject clo1(11) ;
    CLargeObject clo2 = clo1 ;
    CLargeObject clo3(21) ;
    clo3 = clo1 ;

    clo2.SetVal(212) ;
	return 0 ;
}
