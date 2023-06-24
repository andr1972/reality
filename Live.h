#pragma once
#include "Matter.h"
#include "Brain.h"
#include "Information.h"

class Living : public Thing {
};

class Plant: public Living {

};

class Animal: public Living {
public:
    ~Animal(){}
    Senses senses;
    Brain* brain = nullptr;

    Color* getVisualQualia(const vector<Photon>& photons) {
        RGBInformation rgb = senses.getRgb(photons);
        return brain->getColorFeeling(rgb);
    }

    Sound* getSoundQualia(SoundInTheAir *sound) {
        SoundInformation hearingNeuronsInformation = senses.getInfoAboutSound(sound);
        return brain->getSoundFeeling(hearingNeuronsInformation);
    }

    Smell* getSmellQualia(OzoneInTheAir *ozone) {
        SmellInformation infoNeuronowWechu = senses.getInfoAboutSmell(ozone);
        return brain->getSmellFeeling(infoNeuronowWechu);
    }

    Touch* getTouchQualia(Thing *przedmiot) {
        TouchInformation infoNeuronowDotyku = senses.getInfoAboutTouch(przedmiot);
        return brain->getTouchFeeling(infoNeuronowDotyku);
    }

    Sound* hear(SoundInTheAir *soundInTheAir){
        cout << "I am " << brain->subjectIdent << " I hear " + soundInTheAir->thingIdent << endl;
        return getSoundQualia(soundInTheAir);
    }

    virtual void look(Thing *thing) {
        vector<Photon> photons = thing->getPhotons();
        getVisualQualia(photons);
        cout << "I am " << brain->subjectIdent << " I see " << thing->thingIdent << endl;
    }

    void feelTheTouch(Thing *thing) {
        getTouchQualia(thing);
        cout << "I am " << brain->subjectIdent + " I feel the touch of " + thing->thingIdent << endl;
    }

    virtual Thought* feelTheSmell(OzoneInTheAir *ozone) {
        Smell* smell = getSmellQualia(ozone);
        cout << "I am " << brain->subjectIdent << " I smell " + ozone->thingIdent << endl;
        return nullptr;
    }
};

class OtherAnimal: public Animal {
public:
    OtherAnimal(string ident) {
        brain = new Brain(ident);
        thingIdent = "body of " + ident;
    }
};

class Cat: public OtherAnimal {
public:
    Cat(string ident): OtherAnimal(ident){}
};

class Human: public Animal {
public:
    Human(string ident) {
        brain = new HumanBrain(ident);
        thingIdent = "body of " + ident;
    };

    void look(Thing *thing) {
        Animal::look(thing);
        dynamic_cast<HumanBrain*>(brain)->thinkAbout(thing);
    }

    Thought* lookAndBelieve(Effigy *effigy, Thing* linkedTo) {
        Animal::look(effigy);
        return dynamic_cast<HumanBrain*>(brain)->thinkAbout(linkedTo);
    }

    void learn(Thought* thought, string label) {
        dynamic_cast<HumanBrain*>(brain)->learn(thought, label);
    }

    Thought* assumeAttribute(Thing* thing, Attribute *attr) {
        return new ThoughtAboutThingOpinion(attr, thing);


        /*
                     Thought *thought;
    if (dynamic_cast<Animal*>(being) != nullptr) {
        if (dynamic_cast<OtherAnimal*>(being) != nullptr)
            thought = new ThoughtAboutAnimal(currentQualia, dynamic_cast<OtherAnimal*>(being));
        else
            thought = new ThoughtAboutHuman(currentQualia, dynamic_cast<Human*>(being));
    }
    else
        thought = new ThoughtAboutThingQualia(currentQualia, dynamic_cast<Thing*>(being));
    currentThought = thought;
    return thought;

         * */
    };
//todo learn smell
    Thought* feelTheSmell(OzoneInTheAir *ozone) override {
        auto smell = Animal::feelTheSmell(ozone);
        dynamic_cast<HumanBrain*>(brain)->thinkAbout(ozone);
        auto th = dynamic_cast<HumanBrain*>(brain)->thinkAbout(smell);
        return th;
    }

    void moveTheThingYouSaw() {
        auto* thoughtAboutThing =  dynamic_cast<ThoughtAboutThingQualia*>(dynamic_cast<HumanBrain*>(brain)->currentThought);
        if (thoughtAboutThing == nullptr) return;
        if (thoughtAboutThing->qualia == brain->currentQualia) {
            cout << "I am " << brain->subjectIdent << " I intend move " << thoughtAboutThing->thing->thingIdent << endl;
            thoughtAboutThing->thing->movePosition(10.0);
        }
    }

    void touchTheCat() {
        auto* thoughtAboutAnimal =  dynamic_cast<ThoughtAboutAnimal*>(dynamic_cast<HumanBrain*>(brain)->currentThought);
        if (thoughtAboutAnimal == nullptr) return;
        if (thoughtAboutAnimal->qualia == brain->currentQualia) {
            this->feelTheTouch(thoughtAboutAnimal->animal);
            thoughtAboutAnimal->animal->feelTheTouch(this);
        }
    }

    SoundInTheAir say(string message) {
        cout << "I am " << brain->subjectIdent << " I intend to speak" << endl;
        cout << thingIdent << " produces sound in the air" << endl;
        return SoundInTheAir("sound in the air", message);
    }

    string getMessage(Sound *sound) {
        return dynamic_cast<HumanBrain *>(brain)->getlabel(sound);
    }

    void understand(string message) {
        return dynamic_cast<HumanBrain *>(brain)->understand(message);
    }
};
