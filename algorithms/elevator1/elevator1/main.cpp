/*
** �Ʊ۵����㷨�����������֣�
** 1�� �����ȷ����㷨�� (���ݷ������������������Ⱥ����������ִ�д���
** 2�� ���Ѱ��ʱ�����ȵ����㷨��(�ӵȴ��ķ���������ѡѰ��ʱ����̵��Ǹ�����ִ�У������ܷ����ߵ��Ⱥ����
** 3�� ���ݵ����㷨��(���ƶ��۵�ǰλ�����ƶ�����ѡ��������Ǹ�����ķ�������ִ�У����÷��������������ʱ���͸ı��ƶ�������ѡ��)
** 4�� ����ɨ������㷨�� (��0���濪ʼ���ﵥ��ɨ�裬ɨ���ĸ�ִ���ĸ���
*/



#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <string>

struct Head
{
  int nPosition;
  bool bVisited;
};

void Visit(struct Head *pHead)
{
  printf("visite cy:%d\n",pHead->nPosition);
  pHead->bVisited=true;
}

int ReadInputKeyboard(struct Head *pHead,int *pCurrentPosition,int nMaxNumber)
{
  int i;
  printf("please input Current position:");
  scanf("%d",pCurrentPosition);
  printf("please input will visit position:");

  for(i=0;i<nMaxNumber;i++)
  {
    scanf("%d",&pHead[i].nPosition);
    pHead[i].bVisited=false;
    if(pHead[i].nPosition<0)
      break;
  }
  return i;
}

int ReadInputFile(struct Head *pHead,int *pCurrentPosition,int nMaxNumber)
{
  int i;
  char szFileName[256],*q,*p,szTemp[20];
  printf("please input filename:");
  scanf("%s",szFileName);

  FILE *pFile=fopen(szFileName,"r");
  if(pFile==NULL)
  {
    printf("open file %s error",szFileName);
    return -1;
  }

  for(i=0;!feof(pFile) &&i<nMaxNumber;)
  {
    p=szFileName;
    fgets(p,256,pFile);
    while(q=strchr(p,','))
    {
      memset(szTemp,0,sizeof(szTemp)*sizeof(char));
      strncpy(szTemp,p,q-p);
      p=q+1;
      if(i==0)
        *pCurrentPosition=atoi(szTemp);
      else
      {
        pHead[i-1].nPosition=atoi(szTemp);
        pHead[i-1].bVisited=false;
      }
      i++;
    }
    memset(szTemp,0,sizeof(szTemp)*sizeof(char));
    pHead[i-1].nPosition=atoi(p);
    pHead[i-1].bVisited=false;
    //i++;

  }
  fclose(pFile);
  return i;
}

int FifoVisit(int nCurrentPosition,struct Head *pHead,int nNumber)
{
  //�����ȷ���

  int nHaveVisited=0;
  int nMoveDistance=0;
  int i;
  while(nHaveVisited<nNumber)
  {
    for(i=0;i<nNumber;i++)
    {
      if(pHead[i].bVisited)
        continue;
      Visit(&pHead[i]);
      nHaveVisited++;
      nMoveDistance+=abs(nCurrentPosition-pHead[i].nPosition);
      nCurrentPosition=pHead[i].nPosition;
    }
  }
  printf("the sum of move distance:%d\n",nMoveDistance);
  return nMoveDistance;
}

int SsfoVisit(int nCurrentPosition,struct Head *pHead,int nNumber)
{
  // ���Ѱ��ʱ������

  int nHaveVisited=0;
  int nMoveDistance=0;
  int nMinDistance=0;
  int nMinIndex=0;
  int i;
  while(nHaveVisited<nNumber)
  {
    nMinDistance=0xffff;
    nMinIndex=0;
    //����Сֵ

    for(i=0;i<nNumber;i++)
    {
      if(pHead[i].bVisited)
        continue;
      if(nMinDistance>abs(pHead[i].nPosition-nCurrentPosition))
      {
        nMinDistance=abs(pHead[i].nPosition-nCurrentPosition);
        nMinIndex=i;
      }
    }
    //����

    Visit(&pHead[nMinIndex]);
    nHaveVisited++;
    nMoveDistance+=nMinDistance;
    nCurrentPosition=pHead[nMinIndex].nPosition;
  }
  printf("the sum of move distance:%d\n",nMoveDistance);
  return nMoveDistance;
}

int DtVisit(int nCurrentPosition,bool bOut,struct Head *pHead,int nNumber)
{
  //���ݵ����㷨

  int nHaveVisited=0;
  int nMoveDistance=0;
  int nMinDistance=0;
  int nMinIndex=0;
  int i;
  while(nHaveVisited<nNumber)
  {
    nMinDistance=0xffff;
    nMinIndex=0;
    //����Сֵ

    for(i=0;i<nNumber;i++)
    {
      if(pHead[i].bVisited)
        continue;
      if(bOut&&pHead[i].nPosition<nCurrentPosition||!bOut&&pHead[i].nPosition>nCurrentPosition)
      {
        if(nMinDistance>abs(pHead[i].nPosition-nCurrentPosition))
        {
          nMinDistance=abs(pHead[i].nPosition-nCurrentPosition);
          nMinIndex=i;
        }
      }
    }
    if(nMinDistance==0xffff)
    {
      bOut=!bOut;
      continue;
    }

    //����

    Visit(&pHead[nMinIndex]);
    nHaveVisited++;
    nMoveDistance+=nMinDistance;
    nCurrentPosition=pHead[nMinIndex].nPosition;
  }
  printf("the sum of move distance:%d\n",nMoveDistance);
  return nMoveDistance;
}

int DxVisit(int nCurrentPosition,struct Head *pHead,int nNumber)
{
  //��������㷨

  int nHaveVisited=0;
  int nMoveDistance=0;
  int nMinDistance=0;
  int nMinIndex=0;
  int i;
  while(nHaveVisited<nNumber)
  {
    nMinDistance=0xffff;
    nMinIndex=0;
    //����Сֵ

    for(i=0;i<nNumber;i++)
    {
      if(pHead[i].bVisited)
        continue;
      if(pHead[i].nPosition>nCurrentPosition )
      {
        if(nMinDistance>abs(pHead[i].nPosition-nCurrentPosition))
        {
          nMinDistance=abs(pHead[i].nPosition-nCurrentPosition);
          nMinIndex=i;
        }
      }
    }
    if(nMinDistance==0xffff)
    {
      nMoveDistance+=199-nCurrentPosition;
      nCurrentPosition=0;
      continue;
    }

    //����

    Visit(&pHead[nMinIndex]);
    nHaveVisited++;
    nMoveDistance+=nMinDistance;
    nCurrentPosition=pHead[nMinIndex].nPosition;
  }
  printf("the sum of move distance:%d\n",nMoveDistance);
  return nMoveDistance;
}

int main(int argc, char* argv[])
{
  //p114

  struct Head mylist[20];//={98,false,183,false,37,false,122,false,14,false,124,false,65,false,67,false};

  //int nCurrentPosition=53;

  //int nRealNumber=8;


  int nCurrentPosition=0;
  int nRealNumber=ReadInputFile(mylist,&nCurrentPosition,20);
  // FifoVisit(nCurrentPosition,mylist,nRealNumber);

  // SsfoVisit(nCurrentPosition,mylist,nRealNumber);

  //DtVisit(nCurrentPosition,false,mylist,nRealNumber);

  DxVisit(nCurrentPosition,mylist,nRealNumber);

  return 0;
}