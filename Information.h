#pragma once

class ClassicalInformation : public Being {

};

class Attribute: public ClassicalInformation {
public:
    virtual string toString() = 0;
};

class MassAttr: public Attribute {
public:
    string toString() override {return "MassAttr";}
};

class AreaAttr: public Attribute {
public:
    string toString() override {return "AreaAttr";}
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