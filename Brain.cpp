#include "Brain.h"
#include "Live.h"

std::shared_ptr<ThoughtAboutThingQualia> HumanBrain::thinkAboutThing(Being* being) {
    std::shared_ptr<ThoughtAboutThingQualia> thought;
    thought = std::make_shared<ThoughtAboutThingQualia>(currentQualia.get(), dynamic_cast<Thing*>(being));
    currentThought = thought;
    return thought;
}

std::shared_ptr<ThoughtAboutAnimal> HumanBrain::thinkAboutAnimal(Being* being) {
    std::shared_ptr<ThoughtAboutAnimal> thought;
    thought = std::make_shared<ThoughtAboutAnimal>(currentQualia.get(), dynamic_cast<OtherAnimal*>(being));
    currentThought = thought;
    return thought;
}

std::shared_ptr<ThoughtAboutHuman> HumanBrain::thinkAboutHuman(Being* being) {
    std::shared_ptr<ThoughtAboutHuman> thought;
    thought = std::make_shared<ThoughtAboutHuman>(currentQualia.get(), dynamic_cast<Human*>(being));
    currentThought = thought;
    return thought;
}