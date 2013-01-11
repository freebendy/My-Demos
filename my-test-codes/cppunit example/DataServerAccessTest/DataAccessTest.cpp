#pragma warning (disable : 4251)

#include "DataAccessTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DataAccessTest);

void DataAccessTest::setUp()
{
    m_DataAccess = new SQLDataAccess("mysql");
}

void DataAccessTest::tearDown()
{
    delete m_DataAccess;
}

void DataAccessTest::testMethod()
{
    CPPUNIT_ASSERT(0 == 0);
}

void DataAccessTest::testDropDatabase()
{
    std::string sql(
        "DROP DATABASE IF EXISTS pctor"
        );
    int affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(31 == affectRows);
}

void DataAccessTest::testCreateDatabase()
{
    std::string sql(
        "CREATE DATABASE IF NOT EXISTS pctor character set utf8"
        );
    int affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(1 == affectRows);
}

void DataAccessTest::testChangeDatabase()
{
    std::string sql(
        "USE pctor"
        );
    int affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);
}

void DataAccessTest::testCreateTable()
{
    std::string sql;
    int affectRows;

    sql.assign(
        "USE pctor"
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table IM_CHATHISTORY                                                                                                            "
        "(                                                                                                                                      "
        "   USERACCOUNT          varchar(128) not null comment '用户帐号',                                                                      "
        "   USERINFOIID          char(32) not null comment '用户基本信息IID',                                                                   "
        "   TALKERACCOUNT        varchar(128) not null comment '讲话者帐号',                                                                    "
        "   TALKERNAME           varchar(210) comment '讲话者名字',                                                                             "
        "   DATETIME             varchar(20) not null comment '日期时间',                                                                       "
        "   CONTENTS             varchar(510) comment '内容',                                                                                   "
        "   FILESENDERINFOID     char(32) comment '文件发送者基本信息ID',                                                                       "
        "   FILESENDER           varchar(128) comment '文件发送者',                                                                             "
        "   FILEURL              varchar(256) comment '文件全路径',                                                                             "
        "   TYPE                 tinyint comment '0代表即时消息内容,1代表即时消息发送失败提示信息,2代表文件发送成功信息,3代表文件发送失败信息', "
        "   primary key (USERACCOUNT, USERINFOIID, DATETIME)                                                                                    "
        ")                                                                                                                                      "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '个人聊天记录'                                                                            "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table IM_GROUPCHATATTENDEDBINDS                                  "
        "(                                                                       "
        "   SESSIONID            char(32) not null comment '讨论信息的ID',       "
        "   ATTENDEDACCOUNT      varchar(128) not null comment '参与者帐号',     "
        "   ATTENDEDUSERINFOIID  char(32) not null comment '参与者基本信息IID',  "
        "   primary key (SESSIONID, ATTENDEDACCOUNT)                             "
        ")                                                                       "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '多人讨论信息参与者邦定表' "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table IM_GROUPCHATHISTORYCONTENTS                                                   "
        "(                                                                                          "
        "   SESSIONID            char(32) not null comment '讨论信息的ID',                          "
        "   CONTENTS             varchar(510) comment '单条发言内容',                               "
        "   TIME                 datetime not null comment '发言时间',                              "
        "   TALKERNAME           varchar(210) comment '讲话者名字',                                 "
        "   TALKERID             char(32) comment '讲话者基本信息ID',                               "
        "   TALKERACCOUNT        varchar(128) not null comment '讲话者帐号',                        "
        "   TYPE                 tinyint comment '0代表多人讨论的信息内容,1代表其中信息提示的内容', "
        "   primary key (SESSIONID, TIME, TALKERACCOUNT)                                            "
        ")                                                                                          "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '多人讨论内容表'                              "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table IM_GROUPCHATINFO                                     "
        "(                                                                 "
        "   SESSIONID            char(32) not null comment '讨论信息的ID', "
        "   TOPIC                varchar(20) comment '多人讨论主题',       "
        "   CREATEDTIME          datetime not null comment '创建时间',     "
        "   USERACCOUNT          varchar(128) not null comment '用户帐号', "
        "   primary key (SESSIONID)                                        "
        ")                                                                 "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '多人讨论信息表'     "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table IM_INFORMATTENDERBINDS                                    "
        "(                                                                      "
        "   SESSIONID            char(32) not null comment '通知信息的ID',      "
        "   ATTENDEDACCOUNT      varchar(128) not null comment '参与者帐号',    "
        "   type                 tinyint comment '0代表发送成功,1代表发送失败', "
        "   primary key (SESSIONID, ATTENDEDACCOUNT)                            "
        ")                                                                      "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '通知信息参与者绑定'      "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table IM_INFORMHISTORY                                                          "
        "(                                                                                      "
        "   USERACCOUNT          varchar(128) not null comment '用户帐号',                      "
        "   SESSIONID            char(32) not null comment '通知信息的ID',                      "
        "   TIME                 datetime comment '发言时间',                                   "
        "   SENDER               varchar(128) not null comment '发送者是本人帐号/或者对方帐号', "
        "   SENDERID             char(32) comment '发送者基本信息ID',                           "
        "   CREATEDTIME          datetime not null comment '创建时间',                          "
        "   primary key (SESSIONID)                                                             "
        ")                                                                                      "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '通知'                                    "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table SVR_CORPINFO                                                                                                                                                                                                                             "
        "(                                                                                                                                                                                                                                                     "
        "   CORPIID              mediumint not null auto_increment comment '全局唯一',                                                                                                                                                                         "
        "   CREATETIME           timestamp comment '创建日期',                                                                                                                                                                                                 "
        "   MODIFYTIME           timestamp comment '更新日期',                                                                                                                                                                                                 "
        "   CORPID               varchar(32) not null comment '运营管理员录入的',                                                                                                                                                                              "
        "   CORPNAME             varchar(64) not null comment '企业名字',                                                                                                                                                                                      "
        "   MANAGEURL            varchar(256) not null comment '管理系统的访问网址',                                                                                                                                                                           "
        "   EMAIL                varchar(128) comment '客户邮件地址',                                                                                                                                                                                          "
        "   SELFURL              varchar(256) comment '自服务系统的访问网址',                                                                                                                                                                                  "
        "   MODIFIER             varchar(128) comment '修改者',                                                                                                                                                                                                "
        "   POSTCODE             varchar(16) comment '邮政编码',                                                                                                                                                                                               "
        "   LINKMANNAME          varchar(32) not null comment '联系人',                                                                                                                                                                                        "
        "   PHONE                varchar(32) comment '联系电话',                                                                                                                                                                                               "
        "   FAX                  varchar(32) comment '联系传真',                                                                                                                                                                                               "
        "   CORPADDRESS          varchar(256) comment '企业地址',                                                                                                                                                                                              "
        "   MAXUSER              smallint not null comment '最大用户注册数',                                                                                                                                                                                   "
        "   MAXTCUSTOMERRUSTFUL  smallint not null comment '此客户可信任的最大客户数量,IM服务器需要根据此值开辟缓存',                                                                                                                                          "
        "   CUSTOMERSTATUS       varchar(32) not null comment '客户状态,冗余数据(0为正常/1为锁定)',                                                                                                                                                            "
        "   DOMAINNAME           varchar(64) not null comment '客户域名,冗余数据',                                                                                                                                                                             "
        "   SERVICESTATUS        varchar(32) comment '服务状态,冗余数据(每一位表示开通了什么服务及其服务状态,第一位表示UAB,第2位表示IM,,第3位表示SMS,,第4位表示MAIL,取值:0为未开通/1为开通/2为暂停/3为删除错误,因为目前UAB,默认总是开通状态,所以此值只取1或3', "
        "   INNERSYNCHRONIZETIME date not null comment '最近一次内部信息同步时间',                                                                                                                                                                             "
        "   OUTERSYNCHRONIZETIME datetime not null comment '最近一次外部信息同步时间',                                                                                                                                                                         "
        "   primary key (CORPIID)                                                                                                                                                                                                                              "
        ")                                                                                                                                                                                                                                                     "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '映射服务器端企业信息表'                                                                                                                                                                                 "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table SVR_UAB_CORP_GROLINKBINDS                                                                   "
        "(                                                                                                        "
        "   CORPGROLINKBINDSIID  char(32) not null,                                                               "
        "   CREATETIME           datetime,                                                                        "
        "   CORPIID              mediumint not null,                                                              "
        "   CORPGROUPIID         char(32) not null comment '外部组IID',                                           "
        "   CORPMERLINKMANIID    char(32) not null comment '联系人IID',                                           "
        "   DATAOWNERIID         char(32) not null comment '冗余,当企业外部联系人的所有人发生变化此字段随着变化', "
        "   HASHVERSION          varchar(32),                                                                     "
        "   DELETED              tinyint not null default 0 comment '删除标志,0代表不需要删除,1代表需要删除',     "
        "	UPLOAD               tinyint not null comment '上传标志,0表示下载的数据,1表示该数据需要上传',		  "
		"   primary key (CORPGROLINKBINDSIID)                                                                     "
        ")                                                                                                        "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '映射服务器端外部组与外部联系人的关联'                      "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table SVR_UAB_CORP_GRORIGHT                                                                   "
        "(                                                                                                    "
        "   CORPGRORIGHTIID      char(32) not null,                                                           "
        "   CREATETIME           timestamp,                                                                   "
        "   CORPIID              mediumint not null comment '企业ID',                                         "
        "   CORPGROUPIID         char(32) not null comment '外部组IID',                                       "
        "   CORPUSERINFOIID      char(32) not null comment '用户基本信息IID',                                 "
        "   GRORIGHT             varchar(32) not null comment '0:读;1:写;缺省:0',                             "
        "   DELETED              tinyint not null default 0 comment '删除标志,0代表不需要删除,1代表需要删除', "
        "   primary key (CORPGRORIGHTIID)                                                                     "
        ")                                                                                                    "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '用户可以对哪些外部组进行读写操作'                      "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table SVR_UAB_CORP_GROUP                                                                                  "
        "(                                                                                                                "
        "   CORPGROUPIID         char(32) not null,                                                                       "
        "   CREATETIME           timestamp,                                                                               "
        "   PARENTCUSTOMERGROUPIID char(32) not null,                                                                     "
        "   CORPIID              mediumint not null comment '全局唯一,为了满足统一通讯录组现有的代码中的需要,而采用整型', "
        "   DESCRIPTION          varchar(256),                                                                            "
        "   GROUPNAME            varchar(32),                                                                             "
        "   HASHVERSION          varchar(32),                                                                             "
        "   DELETED              tinyint not null default 0 comment '删除标志, 0代表不需要删除, 1代表需要删除',           "
        "   primary key (CORPGROUPIID)                                                                                    "
        ")                                                                                                                "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '映射服务器端企业外部组表'                                          "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table SVR_UAB_CORP_MERLINKMAN                                                                                                       "
        "(                                                                                                                                          "
        "   CORPMERLINKMANIID    char(32) not null comment '联系人IID',                                                                             "
        "   CORPIID              mediumint not null comment '企业ID',                                                                               "
        "   CREATETIME           timestamp comment '创建日期',                                                                                      "
        "   DATAOWNERIID         char(32) not null comment '既可以是普通用户基本信息IID也可以是管理员IID,所以没有与用户建立外键',                   "
        "   DATASTATUS           varchar(32) not null comment '0为正常,1为锁定(禁止提交此资料的普通用户维护此联系人记录)',                          "
        "   LINKMANNAME          varchar(32) not null comment '联系人姓名',                                                                         "
        "   COMPANY              varchar(32) comment '公司名称',                                                                                    "
        "   COMPANYZIP           varchar(16) comment '公司邮政编码',                                                                                "
        "   COMPADDRESS          varchar(128) comment '公司地址',                                                                                   "
        "   ORGNAME              varchar(64) comment '部门名字',                                                                                    "
        "   OFFICE               varchar(30) comment '办公室',                                                                                      "
        "   DUTY                 varchar(30) comment '职务',                                                                                        "
        "   POSITION             varchar(30) comment '职称',                                                                                        "
        "   BUSINESSPHONE1       varchar(32) comment '办公电话1',                                                                                   "
        "   BUSINESSPHONE2       varchar(32) comment '办公电话2',                                                                                   "
        "   BUSINESSFAX          varchar(32) comment '办公传真',                                                                                    "
        "   BUSINESSIPPHONE      varchar(32) comment 'IP电话',                                                                                      "
        "   BUSINESSMESNO        varchar(128) comment '办公即时通讯帐号',                                                                           "
        "   BUSINESSMOBILEPHONE  varchar(32) comment '办公移动电话',                                                                                "
        "   BUSINESSEMAIL1       varchar(128) comment '办公邮件1',                                                                                  "
        "   BUSINESSEMAIL2       varchar(128) comment '办公邮件2',                                                                                  "
        "   BUSINESSEMAIL3       varchar(128) comment '办公邮件3',                                                                                  "
        "   DEPARTMENTPAGE       varchar(256) comment '部门主页',                                                                                   "
        "   COMPANYPAGE          varchar(256) comment '公司主页',                                                                                   "
        "   NICKNAME             varchar(20) comment '昵称',                                                                                        "
        "   GENDER               tinyint comment '性别. 0代表男, 1代表女',                                                                          "
        "   BIRTHDAY             date comment '生日',                                                                                               "
        "   NATION               varchar(20) comment '民族',                                                                                        "
        "   NATIVEPLACE          varchar(20) comment '籍贯',                                                                                        "
        "   POSTCODE             varchar(16) comment '邮政编码',                                                                                    "
        "   HOMECOUNTRY          varchar(64) comment '家庭住址',                                                                                    "
        "   SELFMOBILEPHONE      varchar(32) comment '个人移动电话',                                                                                "
        "   SELFPHONE            varchar(32) comment '个人固定电话',                                                                                "
        "   SELFFAX              varchar(32) comment '个人传真',                                                                                    "
        "   SELFEMAIL1           varchar(128) comment '电子邮件1',                                                                                  "
        "   SELFEMAIL2           varchar(128) comment '电子邮件2',                                                                                  "
        "   SELFEMAIL3           varchar(128) comment '电子邮件3',                                                                                  "
        "   SELFMESNO1           varchar(128) comment '即时通讯帐号1',                                                                              "
        "   SELFMESNO2           varchar(128) comment '即时通讯帐号2',                                                                              "
        "   SELFMESNO3           varchar(128) comment '即时通讯帐号3',                                                                              "
        "   HOMEPAGE             varchar(256) comment '个人主页',                                                                                   "
        "   URGENCYLINKMAN       varchar(20) comment '紧急联系人',                                                                                  "
        "   URGENCYPHONE         varchar(32) comment '紧急联系电话',                                                                                "
        "   MARRIAGEFLAG         tinyint comment '0为未婚,1为已婚',                                                                                 "
        "   SPOUSE               varchar(20) comment '配偶',                                                                                        "
        "   CHILDREN             varchar(32) comment '子女',                                                                                        "
        "   DESCRIPTION          varchar(256) comment '描述介绍信息',                                                                               "
        "   HASHVERSION          varchar(32) comment '版本',                                                                                        "
        "   RANK                 smallint comment '统一通讯录组需要用:用于定义联系人的等级,数字越小,等级越高',                                      "
        "   MODIFIED             tinyint not null default 0 comment '修改标志;0 代表初始值,1 代表数据新增, 2 代表数据被删除,3代表该数据已经被更新', "
        "   UPLOAD               tinyint not null comment '上传标志,  0代表不需要上传,1代表需要上传',                                               "
        "   primary key (CORPMERLINKMANIID)                                                                                                         "
        ")                                                                                                                                          "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '映射服务器端的企业外部联系人'                                                                "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table SVR_UAB_CORP_ORGANIZATION                                                                 "
        "(                                                                                                      "
        "   CORPORGANIZATIONIID  char(32) not null comment '组织IID',                                           "
        "   CREATETIME           timestamp comment '创建日期',                                                  "
        "   CORPIID              mediumint not null comment '企业IID',                                          "
        "   PARENTORGANIZATIONIID char(32) not null comment '父组织IID',                                        "
        "   ORGNAME              varchar(64) not null comment '部门名字',                                       "
        "   DIRECTOR             varchar(32) comment '部门负责人',                                              "
        "   RANK                 tinyint comment '统一通讯录组需要用:用于定义联系人的等级,数字越小,等级越高',   "
        "   DEPARTMENTHOMEPAGE   varchar(256) comment '部门主页',                                               "
        "   ADDRESS              varchar(256) comment '部门地址',                                               "
        "   DESCRIPTION          varchar(256) comment '部门描述',                                               "
        "   POSTCODE             varchar(16) comment '邮政编码',                                                "
        "   PHONE                varchar(32) comment '联系电话',                                                "
        "   FAX                  varchar(32) comment '联系传真',                                                "
        "   ORGFLAG              varchar(150) not null comment '部门标志',                                      "
        "   DELETED              tinyint not null default 0 comment '删除标志, 0代表不需要删除, 1代表需要删除', "
        "   primary key (CORPORGANIZATIONIID)                                                                   "
        ")                                                                                                      "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '映射服务器端企业内部组的信息'                            "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table SVR_UAB_CORP_ORGUSERBINDS                                                               "
        "(                                                                                                    "
        "   CORPORGUSERBINDSIID  char(32) not null comment '成员IID',                                         "
        "   CREATETIME           timestamp comment '创建日期',                                                "
        "   CORPORGANIZATIONIID  char(32) not null comment '组织IID',                                         "
        "   CORPUSERINFOIID      char(32) not null comment '用户基本信息IID',                                 "
        "   CORPIID              mediumint not null comment '企业IID',                                        "
        "   DELETED              tinyint not null default 0 comment '删除标志,0代表不需要删除,1代表需要删除', "
        "   primary key (CORPORGUSERBINDSIID, CORPORGANIZATIONIID, CORPIID)                                   "
        ")                                                                                                    "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '映射服务器端企业内部组织成员表'                        "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table SVR_UAB_CORP_USERINFO                                                                   "
        "(                                                                                                    "
        "   CORPUSERINFOIID      char(32) not null comment '用户基本信息IID',                                 "
        "   CREATETIME           timestamp comment '创建日期',                                                "
        "   CORPIID              mediumint not null comment '企业IID',                                        "
        "   LOGINUSERID          varchar(128) comment '冗余,形式为用户ID@客户域名',                           "
        "   SIGNATURE            varchar(50) comment '用户签名信息',                                          "
        "   USERNAME             varchar(32) not null comment '姓名',                                         "
        "   PHOTOURL             varchar(128) comment '存完全url如:http://www.image.com/aaaa/ddddddd.gif',    "
        "   PHOTOHASHCODE        varchar(32) comment '32位16进制数',                                          "
        "   BINDEMAIL            varchar(128) comment '绑定个人网站用户邮件帐号',                             "
        "   OFFICE               varchar(30) comment '办公室',                                                "
        "   DUTY                 varchar(30) comment '职务',                                                  "
        "   POSITION             varchar(30) comment '职称',                                                  "
        "   BUSINESSIPPHONE      varchar(32) comment 'IP电话',                                                "
        "   BUSINESSPHONE1       varchar(32) comment '办公电话1',                                             "
        "   BUSINESSPHONE2       varchar(32) comment '办公电话2',                                             "
        "   BUSINESSFAX          varchar(32) comment '办公传真',                                              "
        "   BUSINESSMOBILEPHONE  varchar(32) comment '办公移动电话',                                          "
        "   BUSINESSMESNO1       varchar(128) comment '办公即时通讯帐号1',                                    "
        "   BUSINESSMESNO2       varchar(128) comment '办公即时通讯帐号2',                                    "
        "   BUSINESSMESNO3       varchar(128) comment '办公即时通讯帐号3',                                    "
        "   BUSINESSEMAIL1       varchar(128) comment '办公邮件1',                                            "
        "   BUSINESSEMAIL2       varchar(128) comment '办公邮件2',                                            "
        "   BUSINESSEMAIL3       varchar(128) comment '办公邮件3',                                            "
        "   SELFPHONE            varchar(32) comment '个人固定电话',                                          "
        "   NICKNAME             varchar(20) comment '昵称',                                                  "
        "   GENDER               tinyint comment '0为男,1为女',                                               "
        "   BIRTHDAY             date comment '生日',                                                         "
        "   NATION               varchar(20) comment '民族',                                                  "
        "   NATIVEPLACE          varchar(20) comment '籍贯',                                                  "
        "   HOMEPOSTALCODE       varchar(16) comment '邮政编码',                                              "
        "   HOMECOUNTRY          varchar(64) comment '家庭住址',                                              "
        "   SELFFAX              varchar(32) comment '个人传真',                                              "
        "   SELFMOBILEPHONE      varchar(32) comment '个人移动电话',                                          "
        "   SELFEMAIL1           varchar(128) comment '个人电子邮件1',                                        "
        "   SELFEMAIL2           varchar(128) comment '个人电子邮件2',                                        "
        "   SELFEMAIL3           varchar(128) comment '个人电子邮件3',                                        "
        "   SELFMESNO1           varchar(128) comment '个人即时通讯帐号1',                                    "
        "   SELFMESNO2           varchar(128) comment '个人能即时通讯帐号2',                                  "
        "   SELFMESNO3           varchar(128) comment '个人能即时通讯帐号3',                                  "
        "   HOMEPAGE             varchar(256) comment '个人主页',                                             "
        "   URGENCYLINKMAN       varchar(20) comment '紧急联系人',                                            "
        "   URGENCYPHONE         varchar(32) comment '紧急联系电话',                                          "
        "   MARRIAGEFLAG         tinyint comment '0为未婚,1为已婚',                                           "
        "   SPOUSE               varchar(20) comment '配偶',                                                  "
        "   CHILDREN             varchar(32) comment '子女',                                                  "
        "   DESCRIPTION          varchar(256) comment '描述介绍信息',                                         "
        "   HASHVERSION          varchar(32) comment '版本',                                                  "
        "   RANK                 tinyint comment '统一通讯录组需要用:用于定义联系人的等级,数字越小,等级越高', "
        "   DELETED              tinyint not null default 0 comment '删除标志,0代表不需要删除,1代表需要删除', "
        "   UPLOAD               tinyint not null default 0 comment '上传标志,0代表不需要上传,1代表需要上传', "
        "   primary key (CORPUSERINFOIID)                                                                     "
        ")                                                                                                    "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '映射服务器端企业内部用户的基本信息'                    "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table SVR_UAB_FREQUENCYCONTACT                                                                "
        "(                                                                                                    "
        "   CORPIID              mediumint not null comment '企业IID',                                        "
        "   CORPUSERINFOIID      varchar(32) not null comment '用户基本信息IID',                              "
        "   LINKMANINFOIID       varchar(32) not null comment '联系人基本信息IID',                            "
        "   LINKMANNAME          varchar(32) not null comment '联系人姓名',                                   "
        "   DELETED              tinyint not null default 0 comment '删除标志,0代表不需要删除,1代表需要删除', "
        "	UPLOAD               tinyint not null comment '上传标志,0表示下载的数据,1表示该数据需要上传',	  "
		"   primary key (CORPIID,CORPUSERINFOIID,LINKMANINFOIID)                                              "
        ")                                                                                                    "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '映射服务器端用户的常用联系人表'                        "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table SVR_UAB_USERCORPS                                                "
        "(                                                                             "
        "   USERACCOUNT          varchar(128) not null comment '用户帐号',             "
        "   CORPIID              mediumint not null comment '企业IID',                 "
        "   LOCKSTATUS           tinyint default 0 comment '锁定状态:0未锁定,1为锁定', "
        "   primary key (USERACCOUNT,CORPIID)                                          "
        ")                                                                             "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '用户可以访问 的企业'            "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_ACCOUNT                                                                                                                                                                                                                                                                        "
        "(                                                                                                                                                                                                                                                                                               "
        "   USERACCOUNT          varchar(128) not null comment '用户帐号',                                                                                                                                                                                                                               "
        "   USERINFOIID          char(32) not null comment '用户基本信息IID',                                                                                                                                                                                                                            "
        "   PASSWORD             varchar(32) comment '用户密码',                                                                                                                                                                                                                                         "
        "   TYPE                 tinyint comment '0代表企业用户; 1代表个人用户',                                                                                                                                                                                                                         "
        "   SERVICESTATUS        varchar(64) not null comment '冗余数据(每一位表示开通了什么服务及其服务状态,第一位表示UAB,第2位表示IM,,第3位表示SMS,,第4位表示MAIL,取值:0为未开通/1为开通/2为暂停/3为删除错误 ,因为目前UAB,默认总是开通状态,所以此值只取1或3',                                          "
        "   SERVICERIGHT         varchar(256) comment '该权限对应相应的服务状态.每一位对应一个权限,目前是UAB,没有权限控制.此值无意义.如果开通IM,则(每一位表示开通了什么权限及其权限状态,第一位表示发送文件权限,第2位表示群发文件权限,,第3位表示多人讨论,,第4位表示发送通知权限,,取值:0为未开通/1为开通', "
        "   SYNCHRONIZEUSERINFO  tinyint not null default 0 comment '同步用户基本信息标志,0 代表不需要同步,1代表需要同步',                                                                                                                                                                               "
        "   primary key (USERACCOUNT)                                                                                                                                                                                                                                                                    "
        ")                                                                                                                                                                                                                                                                                               "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '客户端的用户帐户表,type:用户帐号/个人帐号'                                                                                                                                                                                                        "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_CONFIGURATION                                        "
        "(                                                                     "
        "   OWNER                varchar(128) not null comment '拥有者',       "
        "   SECTION              varchar(32) not null comment '分段',          "
        "   CONFIGKEY            varchar(32) not null comment '键',            "
        "   STRINGVALUE          varchar(260) comment '字符串型值',            "
        "   DOUBLEVALUE          double comment '双精度型值',                  "
        "   LONGVALUE            mediumint comment '长整型值',                 "
        "   primary key (OWNER, SECTION, CONFIGKEY)                            "
        ")                                                                     "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '客户端的用户配置信息表' "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_CORPINFO                                                                                                                                                                                                                    "
        "(                                                                                                                                                                                                                                            "
        "   CORPIID              mediumint not null auto_increment comment '企业IID,全局唯一',                                                                                                                                                        "
        "   CREATETIME           timestamp comment '创建日期',                                                                                                                                                                                        "
        "   MODIFYTIME           timestamp comment '更新日期',                                                                                                                                                                                        "
        "   CORPID               varchar(32) not null comment '运营管理员录入的',                                                                                                                                                                     "
        "   CORPNAME             varchar(64) not null comment '客户名称',                                                                                                                                                                             "
        "   MANAGEURL            varchar(256) not null comment '管理系统的访问网址',                                                                                                                                                                  "
        "   EMAIL                varchar(128) comment '客户邮件地址',                                                                                                                                                                                 "
        "   SELFURL              varchar(256) comment '自服务系统的访问网址',                                                                                                                                                                         "
        "   MODIFIER             varchar(128) comment '修改者',                                                                                                                                                                                       "
        "   POSTCODE             varchar(16) comment '邮政编码',                                                                                                                                                                                      "
        "   LINKMANNAME          varchar(32) not null comment '联系人',                                                                                                                                                                               "
        "   PHONE                varchar(32) comment '联系电话',                                                                                                                                                                                      "
        "   FAX                  varchar(32) comment '联系传真',                                                                                                                                                                                      "
        "   CORPADDRESS          varchar(256) comment '企业地址',                                                                                                                                                                                     "
        "   MAXUSER              smallint not null comment '最大用户注册数',                                                                                                                                                                          "
        "   MAXTCUSTOMERRUSTFUL  smallint not null comment '此客户可信任的最大客户数量,IM服务器需要根据此值开辟缓存',                                                                                                                                 "
        "   CUSTOMERSTATUS       varchar(32) not null comment '冗余数据(0为正常/1为锁定)',                                                                                                                                                            "
        "   DOMAINNAME           varchar(64) not null comment '冗余数据',                                                                                                                                                                             "
        "   SERVICESTATUS        varchar(32) comment '冗余数据(每一位表示开通了什么服务及其服务状态,第一位表示UAB,第2位表示IM,,第3位表示SMS,,第4位表示MAIL,取值:0为未开通/1为开通/2为暂停/3为删除错误,因为目前UAB,默认总是开通状态,所以此值只取1或3', "
        "   INNERSYNCHRONIZETIME date not null comment '最近一次内部信息同步时间',                                                                                                                                                                             "
        "   OUTERSYNCHRONIZETIME datetime not null comment '最近一次外部信息同步时间',                                                                                                                                                                         "
        "   primary key (CORPIID)                                                                                                                                                                                                                     "
        ")                                                                                                                                                                                                                                            "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '客户端企业信息表'                                                                                                                                                                              "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_CORP_GROLINKBINDS                                                                       "
        "(                                                                                                        "
        "   CORPGROLINKBINDSIID  char(32) not null comment '企业外部组成员IID',                                   "
        "   CREATETIME           datetime,                                                                        "
        "   CORPIID              mediumint not null,                                                              "
        "   CORPGROUPIID         char(32) not null comment '外部组IID',                                           "
        "   CORPMERLINKMANIID    char(32) not null comment '联系人IID',                                           "
        "   DATAOWNERIID         char(32) not null comment '冗余,当企业外部联系人的所有人发生变化此字段随着变化', "
        "   HASHVERSION          varchar(32) comment '版本',                                                      "
        "   DELETED              tinyint not null default 0 comment '删除标志,0代表不需要删除,1代表需要删除',     "
        "   SYNCHRONIZE          tinyint not null default 0 comment '同步标志,0 代表不需要同步,1代表需要同步',    "
        "   primary key (CORPGROLINKBINDSIID)                                                                     "
        ")                                                                                                        "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '外部组与外部联系人的关联'                                  "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_CORP_GRORIGHT                                                  "
        "(                                                                               "
        "   CORPGRORIGHTIID      char(32) not null comment '企业外部组权限IID',          "
        "   CREATETIME           timestamp,                                              "
        "   CORPIID              mediumint not null comment '企业ID',                    "
        "   CORPGROUPIID         char(32) not null comment '外部组IID',                  "
        "   CORPUSERINFOIID      char(32) not null comment '用户基本信息IID',            "
        "   GRORIGHT             varchar(32) not null comment '0:读;1:写;缺省:0',        "
        "   primary key (CORPGRORIGHTIID)                                                "
        ")                                                                               "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '用户可以对哪些外部组进行读写操作' "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_CORP_GROUP                                                                                      "
        "(                                                                                                                "
        "   CORPGROUPIID         char(32) not null comment '外部组IID',                                                   "
        "   CREATETIME           timestamp,                                                                               "
        "   PARENTCORPGROUPIID   char(32) comment '父外部组IID',                                                          "
        "   CORPIID              mediumint not null comment '全局唯一,为了满足统一通讯录组现有的代码中的需要,而采用整型', "
        "   DESCRIPTION          varchar(256) comment '描述介绍信息',                                                     "
        "   GROUPNAME            varchar(32) comment '企业外部组名',                                                      "
        "   HASHVERSION          varchar(32) comment '版本',                                                              "
        "   DELETED              tinyint not null default 0 comment '删除标志,0代表不需要删除,1代表需要删除',             "
        "   primary key (CORPGROUPIID)                                                                                    "
        ")                                                                                                                "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '客户端企业外部组表'                                                "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_CORP_MERLINKMAN                                                                                                       "
        "(                                                                                                                                      "
        "   CORPMERLINKMANIID    char(32) not null comment '联系人IID',                                                                         "
        "   CORPIID              mediumint not null comment '企业ID',                                                                           "
        "   CREATETIME           timestamp,                                                                                                     "
        "   DATAOWNERIID         char(32) not null comment '既可以是普通用户基本信息IID也可以是管理员IID,所以没有与用户建立外键',               "
        "   DATASTATUS           varchar(32) not null comment '0为正常,1为锁定(禁止提交此资料的普通用户维护此联系人记录)',                      "
        "   LINKMANNAME          varchar(32) not null comment '联系人姓名',                                                                     "
        "   COMPANY              varchar(32) comment '公司名称',                                                                                "
        "   COMPANYZIP           varchar(16) comment '公司邮政编码',                                                                            "
        "   COMPADDRESS          varchar(128) comment '公司地址',                                                                               "
        "   ORGNAME              varchar(64) comment '部门名字',                                                                                "
        "   OFFICE               varchar(30) comment '办公室',                                                                                  "
        "   DUTY                 varchar(30) comment '职务',                                                                                    "
        "   POSITION             varchar(30) comment '职称',                                                                                    "
        "   BUSINESSPHONE1       varchar(32) comment '办公电话1',                                                                               "
        "   BUSINESSPHONE2       varchar(32) comment '办公电话2',                                                                               "
        "   BUSINESSFAX          varchar(32) comment '办公传真',                                                                                "
        "   BUSINESSIPPHONE      varchar(32) comment 'IP电话',                                                                                  "
        "   BUSINESSMESNO        varchar(128) comment '办公即时通讯帐号',                                                                       "
        "   BUSINESSMOBILEPHONE  varchar(32) comment '办公移动电话',                                                                            "
        "   BUSINESSEMAIL1       varchar(128) comment '办公邮件',                                                                               "
        "   BUSINESSEMAIL2       varchar(128) comment '办公邮件',                                                                               "
        "   BUSINESSEMAIL3       varchar(128) comment '办公邮件',                                                                               "
        "   DEPARTMENTPAGE       varchar(256),                                                                                                  "
        "   COMPANYPAGE          varchar(256),                                                                                                  "
        "   NICKNAME             varchar(20) comment '昵称',                                                                                    "
        "   GENDER               tinyint comment '性别. 0代表男,1代表女',                                                                       "
        "   BIRTHDAY             date comment '生日',                                                                                           "
        "   NATION               varchar(20) comment '民族',                                                                                    "
        "   NATIVEPLACE          varchar(20) comment '籍贯',                                                                                    "
        "   POSTCODE             varchar(16) comment '邮政编码',                                                                                "
        "   HOMECOUNTRY          varchar(64) comment '家庭住址',                                                                                "
        "   SELFMOBILEPHONE      varchar(32) comment '个人移动电话',                                                                            "
        "   SELFPHONE            varchar(32) comment '个人固定电话',                                                                            "
        "   SELFFAX              varchar(32) comment '个人传真',                                                                                "
        "   SELFEMAIL1           varchar(128) comment '电子邮件1',                                                                              "
        "   SELFEMAIL2           varchar(128) comment '电子邮件2',                                                                              "
        "   SELFEMAIL3           varchar(128) comment '电子邮件3',                                                                              "
        "   SELFMESNO1           varchar(128) comment '即时通讯帐号1',                                                                          "
        "   SELFMESNO2           varchar(128) comment '即时通讯帐号2',                                                                          "
        "   SELFMESNO3           varchar(128) comment '即时通讯帐号3',                                                                          "
        "   HOMEPAGE             varchar(256) comment '个人主页',                                                                               "
        "   URGENCYLINKMAN       varchar(20) comment '紧急联系人',                                                                              "
        "   URGENCYPHONE         varchar(32) comment '紧急联系电话',                                                                            "
        "   MARRIAGEFLAG         tinyint comment '0为未婚,1为已婚',                                                                             "
        "   SPOUSE               varchar(20) comment '配偶',                                                                                    "
        "   CHILDREN             varchar(32) comment '子女',                                                                                    "
        "   DESCRIPTION          varchar(256) comment '描述介绍信息',                                                                           "
        "   HASHVERSION          varchar(32) comment '版本',                                                                                    "
        "   RANK                 smallint comment '统一通讯录组需要用:用于定义联系人的等级,数字越小,等级越高',                                  "
        "   MODIFIED             tinyint not null default 0 comment '修改标志,0代表初始值,1代表数据新增,2代表数据被删除,3代表该数据已经被更新', "
        "   SYNCHRONIZE          tinyint not null default 0 comment '同步标志,0代表不需要同步,1代表需要同步',                                   "
        "   primary key (CORPMERLINKMANIID)                                                                                                     "
        ")                                                                                                                                      "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '客户端企业外部联系人表'                                                                  "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_CORP_ORGANIZATION                                                                   "
        "(                                                                                                    "
        "   CORPORGANIZATIONIID  char(32) not null comment '组织IID',                                         "
        "   CREATETIME           timestamp,                                                                   "
        "   CORPIID              mediumint not null comment '企业IID',                                        "
        "   PARENTORGANIZATIONIID char(32) comment '父组织IID',                                               "
        "   ORGNAME              varchar(64) not null comment '部门名字',                                     "
        "   DIRECTOR             varchar(32) comment '部门负责人',                                            "
        "   RANK                 tinyint comment '统一通讯录组需要用:用于定义联系人的等级,数字越小,等级越高', "
        "   DEPARTMENTHOMEPAGE   varchar(256) comment '部门主页',                                             "
        "   ADDRESS              varchar(256) comment '部门地址',                                             "
        "   DESCRIPTION          varchar(256) comment '部门描述',                                             "
        "   POSTCODE             varchar(16) comment '邮政编码',                                              "
        "   PHONE                varchar(32) comment '联系电话',                                              "
        "   FAX                  varchar(32) comment '联系传真',                                              "
        "   ORGFLAG              varchar(150) not null comment '冗余字段,由父组织的IID和2位从00到99组成的串', "
        "   DELETED              tinyint not null default 0 comment '删除标志,0代表不需要删除,1代表需要删除', "
        "   primary key (CORPORGANIZATIONIID)                                                                 "
        ")                                                                                                    "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '企业内部组信息'                                        "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_CORP_ORGUSERBINDS                                                                               "
        "(                                                                                                                "
        "   CORPORGUSERBINDSIID  char(32) not null comment '成员IID',                                                     "
        "   CREATETIME           timestamp,                                                                               "
        "   CORPORGANIZATIONIID  char(32) not null comment '组织IID',                                                     "
        "   CORPUSERINFOIID      char(32) not null comment '用户基本信息IID',                                             "
        "   CORPIID              mediumint not null comment '全局唯一,为了满足统一通讯录组现有的代码中的需要,而采用整型', "
        "   DELETED              tinyint not null default 0 comment '删除标志,0代表不需要删除,1代表需要删除',             "
        "   primary key (CORPORGUSERBINDSIID,CORPORGANIZATIONIID,CORPIID)                                                 "
        ")                                                                                                                "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '企业内部组织成员表'                                                "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_CORP_USERINFO                                                                        "
        "(                                                                                                     "
        "   CORPUSERINFOIID      char(32) not null comment '用户基本信息IID',                                  "
        "   CREATETIME           timestamp,                                                                    "
        "   CORPIID              mediumint not null,                                                           "
        "   LOGINUSERID          varchar(128) comment '冗余,形式为用户ID@客户域名',                            "
        "   SIGNATURE            varchar(50) comment '用户签名信息',                                           "
        "   USERNAME             varchar(32) not null comment '姓名',                                          "
        "   PHOTOURL             varchar(128) comment '存完全url如:http://www.image.com/aaaa/ddddddd.gif',     "
        "   PHOTOHASHCODE        varchar(32) comment '32位16进制数',                                           "
        "   BINDEMAIL            varchar(128) comment '绑定个人网站用户邮件帐号',                              "
        "   OFFICE               varchar(30) comment '办公室',                                                 "
        "   DUTY                 varchar(30) comment '职务',                                                   "
        "   POSITION             varchar(30) comment '职称',                                                   "
        "   BUSINESSIPPHONE      varchar(32) comment 'IP电话',                                                 "
        "   BUSINESSPHONE1       varchar(32) comment '办公电话1',                                              "
        "   BUSINESSPHONE2       varchar(32) comment '办公电话2',                                              "
        "   BUSINESSFAX          varchar(32) comment '办公传真',                                               "
        "   BUSINESSMOBILEPHONE  varchar(32) comment '办公移动电话',                                           "
        "   BUSINESSMESNO1       varchar(128),                                                                 "
        "   BUSINESSMESNO2       varchar(128),                                                                 "
        "   BUSINESSMESNO3       varchar(128),                                                                 "
        "   BUSINESSEMAIL1       varchar(128) comment '办公邮件',                                              "
        "   BUSINESSEMAIL2       varchar(128) comment '办公邮件',                                              "
        "   BUSINESSEMAIL3       varchar(128) comment '办公邮件',                                              "
        "   SELFPHONE            varchar(32) comment '个人固定电话',                                           "
        "   NICKNAME             varchar(20) comment '昵称',                                                   "
        "   GENDER               tinyint comment '0为男,1为女',                                                "
        "   BIRTHDAY             date comment '生日',                                                          "
        "   NATION               varchar(20) comment '民族',                                                   "
        "   NATIVEPLACE          varchar(20) comment '籍贯',                                                   "
        "   HOMEPOSTALCODE       varchar(16) comment '邮政编码',                                               "
        "   HOMECOUNTRY          varchar(64) comment '家庭住址',                                               "
        "   SELFFAX              varchar(32) comment '个人传真',                                               "
        "   SELFMOBILEPHONE      varchar(32) comment '个人移动电话',                                           "
        "   SELFEMAIL1           varchar(128) comment '电子邮件1',                                             "
        "   SELFEMAIL2           varchar(128) comment '电子邮件2',                                             "
        "   SELFEMAIL3           varchar(128) comment '电子邮件3',                                             "
        "   SELFMESNO1           varchar(128) comment '即时通讯帐号1',                                         "
        "   SELFMESNO2           varchar(128) comment '即时通讯帐号2',                                         "
        "   SELFMESNO3           varchar(128) comment '即时通讯帐号3',                                         "
        "   HOMEPAGE             varchar(256) comment '个人主页',                                              "
        "   URGENCYLINKMAN       varchar(20) comment '紧急联系人',                                             "
        "   URGENCYPHONE         varchar(32) comment '紧急联系电话',                                           "
        "   MARRIAGEFLAG         tinyint comment '0为未婚,1为已婚',                                            "
        "   SPOUSE               varchar(20) comment '配偶',                                                   "
        "   CHILDREN             varchar(32) comment '子女',                                                   "
        "   DESCRIPTION          varchar(256) comment '描述介绍信息',                                          "
        "   HASHVERSION          varchar(32) comment '版本',                                                   "
        "   RANK                 smallint comment '统一通讯录组需要用:用于定义联系人的等级,数字越小,等级越高', "
        "   DELETED              tinyint not null default 0 comment '删除标志,0代表不需要删除,1代表需要删除',  "
        "   primary key (CORPUSERINFOIID)                                                                      "
        ")                                                                                                     "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '企业内部用户的基本信息'                                 "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(                                                                                                          
        "create table UAB_FREQUENCYCONTACT                                                               "
        "(                                                                                               "
        "   USERACCOUNT          varchar(128) not null comment '用户帐号',                               "
        "   CORPIID              mediumint comment '用户企业IID',                                        "
        "   BINDINGACCOUNT       varchar(128) not null comment '绑定帐号',                               "
        "   BINDINGUSERIID       char(32) not null comment '绑定帐号基本信息IID',                        "
        "   TYPE                 tinyint not null comment '0企业内部联系人;1企业外部联系人;2临时联系人', "
        "   LINKMANACCOUNT       varchar(128) comment '联系人帐号',                                      "
        "   LINKMANIID           char(32) not null comment '联系人ID',                                   "
        "   DELETED              tinyint comment '删除标志',                                             "
        "   SYNCHRONIZE          tinyint default 0 comment '同步标志,0代表不需要同步,1代表需要同步',     "
        "   primary key (USERACCOUNT,BINDINGUSERIID,LINKMANIID)                                          "
        ")                                                                                               "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '常用联系人表'                                     "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_RECENTCONTACT                                                           "
        "(                                                                                        "
        "   USERACCOUNT          varchar(128) not null comment '用户帐号',                        "
        "   BINDINGACCOUNT       varchar(128) not null comment '绑定帐号',                        "
        "   BINDINGUSERIID       char(32) not null comment '绑定帐号基本信息IID',                 "
        "   LINKMANIID            char(32) not null comment '联系人ID',                           "
        "   LINKMANACCOUNT       varchar(128) comment '联系人帐号',                               "
        "   TYPE                 tinyint comment '0 企业内部联系人; 1企业外部联系人;2临时联系人', "
        "   ACCESSTIME           datetime not null comment '最近访问时间',                        "
        "   primary key (USERACCOUNT,BINDINGUSERIID,LINKMANIID)                                   "
        ")                                                                                        "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '最近联系人表'                              "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_USER                                                                    "
        "(                                                                                        "
        "   USERACCOUNT          varchar(128) not null comment '用户帐号',                        "
        "   AUTOLOGIN            tinyint comment '自动登录',                                      "
        "   AUTOSAVEPASSWORD     tinyint comment '自动存储密码',                                  "
        "   DEFAULTSTATUS        tinyint comment '默认状态登陆',                                  "
        "   TYPE                 tinyint comment '0代表系统帐号,1代表用户帐号',                   "
        "   RECENTSYNCHRONIZETIME datetime comment '最近一次同步时间',                            "
        "   LASTLOGINTIME        datetime not null comment '最后一次的成功登陆时间',              "
        "   primary key (USERACCOUNT)                                                             "
        ")                                                                                        "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '客户端的用户帐户表,type:用户帐号/个人帐号' "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_USERACCOUNTBINDING                                      "
        "(                                                                        "
        "   USERACCOUNT          varchar(128) not null comment '用户帐号',        "
        "   USERINFOIID          char(32) not null comment '用户基本信息IID',     "
        "   BINDINGACCOUNT       varchar(128) not null comment '用户绑定帐号',    "
        "   BINDINGUSERINFOIID   char(32) not null comment '绑定用户基本信息IID', "
        "   primary key (USERINFOIID,BINDINGUSERINFOIID)                          "
        ")                                                                        "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '客户端的帐户绑定表'        "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "create table UAB_USERCORPS                                                    "
        "(                                                                             "
        "   USERACCOUNT          varchar(128) not null comment '用户帐号',             "
        "   USERINFOIID          char(32) not null comment '用户基本信息IID',          "
        "   CORPIID              mediumint not null comment '企业IID',                 "
        "   LOCKSTATUS           tinyint default 0 comment '锁定状态:0未锁定,1为锁定', "
        "   primary key (USERINFOIID,CORPIID)                                          "
        ")                                                                             "
        "ENGINE=InnoDB DEFAULT CHARSET=utf8 comment = '用户加入的企业'                 "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);
}

void DataAccessTest::testCreateIndex()
{
    std::string sql;
    int affectRows;

    sql.assign(
        "USE pctor"
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table IM_CHATHISTORY add constraint FK_ACCOUNT_CHATHISTORY foreign key (USERACCOUNT) "
        "      references UAB_ACCOUNT (USERACCOUNT) on delete restrict on update restrict           "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table IM_GROUPCHATATTENDEDBINDS add constraint FK_REF_GROUPCHATINFO_CHATATTENDEDBIND foreign key (SESSIONID) "
        "      references IM_GROUPCHATINFO (SESSIONID) on delete restrict on update restrict                                "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table IM_GROUPCHATHISTORYCONTENTS add constraint FK_REF_GROUPCHATINFO_GROUPCHATCONTENTS foreign key (SESSIONID) "
        "      references IM_GROUPCHATINFO (SESSIONID) on delete restrict on update restrict                                   "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table IM_GROUPCHATINFO add constraint FK_REF_ACCOUNT_GROUPCHAT foreign key (USERACCOUNT) "
        "      references UAB_ACCOUNT (USERACCOUNT) on delete restrict on update restrict               "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table IM_INFORMATTENDERBINDS add constraint FK_REF_INFORM_INFORMATTENDEDBIND foreign key (SESSIONID) "
        "      references IM_INFORMHISTORY (SESSIONID) on delete restrict on update restrict                        "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table IM_INFORMHISTORY add constraint FK_REF_ACCOUNT_INFORM foreign key (USERACCOUNT) "
        "      references UAB_ACCOUNT (USERACCOUNT) on delete restrict on update restrict            "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CONFIGURATION add constraint FK_REF_USER_CONFIGURE foreign key (OWNER) "
        "      references UAB_USER (USERACCOUNT) on delete restrict on update restrict          "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_GROLINKBINDS add constraint FK_REF_CORPINFO_GROUPBIND foreign key (CORPIID) "
        "      references UAB_CORPINFO (CORPIID) on delete restrict on update restrict                    "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_GROLINKBINDS add constraint FK_UAB_CUSGROLINKBINDS_UAB_CUSTOMERGROUP foreign key (CORPMERLINKMANIID) "
        "      references UAB_CORP_MERLINKMAN (CORPMERLINKMANIID) on delete restrict on update restrict                            "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_GROLINKBINDS add constraint FK_UAB_CUSTOMERGROUP_UAB_CUSGROLINKBINDS foreign key (CORPGROUPIID) "
        "      references UAB_CORP_GROUP (CORPGROUPIID) on delete restrict on update restrict                                 "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_GRORIGHT add constraint FK_REF_CORPINFO_GROUPPERSSION foreign key (CORPIID) "
        "      references UAB_CORPINFO (CORPIID) on delete restrict on update restrict                    "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_GRORIGHT add constraint FK_UAB_CUSGRORIGHT_UAB_GROUP foreign key (CORPGROUPIID) "
        "      references UAB_CORP_GROUP (CORPGROUPIID) on delete restrict on update restrict                 "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_GROUP add constraint FK_REF_CORPINFO_GROUP foreign key (CORPIID) "
        "      references UAB_CORPINFO (CORPIID) on delete restrict on update restrict         "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_MERLINKMAN add constraint FK_REF_CORPINFO_LINKMANINFO foreign key (CORPIID) "
        "      references UAB_CORPINFO (CORPIID) on delete restrict on update restrict                    "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_ORGANIZATION add constraint FK_REF_CORPINFO_ORG foreign key (CORPID) "
        "      references UAB_CORPINFO (CORPIID) on delete restrict on update restrict             "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_ORGUSERBINDS add constraint FK_REF_CORPINFO_ORGNIZATIONBIND foreign key (CORPIID) "
        "      references UAB_CORPINFO (CORPIID) on delete restrict on update restrict                          "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_ORGUSERBINDS add constraint FK_UAB_CORP_ORGUSERBINDS_UAB_CORP_USERINFO foreign key (CORPUSERINFOIID) "
        "      references UAB_CORP_USERINFO (CORPUSERINFOIID) on delete restrict on update restrict                                "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_ORGUSERBINDS add constraint FK_UAB_ORGANIZATION_UAB_ORGUSERBINDS foreign key (CORPORGANIZATIONIID) "
        "      references UAB_CORP_ORGANIZATION (CORPORGANIZATIONIID) on delete restrict on update restrict                      "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_CORP_USERINFO add constraint FK_REF_CORPINFO_USERINFO foreign key (CORPIID) "
        "      references UAB_CORPINFO (CORPIID) on delete restrict on update restrict               "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_FREQUENCYCONTACT add constraint FK_REF_ACCOUNT_FREQUENCYCONTACT foreign key (USERACCOUNT) "
        "      references UAB_ACCOUNT (USERACCOUNT) on delete restrict on update restrict                          "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_RECENTCONTACT add constraint FK_REF_ACCOUNT_RECENTLINKMAN foreign key (USERACCOUNT) "
        "      references UAB_ACCOUNT (USERACCOUNT) on delete restrict on update restrict                    "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_USER add constraint FK_REF_ACCOUNT_USERS foreign key (USERACCOUNT) "
        "      references UAB_ACCOUNT (USERACCOUNT) on delete restrict on update restrict   "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_USERACCOUNTBINDING add constraint FK_REF_ACCOUNT_ACCOUNTBIND foreign key (BINDINGACCOUNT) "
        "      references UAB_ACCOUNT (USERACCOUNT) on delete restrict on update restrict                          "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_USERACCOUNTBINDING add constraint FK_REF_USER_ACCOUNTBIND foreign key (USERACCOUNT) "
        "      references UAB_USER (USERACCOUNT) on delete restrict on update restrict                       "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_USERCORPS add constraint FK_REF_ACCOUNT_USERCORP foreign key (USERACCOUNT) "
        "      references UAB_ACCOUNT (USERACCOUNT) on delete restrict on update restrict           "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "alter table UAB_USERCORPS add constraint FK_REF_CORPINFO_USERCORP foreign key (CORPIID) "
        "      references UAB_CORPINFO (CORPIID) on delete restrict on update restrict           "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);
}

void DataAccessTest::testAdd()
{
    std::string sql;
    int affectRows;

    sql.assign(
        "USE pctor"
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "INSERT INTO UAB_CONFIGURATION  (OWNER, SECTION, CONFIGKEY, STRINGVALUE)     "
        "VALUES ('SYSTEM', 'DownloadCorpFile', 'DownloadServer', '172.20.16.127') "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(1 == affectRows);

    sql.assign(
        "INSERT INTO UAB_CONFIGURATION  (OWNER, SECTION, CONFIGKEY)     "
        "VALUES ('SYSTEM', 'DownloadCorpFile', 'DownloadServerPort') "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(1 == affectRows);

    sql.assign(
        "INSERT INTO UAB_CONFIGURATION  (OWNER, SECTION, CONFIGKEY, STRINGVALUE)               "
        "VALUES ('SYSTEM', 'DownloadUserPicture', 'DownloadPictureServer', '172.20.16.127') "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(1 == affectRows);

    sql.assign(
        "INSERT INTO UAB_CONFIGURATION  (OWNER, SECTION, CONFIGKEY)            "
        "VALUES ('SYSTEM', 'DownloadUserPicture', 'DownloadPictureServerPort') "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(1 == affectRows);

    sql.assign(
        "INSERT INTO UAB_CONFIGURATION  (OWNER, SECTION, CONFIGKEY, STRINGVALUE)        "
        "VALUES ('SYSTEM', 'UploadUserPicture', 'UploadPictureServer', '172.20.16.127') "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(1 == affectRows);

    sql.assign(
        "INSERT INTO UAB_CONFIGURATION  (OWNER, SECTION, CONFIGKEY)        "
        "VALUES ('SYSTEM', 'UploadUserPicture', 'UploadPictureServerPort') "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(1 == affectRows);

    sql.assign(
        "INSERT INTO `uab_configuration`(OWNER, SECTION, CONFIGKEY, STRINGVALUE)     "
        "VALUES ('SYSTEM', 'IceCorpCustomer', 'IceConfigFile', 'config.client')   "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(1 == affectRows);

	sql.assign(
		"INSERT INTO `uab_configuration`(OWNER, SECTION, CONFIGKEY, STRINGVALUE)     "
		"VALUES ('SYSTEM', 'IceUserCommon', 'IceConfigFile', 'config2.client')   "
		);
	affectRows = m_DataAccess->execute(sql);

	CPPUNIT_ASSERT(1 == affectRows);

	//sql.assign(
	//	"INSERT INTO `svr_uab_frequencycontact`(CORPIID, CORPUSERINFOIID, LINKMANINFOIID, LINKMANNAME, DELETED, UPLOAD) VALUES ('1', 'IceUserCommon', 'IceConfigFile', 'config2.client, '0', '1') "
	//	);
	//affectRows = m_DataAccess->execute(sql);

	//CPPUNIT_ASSERT(1 == affectRows);

	//sql.assign(
	//	"INSERT INTO `svr_uab_frequencycontact`(CORPIID, CORPUSERINFOIID, LINKMANINFOIID, LINKMANNAME, DELETED, UPLOAD) VALUES ('1', 'IceUserCommon', 'IceConfigFile', 'config2.client, '1', '1') "
	//	);
	//affectRows = m_DataAccess->execute(sql);

	//CPPUNIT_ASSERT(1 == affectRows);

	m_DataAccess->commit();
}

void DataAccessTest::testDelete()
{
    std::string sql;
    int affectRows;

    sql.assign(
        "USE pctor"
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "DELETE FROM SVR_UAB_CORP_GROUP                           "
        " WHERE CORPGROUPIID = 'D8640C9C8B924270889783C31BA87AF5' "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(1 == affectRows);

    m_DataAccess->commit();
}

void DataAccessTest::testUpdate()
{
    std::string sql;
    int affectRows;

    sql.assign(
        "USE pctor"
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(0 == affectRows);

    sql.assign(
        "UPDATE SVR_UAB_CORP_GROUP                                       "
        "   SET HASHVERSION =  MD5(CONCAT(PARENTCUSTOMERGROUPIID,        "
        "                                        GROUPNAME))             "
        "                       WHERE CORPGROUPIID =                     "
        "                             'D8640C9C8B924270889783C31BA87AF5' "
        );
    affectRows = m_DataAccess->execute(sql);

    CPPUNIT_ASSERT(1 == affectRows);

    m_DataAccess->commit();
}

void DataAccessTest::testQuery()
{
    std::string sql;
    int affectRows;

 //   sql.assign(
 //       "USE pctor"
 //       );
 //   affectRows = m_DataAccess->execute(sql);

 //   CPPUNIT_ASSERT(0 == affectRows);

	//sql.assign(
	//	"UPDATE SVR_UAB_CORP_MERLINKMAN								 "
	//	"SET LINKMANNAME = '\xE6\x88\x90\xE9\x9B\xAA\xE9\xA3\x9E'    "
	//	"WHERE CORPMERLINKMANIID = '7ed70143b41e0fb71165bf7ca2194bf8'"
	//	);
	//affectRows = m_DataAccess->execute(sql);

	//CPPUNIT_ASSERT(1 == affectRows);

 //   std::vector<Sptr<ISQLRow> > results;
 //   sql.assign(
 //       "SELECT LINKMANNAME											 "
	//	"FROM SVR_UAB_CORP_MERLINKMAN								 "
	//	"WHERE CORPMERLINKMANIID = '7ed70143b41e0fb71165bf7ca2194bf8'"
 //       );
 //   m_DataAccess->query(sql, results);

 //   CPPUNIT_ASSERT(1 == results.size());

	sql.assign(
       "USE bookmark"
       );
   affectRows = m_DataAccess->execute(sql);

   CPPUNIT_ASSERT(0 == affectRows);

   std::vector<Sptr<ISQLRow> > results;
   sql.assign(
       "SELECT id, name, order FROM section"
       );
   m_DataAccess->query(sql, results);

   CPPUNIT_ASSERT(1 == results.size());
}

void DataAccessTest::testAddData()
{
	//std::string sql;
	//int affectRows;

	//sql.assign(
	//	"USE pctor"
	//	);
	//affectRows = m_DataAccess->execute(sql);

	//CPPUNIT_ASSERT(0 == affectRows);

	//sql.assign(
	//	"INSERT INTO UAB_CONFIGURATION  (OWNER, SECTION, CONFIGKEY, STRINGVALUE)     "
	//	"VALUES ('SYSTEM', 'DownloadCorpFile', 'DownloadServer', '172.20.16.127') "
	//	);
	//affectRows = m_DataAccess->execute(sql);

	//CPPUNIT_ASSERT(1 == affectRows);

	//m_DataAccess->commit();

	CPPUNIT_ASSERT(0 == 0);
}

void DataAccessTest::testEscape()
{
	CPPUNIT_ASSERT(0 == 0);
}