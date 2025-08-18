#pragma once
#include <memory>

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
    std::unique_ptr<Brain> brain;

    std::shared_ptr<Color> getVisualQualia(const std::vector<Photon>& photons) {
        RGBInformation rgb = senses.getRgb(photons);
        return brain->getColorFeeling(rgb);
    }

    std::shared_ptr<Sound> getSoundQualia(SoundInTheAir *sound) {
        SoundInformation hearingNeuronsInformation = senses.getInfoAboutSound(sound);
        return brain->getSoundFeeling(hearingNeuronsInformation);
    }

    std::shared_ptr<Smell> getSmellQualia(OzoneInTheAir *ozone) {
        SmellInformation infoNeuronowWechu = senses.getInfoAboutSmell(ozone);
        return brain->getSmellFeeling(infoNeuronowWechu);
    }

    std::shared_ptr<Touch> getTouchQualia(Thing *thing) {
        TouchInformation tactileNeuronInfo = senses.getInfoAboutTouch(thing);
        return brain->getTouchFeeling(tactileNeuronInfo);
    }

    std::shared_ptr<Sound> hear(SoundInTheAir *soundInTheAir){
        std::cout << "I am " << brain->subjectIdent << " I hear " + soundInTheAir->thingIdent << std::endl;
        return getSoundQualia(soundInTheAir);
    }

    virtual void look(Thing* thing) {
        std::vector<Photon> photons = thing->getPhotons();
        getVisualQualia(photons);
        std::cout << "I am " << brain->subjectIdent << " I see " << thing->thingIdent << std::endl;
    }

    void feelTheTouch(Thing* thing) {
        getTouchQualia(thing);
        std::cout << "I am " << brain->subjectIdent + " I feel the touch of " + thing->thingIdent << std::endl;
    }

    virtual std::shared_ptr<ThoughtAboutThingQualia> feelTheSmell(OzoneInTheAir *ozone) {
        auto smell = getSmellQualia(ozone);
        std::cout << "I am " << brain->subjectIdent << " I smell " + ozone->thingIdent << std::endl;
        return nullptr;
    }
};

class OtherAnimal: public Animal {
public:
    OtherAnimal(std::string ident) {
        brain = std::make_unique<Brain>(ident);;
        thingIdent = "body of " + ident;
    }
};

class Cat: public OtherAnimal {
public:
    Cat(std::string ident): OtherAnimal(ident){}
};

class Human: public Animal {
public:
    Human(std::string ident) {
        brain = std::make_unique<HumanBrain>(ident);
        thingIdent = "body of " + ident;
    };

    void look(Thing* thing) {
        Animal::look(thing);
        dynamic_cast<HumanBrain*>(brain.get())->thinkAboutThing(thing);
    }

    std::shared_ptr<Thought> lookAndBelieve(Effigy *effigy, Thing* linkedTo) {
        Animal::look(effigy);
        return dynamic_cast<HumanBrain*>(brain.get())->thinkAboutThing(linkedTo);
    }

    //todo learn about thing, animal, etc
    void learn(const std::shared_ptr<Thought> &thought, std::string label) {
        dynamic_cast<HumanBrain*>(brain.get())->learn(thought, label);
    }

    std::shared_ptr<Thought> assumeAttribute(Thing* thing, Attribute *attr) {
        return std::make_shared<ThoughtAboutThingOpinion>(attr, thing);


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
    std::shared_ptr<ThoughtAboutThingQualia> feelTheSmell(OzoneInTheAir *ozone) override {
        auto smell = Animal::feelTheSmell(ozone);
        dynamic_cast<HumanBrain*>(brain.get())->thinkAboutThing(ozone);
        return dynamic_cast<HumanBrain*>(brain.get())->thinkAboutThing(smell.get());
    }

    void moveTheThingYouSaw() {
        auto thought =  dynamic_cast<HumanBrain*>(brain.get())->currentThought.get();
        auto thoughtAboutThing =  dynamic_cast<ThoughtAboutThingQualia*>(thought);
        if (thoughtAboutThing == nullptr) return;
        if (thoughtAboutThing->qualia == brain->currentQualia) {
            std::cout << "I am " << brain->subjectIdent << " I intend move " << thoughtAboutThing->thing->thingIdent << std::endl;
            thoughtAboutThing->thing->movePosition(10.0);
        }
    }

    void touchTheCat() {
        auto thought = dynamic_cast<HumanBrain*>(brain.get())->currentThought.get();
        auto thoughtAboutAnimal =  dynamic_cast<ThoughtAboutAnimal*>(thought);
        if (thoughtAboutAnimal == nullptr) return;
        if (thoughtAboutAnimal->qualia == brain->currentQualia) {
            this->feelTheTouch(thoughtAboutAnimal->animal.get());
            thoughtAboutAnimal->animal->feelTheTouch(this);
        }
    }

    SoundInTheAir say(std::string message) {
        std::cout << "I am " << brain->subjectIdent << " I intend to speak" << std::endl;
        std::cout << thingIdent << " produces sound in the air" << std::endl;
        return SoundInTheAir("sound in the air", message);
    }

    std::string getMessage(Sound *sound) {
        return dynamic_cast<HumanBrain *>(brain.get())->getlabel(sound);
    }

    void understand(std::string message) {
        return dynamic_cast<HumanBrain *>(brain.get())->understand(message);
    }
};
