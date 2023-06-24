#include "Brain.h"
#include "Live.h"

Thought *HumanBrain::thinkAbout(Being *being) {
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
}