#include <vector>
#include <random>
#include <iostream>
#include "Live.h"
#include "Information.h"

using namespace std;

void stoneKickTest() {
    cout << "stone kick test" << endl;
    Human SamuelJohnson("Samuel Johnson");
    Human Berkeley("Berkeley");
    Stone stone(10.0, WhiteMaterial);
    Berkeley.look(&stone);
    SamuelJohnson.look(&stone);
    SamuelJohnson.moveTheThingYouSaw();
    Berkeley.look(&stone);
    cout << endl;
}

void chairMovingTest() {
    cout << "chair moving test" << endl;
    Human clerk("clerk");
    Chair redChair(15, RedMaterial);
    clerk.look(&redChair);
    clerk.moveTheThingYouSaw();
    cout << endl;
}

void touchingCatTest() {
    cout << "touching cat test" << endl;
    Human aunt("aunt");
    Cat cat("aunt's cat");
    aunt.look(&cat);
    aunt.touchTheCat();
    cout << endl;
}

void talkAboutOzoneTest() {
    cout << "talk about ozone test" << endl;
    OzoneInTheAir ozoneOneTime("ozone one time");
    Human person1("person1");
    Human person2("person2");
    auto thought = person2.feelTheSmell(&ozoneOneTime);
    person2.learn(thought, "ozone");
    //after some years....
    OzoneInTheAir ozoneToday("ozone today");
    person1.feelTheSmell(&ozoneToday);
    SoundInTheAir soundInTheAir = person1.say("ozone");
    auto sound = person2.hear(&soundInTheAir).get();
    string message = person2.getMessage(sound);
    person2.understand(message);
    cout << endl;
}

void talkAboutIdeasTest() {
    cout << "talk about ideas test" << endl;
    Human instructor("instructor");
    Human student("student");
    //student.learn()
    //after some years....
    SoundInTheAir soundInTheAir = instructor.say("pi");
    Sound *sound = student.hear(&soundInTheAir).get();
    string message = student.getMessage(sound);
    student.understand(message);
    soundInTheAir = instructor.say("Mandelbrot");
    sound = student.hear(&soundInTheAir).get();
    message = student.getMessage(sound);
    student.understand(message);
    cout << endl;
}

void learnAboutEarthTest() {
    Human student("student");
    Planet Earth("Earth");
    Effigy EarthPhoto("Earth photo");
    auto th1 = student.lookAndBelieve(&EarthPhoto, &Earth);
    student.learn(th1, "Earth.look");
    MassAttr EarthMass;
    auto th2 = student.assumeAttribute(&Earth, &EarthMass);
    student.learn(th2, "Earth.mass");
    AreaAttr EarthArea;
    auto th3 = student.assumeAttribute(&Earth, &EarthArea);
    student.learn(th3, "Earth.area");
}

int main() {
    //learnAboutEarthTest();
    //stoneKickTest();
    /*chairMovingTest();
    touchingCatTest();*/
    //talkAboutOzoneTest();
    talkAboutIdeasTest();
    return 0;
}