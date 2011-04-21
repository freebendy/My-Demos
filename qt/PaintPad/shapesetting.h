#ifndef SETTING_H
#define SETTING_H

#include <QColor>

class ShapeSetting
{
public:
    /**
    * constructor
    **/
    ShapeSetting() {}

    /**
    * destructor
    **/
    virtual ~ShapeSetting() {}

    /**
    * get the opactity of setting
    **/
    virtual float opacity() = 0;

    /**
    * get the line size of setting
    **/
    virtual int lineSize() = 0;

    /**
    * get the edge size of setting
    **/
    virtual int edgeSize() = 0;

    /**
    * get the edge color of setting
    **/
    virtual QColor edgeColor() = 0;

    /**
    * get the frontground color of setting
    **/
    virtual QColor fbColor() = 0;

};

#endif // SETTING_H
