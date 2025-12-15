#include <iostream>
#include <unistd.h> // For usleep
using namespace std;

// ---------- Texting Effect ----------
void typeText(const string &text, int delay = 30000) { // delay in microseconds
    for (char c : text) {
        cout << c;
        cout.flush();
        usleep(delay);
    }
    cout << endl;
}

// ---------- Global Variables ----------
bool isMerciful = false;
bool isRomanticTensionActive = false;
int Blazer_Impression_Score = 0;

// ---------- Function Declarations ----------
void scene_introduction();
void scene_apartment_interrogation();
void scene_street_fight();
void scene_bar_flambae();
void scene_billboard();
void scene_combat_toxic();

// ---------- Main ----------
int main() {
    scene_introduction();
    scene_apartment_interrogation();
    scene_street_fight();
    scene_bar_flambae();
    scene_billboard();
    scene_combat_toxic();

    typeText("\n=== END OF EPISODE ===");
    return 0;
}


// =================================================
// SCENE 1: INTRODUCTION
// =================================================
void scene_introduction() {
    int choice;
    
    typeText("\n========== SCENE 1: INTRODUCTION ==========\n");

    typeText("Robert: Obviously.");
    typeText("Robert: I love him, he's my dad.");
    typeText("Goon: Hmm...");
    typeText("Robert: What does that \"Hmm\" mean? Just say what you want to say.");
    typeText("Goon: It's just when you add 'obviously' it feels a little less obvious.");
    typeText("Goon: So I'll ask again: how do you really feel about your father?\n");

    typeText("CHOICES:");
    typeText("1. Didn't know him well");
    typeText("2. I love my dad");
    typeText("3. He's gone");
    typeText("Choice: ");
    cin >> choice;

    typeText("\nGoon: It's as if maybe it's a little more complicated than you feel comfortable admitting,");
    typeText("Goon: which is completely understandable.\n");

    if (choice == 2) {
        typeText("Robert: Look, I love my dad, all right? I love my dad. That's the truth.");
        typeText("Goon: Loved.");
        typeText("Robert: That's what I said.");
        typeText("Goon: You said 'love.' Your dad's dead.");
        typeText("Robert: Just so sensitive.");
        typeText("Robert: If I didn't love him, we wouldn't be here.");
        typeText("Robert: Why would I be trying to find the man who killed him?");
        typeText("Robert: My nose is bleeding. Thought I was getting emotionally snotty.");
        typeText("Soothing Goon: No, it's probably from when I kicked you in the face.");
    } else if (choice == 1) {
        typeText("Robert: I didn't really know him that well.");
        typeText("Goon: That kind of loss sticks around anyway.");
    } else {
        typeText("Robert: He's gone.");
        typeText("Goon: And you're still standing here because of it.");
    }
    typeText("\n===== End of Scene 1 =====\n");
}

// =================================================
// SCENE 2: APARTMENT INTERROGATION
// =================================================
void scene_apartment_interrogation() {
    int choice;

    typeText("\n========== SCENE 2: APARTMENT INTERROGATION ==========\n");

    typeText("Robert: Yeah. Thanks for reminding me.");
    typeText("Robert: So here's what's going to happen.\n");

    typeText("Robert: I'm going to hang you off the side of this building.");
    typeText("Robert: You're going to tell me where Shroud is.");
    typeText("Robert: Or I'm going to drop you.\n");

    typeText("Soothing Goon: Come on. I thought we were having a breakthrough.");
    typeText("Robert: For being a real piece of shit, you're pretty easy to talk to.");
    typeText("Robert: But I only need one thing. Shroud's location.\n");

    typeText("Soothing Goon: I'm not telling you SHIT!");
    typeText("Robert: See? This is more like what I expected.\n");

    typeText("*Chair scrapes across the floor*");
    typeText("Soothing Goon: I hope Shroud kills you like he killed your father!\n");

    typeText("*Wind howls*");
    typeText("Robert: Windy up here tonight.");
    typeText("Soothing Goon: Why are we outside?");
    typeText("Robert: No telling where you land.\n");

    typeText("Soothing Goon: WAIT! WAIT! STEEL MILL!");
    typeText("Soothing Goon: Llewelyn Steel Works!\n");

    typeText("CHOICES:");
    typeText("1. LET HIM DROP");
    typeText("2. PULL HIM BACK");
    typeText("Choice: ");
    cin >> choice;

    if (choice == 2) {
        isMerciful = true;
        typeText("\nRobert: Honestly, it was nice talking to someone about this stuff.");
        typeText("Robert: I'm really glad I kidnapped you tonight.");
    } else {
        isMerciful = false;
        typeText("\n*Silence follows as the screaming fades*");
    }
    typeText("\n===== End of Scene 2 =====\n");
}

// =================================================
// SCENE 3: STREET FIGHT
// =================================================
void scene_street_fight() {
    int choice;

    typeText("\n========== SCENE 3: STREET FIGHT ==========\n");
    typeText("You see a masked thief holding a crowbar, blocking your path.");
    typeText("This fight is immediate and tactical.\n");

    typeText("CHOICES:");
    typeText("1. Right Hand Punch");
    typeText("2. Left Hand Punch");
    typeText("Choice: ");
    cin >> choice;

    if (choice == 1) {
        typeText("\nYou swing with your right hand.");
        typeText("The thief reads it perfectly and counters with the crowbar!");
        typeText("*You get struck and stagger backward.*");
        typeText("Outcome: You were countered and injured.");
    }
    else if (choice == 2) {
        typeText("\nYou swing with your left hand.");
        typeText("Your punch lands perfectly and knocks out the attacker!");
        typeText("Outcome: Tactical success — enemy down.");
    }
    else {
        typeText("\nInvalid choice — no attack made.");
        typeText("The thug stays aggressive.");
    }

    typeText("\n===== End of Scene 3 =====\n");
}

// =================================================
// SCENE 4: BAR FLAMBAE
// =================================================
void scene_bar_flambae() {
    int choice;

    typeText("\n===== Scene 4: Bar Flambae =====\n");

    typeText("*A glass shatters nearby*  (╯°□°）╯︵ ┻━┻");
    typeText("Mecha Man: What're you doing?");
    typeText("Person: Hey! Bitch!..... Hey! I'm talkin' to you bitch!");
    typeText("Mecha Man: Alright, just so you know, I only turned around cause someone yelled,");
    typeText("not because I'm a bitch or anything.");

    typeText("Flambae: Don't you watch the news? This is a superhero bar.");
    typeText("Mecha Man: Oh, wow, are you a superhero? That's so cool.");
    typeText("Is this your power?");
    typeText("You're like, tell people obvious shit guy?");

    typeText("Flambae: You're really gonna act like you don't remember me?");
    typeText("Mecha Man: Wait, it's coming back to me...");
    typeText("Yeah, it's coming back to me...\n");

    typeText("1. Dr. Don't Do Shit");
    typeText("2. Mr. Wet Ponytail");
    typeText("3. Sunglasses at Night Guy");
    typeText("Choice: ");
    cin >> choice;

    typeText("Oh wait, I know it.");

    if (choice == 1) {
        typeText("You are Dr. Don't Do Shit.");
        typeText("Your deal is you walk up to people, look threatening,");
        typeText("talk a big game, then don't do shit about it.");
        typeText("Also, you're not a real doctor cause you're a fuckin' idiot.");
    }
    else if (choice == 2) {
        typeText("You are Mr. Wet Ponytail.");
        typeText("Your superpower is in your ponytail, which aside from being disgusting,");
        typeText("has the ability to never not be wet.");
        typeText("In battle, you whip it around and anyone it touches fuckin' kills themself.");
    }
    else if (choice == 3) {
        typeText("You are Sunglasses Indoors at Night Guy.");
        typeText("Your superpower is letting everyone know in the room");
        typeText("that you're a douchebag.");
        typeText("Cause you should literally never do that.");
    }
    else {
        typeText("Mecha Man: ...Yeah, I lost it.");
    }

    typeText("Flambae: You good?");
    typeText("Person: Sorry, I choked on my spit.");
    typeText("No, Mecha Bitch. I control the fire--");

    typeText("Mecha Man: The fire?");
    typeText("Flambae: And the flame.");
    typeText("And my skin does not burn.");
    typeText("I am Flambae.");

    typeText("Mecha Man: Wait, oh shit. I do remember you.");
    typeText("You're that shitty villain I busted up.");

    typeText("Flambae: Not anymore, Mecha Dick.");
    typeText("As I literally just said, I am Flambae, a real superhero.");
    typeText("And you are not Mecha Man anymore.");
    typeText("So you need to get the fuck out of here.\n");

    typeText("1. Water");
    typeText("2. Alcohol");
    typeText("Choice: ");
    cin >> choice;

    if (choice == 1) {
        typeText("*You throw water on Flambae*  (っ・ω・)っ💧");
        typeText("Mecha Man: There. The easy way.");
        typeText("Flambae: I've been waiting a long time for this.");
        typeText("*Flambae charges, slips, and knocks himself out*  (x_x)");
    }
    else if (choice == 2) {
        typeText("*You throw alcohol on Flambae*  (っ🔥)っ🥃");
        typeText("*The flames explode upward*  (🔥🔥🔥)");
        typeText("Flambae: OH YOU FUCKED UP.");
    }
    else {
        typeText("Mecha Man: Yeah... bad call.");
    }

    typeText("\n===== End of Scene 4 =====\n");
}

// =================================================
// SCENE 5: BILLBOARD ROMANCE
// =================================================
void scene_billboard() {
    int choice;

    typeText("\n===== Scene 5: Billboard =====\n");

    typeText("*Mecha Man and Blonde Blazer land on the billboard*  (ง•̀_•́)ง");
    typeText("*City lights glow beneath them*  ✨🏙️");

    typeText("Robert: I actually thought you were taking us to sit on it.");
    typeText("Blonde Blazer: Hmm! Oh yeah, that woulda been cool.");
    typeText("But no, this is better cause you can see it.");
    typeText("And it looks like there's a couple up there already.\n");

    typeText("1. I really needed this");
    typeText("2. Thanks for helping me");
    typeText("3. Sorry about the spit thing");
    typeText("Choice: ");
    cin >> choice;

    if (choice == 1) {
        typeText("Robert: All this has been pretty overwhelming, you know.");
        typeText("I don't get out often, and I think I really needed this.");
        typeText("So thank you. For bringing me out.");
        typeText("I had a really great time.");
    }
    else if (choice == 2) {
        typeText("Robert: I really appreciate you coming to my rescue back there.");
        typeText("I still think I could've handled it, but...");
        typeText("Thanks. I should've just said that.");
        typeText("But yep. I'm still talking.");
    }
    else if (choice == 3) {
        typeText("Robert: I know I shouldn't bring it up.");
        typeText("But I am seriously sorry about the whole spitting thing.");
        typeText("Blonde Blazer: Yeah, that's usually like a second date kinda thing with me.");
        typeText("I'm joking. I'm joking.");
        typeText("This is not a date.");
        typeText("Robert: No. Totally. Yeah.");
    }
    else {
        typeText("Robert: Yeah... ignore that.");
    }

    typeText("Blonde Blazer: Don't you worry about it, Robert Roberson.");
    typeText("Robert: How do you know my name?");
    typeText("Blonde Blazer: Whoops!");
    typeText("Robert: What's going on?");
    typeText("Blonde Blazer: Okay, I'll tell you.");
    typeText("But only after you tell me how you ended up with a name like that.");

    typeText("Robert: Oh, you mean a name like Robert Roberson the Third?");
    typeText("Blonde Blazer: The Third?! Three times this happened?");

    typeText("Robert: There was grandpa Bobby.");
    typeText("Then my dad, who everyone called Robbie.");
    typeText("Then me.");
    typeText("Cause I wanted to be taken seriously.");

    typeText("Blonde Blazer: A family tradition.");
    typeText("Robert: In more ways than one.");

    typeText("Robert: Gramps was the first Mecha Man.");
    typeText("He died in the suit before I was born.");
    typeText("Dad was killed fighting Shroud.");
    typeText("That's when I took over.");

    typeText("Blonde Blazer: I'm so sorry. I didn't realize.");
    typeText("Robert: Just your run of the mill sad superhero origin story.");
    typeText("The family tradition is dying in that suit.");
    typeText("Which I guess I don't have to worry about anymore.");

    typeText("Blonde Blazer: I'm not quite drunk enough to share my origin story just yet.");
    typeText("But remind me someday.");
    typeText("Robert: Definitely.");

    typeText("*Blonde Blazer gently touches Robert’s face*  (〃ω〃)");

    typeText("1. Kiss her");
    typeText("2. Let the moment pass");
    typeText("Choice: ");
    cin >> choice;

    if (choice == 1) {
        typeText("*You lean in and kiss her*  ( ˘ ³˘)♥");
        typeText("Blonde Blazer: No.");
        typeText("This... I'm sorry if I gave the wrong impression.");
    }
    else if (choice == 2) {
        typeText("*You hesitate and pull back*  (•_•)");
        typeText("Blonde Blazer: Sorry.");
        typeText("I'm actually here with a purpose.");
    }
    else {
        typeText("Robert: Uh... yeah.");
    }

    typeText("Robert: Oh no.");
    typeText("Blonde Blazer: It's my fault.");
    typeText("Robert: I'm so sorry, I totally misread that--");
    typeText("Blonde Blazer: You didn't.");
    typeText("I mean, you did, but...");
    typeText("The way I went about tonight was a little unprofessional.");

    typeText("Robert: Unprofessional?");
    typeText("I'm not sure that applies but... okay.");

    typeText("\n===== End of Scene 5 =====\n");
}

// =================================================
// SCENE 6: COMBAT – TOXIC FACTORY
// =================================================
void scene_combat_toxic() {
    int choice;

    typeText("\n========== SCENE: COMBAT – TOXIC ==========\n");

    typeText("Mecha Man: Hey, um can I get a copy of that video when we're through here?\n");

    typeText("CHOICES:");
    typeText("1. It's over Shroud");
    typeText("2. Prepare to die");
    typeText("3. I'm here to fuck you up");
    typeText("Choice: ");
    cin >> choice;

    if (isMerciful) {
        typeText("\nMecha Man: Cause it’s over, Shroud.");
        typeText("Mecha Man: And it would be nice to watch that back at a different angle.\n");

        typeText("Soothing Goon: Oh no, it's over Shroud. All this buildup face to face with your father’s killer.");
        typeText("Soothing Goon: And you come in here with that lame shit?\n");
    } else {
        typeText("\nMecha Man: Uh, where the fuck is Shroud?");
        typeText("Soothing Goon: He’ll be here in a bit.");
        typeText("Soothing Goon: After that you let me go I swore that I will fuck you up.\n");
    }

    typeText("Soothing Goon: Oh hey, after our conversation I asked him about your dad.");
    typeText("Soothing Goon: Fun little tidbit, he was very well hydrated.\n");

    typeText("Soothing Goon: It turns out right after Shroud shot him in the chest, your dad pissed his pants");
    typeText("Soothing Goon: Betcha didnt know that, huh?");
    typeText("Soothing Goon: So, after that bullet tore through his insides,");
    typeText("Soothing Goon: he still had enough time to know how absolutely fucked he was\n");

    typeText("Soothing Goon: and just pissed himsef like a little bitch. It was like, so much piss.");
    typeText("Soothing Goon: cause you dad was wearing shorts so it just –\n");

    typeText("CHOICES:");
    typeText("1. PUNT");
    typeText("2. STOMP");
    typeText("Choice: ");
    cin >> choice;

    if (choice == 1) {
        typeText("\n*Robot breaks in, Shroud flies across*");
    } else if (choice == 2) {
        typeText("\n*Robot falls on top of goon*");
    } else {
        typeText("\nInvalid choice.");
    }

    typeText("\nMecha Man: Hey! I get it");
    typeText("Mecha Man: Can we just skip to the part where you reveal your bullshit superpower so we can fight for real?");

    typeText("=== Soothing Goon turns into Toxic ===");
    typeText("Mecha Man: Cool dick, so, you, ug, got some kinda clever supervillain name?");
    typeText("Toxic: You can call me Toxic");
    typeText("Mecha Man: Bro, that work on so many levels for you");
    typeText("Toxic: Yeah, no shit, that’s the point\n");

    typeText("=== During the fight, Mecha Man been corned ===");
    typeText("Toxic: So whaddaya got left on them shields?");
    typeText("Toxic: I said forty percents but boss man says you’re down to twenty-eight, and he is not wrong about these things");
    typeText("Toxic: Good news, buddy. Shroud says he just wants the astral pulse.");
    typeText("Toxic: Which, we all know, isnt really yours anyway.\n");

    typeText("Mecha Man: System Check. Calculate the damage per second hitting shields,");
    typeText("Mecha Man: then tell me how many seconds I need to divert Astral Pulse energy to rocket boosters.");
    typeText("Mecha Man System: 12.89 seconds of damage before critical.\n");

    typeText("Toxic: Oh, hey. Boss man says if you’re planning on diverting puss pow– sorry, pulse power to the boosters, it won’t work.\n");

    typeText("CHOICES:");
    typeText("1. Ignore him");
    typeText("2. You're Bluffing");
    typeText("3. Bullshit");
    typeText("Choice: ");
    cin >> choice;

    typeText("\nToxic: This is a limited time offer dude, What’s up?");
    typeText("Toxic: You were so fucking talkative earlier?\n");

    if (choice == 1) {
        typeText("Toxic: He says you’re not calculating that shit stuck to your leg… dumbass.");
        typeText("Mecha Man: Fuck it");
        typeText("Toxic: Aye. Great. All going to plan. Now get outta there, babe.");
        typeText("Mecha Man: Come on");
        typeText("=== Mecha Man escaped the factory ===");
    } else {
        typeText("Toxic: Talking won't save you.");
        typeText("*Combat continues*");
    }

    typeText("\n===== End of Scene 6 =====\n");
}
