#pragma once
#include "Fundamental.h"
#include "Information.h"

class PhysicalEntities: public Being {
public:
    std::string thingIdent;
};

class Matter: public PhysicalEntities {
};

class RGBInformation: ClassicalInformation {
public:
    float R=0,G=0,B=0;
};

class SmellInformation: ClassicalInformation {
    int particleType;
    float intensity;
};

class SoundInformation: ClassicalInformation {
public:
    float frequency;
    float intensity;
};

class TouchInformation: ClassicalInformation {
    int touchKind;
    float intensity;
};

class Photon: Matter {
public:
    int energy;
    explicit Photon(int energy): energy(energy){};
};

class QuantumField : PhysicalEntities {
    float intensity;
public:
    Photon* createPhoton() {
        if (random()%int(10000 / intensity) ==0)
            return new Photon((float)random());
        else
            return nullptr;
    }
};

enum MaterialColor {RedMaterial, GreenMaterial, WhiteMaterial};

class Thing: public Matter {
    Photon reflectOffMaterial() const {
        if(materialColor == RedMaterial)
            return Photon(100);
        else if(materialColor == GreenMaterial)
            return Photon(200);
        else if (materialColor == WhiteMaterial) {
            switch (random() % 3) {
                case 0: return Photon(100);
                case 1: return Photon(200);
                case 2: return Photon(300);
            }
        }
        return Photon(500);
    }
public:
    virtual ~Thing(){};
    float position;
    MaterialColor materialColor;
    Thing(float position, MaterialColor materialColor): position(position), materialColor(materialColor){}

    Thing() {};
    std::vector<Photon> getPhotons() {
        std::vector<Photon> photons;
        for (int i=0; i<10;i++) {
            Photon foton = reflectOffMaterial();
            photons.push_back(foton);
        }
        return photons;
    }

    void movePosition(double delta) {
        std::cout << "is moving physical position of " << thingIdent << std::endl;
        position+=delta;
    }
};

class SoundInTheAir: public Matter {
public:
    int frequency;
    SoundInTheAir(std::string ident, std::string message) { //todo tutaj nie message
        this->thingIdent = ident;
        if (message == "ozone") frequency=1005;
        else if (message == "pi") frequency=1205;
        else frequency=100;
    };
};

class OzoneInTheAir: public Matter {
public:
    OzoneInTheAir(std::string ident) {
        this->thingIdent = ident;
    };
};

/*
 * Class Chair is universal, and objects of class Chair are specific chairs
  * */
class Chair : public Thing {
public:
    Chair(float position, MaterialColor materialColor): Thing(position, materialColor){
        thingIdent = "physical chair";
    }
};

class Stone : public Thing {
public:
    Stone(float position, MaterialColor materialColor): Thing(position, materialColor){
        thingIdent = "physical stone";
    }
};

class Planet: public Thing {
public:
    Planet(std::string thingIdent) {
        this->thingIdent = thingIdent;
    }
};

class Senses: public Thing {
public:
    RGBInformation getRgb(const std::vector<Photon> &photons) {
        RGBInformation rgb;
        for (auto& photon: photons) {
            switch (photon.energy) {
                case 100:
                    rgb.R++;
                    break;
                case 200:
                    rgb.G++;
                    break;
                case 300:
                    rgb.B++;
                    break;
            }
        }
        return rgb;
    }

    SoundInformation getInfoAboutSound(SoundInTheAir* soundInTheAir) {
        SoundInformation information;
        information.frequency = soundInTheAir->frequency;
        return information;
    }

    SmellInformation getInfoAboutSmell(OzoneInTheAir *ozone) {
        return SmellInformation();
    }

    TouchInformation getInfoAboutTouch(Thing *thing) {
        return TouchInformation();
    }
};

class Effigy: public Thing {
public:
    Effigy(std::string thingIdent) {
        this->thingIdent = thingIdent;
    }
};