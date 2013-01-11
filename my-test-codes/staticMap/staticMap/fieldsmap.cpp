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
        //帐号表映射
        FieldsMap::accountMap["SENDFILEAUTHORITY"] = "SENDFILEAUTHORITY" ;                         //发送文件权限
        FieldsMap::accountMap["GROUPSENDFILEAUTHORITY"] = "GROUPSENDFILEAUTHORITY" ;               //群发文件权限
        FieldsMap::accountMap["GROUPCHATAUTHORITY"] = "GROUPCHATAUTHORITY" ;                      //多人讨论权限
        FieldsMap::accountMap["SENDINFORMAUTHORITY"] = "SENDINFORMAUTHORITY" ;                    //发送通知权限

        //用户企业表映射
        FieldsMap::enterpriseMap["NAME"] = "CORPNAME" ; //企业名称

        //企业内部组织表映射                                                                   
        FieldsMap::enterpriseGroupMap["NAME"]  = "ORGNAME" ;                                                                //部门名
        FieldsMap::enterpriseGroupMap["DIRECTOR"] = "DIRECTOR" ;                                                        //部门负责人
        FieldsMap::enterpriseGroupMap["ADDRESS"] = "ADDRESS" ;                                                           //客户地址
        FieldsMap::enterpriseGroupMap["ZIP"] = "ZIP" ;                                                                             //邮政编码
        FieldsMap::enterpriseGroupMap["PHONE"] = "PHONE" ;                                                                  //联系电话
        FieldsMap::enterpriseGroupMap["FAX"] = "FAX" ;                                                                            //联系传真
        FieldsMap::enterpriseGroupMap["ORGFLAG"] = "ORGFLAG" ;                                                           //部门标志
        FieldsMap::enterpriseGroupMap["DESCRIPTION"] = "DESCRIPTION" ;                                             //部门描述

        //企业内部联系人表映射
        FieldsMap::enterpriseContactMap["NAME"] = "USERNAME" ;                                                           //姓名
        FieldsMap::enterpriseContactMap["SIGNATURE"] = "SIGNATURE" ;                                                 //签名
        FieldsMap::enterpriseContactMap["PHOTOPATH"] = "PHOTOPATH" ;                                               //照片路径
        FieldsMap::enterpriseContactMap["OFFICE"] = "OFFICE" ;                                                              //办公室
        FieldsMap::enterpriseContactMap["DUTY"] = "DUTY" ;                                                                     //职务
        FieldsMap::enterpriseContactMap["TITLEPOSITION"] = "TITLEPOSITION" ;                                     //职称
        FieldsMap::enterpriseContactMap["OFFICEPHONE1"] = "BUSINESSPHONE1" ;                               //办公电话1
        FieldsMap::enterpriseContactMap["OFFICEPHONE2"] = "BUSINESSPHONE2" ;                               //办公电话2
        FieldsMap::enterpriseContactMap["OFFICEFAX"] = "BUSINESSFAX" ;                                             //办公传真
        FieldsMap::enterpriseContactMap["IPPHONE"] = "BUSINESSIPPHONE" ;                                       //IP电话
        FieldsMap::enterpriseContactMap["OFFICEMESNO"] = "BUSINESSMESNO" ;                                  //办公即时通讯帐号
        FieldsMap::enterpriseContactMap["OFFICEMOBILE"] = "BUSINESSMOBILEPHONE" ;                     //移动电话
        FieldsMap::enterpriseContactMap["NICKNAME"] = "NICKNAME" ;                                                   //昵称
        FieldsMap::enterpriseContactMap["GENDER"] = "NICKNAME" ;                                                       //性别
        FieldsMap::enterpriseContactMap["BIRTHDAY"] = "BIRTHDAY" ;                                                     //生日
        FieldsMap::enterpriseContactMap["NATION"] = "NATION" ;                                                            //民族
        FieldsMap::enterpriseContactMap["NATIVEPLACE"] = "NATIVEPLACE" ;                                       //籍贯
        FieldsMap::enterpriseContactMap["HOMEZIP"] = "HOMEPOSTALCODE" ;                                    //邮政编码
        FieldsMap::enterpriseContactMap["HOMEADDRESS"] = "HOMECOUNTRY" ;                                  //家庭地址
        FieldsMap::enterpriseContactMap["SELFMOBILE"] = "SELFMOBILEPHONE" ;                               //个人移动电话
        FieldsMap::enterpriseContactMap["SELFPHONE"] = "SELFPHONE" ;                                            //个人固定电话
        FieldsMap::enterpriseContactMap["SELFAX"] = "SELFAX" ;                                                          //个人传真
        FieldsMap::enterpriseContactMap["EMAIL1"] = "SELFEMAIL1" ;                                                   //电子邮件1
        FieldsMap::enterpriseContactMap["EMAIL2"] = "SELFEMAIL2" ;                                                   //电子邮件2
        FieldsMap::enterpriseContactMap["EMAIL3"] = "SELFEMAIL3" ;                                                   //电子邮件3
        FieldsMap::enterpriseContactMap["MESNO1"] = "SELFMESNO1" ;                                                //即时通讯帐号1
        FieldsMap::enterpriseContactMap["MESNO2"] = "SELFMESNO2" ;                                                //即时通讯帐号2
        FieldsMap::enterpriseContactMap["MESNO3"] = "SELFMESNO3" ;                                                //即时通讯帐号3
        FieldsMap::enterpriseContactMap["HOMEPAGE"] = "HOMEPAGE" ;                                               //个人主页
        FieldsMap::enterpriseContactMap["URGENCYLINKMAN"] = "URGENCYLINKMAN" ;                         //紧急联系人
        FieldsMap::enterpriseContactMap["URGENCYPHONE"] = "URGENCYPHONE" ;                               //紧急联系电话
        FieldsMap::enterpriseContactMap["MARRIAGEFLAG"] = "MARRIAGEFLAG" ;                                   //婚姻状况
        FieldsMap::enterpriseContactMap["SPOUSE"] = "SPOUSE" ;                                                         //配偶
        FieldsMap::enterpriseContactMap["CHILDREN"] = "CHILDREN" ;                                                   //子女
        FieldsMap::enterpriseContactMap["DESCRIPTION"] = "DESCRIPTION" ;                                        // 描述介绍信息

        //企业外部组表映射
        FieldsMap::customGroupMap["NAME"] = "CROUPNAME" ; 
        FieldsMap::customGroupMap["DESCRIPTION"] = "DESCRIPTION" ; 

        //企业外部联系人表映射                                                                  
        FieldsMap::customContactMap["NAME"] = "LINKMANNAME" ;                                                             //姓名
        FieldsMap::customContactMap["COMPANY"] = "COMPANY" ;                                                             //公司名称
        FieldsMap::customContactMap["COMPANYZIP"] = "COMPANYZIP" ;                                                   //公司邮编
        FieldsMap::customContactMap["COMPANYADDRESS"] = "COMPANYADDRESS" ;                                 //公司地址
        FieldsMap::customContactMap["ORGNAME"] = "ORGNAME" ;                                                               //部门名称
        FieldsMap::customContactMap["OFFICE"] = "OFFICE" ;                                                                         //办公室                                 
        FieldsMap::customContactMap["DUTY"] = "DUTY" ;                                                                                //职务
        FieldsMap::customContactMap["TITLEPOSITION"] = "TITLEPOSITION" ;                                                //职称
        FieldsMap::customContactMap["OFFICEPHONE1"] = "BUSINESSPHONE1" ;                                          //办公电话1
        FieldsMap::customContactMap["OFFICEPHONE2"] = "BUSINESSPHONE2" ;                                          //办公电话2
        FieldsMap::customContactMap["OFFICEFAX"] = "BUSINESSFAX" ;                                                        //办公传真
        FieldsMap::customContactMap["IPPHONE"] = "BUSINESSIPPHONE" ;                                                  //IP电话
        FieldsMap::customContactMap["OFFICEMESNO"] = "BUSINESSMESNO" ;                                              //办公即时通讯
        FieldsMap::customContactMap["OFFICEMOBILE"] = "BUSINESSMOBILEPHONE" ;                                //移动电话
        FieldsMap::customContactMap["NICKNAME"] = "NICKNAME" ;                                                               //昵称
        FieldsMap::customContactMap["GENDER"] = "GENDER" ;                                                                       //性别
        FieldsMap::customContactMap["BIRTHDAY"] = "BIRTHDAY" ;                                                                  //生日
        FieldsMap::customContactMap["NATION"] = "NATION" ;                                                                        //民族
        FieldsMap::customContactMap["NATIVEPLACE"] = "NATIVEPLACE" ;                                                    //籍贯
        FieldsMap::customContactMap["HOMEZIP"] = "ZIP" ;                                                                           //邮政编码
        FieldsMap::customContactMap["HOMEADDRESS"] = "HOMECOUNTRY" ;                                                 //家庭地址
        FieldsMap::customContactMap["SELFMOBILE"] = "SELFMOBILEPHONE" ;                                             //个人移动电话
        FieldsMap::customContactMap["SELFPHONE"] = "SELFPHONE" ;                                                         //个人固定电话
        FieldsMap::customContactMap["SELFAX"] = "SELFAX" ;                                                                       //个人传真
        FieldsMap::customContactMap["EMAIL1"] = "SELFEMAIL1" ;                                                                //电子邮件1
        FieldsMap::customContactMap["EMAIL2"] = "SELFEMAIL2" ;                                                                //电子邮件2
        FieldsMap::customContactMap["EMAIL3"] = "SELFEMAIL3" ;                                                                //电子邮件3
        FieldsMap::customContactMap["MESNO1"] = "SELFMESNO1" ;                                                             //即时通讯帐号1
        FieldsMap::customContactMap["MESNO2"] = "SELFMESNO2" ;                                                             //即时通讯帐号2
        FieldsMap::customContactMap["MESNO3"] = "SELFMESNO3" ;                                                             //即时通讯帐号3
        FieldsMap::customContactMap["HOMEPAGE"] = "HOMEPAGE" ;                                                           //个人主页
        FieldsMap::customContactMap["URGENCYLINKMAN"] = "URGENCYLINKMAN" ;                                     //紧急联系人
        FieldsMap::customContactMap["URGENCYPHONE"] = "URGENCYPHONE" ;                                           //紧急联系电话
        FieldsMap::customContactMap["MARRIAGEFLAG"] = "MARRIAGEFLAG" ;                                               //婚姻状况
        FieldsMap::customContactMap["SPOUSE"] = "SPOUSE" ;                                                                      //配偶
        FieldsMap::customContactMap["CHILDREN"] = "CHILDREN" ;                                                                //子女
        FieldsMap::customContactMap["DESCRIPTION"] = "DESCRIPTION" ;                                                      // 描述介绍信息
    }
} //namespace pctor
