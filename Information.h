#pragma once

class ClassicalInformation : public Being {

};

class Attribute: public ClassicalInformation {
public:
    virtual std::string toString() = 0;
};

class MassAttr: public Attribute {
public:
    std::string toString() override {return "MassAttr";}
};

class AreaAttr: public Attribute {
public:
    std::string toString() override {return "AreaAttr";}
};

class Number {
    float value;
};

class Mass {
};

class MassUnit {
};

class Area {
};

class AreaUnit {

};

class NumberForm {

};

class Currency {

};