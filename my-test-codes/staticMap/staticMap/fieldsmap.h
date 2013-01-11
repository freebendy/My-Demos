#pragma once

#include <map>
#include <string>

namespace pctor
{
    class FieldsMap
    {
    public:
        static void initialize() ;

    public:
        //�ʺű�ӳ��
        static std::map<std::string,std::string> accountMap;

        //�û���ҵ��ӳ��
        static std::map<std::string,std::string> enterpriseMap ;

        //��ҵ�ڲ���֯��ӳ��
        static std::map<std::string,std::string> enterpriseGroupMap ;                                                                      

        //��ҵ�ڲ���ϵ�˱�ӳ��
        static std::map<std::string,std::string> enterpriseContactMap ;

        //��ҵ�ⲿ���ӳ��
        static std::map<std::string,std::string> customGroupMap ;

        //��ҵ�ⲿ��ϵ�˱�ӳ��
        static std::map<std::string,std::string> customContactMap ;   

    };
} //namespace pctor
