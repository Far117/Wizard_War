#include "spells.h"
#include "constants.h"

#include <vector>

//#include <iostream>

//using namespace std;


//=============== Fire
Spell torch;
Spell fireball;
Spell flamethrower;
Spell firerain;
Spell lightning;
Spell kamehameha;
Spell spiritbomb;
//=============== Water
Spell slap;
Spell wave;
Spell icedagger;
Spell icesword;
Spell iciclerain;
Spell zero;
//=============== Earth
Spell pebble_rain;
Spell rockhurl;
Spell quicksand;
Spell boulder;
Spell volcano;
Spell meteor;
//=============== Air
Spell air_wave;
Spell downflow;
Spell upflow;
Spell airslice;
Spell tornado;
Spell suffocate;
Spell voids;
//=============== Force
Spell push;
Spell hurl;
Spell atmosphere;
Spell explode;
Spell implode;
Spell atomic;
//================ Physical
Spell punch;
Spell kick;
Spell flurry;
Spell dropkick;
Spell falconpunch;
Spell dragonfist;
Spell chucknorris;
//================ Sword
Spell woodsword;
Spell dagger;
Spell sword;
Spell longsword;
Spell lightsaber;
Spell soulsword;
//================ End

//std::vector<Spell> spell_list;

Hero init_spells(Hero p){

    //=============================================================================== Fire
    torch.name="Torch";
    torch.description="Send a small burst of fire into your opponent's face!";
    torch.power_requirement=2;
    torch.type=1;
    torch.cost=15;

    fireball.name="Fireball";
    fireball.description="Hurl a ball of pure fire into your opponent!";
    fireball.power_requirement=20;
    fireball.type=1;
    fireball.cost=50;

    flamethrower.name="Flamethrower";
    flamethrower.description="Launch a column of fire into your opponent!";
    flamethrower.power_requirement=50;
    flamethrower.type=1;
    flamethrower.cost=100;

    firerain.name="Fire Rain";
    firerain.description="Pour fire from the heavens onto your opponent!";
    firerain.power_requirement=150;
    firerain.type=1;
    firerain.cost=500;

    lightning.name="Lightning";
    lightning.description="Summon a bolt of lightning from your own hands to fry your opponent!";
    lightning.power_requirement=300;
    lightning.type=1;
    lightning.cost=1000;

    kamehameha.name="Kamehameha";
    kamehameha.description="Send all of your KI out of your hands. What will their scouters say about THAT?";
    kamehameha.power_requirement=500;
    kamehameha.type=1;
    kamehameha.cost=1500;

    spiritbomb.name="Spirit Bomb";
    spiritbomb.description="Steal your opponents power, then send it back at him! Earth! We need you!";
    spiritbomb.power_requirement=1000;
    spiritbomb.type=1;
    spiritbomb.cost=3500;
    //=============================================================================== Water
    slap.name="Slap";
    slap.description="Slap your opponent with a small burst of water!";
    slap.power_requirement=2;
    slap.type=2;
    slap.cost=15;

    wave.name="Wave";
    wave.description="Pull a wave out of the earth, and wash away your opponent!";
    wave.power_requirement=10;
    wave.type=2;
    wave.cost=50;

    icedagger.name="Ice Dagger";
    icedagger.description="Freeze some daggers in your hand. Nice for fast attacks.";
    icedagger.power_requirement=50;
    icedagger.type=2;
    icedagger.cost=150;

    icesword.name="Ice Sword";
    icesword.description="Freeze yourself a sword, and FIGHT!";
    icesword.power_requirement=60;
    icesword.cost=300;
    icesword.type=2;

    iciclerain.name="Icicle Rain";
    iciclerain.description="Summon a hail of icicles to impale your opponent!";
    iciclerain.power_requirement=150;
    iciclerain.type=2;
    iciclerain.cost=1000;

    zero.name="Absolute Zero";
    zero.description="Freeze the air around you to absolute zero, cold enough to stop atoms...";
    zero.power_requirement=500;
    zero.type=2;
    zero.cost=1500;
    //============================================================================== Earth
    pebble_rain.name="Pebble Rain";
    pebble_rain.description="Send the pebbles at your feet flying into the air, and have them ran down on your opponent!";
    pebble_rain.power_requirement=5;
    pebble_rain.type=3;
    pebble_rain.cost=20;

    rockhurl.name="Rock Hurl";
    rockhurl.description="Hurl a large rock at your enemy. Aim for the face!";
    rockhurl.power_requirement=20;
    rockhurl.type=3;
    rockhurl.cost=75;

    quicksand.name="Quicksand";
    quicksand.description="Turn the floor into deadly quicksand. You CAN sink in this one!";
    quicksand.power_requirement=50;
    quicksand.type=3;
    quicksand.cost=150;

    boulder.name="Boulder";
    boulder.description="Drop a huge boulder on your opponent!";
    boulder.power_requirement=75;
    boulder.type=3;
    boulder.cost=250;

    volcano.name="Volcano";
    volcano.description="Make a volcano erupt at your opponent's feet!";
    volcano.power_requirement=200;
    volcano.cost=1700;
    volcano.type=3;

    meteor.name="Meteor";
    meteor.description="Concentrate... and pull a giant meteor out of space onto your opponent!!!";
    meteor.power_requirement=500;
    meteor.cost=5000;
    meteor.type=3;
    //=================================================================================== Air
    air_wave.name="Air Wave";
    air_wave.description="Call the winds to send your opponent flying!";
    air_wave.power_requirement=5;
    air_wave.type=4;
    air_wave.cost=25;

    downflow.name="Downflow";
    downflow.description="Summon a torrent of air to push your opponent onto the ground!";
    downflow.power_requirement=15;
    downflow.type=4;
    downflow.cost=100;

    upflow.name="Upflow";
    upflow.description="Summon a torrent of air to launch your opponent into the air!";
    upflow.power_requirement=50;
    upflow.type=4;
    upflow.cost=250;

    airslice.name="Air Slice";
    airslice.description="Slice your opponent using nothing but air!";
    airslice.power_requirement=100;
    airslice.type=4;
    airslice.cost=600;

    tornado.name="Tornado";
    tornado.description="Fling a raging mass of air at your opponent!";
    tornado.power_requirement=200;
    tornado.type=4;
    tornado.cost=1500;

    suffocate.name="Suffocate";
    suffocate.description="Pull the air out of your opponents lungs!";
    suffocate.power_requirement=300;
    suffocate.cost=3000;
    suffocate.type=4;

    voids.name="Void";
    voids.description="Pull all air out from around your enemy, atomizing it.";
    voids.power_requirement=1000;
    voids.type=4;
    voids.cost=10000;
    //================================================================================= Force
    push.name="Push";
    push.description="Send your enemies stumbling backwards, hopefully into a wall or over a cliff!";
    push.power_requirement=2;
    push.type=5;
    push.cost=15;

    hurl.name="Hurl";
    hurl.description="Flat out send your opponent flying.";
    hurl.power_requirement=10;
    hurl.type=5;
    hurl.cost=50;

    atmosphere.name="Atmospheric Throw";
    atmosphere.description="Send your opponent into space!";
    atmosphere.power_requirement=50;
    atmosphere.type=5;
    atmosphere.cost=250;

    explode.name="Explosion";
    explode.description="Blow up your enemy!";
    explode.power_requirement=300;
    explode.type=5;
    explode.cost=5000;

    implode.name="Implosion";
    implode.description="Pull your enemy into himself!";
    implode.power_requirement=1000;
    implode.type=5;
    implode.cost=12000;

    atomic.name="Atom Rip";
    atomic.description="Pull your enemy apart... atom by atom...";
    atomic.power_requirement=5000;
    atomic.type=5;
    atomic.cost=55000;









    p.spell_list.push_back(torch);
    p.spell_list.push_back(fireball);
    p.spell_list.push_back(flamethrower);
    p.spell_list.push_back(lightning);
    p.spell_list.push_back(kamehameha);
    p.spell_list.push_back(spiritbomb);

    p.spell_list.push_back(slap);
    p.spell_list.push_back(wave);
    p.spell_list.push_back(icedagger);
    p.spell_list.push_back(icesword);
    p.spell_list.push_back(iciclerain);
    p.spell_list.push_back(zero);

    p.spell_list.push_back(pebble_rain);
    p.spell_list.push_back(rockhurl);
    p.spell_list.push_back(quicksand);
    p.spell_list.push_back(boulder);
    p.spell_list.push_back(volcano);
    p.spell_list.push_back(meteor);

    p.spell_list.push_back(air_wave);
    p.spell_list.push_back(downflow);
    p.spell_list.push_back(upflow);
    p.spell_list.push_back(tornado);
    p.spell_list.push_back(suffocate);
    p.spell_list.push_back(voids);

    p.spell_list.push_back(push);
    p.spell_list.push_back(hurl);
    p.spell_list.push_back(atmosphere);
    p.spell_list.push_back(explode);
    p.spell_list.push_back(implode);
    p.spell_list.push_back(atomic);

    //==================================================== Physical

    punch.name="Punch";
    punch.description="Punch your opponent in the face... hard. Recommended beginner move...";
    punch.power_requirement=0;
    punch.type=100;
    punch.cost=1;

    kick.name="Kick";
    kick.description="Kick your opponent. You know where to aim.";
    kick.power_requirement=10;
    kick.type=100;
    kick.cost=100;

    flurry.name="Flurry";
    flurry.description="A quick combo of attacks.";
    flurry.power_requirement=30;
    flurry.type=100;
    flurry.cost=150;

    dropkick.name="Dropkick";
    dropkick.description="Beat your enemy in the most humiliating way possible (besides punching of course)!";
    dropkick.power_requirement=75;
    dropkick.type=100;
    dropkick.cost=500;

    falconpunch.name="Falcon Punch";
    falconpunch.description="FAAAAAAAAAAAAAALLLLLCOOOOOOOOOOOOOONNNNNNNNN.......";
    falconpunch.power_requirement=500;
    falconpunch.type=100;
    falconpunch.cost=5000;

    dragonfist.name="Dragon Fist";
    dragonfist.description="This is waaay over 9,000...";
    dragonfist.power_requirement=9001;
    dragonfist.type=100;
    dragonfist.cost=100000;

    chucknorris.name="Norris Kick";
    chucknorris.description="A roundhouse kick with the power of Chuck Norris himself! Nothing can survive!";
    chucknorris.power_requirement=100000;
    chucknorris.cost=10000000;
    chucknorris.type=100;


    p.spell_list.push_back(punch);
    p.spell_list.push_back(kick);
    p.spell_list.push_back(flurry);
    p.spell_list.push_back(dropkick);
    p.spell_list.push_back(falconpunch);
    p.spell_list.push_back(dragonfist);
    p.spell_list.push_back(chucknorris);

    //======================================== Sword

    woodsword.name="Wooden Sword";
    woodsword.description="Well... you might be able to get an eye...";
    woodsword.power_requirement=0.1;
    woodsword.type=101;
    woodsword.cost=5;

    dagger.name="Daggers";
    dagger.description="Dual wielded daggers! Tear 'em up!";
    dagger.power_requirement=10;
    dagger.type=101;
    dagger.cost=75;

    sword.name="Sword";
    sword.description="A standard sword. Aim for the heart!";
    sword.power_requirement=50;
    sword.type=101;
    sword.cost=300;

    longsword.name="Longsword";
    longsword.description="Longer reach. More weight. Double damage!";
    longsword.power_requirement=100;
    longsword.type=101;
    longsword.cost=750;

    lightsaber.name="Lighsaber";
    lightsaber.description="A blade of plasma. Insane level armor needed to even survive!";
    lightsaber.power_requirement=1000;
    lightsaber.type=101;
    lightsaber.cost=10000;

    soulsword.name="Soul Sword";
    soulsword.description="Just one touch will suck their very souls from their bodies...";
    soulsword.power_requirement=5000;
    soulsword.type=101;
    soulsword.cost=60000;

    p.spell_list.push_back(woodsword);
    p.spell_list.push_back(dagger);
    p.spell_list.push_back(sword);
    p.spell_list.push_back(longsword);
    p.spell_list.push_back(lightsaber);
    p.spell_list.push_back(soulsword);

    for(int x=0;x<p.spell_list.size();x++){
        p.spell_list[x].unlocked=false;
    }
    return p;
}


