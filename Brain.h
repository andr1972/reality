#pragma once

#include <string>
#include "Spiritual.h"
#include "Matter.h"

class Brain: public virtual Conscious, public Thing {
public:
    Brain(string ident): Conscious(ident) {}
Color* getColorFeeling(RGBInformation rgb) {
    Color* color;
    if (rgb.R>rgb.G && rgb.R>rgb.B)
        color = new Redness();
    else
        color = new Whiteness();
    currentQualia = color;
    return color;
}

Sound* getSoundFeeling(SoundInformation soundInformation) {
    Sound *sound = new Sound;
    sound->kind = soundInformation.frequency / 10;
    return sound;
}

Smell* getSmellFeeling(SmellInformation fragnanceInformation) {
    return new Smell();
}

Touch* getTouchFeeling(TouchInformation touchInformation) {
    return new Touch();
}
};

class HumanBrain: public virtual Rational, public Brain {
public:
    HumanBrain(string ident): Rational(ident), Brain(ident) {
        subjectIdent = ident;
        thingIdent = "brain " + ident;
    }
    //very strong function of mind!
    Thought *thinkAbout(Being *being);
};

