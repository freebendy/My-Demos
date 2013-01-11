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
        //帐号表映射
        static std::map<std::string,std::string> accountMap;

        //用户企业表映射
        static std::map<std::string,std::string> enterpriseMap ;

        //企业内部组织表映射
        static std::map<std::string,std::string> enterpriseGroupMap ;                                                                      

        //企业内部联系人表映射
        static std::map<std::string,std::string> enterpriseContactMap ;

        //企业外部组表映射
        static std::map<std::string,std::string> customGroupMap ;

        //企业外部联系人表映射
        static std::map<std::string,std::string> customContactMap ;   

    };
} //namespace pctor
