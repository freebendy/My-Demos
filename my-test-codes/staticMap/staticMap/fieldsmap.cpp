#include "fieldsmap.h"
namespace pctor
{
    std::map<std::string,std::string> FieldsMap::accountMap ;
    std::map<std::string,std::string> FieldsMap::customContactMap ;
    std::map<std::string,std::string> FieldsMap::customGroupMap ;
    std::map<std::string,std::string> FieldsMap::enterpriseContactMap ;
    std::map<std::string,std::string> FieldsMap::enterpriseGroupMap ;
    std::map<std::string,std::string> FieldsMap::enterpriseMap ;

    void FieldsMap::initialize()
    {
        //�ʺű�ӳ��
        FieldsMap::accountMap["SENDFILEAUTHORITY"] = "SENDFILEAUTHORITY" ;                         //�����ļ�Ȩ��
        FieldsMap::accountMap["GROUPSENDFILEAUTHORITY"] = "GROUPSENDFILEAUTHORITY" ;               //Ⱥ���ļ�Ȩ��
        FieldsMap::accountMap["GROUPCHATAUTHORITY"] = "GROUPCHATAUTHORITY" ;                      //��������Ȩ��
        FieldsMap::accountMap["SENDINFORMAUTHORITY"] = "SENDINFORMAUTHORITY" ;                    //����֪ͨȨ��

        //�û���ҵ��ӳ��
        FieldsMap::enterpriseMap["NAME"] = "CORPNAME" ; //��ҵ����

        //��ҵ�ڲ���֯��ӳ��                                                                   
        FieldsMap::enterpriseGroupMap["NAME"]  = "ORGNAME" ;                                                                //������
        FieldsMap::enterpriseGroupMap["DIRECTOR"] = "DIRECTOR" ;                                                        //���Ÿ�����
        FieldsMap::enterpriseGroupMap["ADDRESS"] = "ADDRESS" ;                                                           //�ͻ���ַ
        FieldsMap::enterpriseGroupMap["ZIP"] = "ZIP" ;                                                                             //��������
        FieldsMap::enterpriseGroupMap["PHONE"] = "PHONE" ;                                                                  //��ϵ�绰
        FieldsMap::enterpriseGroupMap["FAX"] = "FAX" ;                                                                            //��ϵ����
        FieldsMap::enterpriseGroupMap["ORGFLAG"] = "ORGFLAG" ;                                                           //���ű�־
        FieldsMap::enterpriseGroupMap["DESCRIPTION"] = "DESCRIPTION" ;                                             //��������

        //��ҵ�ڲ���ϵ�˱�ӳ��
        FieldsMap::enterpriseContactMap["NAME"] = "USERNAME" ;                                                           //����
        FieldsMap::enterpriseContactMap["SIGNATURE"] = "SIGNATURE" ;                                                 //ǩ��
        FieldsMap::enterpriseContactMap["PHOTOPATH"] = "PHOTOPATH" ;                                               //��Ƭ·��
        FieldsMap::enterpriseContactMap["OFFICE"] = "OFFICE" ;                                                              //�칫��
        FieldsMap::enterpriseContactMap["DUTY"] = "DUTY" ;                                                                     //ְ��
        FieldsMap::enterpriseContactMap["TITLEPOSITION"] = "TITLEPOSITION" ;                                     //ְ��
        FieldsMap::enterpriseContactMap["OFFICEPHONE1"] = "BUSINESSPHONE1" ;                               //�칫�绰1
        FieldsMap::enterpriseContactMap["OFFICEPHONE2"] = "BUSINESSPHONE2" ;                               //�칫�绰2
        FieldsMap::enterpriseContactMap["OFFICEFAX"] = "BUSINESSFAX" ;                                             //�칫����
        FieldsMap::enterpriseContactMap["IPPHONE"] = "BUSINESSIPPHONE" ;                                       //IP�绰
        FieldsMap::enterpriseContactMap["OFFICEMESNO"] = "BUSINESSMESNO" ;                                  //�칫��ʱͨѶ�ʺ�
        FieldsMap::enterpriseContactMap["OFFICEMOBILE"] = "BUSINESSMOBILEPHONE" ;                     //�ƶ��绰
        FieldsMap::enterpriseContactMap["NICKNAME"] = "NICKNAME" ;                                                   //�ǳ�
        FieldsMap::enterpriseContactMap["GENDER"] = "NICKNAME" ;                                                       //�Ա�
        FieldsMap::enterpriseContactMap["BIRTHDAY"] = "BIRTHDAY" ;                                                     //����
        FieldsMap::enterpriseContactMap["NATION"] = "NATION" ;                                                            //����
        FieldsMap::enterpriseContactMap["NATIVEPLACE"] = "NATIVEPLACE" ;                                       //����
        FieldsMap::enterpriseContactMap["HOMEZIP"] = "HOMEPOSTALCODE" ;                                    //��������
        FieldsMap::enterpriseContactMap["HOMEADDRESS"] = "HOMECOUNTRY" ;                                  //��ͥ��ַ
        FieldsMap::enterpriseContactMap["SELFMOBILE"] = "SELFMOBILEPHONE" ;                               //�����ƶ��绰
        FieldsMap::enterpriseContactMap["SELFPHONE"] = "SELFPHONE" ;                                            //���˹̶��绰
        FieldsMap::enterpriseContactMap["SELFAX"] = "SELFAX" ;                                                          //���˴���
        FieldsMap::enterpriseContactMap["EMAIL1"] = "SELFEMAIL1" ;                                                   //�����ʼ�1
        FieldsMap::enterpriseContactMap["EMAIL2"] = "SELFEMAIL2" ;                                                   //�����ʼ�2
        FieldsMap::enterpriseContactMap["EMAIL3"] = "SELFEMAIL3" ;                                                   //�����ʼ�3
        FieldsMap::enterpriseContactMap["MESNO1"] = "SELFMESNO1" ;                                                //��ʱͨѶ�ʺ�1
        FieldsMap::enterpriseContactMap["MESNO2"] = "SELFMESNO2" ;                                                //��ʱͨѶ�ʺ�2
        FieldsMap::enterpriseContactMap["MESNO3"] = "SELFMESNO3" ;                                                //��ʱͨѶ�ʺ�3
        FieldsMap::enterpriseContactMap["HOMEPAGE"] = "HOMEPAGE" ;                                               //������ҳ
        FieldsMap::enterpriseContactMap["URGENCYLINKMAN"] = "URGENCYLINKMAN" ;                         //������ϵ��
        FieldsMap::enterpriseContactMap["URGENCYPHONE"] = "URGENCYPHONE" ;                               //������ϵ�绰
        FieldsMap::enterpriseContactMap["MARRIAGEFLAG"] = "MARRIAGEFLAG" ;                                   //����״��
        FieldsMap::enterpriseContactMap["SPOUSE"] = "SPOUSE" ;                                                         //��ż
        FieldsMap::enterpriseContactMap["CHILDREN"] = "CHILDREN" ;                                                   //��Ů
        FieldsMap::enterpriseContactMap["DESCRIPTION"] = "DESCRIPTION" ;                                        // ����������Ϣ

        //��ҵ�ⲿ���ӳ��
        FieldsMap::customGroupMap["NAME"] = "CROUPNAME" ; 
        FieldsMap::customGroupMap["DESCRIPTION"] = "DESCRIPTION" ; 

        //��ҵ�ⲿ��ϵ�˱�ӳ��                                                                  
        FieldsMap::customContactMap["NAME"] = "LINKMANNAME" ;                                                             //����
        FieldsMap::customContactMap["COMPANY"] = "COMPANY" ;                                                             //��˾����
        FieldsMap::customContactMap["COMPANYZIP"] = "COMPANYZIP" ;                                                   //��˾�ʱ�
        FieldsMap::customContactMap["COMPANYADDRESS"] = "COMPANYADDRESS" ;                                 //��˾��ַ
        FieldsMap::customContactMap["ORGNAME"] = "ORGNAME" ;                                                               //��������
        FieldsMap::customContactMap["OFFICE"] = "OFFICE" ;                                                                         //�칫��                                 
        FieldsMap::customContactMap["DUTY"] = "DUTY" ;                                                                                //ְ��
        FieldsMap::customContactMap["TITLEPOSITION"] = "TITLEPOSITION" ;                                                //ְ��
        FieldsMap::customContactMap["OFFICEPHONE1"] = "BUSINESSPHONE1" ;                                          //�칫�绰1
        FieldsMap::customContactMap["OFFICEPHONE2"] = "BUSINESSPHONE2" ;                                          //�칫�绰2
        FieldsMap::customContactMap["OFFICEFAX"] = "BUSINESSFAX" ;                                                        //�칫����
        FieldsMap::customContactMap["IPPHONE"] = "BUSINESSIPPHONE" ;                                                  //IP�绰
        FieldsMap::customContactMap["OFFICEMESNO"] = "BUSINESSMESNO" ;                                              //�칫��ʱͨѶ
        FieldsMap::customContactMap["OFFICEMOBILE"] = "BUSINESSMOBILEPHONE" ;                                //�ƶ��绰
        FieldsMap::customContactMap["NICKNAME"] = "NICKNAME" ;                                                               //�ǳ�
        FieldsMap::customContactMap["GENDER"] = "GENDER" ;                                                                       //�Ա�
        FieldsMap::customContactMap["BIRTHDAY"] = "BIRTHDAY" ;                                                                  //����
        FieldsMap::customContactMap["NATION"] = "NATION" ;                                                                        //����
        FieldsMap::customContactMap["NATIVEPLACE"] = "NATIVEPLACE" ;                                                    //����
        FieldsMap::customContactMap["HOMEZIP"] = "ZIP" ;                                                                           //��������
        FieldsMap::customContactMap["HOMEADDRESS"] = "HOMECOUNTRY" ;                                                 //��ͥ��ַ
        FieldsMap::customContactMap["SELFMOBILE"] = "SELFMOBILEPHONE" ;                                             //�����ƶ��绰
        FieldsMap::customContactMap["SELFPHONE"] = "SELFPHONE" ;                                                         //���˹̶��绰
        FieldsMap::customContactMap["SELFAX"] = "SELFAX" ;                                                                       //���˴���
        FieldsMap::customContactMap["EMAIL1"] = "SELFEMAIL1" ;                                                                //�����ʼ�1
        FieldsMap::customContactMap["EMAIL2"] = "SELFEMAIL2" ;                                                                //�����ʼ�2
        FieldsMap::customContactMap["EMAIL3"] = "SELFEMAIL3" ;                                                                //�����ʼ�3
        FieldsMap::customContactMap["MESNO1"] = "SELFMESNO1" ;                                                             //��ʱͨѶ�ʺ�1
        FieldsMap::customContactMap["MESNO2"] = "SELFMESNO2" ;                                                             //��ʱͨѶ�ʺ�2
        FieldsMap::customContactMap["MESNO3"] = "SELFMESNO3" ;                                                             //��ʱͨѶ�ʺ�3
        FieldsMap::customContactMap["HOMEPAGE"] = "HOMEPAGE" ;                                                           //������ҳ
        FieldsMap::customContactMap["URGENCYLINKMAN"] = "URGENCYLINKMAN" ;                                     //������ϵ��
        FieldsMap::customContactMap["URGENCYPHONE"] = "URGENCYPHONE" ;                                           //������ϵ�绰
        FieldsMap::customContactMap["MARRIAGEFLAG"] = "MARRIAGEFLAG" ;                                               //����״��
        FieldsMap::customContactMap["SPOUSE"] = "SPOUSE" ;                                                                      //��ż
        FieldsMap::customContactMap["CHILDREN"] = "CHILDREN" ;                                                                //��Ů
        FieldsMap::customContactMap["DESCRIPTION"] = "DESCRIPTION" ;                                                      // ����������Ϣ
    }
} //namespace pctor
