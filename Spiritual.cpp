#include "Spiritual.h"
#include "Live.h"

ThoughtAboutThingQualia::ThoughtAboutThingQualia(Qualia *qualia, Thing *thing): qualia(qualia), thing(thing) {
    cout << "assigned qualia " << qualia->kindstr() << " to thing " << thing->thingIdent << endl;
}

ThoughtAboutAnimal::ThoughtAboutAnimal(Qualia *qualia, Animal *animal): qualia(qualia), animal(animal){
        cout << "assigned qualia to animal " << animal->thingIdent << endl;
};

ThoughtAboutHuman::ThoughtAboutHuman(Qualia *qualia, Human *human): qualia(qualia), human(human){
    cout << "assigned qualia to human " << human->thingIdent << endl;
}