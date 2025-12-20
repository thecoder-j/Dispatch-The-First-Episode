#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <limits>
using namespace std;

bool isMerciful = false; 
int Robert_Mercy_Rating = 0; 
void scene_intro();
void scene_apartment_interrogation();
void scene_street_fight();
void scene_bar_flambae();
void scene_billboard();
void scene_combat_toxic();
int impressionScore = 0;
int publicChaos = 0;
int isRomanticTensionActive = 0;


void printWords(const string &text, int wordDelayMs = 150) {
    stringstream ss(text);
    string word;
    while (ss >> word) {
        cout << word << " " << flush;
        this_thread::sleep_for(chrono::milliseconds(wordDelayMs));
    }
    cout << endl;
}

// Line-by-line printing for actions
void printLines(const string &text, int lineDelayMs = 600) {
    stringstream ss(text);
    string line;
    while (getline(ss, line, '\n')) {
        cout << line << endl;
        this_thread::sleep_for(chrono::milliseconds(lineDelayMs));
    }
}

// Wait for Enter key press
void waitForEnter(const string &prompt = "\n[Press Enter to continue...]") {
    cout << prompt << flush;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Enhanced choice reader with range validation
int readChoice(int min = 1, int max = 3) {
    int choice;
    while (true) {
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter " << min << "-" << max << ": ";
    }
}

// =================================================
// SCENE 1: INTRODUCTION
// =================================================
void scene_intro() {
    int choice;

    waitForEnter("\n[Press Enter to begin Scene 1: Introduction...]");

    cout << "\n========== SCENE 1: INTRODUCTION ==========\n\n";

    printWords("Robert: Obviously.");
    printWords("Robert: I love him, he's my dad.");
    printWords("Goon: Hmm...");
    printWords("Robert: What does that \"Hmm\" mean? Just say what you want to say.");
    printWords("Goon: It's just when you add 'obviously' it feels a little less obvious.");
    printWords("Goon: So I'll ask again: how do you really feel about your father?");

    cout << "\n+---------------------------------------+\n";
    cout << "|  CHOICES:                             |\n";
    cout << "+---------------------------------------+\n";
    cout << "|  1. Didn't know him well              |\n";
    cout << "|  2. I love my dad                     |\n";
    cout << "|  3. He's gone                         |\n";
    cout << "+---------------------------------------+\n";
    cout << "Choice: ";
    choice = readChoice(1, 3);

    printLines("\n");
    printWords("Goon: It's as if maybe it's a little more complicated than you feel comfortable admitting,");
    printWords("Goon: which is completely understandable.");

    if (choice == 2) {
        printLines("\n");
        printWords("Robert: Look, I love my dad, all right? I love my dad. That's the truth.");
        printWords("Goon: Loved.");
        printWords("Robert: That's what I said.");
        printWords("Goon: You said 'love.' Your dad's dead.");
        printWords("Robert: Just so sensitive.");
        printWords("Robert: If I didn't love him, we wouldn't be here.");
        printWords("Robert: Why would I be trying to find the man who killed him?");
        printWords("Robert: My nose is bleeding. Thought I was getting emotionally snotty.");
        printWords("Soothing Goon: No, it's probably from when I kicked you in the face.");
    }
    else if (choice == 1) {
        printLines("\n");
        printWords("Robert: I didn't really know him that well.");
        printWords("Goon: That kind of loss sticks around anyway.");
    }
    else {
        printLines("\n");
        printWords("Robert: He's gone.");
        printWords("Goon: And you're still standing here because of it.");
    }

    cout << "\n========================================\n";
    cout << "         End of Scene 1\n";
    cout << "========================================\n";
}

// =================================================
// SCENE 2: APARTMENT INTERROGATION
// =================================================
void scene_apartment_interrogation() {
    int choice;

    waitForEnter("\n[Press Enter to begin Scene 2: Apartment Interrogation...]");

    cout << "\n========== SCENE 2: APARTMENT INTERROGATION ==========\n\n";

    printWords("Robert: Yeah. Thanks for reminding me.");
    printWords("Robert: So here's what's going to happen.");
    printLines("\n");

    printWords("Robert: I'm going to hang you off the side of this building.");
    printWords("Robert: You're going to tell me where Shroud is.");
    printWords("Robert: Or I'm going to drop you.");
    printLines("\n");

    printWords("Soothing Goon: Come on. I thought we were having a breakthrough.");
    printWords("Robert: For being a real piece of shit, you're pretty easy to talk to.");
    printWords("Robert: But I only need one thing. Shroud's location.");
    printLines("\n");

    printWords("Soothing Goon: I'm not telling you SHIT!");
    printWords("Robert: See? This is more like what I expected.");
    printLines("\n");

    printLines("*Chair scrapes across the floor*");
    printWords("Soothing Goon: I hope Shroud kills you like he killed your father!");
    printLines("\n");

    printLines("*Wind howls*");
    printWords("Robert: Windy up here tonight.");
    printWords("Soothing Goon: Why are we outside?");
    printWords("Robert: No telling where you land.");
    printLines("\n");

    printWords("Soothing Goon: WAIT! WAIT! STEEL MILL!");
    printWords("Soothing Goon: Llewelyn Steel Works!");

    this_thread::sleep_for(chrono::milliseconds(1000));

    // CRITICAL MORAL CHOICE
    cout << "\n+=======================================+\n";
    cout << "|  THE MORAL CROSSROADS                 |\n";
    cout << "+=======================================+\n";
    cout << "|  1. LET HIM DROP                      |\n";
    cout << "|     (Ruthless Efficiency)             |\n";
    cout << "|                                       |\n";
    cout << "|  2. PULL HIM BACK                     |\n";
    cout << "|     (Compassion, Restraint)           |\n";
    cout << "+=======================================+\n";
    cout << "Choice: ";
    choice = readChoice(1, 2);

    // UPDATE GLOBAL VARIABLES BASED ON CHOICE
    if (choice == 2) {
        // PULL HIM BACK - Mercy path
        isMerciful = true;
        Robert_Mercy_Rating += 10;
        
        printLines("\n*You pull him back onto the roof*");
        printWords("Robert: Honestly, it was nice talking to someone about this stuff.");
        printWords("Robert: I'm really glad I kidnapped you tonight.");
        
        cout << "\n[✓ MERCY PATH CHOSEN - isMerciful = TRUE]\n";
        cout << "[Robert shows compassion even to enemies]\n";
        
    } else {
        // LET HIM DROP - Ruthless path
        isMerciful = false;
        Robert_Mercy_Rating -= 5;
        
        printLines("\n*Silence follows as the screaming fades*");
        
        cout << "\n[✗ RUTHLESS PATH CHOSEN - isMerciful = FALSE]\n";
        cout << "[Robert prioritizes efficiency over mercy]\n";
    }
    
    // =================================================
    // STATUS
    // =================================================
    cout << "\n+======================================+\n";
    cout << "|          MORAL STATUS                 |\n";
    cout << "+======================================+\n";
    cout << "|  Mercy Path: " << (isMerciful ? "TRUE" : "FALSE") << "               |\n";
    cout << "|  Robert's Mercy Rating: " << Robert_Mercy_Rating << "          |\n";
    cout << "+======================================+\n\n";

    cout << "\n========================================\n";
    cout << "         End of Scene 2\n";
    cout << "========================================\n";
}

// =================================================
// SCENE 3: STREET FIGHT
// =================================================
void scene_street_fight() {
    int choice;
    waitForEnter("\n[Press Enter to begin Scene: Street Fight...]");

    cout << "\n========== SCENE 3: STREET FIGHT ==========\n\n";

    // Dialogue
    printWords("Mecha Man: Hey, assholes. Yeah, all you assholes. Pretty disrespectful for you to be doing that in front of me.");
    printWords("Red Ski Mask: Hey, who are you calling assholes, asshole?");
    printWords("Orange Ski Mask: I'll handle this idiot. Who the fuck are you? Yeah, you, go-fucking-hobo-ranger.");
    printWords("Mecha Man: Right now, I’m someone with nothing to lose, which is probably bad news for you.");
    printWords("Red Ski Mask: Well, with nothing you have, you’re about to lose again.");
    printWords("Mecha Man: I’m enough to pack a fucking Skittles idiot like you.");
    printWords("Mecha Man: Goddammit Look, you’re hurt, you’re not thinking straight. You don’t want to fight someone who knows which hand every punch is coming from.");
    printWords("Red Ski Mask: (Swings)");
    printWords("Mecha Man: Left.");
    printWords("(Mecha Man dodges the first swing)");
    printWords("Red Ski Mask: (Swings again)");
    printWords("Mecha Man: Right.");
    printWords("(Mecha Man dodges the second swing)");
    printWords("Red Ski Mask: (Winds up for another)");
    printWords("Mecha Man: Left.");
    printWords("(Mecha Man counters and strikes Red Ski Mask, knocking him back)");
    printWords("Mecha Man: Whatever the case, I’m going to have to deal with a pack of fucking Skittles idiots like you. God dammit.");
    printWords("Orange Ski Mask: (Stepping forward) Hey! You want some too, old man?");
    printWords("Mecha Man: (Sighs) Look, I’m trying to be nice here. Your friend already learned his lesson. You really want to be next?");
    printWords("Orange Ski Mask: I'm gonna break your other arm, you piece of—");
    printWords("Blazer: (Intervening)");
    printWords("(Orange Ski Mask and Red Ski Mask retreat into the alley)");
    printWords("Blazer: Hi, I’m Blazer. I work over at Superhero Dispatch Network. Hey,");
    printWords("Mecha Man: I... yeah, I know who you are. You’re like, famous.");
    printWords("Mecha Man: I don’t know about that. I’m just a corporate hero for hire. You’re the real deal. You’re the famous one.");
    printWords("Blazer: I don't think \"infamous\" is the same as famous, but... oh god, your arm! Fuck!");
    printWords("Mecha Man: Oh yeah, that’s gross.");
    printWords("Blazer: Yeah, you look like some kind of mime DJ. Let me see it. I’ll help you. Usually, it dislocates the other way.");
    printWords("Mecha Man: Okay, but have you done this before? 'Cause maybe—");
    printWords("(Sound of a loud, wet bone snap)");
    printWords("Mecha Man: Okay. Wow. That’s... that’s okay. Thank you.");

    // Player tactical choice
    cout << "\n+---------------------------------------+\n";
    cout << "|  CHOICE: Tactical Move                |\n";
    cout << "+---------------------------------------+\n";
    cout << "|  1. Right Hand Punch                  |\n";
    cout << "|     (Fails - Countered by Crowbar)   |\n";
    cout << "|  2. Left Hand Punch                   |\n";
    cout << "|     (Success - Knockout)              |\n";
    cout << "+---------------------------------------+\n";
    cout << "Choice: ";
    choice = readChoice(1, 2);

    if (choice == 1) {
        printLines("\n*You throw a Right Hand Punch*");
        printWords("Red Ski Mask counters and strikes you with the crowbar!");
        printLines("*You stagger back, dazed and injured.*");
        printWords("[GAME OVER - Tactical Failure]");
    } else {
        printLines("\n*You throw a Left Hand Punch*");
        printWords("Direct hit! Red Ski Mask is knocked out cold!");
        printWords("Orange Ski Mask sees the result and retreats.");
        printWords("[SUCCESS - Tactical Efficiency Achieved]");
    }

    cout << "\n========================================\n";
    cout << "         End of Street Fight Scene\n";
    cout << "========================================\n";
}

/* ---------- Scene 4: Bar Flambae ---------- */
void scene_bar_flambae() {
    int choice;

    // Wait for player to start the scene
    waitForEnter("\n[Press Enter to begin Scene 4...]");
    
    cout << "\n=========================================\n";
    cout << "     SCENE 4: THE SUPERHERO BAR\n";
    cout << "=========================================\n\n";

    printLines("*CRASH! A glass shatters nearby*  (╯°□°）╯︵ ┻━┻");
    this_thread::sleep_for(chrono::milliseconds(500));
    
    printWords("Mecha Man: What're you doing?");
    printWords("Person: Hey! Bitch!..... Hey! I'm talkin' to you, bitch!");
    printWords("Mecha Man: Alright, just so you know, I only turned around cause someone yelled, not because I'm a bitch or anything.");

    printWords("Person: Don't you watch the news? This is a superhero bar.");
    printWords("Mecha Man: Oh, wow, are you a superhero? That's so cool.");
    printWords("Is this your power?");
    printWords("You're like, tell people obvious shit guy?");

    printWords("Person: You're really gonna act like you don't remember me?");
    printWords("Mecha Man: Wait, it's coming back to me...");
    printWords("Yeah, it's coming back to me...");

    // Character identity choice
    cout << "\n+---------------------------------------+\n";
    cout << "|  Choose Your Insult:                  |\n";
    cout << "+---------------------------------------+\n";
    cout << "|  1. Dr. Don't Do Shit                 |\n";
    cout << "|  2. Mr. Wet Ponytail                  |\n";
    cout << "|  3. Sunglasses at Night Guy           |\n";
    cout << "+---------------------------------------+\n";
    cout << "Choice: ";
    choice = readChoice(1, 3);

    printWords("Oh wait, I know it.");

    if (choice == 1) {
        printWords("You are Dr. Don't Do Shit.");
        printWords("Your deal is you walk up to people, look threatening, talk a big game, then don't do shit about it.");
        printWords("Also, you're not a real doctor cause you're a fuckin' idiot.");
        impressionScore += 1;  // Witty comeback
        publicChaos += 1;      // Causing a scene
    }
    else if (choice == 2) {
        printWords("You are Mr. Wet Ponytail.");
        printWords("Your superpower is in your ponytail, which aside from being disgusting, has the ability to never not be wet.");
        printWords("In battle, you whip it around and anyone it touches fuckin' kills themself.");
        impressionScore += 2;  // Most creative/disgusting
        publicChaos += 2;      // People are grossed out
    }
    else if (choice == 3) {
        printWords("You are Sunglasses Indoors at Night Guy.");
        printWords("Your superpower is letting everyone know in the room that you're a douchebag.");
        printWords("Cause you should literally never do that.");
        impressionScore += 1;  // Solid burn
        publicChaos += 1;
    }
    
    printLines("*Scattered laughter around the bar*");
    printLines("*Someone in the corner chokes on their drink*");
    
    printWords("Person: You good?");
    printWords("Woman: Sorry, I choked on my spit.");
    printWords("Person: No, Mecha Bitch. I control the fire--");

    printWords("Mecha Man: The fire?");
    printWords("Person: And the flame.");
    printWords("And my skin does not burn.");
    printWords("I am Flambae.");

    printWords("Mecha Man: Wait, oh shit. I do remember you.");
    printWords("You're that shitty villain I busted up.");

    printWords("Flambae: Not anymore, Mecha Dick.");
    printWords("As I literally just said, I am Flambae, a real superhero.");
    printWords("And you are not Mecha Man anymore.");
    printWords("So you need to get the fuck out of here.");

    printLines("\n*Flambae's body ignites with flames*  🔥");
    this_thread::sleep_for(chrono::milliseconds(800));

    // Water or Alcohol choice - THE CRITICAL DECISION
    cout << "\n+---------------------------------------+\n";
    cout << "|  What do you throw?                   |\n";
    cout << "+---------------------------------------+\n";
    cout << "|  1. Water (Efficient)                 |\n";
    cout << "|  2. Alcohol (Memorable)               |\n";
    cout << "+---------------------------------------+\n";
    cout << "Choice: ";
    choice = readChoice(1, 2);

    if (choice == 1) {
        // WATER - Efficient but unremarkable
        printLines("\n*You grab a glass of water and throw it*  (っ・ω・)っ💧");
        printLines("*SSSSSSS - Steam rises as the flames extinguish*");
        
        printWords("Mecha Man: There. The easy way.");
        printWords("Flambae: I've been waiting a long time for this.");
        printLines("*Flambae charges forward, slips on the wet floor*");
        printLines("*THUD*  (x_x)");
        printWords("Flambae: ...ow.");
        
        printLines("*Coupe and Punch-up rush over to help*");
        printWords("Dobble: Hey, why don't you do us a favor and step out of this bar.");        
        printWords("Mecha Man: I get it. Can you just tell Blazer I'm outside?");
        printLines("*Dopple duplicates himself, blocking the door*");
        printWords("Dopple: OUT!");
        printWords("Mecha Man: Relax! I'm leaving.");
        
        publicChaos += 1;       // Minor scene
        impressionScore += 2;   // Competent and efficient
        
        printLines("\n*Blonde Blazer watches from across the room*");
        printWords("Blonde Blazer (thinking): Well... that was sensible.");
        printWords("Blonde Blazer (thinking): Boring, but sensible.");
        
        cout << "\n[Blonde Blazer noticed your tactical efficiency]\n";
        
    } else if (choice == 2) {
        // ALCOHOL - Dramatic and unforgettable (PROJECT REQUIREMENT: Higher impression!)
        printLines("\n*You grab a bottle of alcohol and throw it*  (っ🔥)っ🥃");
        this_thread::sleep_for(chrono::milliseconds(500));
        printLines("*WHOOOOOOSH!*");
        printLines("*The flames EXPLODE upward in a massive fireball*  🔥🔥🔥");
        
        printWords("Flambae: AAAHHHHHHH!");
        printWords("Mecha Man: Sorry, which way was that?");
        
        printLines("*A waiter hurries over with a tray*");
        printWords("Waiter: HEY! What the hell?!");
        printWords("Coupe: No, Punch-up, you are literally fanning the flames right now!");
        printWords("Punch-up: Shit, you're right! Anybody got a rug?");
        printWords("Flambae: FUCK! FUCK! IT BURNS!");
        
        printLines("*Flambae runs around in circles, hair ablaze*");
        printLines("*CRASH* *He knocks over three tables*");
        printLines("*Flambae finally rushes out the door, still screaming*");
        
        printWords("Punch-up: You gotta drop and roll, lad!");
        printWords("Mecha Man: I thought he doesn't burn?");
        printWords("Coupe: Some people become scared before they even know they're hurt...");
        printWords("Coupe: ...like babies.");
        printLines("*Coupe shakes his head and walks out after Flambae*");
        
        this_thread::sleep_for(chrono::milliseconds(1000));
        printLines("*Awkward silence fills the bar*");
        
        printWords("Dopple: HEY! Mecha Dick. Get the FUCK out of here. NOW.");
        printWords("Mecha Man: I get it. Can you just tell Blazer I'm outside?");
        printLines("*Dopple duplicates himself, both copies glaring*");
        printWords("Dopple: OUT!");
        printWords("Mecha Man: Relax! I'm leaving.");
        
        publicChaos += 3;       // MAJOR chaos
        impressionScore += 5;   // MEMORABLE - PROJECT REQUIREMENT!
        
        printLines("\n*Blonde Blazer is wide-eyed, hand covering her mouth*");
        this_thread::sleep_for(chrono::milliseconds(800));
        printWords("Blonde Blazer (thinking): Holy shit.");
        printWords("Blonde Blazer (thinking): That was... I mean, terrible, but...");
        printWords("Blonde Blazer (thinking): I cannot believe he just did that.");
        printLines("*She's fighting back a smile*");
        printWords("Blonde Blazer (thinking): ...I will never forget this moment.");
        
        cout << "\n[★★★ UNFORGETTABLE IMPRESSION - Blonde Blazer will remember this ★★★]\n";
    }

    // End scene summary
    cout << "\n=========================================\n";
    cout << "         End of Scene 4\n";
    cout << "=========================================\n";
    
    // Show status with context
    cout << "\n+======================================+\n";
    cout << "|      REPUTATION UPDATE               |\n";
    cout << "+======================================+\n";
    
    if (impressionScore >= 6) {
        cout << "|  Blazer's Memory: VIVID ***          |\n";
    } else if (impressionScore >= 3) {
        cout << "|  Blazer's Memory: Notable **         |\n";
    } else {
        cout << "|  Blazer's Memory: Forgettable *      |\n";
    }
    
    if (publicChaos >= 3) {
        cout << "|  Bar Status: TOTAL CHAOS (!)         |\n";
    } else if (publicChaos >= 2) {
        cout << "|  Bar Status: Disrupted (!)           |\n";
    } else {
        cout << "|  Bar Status: Under Control (OK)      |\n";
    }
    
    cout << "|                                      |\n";
    cout << "|  Impression Score: " << impressionScore << "/10    |\n";
    cout << "|  Chaos Level: " << publicChaos << "/10         |\n";
    cout << "+======================================+\n\n";
}

// ---------- Scene 5: Billboard ----------
void scene_billboard() {
    int choice;

    // Wait for player to start the scene
    waitForEnter("\n[Press Enter to begin Scene 5...]");
    
    cout << "\n=========================================\n";
    cout << "      SCENE 5: BILLBOARD ROMANCE\n";
    cout << "=========================================\n\n";

    // Scene setup
    printLines("*Mecha Man flies through the night sky*");
    printLines("*He lands in the alleyway behind the bar*");
    this_thread::sleep_for(chrono::milliseconds(800));
    printLines("*Blonde Blazer walks out, holding two drinks*");

    printWords("Blonde Blazer: Hey, I couldn't find you.");
    printWords("Mecha Man: Uh, it's cool. I was just admiring the art on this dumpster.");
    printWords("Can't tell why anyone would put those words together.");
    printLines("*He gestures to graffiti reading 'FART BART'*");

    printWords("Mecha Man: Why're you holding two drinks?");
    printWords("Blonde Blazer: Nightcap?");
    printWords("Mecha Man: You're trouble.");
    printWords("Blonde Blazer: Actually, according to the bartender, that's exactly what you are.");

    this_thread::sleep_for(chrono::milliseconds(600));
    printWords("Blonde Blazer: What happened in there?");
    printWords("Blonde Blazer: I walk out and the bartender's pissed. The whole energy is awkward...");
    printWords("...And why did it smell like burnt hair?");

    printWords("Mecha Man: I got a little fired up with the guy, but he ran off before anything happened.");
    printWords("Blonde Blazer: Oh, you got fired up?");
    printWords("Mecha Man: Yeah. Does that not sound convincing enough?");
    printWords("Blonde Blazer: Hold these. I know a place. It's a little out there. Easier if we fly.");

    printLines("\n*They take to the sky*");
    printLines("*City lights blur beneath them*  ✨");
    this_thread::sleep_for(chrono::milliseconds(1000));
    printLines("*They land gracefully on a massive billboard*  (ง•̀_•́)ง");
    printLines("*The city sprawls below, glittering like stars*  🏙️");

    printWords("Robert: I actually thought you were taking us to sit on it.");
    printWords("Blonde Blazer: Hmm! Oh yeah, that woulda been cool. But no, this is better 'cause you can see it.");
    printWords("And it looks like there's a couple up there already.");

    this_thread::sleep_for(chrono::milliseconds(800));

    // First choice - Opening up
    cout << "\n+---------------------------------------+\n";
    cout << "|  How do you respond?                  |\n";
    cout << "+---------------------------------------+\n";
    cout << "|  1. I really needed this              |\n";
    cout << "|     (Vulnerable and honest)           |\n";
    cout << "|                                       |\n";
    cout << "|  2. Thanks for helping me             |\n";
    cout << "|     (Grateful but guarded)            |\n";
    cout << "|                                       |\n";
    cout << "|  3. Sorry about the spit thing        |\n";
    cout << "|     (Self-deprecating humor)          |\n";
    cout << "+---------------------------------------+\n";
    cout << "Choice: ";
    choice = readChoice(1, 3);

    if (choice == 1) {
        printWords("Robert: All this has been pretty overwhelming, you know.");
        printWords("I don't get out often, and I think I really needed this.");
        printWords("So thank you. For bringing me out. I had a really great time.");
        
        impressionScore += 2;  // Vulnerable, emotionally open
        
        printLines("\n*Blonde Blazer's expression softens*");
        printWords("Blonde Blazer (thinking): He's more open than I expected...");
        
    } else if (choice == 2) {
        printWords("Robert: I really appreciate you coming to my rescue back there.");
        printWords("I still think I could've handled it, but... Thanks. I should've just said that.");
        printWords("But yep. I'm still talking.");
        
        impressionScore += 1;  // Polite but slightly awkward
        
        printLines("\n*Blonde Blazer smiles at his rambling*");
        printWords("Blonde Blazer (thinking): He's sweet when he's nervous.");
        
    } else if (choice == 3) {
        printWords("Robert: I know I shouldn't bring it up, but I am seriously sorry about the whole spitting thing.");
        printWords("Blonde Blazer: Yeah, that's usually like a second date kinda thing with me.");
        this_thread::sleep_for(chrono::milliseconds(800));
        printWords("Blonde Blazer: I'm joking. I'm joking. This is not a date.");
        printWords("Robert: No. Totally. Yeah.");
        
        impressionScore += 3;  // Confident humor, addresses awkwardness
        
        printLines("\n*Blonde Blazer laughs genuinely*");
        printWords("Blonde Blazer (thinking): He's funny. I like that.");
    }

    this_thread::sleep_for(chrono::milliseconds(1000));
    printWords("Blonde Blazer: Don't you worry about it, Robert Roberson.");
    
    this_thread::sleep_for(chrono::milliseconds(800));
    printWords("Robert: How do you know my name?");
    this_thread::sleep_for(chrono::milliseconds(600));
    printWords("Blonde Blazer: Whoops!");
    this_thread::sleep_for(chrono::milliseconds(500));
    printWords("Robert: What's going on?");
    
    printWords("Blonde Blazer: Okay, I'll tell you. But only after you tell me how you ended up with a name like that.");

    printWords("Robert: Oh, you mean a name like Robert Roberson the Third?");
    printWords("Blonde Blazer: The Third?! Three times this happened?");
    
    printWords("Robert: There was grandpa Bobby. Then my dad, who everyone called Robbie.");
    printWords("Then me. Because I wanted to be taken seriously.");
    printWords("Blonde Blazer: A family tradition.");
    printWords("Robert: In more ways than one.");

    this_thread::sleep_for(chrono::milliseconds(800));
    printWords("Robert: Gramps was the first Mecha Man. He died in the suit before I was born.");
    printWords("Dad was killed fighting Shroud. That's when I took over.");
    printWords("There was a little inheritance and life insurance money, but...");

    printWords("Blonde Blazer: I'm so sorry. I didn't realize.");
    printWords("Robert: Just your run-of-the-mill sad superhero origin story.");
    printWords("The family tradition is dying in that suit.");
    printWords("Which I guess I don't have to worry about anymore.");

    printWords("Blonde Blazer: I'm not quite drunk enough to share my origin story just yet.");
    printWords("But remind me someday.");
    printWords("Robert: Definitely.");

    this_thread::sleep_for(chrono::milliseconds(1200));
    printLines("\n*Blonde Blazer shifts closer to Robert*");
    printLines("*The city noise fades away*");
    printLines("*She gently reaches up and touches his face*  (〃ω〃)");
    this_thread::sleep_for(chrono::milliseconds(800));
    printLines("*She carefully removes his mask*  ( ﾉ ﾟｰﾟ)ﾉ");
    printLines("*Her eyes meet his*");
    this_thread::sleep_for(chrono::milliseconds(1000));
    printWords("Blonde Blazer: We can work with this.");

    // THE CRITICAL ROMANCE CHOICE
    cout << "\n+---------------------------------------+\n";
    cout << "|  What do you do?                      |\n";
    cout << "+---------------------------------------+\n";
    cout << "|  1. Kiss her                          |\n";
    cout << "|     (Bold, vulnerable, passionate)    |\n";
    cout << "|                                       |\n";
    cout << "|  2. Let the moment pass               |\n";
    cout << "|     (Patient, emotionally aware)      |\n";
    cout << "+---------------------------------------+\n";
    cout << "Choice: ";
    choice = readChoice(1, 2);

    if (choice == 1) {
        // KISS - Bold but creates complicated tension
        printLines("\n*You lean in slowly*");
        printLines("*Your lips meet hers*  ( ˘ ³˘)♥");
        this_thread::sleep_for(chrono::milliseconds(1200));
        printLines("*For a brief moment, she kisses back*");
        printLines("*Then she pulls away gently, hand on your chest*");
        
        printWords("Blonde Blazer: No. This... I'm sorry if I gave the wrong impression.");
        printWords("Robert: Oh god, I--");
        printWords("Blonde Blazer: You didn't misread anything. That's the problem.");
        
        isRomanticTensionActive = true;  // REQUIRED BY PROJECT!
        impressionScore += 3;  // Memorable, shows vulnerability
        publicChaos += 1;  // Public display
        
        printLines("\n*An awkward but electric silence*");
        this_thread::sleep_for(chrono::milliseconds(800));
        printWords("Blonde Blazer (thinking): Dammit. This is exactly what I was afraid of.");
        
        cout << "\n[♥ ROMANTIC TENSION: ACTIVE - Kiss created complicated feelings ♥]\n";
        
    } else if (choice == 2) {
        // DON'T KISS - Shows emotional intelligence
        printLines("\n*You hesitate, reading the moment*  (•_•)");
        printLines("*You pull back slightly, giving her space*");
        
        printWords("Robert: This feels... complicated.");
        this_thread::sleep_for(chrono::milliseconds(600));
        printWords("Blonde Blazer: It is. And I appreciate you sensing that.");
        
        isRomanticTensionActive = true;  // REQUIRED BY PROJECT!
        impressionScore += 4;  // Emotional maturity = very attractive
        
        printLines("\n*Blonde Blazer looks both relieved and... disappointed?*");
        this_thread::sleep_for(chrono::milliseconds(800));
        printWords("Blonde Blazer (thinking): Why does doing the right thing feel this frustrating?");
        
        cout << "\n[♥ ROMANTIC TENSION: ACTIVE - Unresolved chemistry ♥]\n";
    }

    this_thread::sleep_for(chrono::milliseconds(1000));
    
    // Aftermath
    printWords("Robert: Oh no.");
    printWords("Blonde Blazer: It's my fault.");
    printWords("Robert: I'm so sorry, I totally misread that--");
    printWords("Blonde Blazer: You didn't. I mean, you did, but...");
    printWords("The way I went about tonight was a little unprofessional.");

    printWords("Robert: Unprofessional? I'm not sure that applies but... okay.");

    printWords("Blonde Blazer: I'm actually here on official business.");
    printWords("That's how I know your name. That's the proposition I mentioned right before you spit in my mouth--");
    printWords("Robert: Still mortified about that.");
    printWords("Blonde Blazer: It's fine. Do you remember a superhero named Trackstar?");
    
    printWords("Robert: Remember? Of course. He's like family I haven't talked to in a while. What about him?");
    printWords("Blonde Blazer: I work with him at SDN. He recommended you.");
    printWords("He mentioned he worked with your father.");
    
    printWords("Robert: Yeah, he was the youngest member of the Brave Brigade.");
    printWords("Kind of my babysitter for a while. How's he doing?");
    printWords("Blonde Blazer: He's doing great. He's why I'm here.");

    this_thread::sleep_for(chrono::milliseconds(1000));
    
    // The Offer
    printWords("Blonde Blazer: Robert, I would like to make you an offer.");
    printWords("In exchange for dispatching and mentoring some of our rookie heroes,");
    printWords("SDN can make you Mecha Man again.");
    printWords("But this time with all the resources that a company as big as ours has at their disposal.");
    printWords("No more paying out of pocket for repairs, support staff, the whole shebang.");

    printWords("Robert: My suit was totally destroyed...");
    printWords("Blonde Blazer: I saw the report, studied the footage.");
    printWords("It's not totally destroyed, just mostly.");
    
    printWords("Big investment. It'll take considerable time and money to get the suit repaired");
    printWords("and missing pieces replaced.");
    printWords("Plenty of time to learn how to dispatch and level up some heroes on our roster.");
    
    this_thread::sleep_for(chrono::milliseconds(800));
    printWords("Your experience, work ethic, perspective—it's all invaluable.");
    printWords("Share it, Robert. You have a lot left to give.");

    // End scene summary
    cout << "\n=========================================\n";
    cout << "         End of Scene 5\n";
    cout << "=========================================\n";
    
    // Show status with context
    cout << "\n+======================================+\n";
    cout << "|      RELATIONSHIP UPDATE             |\n";
    cout << "+======================================+\n";
    
    if (isRomanticTensionActive) {
        cout << "|  Romance Status: ACTIVE <3 <3 <3     |\n";
    } else {
        cout << "|  Romance Status: ERROR - NOT SET!    |\n";
    }
    
    if (impressionScore >= 10) {
        cout << "|  Blazer's Interest: VERY HIGH        |\n";
    } else if (impressionScore >= 7) {
        cout << "|  Blazer's Interest: HIGH             |\n";
    } else if (impressionScore >= 4) {
        cout << "|  Blazer's Interest: MODERATE         |\n";
    } else {
        cout << "|  Blazer's Interest: LOW              |\n";
    }
    
    cout << "|                                      |\n";
    cout << "|  Total Impression: " << impressionScore << "/15               |\n";
    cout << "|  Public Chaos: " << publicChaos << "/10                   |\n";
    cout << "+======================================+\n\n";
}

// =================================================
// SCENE 5: COMBAT – TOXIC FACTORY
// =================================================
void scene_combat_toxic() {
    int choice;

    waitForEnter("\n[Press Enter to begin Scene 5: Combat - Toxic...]");

    cout << "\n========== SCENE 5: COMBAT – TOXIC ==========\n\n";

    printWords("Mecha Man: Hey, uh, can I get a copy of that video when we're done here?");

    cout << "\n+---------------------------------------+\n";
    cout << "|  CHOICES:                             |\n";
    cout << "+---------------------------------------+\n";
    cout << "|  1. It's over, Shroud                 |\n";
    cout << "|  2. Prepare to die                    |\n";
    cout << "|  3. I'm here to fuck you up           |\n";
    cout << "+---------------------------------------+\n";
    cout << "Choice: ";
    choice = readChoice(1, 3);

    if (isMerciful) {
        printLines("\n");
        printWords("Mecha Man: Cause it's over, Shroud.");
        printWords("Mecha Man: And I'd like to watch this from a different angle.");
    } else {
        printLines("\n");
        printWords("Soothing Goon: After you let me go, I swore I'd fuck you up.");
    }

    printLines("\n");
    printWords("Soothing Goon: Funny thing about your dad.");
    printWords("Soothing Goon: After Shroud shot him, he pissed himself.");
    printWords("Soothing Goon: He knew he was fucked.");
    printLines("\n");

    printWords("Mecha Man: Can we skip to the part where you reveal your bullshit power?");
    printLines("*Goon mutates*");
    printWords("Toxic: Name's Toxic.");
    printWords("Mecha Man: Yeah, that tracks.");
    printLines("\n");

    printWords("Toxic: Shields at twenty-eight percent.");
    printWords("Toxic: Boss says he just wants the Astral Pulse.");

    cout << "\n+---------------------------------------+\n";
    cout << "|  CHOICES:                             |\n";
    cout << "+---------------------------------------+\n";
    cout << "|  1. Ignore him                        |\n";
    cout << "|  2. You're bluffing                   |\n";
    cout << "|  3. Bullshit                          |\n";
    cout << "+---------------------------------------+\n";
    cout << "Choice: ";
    choice = readChoice(1, 3);

    if (choice == 1) {
        printLines("\n");
        printWords("Toxic: You're not accounting for what's stuck to your leg, dumbass.");
        printWords("Mecha Man: Fuck it.");
        printLines("*Boosters ignite*");
        printWords("Mecha Man escapes the factory.");
    } else {
        printLines("\n");
        printWords("Toxic: Talking won't save you.");
        printLines("*Combat intensifies*");
    }

     // =================================================
    // STATUS SUMMARY
    // =================================================
    cout << "\n+======================================+\n";
    cout << "|          COMBAT STATUS                |\n";
    cout << "+======================================+\n";
    cout << "|  Mercy Path: " << (isMerciful ? "TRUE" : "FALSE") << "               |\n";

    if (impressionScore >= 5) {
        cout << "|  Mecha Man's Impression: MEMORABLE   |\n";
    } else if (impressionScore >= 3) {
        cout << "|  Mecha Man's Impression: Notable     |\n";
    } else {
        cout << "|  Mecha Man's Impression: Minor       |\n";
    }

    if (publicChaos >= 3) {
        cout << "|  Chaos Level: HIGH (!)                |\n";
    } else if (publicChaos >= 2) {
        cout << "|  Chaos Level: Medium (!)              |\n";
    } else {
        cout << "|  Chaos Level: Low (OK)               |\n";
    }

    cout << "|  Impression Score: " << impressionScore << "/10          |\n";
    cout << "|  Public Chaos: " << publicChaos << "/10             |\n";
    cout << "+======================================+\n\n";
    
    cout << "\n========================================\n";
    cout << "         End of Scene 5\n";
    cout << "========================================\n";
}

/* ---------- Standalone Main ---------- */
int main() {
    cout << "\n";
    cout << "+=============================================+\n";
    cout << "|                                             |\n";
    cout << "|            DISPATCH: Robert's Story         |\n";
    cout << "|              Scene 1,2,3,4,5,6              |\n";
    cout << "|                                             |\n";
    cout << "+=============================================+\n";
    
    scene_intro();
    scene_apartment_interrogation();
    scene_street_fight();
    scene_bar_flambae();
    scene_billboard();
    scene_combat_toxic();
    
    
    cout << "\n[Press Enter to Exit]";
    cin.get();
    return 0;
}


