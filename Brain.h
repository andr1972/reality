#pragma once

#include <memory>
#include <string>
#include "Spiritual.h"
#include "Matter.h"

class Brain: public virtual Conscious, public Thing {
public:
    Brain(std::string ident): Conscious(ident) {}
    std::shared_ptr<Color> getColorFeeling(RGBInformation rgb) {
        auto color = (rgb.R>rgb.G && rgb.R>rgb.B)
            ? std::static_pointer_cast<Color>(std::make_shared<Redness>())
            : std::static_pointer_cast<Color>(std::make_shared<Whiteness>());
        currentQualia = color;        // współdzielone z Brain i Thought
        return color;
    }

    std::shared_ptr<Sound> getSoundFeeling(SoundInformation &soundInformation) {
        auto sound = std::make_shared<Sound>();
        sound->kind = soundInformation.frequency / 10;
        return sound;
    }

    std::shared_ptr<Smell> getSmellFeeling(SmellInformation &fragnanceInformation) {
        return std::make_shared<Smell>();
    }

    std::shared_ptr<Touch> getTouchFeeling(TouchInformation &touchInformation) {
        return std::make_shared<Touch>();
    }
};

class HumanBrain: public virtual Rational, public Brain {
public:
    ~HumanBrain() {
    }
    HumanBrain(std::string ident): Rational(ident), Brain(ident) {
        subjectIdent = ident;
        thingIdent = "brain " + ident;
    }
    //very strong functions of mind!
    std::shared_ptr<ThoughtAboutThingQualia> thinkAboutThing(Being* being);
    std::shared_ptr<ThoughtAboutAnimal> thinkAboutAnimal(Being* being);
    std::shared_ptr<ThoughtAboutHuman> thinkAboutHuman(Being* being);
};

