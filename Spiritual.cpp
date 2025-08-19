#include "Spiritual.h"
#include "Live.h"

ThoughtAboutThingQualia::ThoughtAboutThingQualia(const std::shared_ptr<Qualia>& qualia, Thing *thing): qualia(qualia), thing(thing) {
    std::cout << "assigned qualia " << qualia->kindstr() << " to thing " << thing->thingIdent << std::endl;
}

ThoughtAboutAnimal::ThoughtAboutAnimal(const std::shared_ptr<Qualia>& qualia, Animal *animal): qualia(qualia), animal(animal){
    std::cout << "assigned qualia to animal " << animal->thingIdent << std::endl;
};

ThoughtAboutHuman::ThoughtAboutHuman(const std::shared_ptr<Qualia>& qualia, Human *human): qualia(qualia), human(human){
    std::cout << "assigned qualia to human " << human->thingIdent << std::endl;
}