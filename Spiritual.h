#pragma once

#include <vector>
#include <iostream>
#include "Fundamental.h"
#include "Matter.h"

class Qualia : public Being {
public:
    virtual string kindstr() = 0;
};

class Color: public Qualia {
};

class Redness: public Color {
public:
    string kindstr() override {
        return "Redness";
    }
};

class Whiteness: public Color {
    string kindstr() override {
        return "Whiteness";
    }
};

class Sound: Qualia {
public:
    int kind;
    string kindstr() override {
        return "Sound";
    }
};

class Smell: public Qualia {
public:
    string kindstr() override {
        return "Smell";
    }
};

class OzoneSmell: public Smell {
public:
    string kindstr() override {
        return "OzoneSmell";
    }
};

class Touch: public Qualia {
public:
    string kindstr() override {
        return "OzoneSmell";
    }
};

class Pleasure: Qualia {
public:
    string kindstr() override {
        return "Pleasure";
    }
};

class Conscious : public Being {
public:
    string subjectIdent;
    Conscious(){ //multibase c++ inheritance need this constructor
        subjectIdent = "??";
    }
    Conscious(string ident): subjectIdent(ident) {}
    Qualia* currentQualia;

};

class Thought;
class Animal;
class Human;
class Thing;

class Thought: public Being {
public:
    virtual ~Thought() = default;
    //virtual Thought* clone() = 0;
};

template<class Idea> class ThoughtAboutIdea : public Thought {

};

class ThoughtAboutThingQualia : public Thought {
public:
    Qualia *qualia;
    Thing *thing;
    ThoughtAboutThingQualia(Qualia *qualia, Thing *thing);
//    Thought* clone() override {
//        auto copy = new ThoughtAboutThingQualia(qualia, thing);
//        return copy;
//    }
};

class ThoughtAboutThingOpinion : public Thought {
public:
    Attribute *opinion;
    Thing *thing;
    ThoughtAboutThingOpinion(Attribute *opinion, Thing *thing): opinion(opinion), thing(thing) {
        cout << "assigned opinion "<<opinion->toString() << " to thing " << thing->thingIdent << endl;
    }

//    Thought* clone() override {
//        auto copy = new ThoughtAboutThingQualia(qualia, thing);
//        return copy;
//    }
};


class ThoughtAboutAnimal : public Thought {
public:
    Qualia *qualia;
    Animal *animal;
    ThoughtAboutAnimal(Qualia *qualia, Animal *animal);
//    Thought* clone() override {
//        auto copy = new ThoughtAboutAnimal(qualia, animal);
//        return copy;
//    }
};

class ThoughtAboutHuman : public Thought {
public:
    Qualia *qualia;
    Human *human;//not human due to C++ circular defs
    ThoughtAboutHuman(Qualia *qualia, Human *human);
//    Thought* clone() override {
//        auto copy = new ThoughtAboutHuman(qualia, human);
//        return copy;
//    }
};

class ThoughtAboutPerson : Thought {
    Human *human;
};

class MemoryItem {
public:
    string label;
    Thought* thought = nullptr;
    MemoryItem(Thought* thought, string label):label(std::move(label)) {
        //if (thought)
            this->thought = thought;//  ->clone();
    }
    virtual ~MemoryItem() = default;
};

class Memory : public Being {
    vector<MemoryItem*> memoryItems;
public:
    Memory(){};
    void add(Thought* thought, string label) {
        memoryItems.emplace_back(new MemoryItem(thought, label));
    }

    MemoryItem *find(string label) {
        for (auto *item: memoryItems) {
            if (item->label == label)
                return item;
        }
        return nullptr;
    }
};

class Conglomerate : public Being {
    vector<Qualia*> items;
};

class Rational: public virtual Conscious {
public:
    Thought* currentThought;
    Memory memory;
    Rational(string ident): Conscious(ident) {}

    string getlabel(Sound *sound) {
        string label;
        if (sound->kind == 100)
            label = "ozone";
        else if (sound->kind == 120)
            label = "pi";
        else
            label = "?";
        cout << "I am rational " << subjectIdent << " I deduce from sound " << label << endl;
        return label;
    }

    void understand(string label) {
        MemoryItem *item = memory.find(label);
        if (item) {
            cout << "I am rational " << subjectIdent << " I understand smell " << label << endl;
            currentThought = item->thought;
        }
    }

    void learn(Thought* thought, string label) {
        memory.add(thought, label);
    }
};
