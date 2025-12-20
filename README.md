# Dispatch Decision Engine - Robert's Story
**A C++ Text-Based Visual Novel**

---

## ( ﾉ ﾟｰﾟ)ﾉ Project Overview

*Jamie, here!* This project was crafted by 3 novices in coding: Lee, Rodge, and of course, the writer of this README, Jamie (´▽`ʃ♡ƪ). It was difficult to start but, with the help of Youtube tutorials, countless revisions, and the fear of failing this subject, we came up with the final output that we can be proud of.

This a text-based visual novel inspired by *Dispatch*, featuring the character Robert as he navigates the critical moment of transitioning from active superhero to dispatcher. The program implements branching narrative paths where player choices determine character relationships, moral alignment, and story outcomes.

**Key Features:**
- 6 interactive scenes with multiple decision points
- Character relationship tracking
- Text effects with word-by-word dialogue display
- A variable system tracking moral choices and relationships
- Multiple endings based on accumulated decisions 💥

---

## 🎮 How to Play

### Compilation & Running

```bash
# Compile the program
1. Open OnlineGDB and select C++ as the language.
2. Paste your code into the editor.
3. Set the C++ standard to C++11:
- Click on Menu → Language Options → Compiler Options.
- Select C++11 from the dropdown.

# Run the program
4. Run the program by clicking the Run button.
```

### Controls
- Enter numerical choices (1, 2, 3, etc.) when asked
- Press Enter to advance between scenes
- Follow on-screen prompts for all interactions

---

## Technicals

### Global Variables

The program uses four main global variables to track player decisions across all scenes:

```cpp
bool isMerciful = false;               // Tracks whether Robert is merciful
int impressionScore = 0;              // Tracks Blonde Blazer's perception of Robert (0-15)
int publicChaos = 0;                  // Tracks public disturbances caused (0-10)
bool isMerciful = false;              // Tracks Robert's moral alignment (compassionate vs ruthless)
bool isRomanticTensionActive = false; // Tracks whether romance route is activated
```

**Why Global Variables?**
It is declared outside of all of the functions and blocks, at the top of the program. They can be accessed from any portion of the program. This creates meaningful consequences where Robert's character development is made by collective decisions rather than isolated choices.

---

## Functions

### Helper Functions

#### `printWords()`
**Use:** Creates cinematic word-by-word text display for dialogue

**Parameters:**
- `text` (string): The dialogue to display
- `wordDelayMs` (int): Milliseconds between each word (default: 120ms)

**Implementation:**
```cpp
void printWords(const string &text, int wordDelayMs = 120) {
    stringstream ss(text);
    string word;
    while (ss >> word) {
        cout << word << " " << flush;
        this_thread::sleep_for(chrono::milliseconds(wordDelayMs));
    }
    cout << endl;
}
```

**Why This Matters:**
When we wrote the EP, I had an issue with how the text immediately prints. We asked our classmates what they did, then we found out the wonders of *text effects.* This function makes dialogue feel more natural and gives players time to read and absorb emotional moments. 

---

#### `printLines()`
**Use:** Displays action descriptions and scene transitions with line-by-line delays

**Parameters:**
- `text` (string): The action text to display
- `lineDelayMs` (int): Milliseconds between lines (default: 500ms)

**Code Example:**
```cpp
void printLines(const string &text, int lineDelayMs = 500) {
    stringstream ss(text);
    string line;
    while (getline(ss, line, '\n')) {
        cout << line << endl;
        this_thread::sleep_for(chrono::milliseconds(lineDelayMs));
    }
}
```

---

#### `waitForEnter()`
**Use:** Pauses program execution until player presses Enter, creating natural scene breaks

**Code Example:**
```cpp
void waitForEnter(const string &prompt = "\n[Press Enter to continue...]") {
    cout << prompt << flush;
    cin.get();
}
```

**Usage in Scenes:**
```cpp
void scene_apartment_interrogation() {
    waitForEnter("\n[Press Enter to begin Scene 2...]");
    // Scene title appears only after Enter is pressed
}
```

---

#### `readChoice()`
**Use:** Validates player input and ensures only valid numerical choices are accepted

**Parameters:**
- `min` (int): Minimum valid choice (default: 1)
- `max` (int): Maximum valid choice (default: 3)

**Implementation:**
```cpp
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
```

**Why Input Validation Matters:**
When we tested the code, it would run smoothly. Until we fiddled around to find that a choice of 1-3 still took the number 8 and continued the code. Without validation, invalid input (letters, symbols, out-of-range numbers) would crash the program or create bugs.

---

### Scene Functions

#### Scene 1: `scene_introduction()`
We added this scene as we saw it fit for the story. It establishes Robert's emotional state and relationship with his father through conversation with the Soothing Goon

**Decision Point:**
Player chooses how Robert describes his feelings about his deceased father:
1. "Didn't know him well" - Creates emotional distance
2. "I love my dad" - Shows emotional openness
3. "He's gone" - Acknowledges loss without elaboration

**Variables Modified:** None (introductory scene establishing context)

**Code Snippet:**
```cpp
if (choice == 2) {
    cout << "Robert: Look, I love my dad, all right? I love my dad. That's the truth.\n";
    cout << "Goon: Loved.\n";
    cout << "Robert: That's what I said.\n";
    cout << "Goon: You said 'love.' Your dad's dead.\n";
}
```

---

#### Scene 2: `scene_apartment_interrogation()`
Implements the moral crossroads where Robert must decide the fate of the Soothing Goon

**Decision Point - The Moral Choice:**
After interrogating the goon about Shroud's location, Robert dangles him off a building:
1. **Let Him Drop** - Ruthless efficiency; establishes fear-based respect
2. **Pull Him Back** - Shows mercy and compassion; values life over vengeance

**Variables Modified:**
```cpp
if (choice == 2) {  // Pull Him Back
    isMerciful = true;
} else {  // Let Him Drop
    isMerciful = false;
}
```

**Code Example:**
```cpp
if (choice == 2) {
    isMerciful = true;
    cout << "\nRobert: Honestly, it was nice talking to someone about this stuff.\n";
    cout << "Robert: I'm really glad I kidnapped you tonight.\n";
} else {
    isMerciful = false;
    cout << "\n*Silence follows as the screaming fades*\n";
}
```

**Why Does This Choice Matters?**
This is Robert's defining moral moment. The `isMerciful` Boolean affects dialogue in Scene 6 and determines how the epilogue describes Robert's character arc. A merciful Robert is seen as a compassionate leader, while a ruthless Robert is feared and respected for pragmatic efficiency.

**Consequences**
- **Immediate >** Determines if the goon survives
- **Scene 6 >** Influences Robert's internal dialogue during combat
- **Epilogue >** Shapes the final character assessment

---

#### Scene 3: `scene_street_fight()`
Teaches tactical consequences through immediate combat feedback

**Decision Point - Tactical Combat:**
Player chooses which hand to punch with:
1. **Right Hand Punch** - Gets countered; Robert is struck with crowbar (failure)
2. **Left Hand Punch** - Successfully knocks out attacker (success)

**Variables Modified:** None (tactical lesson, not character development)

**Code Example:**
```cpp
if (choice == 1) {
    cout << "\nYou swing with your right hand.\n";
    cout << "The thief reads it perfectly and counters with the crowbar!\n";
    cout << "*You get struck and stagger backward.*\n";
} else if (choice == 2) {
    cout << "\nYou swing with your left hand.\n";
    cout << "Your punch lands perfectly and knocks out the attacker!\n";
}
```

**Design Philosophy:**
This scene demonstrates that not all choices affect long-term variables. Some decisions have immediate, binary outcomes (success/failure) that teach players to think tactically. The lack of lasting consequences makes this a "safe" learning moment.

---

#### Scene 4: `scene_bar_flambae()`
Creates a memorable public incident that establishes Robert's reputation among superheroes

**Decision Point 1 - Insult:**
Player chooses how to mock Flambae:
1. Dr. Don't Do Shit (+1 impression, +1 chaos)
2. Mr. Wet Ponytail (+2 impression, +2 chaos)
3. Sunglasses at Night Guy (+1 impression, +1 chaos)

**Decision Point 2 - The Critical Choice:**
How to extinguish Flambae's flames:
1. **Throw Water** - Efficient, quiet outcome (+2 impression, +1 chaos)
2. **Throw Alcohol** - Dramatic scene, unforgettable (+5 impression, +3 chaos)

**Variables Modified**
```cpp
// Water choice
impressionScore += 2;
publicChaos += 1;

// Alcohol choice
impressionScore += 5;  // PROJECT REQUIREMENT: Higher impression
publicChaos += 3;
```

**Code Example**
```cpp
if (choice == 2) {  // Alcohol
    printLines("*You throw alcohol on Flambae*");
    printLines("*The flames EXPLODE upward*");
    printWords("Flambae: OH YOU FUCKED UP.");
    
    impressionScore += 5;  // Memorable and dramatic
    publicChaos += 3;      // Major chaos
    
    printWords("Blonde Blazer (thinking): I will never forget this moment.");
}
```

**Why does the Alcohol Score Higher?**
Per project requirements, the alcohol choice must leave a "stronger impression on witnesses." While water is sensible, alcohol creates a spectacular, memorable moment that Blonde Blazer witnesses. The higher impression score reflects that bold, dramatic actions are more memorable than safe, efficient ones.

**Blonde Blazer's Perspective:**
For this scene I thought to explicitly show Blonde Blazer watching and reacting. Her internal monologue varies based on the choice, establishing different perceptions of Robert's personality (sensible vs. bold).

---

#### Scene 5: `scene_billboard()`
Implements the pivotal romance moment that determines the relationship dynamic between Robert and Blonde Blazer

**Decision Point 1 - Opening Up:**
How Robert responds to the intimate moment:
1. "I really needed this" (+2 impression) - Vulnerable and honest
2. "Thanks for helping me" (+1 impression) - Grateful but guarded
3. "Sorry about the spit thing" (+3 impression) - Humorous and confident

**Decision Point 2 - The Kiss (CRITICAL):**
When Blonde Blazer touches Robert's face:
1. **Kiss Her** - Bold, passionate, creates complicated tension (+3 impression)
2. **Let the Moment Pass** - Patient, emotionally aware (+4 impression)

**Variables Modified:**
```cpp
if (choice == 1) {  // Kiss
    isRomanticTensionActive = true;
    impressionScore += 3;
    publicChaos += 1;
} else if (choice == 2) {  // Don't kiss
    isRomanticTensionActive = true;
    impressionScore += 4;
}
```

**Code Example:**
```cpp
if (choice == 1) {
    printLines("*You lean in and kiss her*");
    printLines("*For a brief moment, she kisses back*");
    printLines("*Then she pulls away gently*");
    printWords("Blonde Blazer: No. This... I'm sorry if I gave the wrong impression.");
    
    isRomanticTensionActive = true;  // REQUIRED by project
    impressionScore += 3;
}
```

**Critical Design Choice:**
BOTH options set `isRomanticTensionActive = true` because romantic tension exists regardless of whether the kiss happens. The difference is in the TYPE of tension:
- **Kiss:** Passionate but awkward; crossed a professional line
- **Don't Kiss:** Unresolved chemistry; respectful restraint

**Why "Don't Kiss" Scores Higher:**
Emotional intelligence is attractive. By reading the situation and giving Blazer space, Robert demonstrates maturity and respect for her complicated position. This scores higher (+4) than the impulsive kiss (+3), though both are valid romantic choices.

**Epilogue Impact:**
The `isRomanticTensionActive` Boolean directly affects the epilogue's romance narrative. Without this variable being set, the epilogue cannot properly conclude the romance arc.

---

#### Scene 6: `scene_combat_toxic()`
Reflects Robert's established personality through combat choices, using previous decisions to inform character consistency

**Decision Point 1 - Opening Line:**
How Robert confronts the situation:
1. "It's over Shroud"
2. "Prepare to die"
3. "I'm here to fuck you up"

**Decision Point 2 - Combat Style (Punt vs Stomp):**
How to deal with the toxic goon:
1. **Punt** - Flashy, creative problem-solving
2. **Stomp** - Brutal, efficient intimidation

**Variables Referenced**
```cpp
if (isMerciful) {
    cout << "Mecha Man: Cause it's over, Shroud.\n";
    // More measured dialogue
} else {
    cout << "Mecha Man: Uh, where the fuck is Shroud?\n";
    // More aggressive dialogue
}
```

**How does `isMerciful` Affect This Scene?**
The Boolean set in Scene 2 (Apartment Interrogation) influences Robert's dialogue here. 

**A merciful Robert:** speaks more thoughtfully  
**A ruthless Robert:** direct and aggressive 

This creates narrative consistency and shows that early choices have lasting character effects.

**Decision Point 3 - Escape Strategy:**
When cornered, player chooses:
1. Ignore Toxic's warning
2. "You're bluffing"
3. "Bullshit"

**Code Example**
```cpp
if (isMerciful) {
    cout << "Soothing Goon: Oh no, it's over Shroud. All this buildup face to face with your father's killer.\n";
    cout << "Soothing Goon: And you come in here with that lame shit?\n";
} else {
    cout << "Mecha Man: Uh, where the fuck is Shroud?\n";
    cout << "Soothing Goon: He'll be here in a bit.\n";
    cout << "Soothing Goon: After that you let me go I swore that I will fuck you up.\n";
}
```
This scene demonstrates how past choices make up the current character behavior. Rather than creating isolated decisions, the program maintains character consistency by referencing the `isMerciful` Boolean established three scenes earlier. 

---

#### Scene 7: `scene_epilogue_summary()`
Provides a comprehensive narrative summary based on all accumulated decisions

**Variables Evaluated**
- `isMerciful` - Determines leadership style description
- `impressionScore` - Determines Blazer's memory and interest level
- `isRomanticTensionActive` - Determines romance outcome
- `publicChaos` - Affects reputation description

**Code Example**
```cpp
void scene_epilogue_summary() {
    if (isMerciful) {
        cout << "Robert chose a path of compassion, showing mercy even to his enemies.\n";
        cout << "His reputation grows as a hero who values life, earning respect and loyalty.\n";
    } else {
        cout << "Robert acted with pragmatic efficiency, prioritizing results over emotions.\n";
        cout << "He became known as a decisive and tough hero, feared and admired alike.\n";
    }
    
    if (impressionScore >= 8) {
        cout << "Blonde Blazer clearly remembers Robert's charm and heroics.\n";
    } else if (impressionScore >= 4) {
        cout << "Blonde Blazer remembers Robert's courage and quirky personality.\n";
    } else {
        cout << "Blonde Blazer saw Robert mostly as a competent but slightly awkward hero.\n";
    }
}
```

**Scoring Thresholds**
- **Impression Score:**
  - 0-3: Low interest, forgettable
  - 4-7: Moderate interest, notable
  - 8+: High interest, memorable

**Multiple Endings**
The epilogue can generate different narrative combinations based on variable states:
- Merciful + High Romance = Compassionate leader with romantic potential
- Ruthless + High Romance = Dangerous attraction dynamic
- Merciful + Low Romance = Respected colleague
- Ruthless + Low Romance = Professional distance with underlying tension

## Variable Tracking Table

| Variable | Initial Value | Modified By | Used By | Final Impact |
|----------|---------------|-------------|---------|--------------|
| `isMerciful` | `false` | Scene 2 (interrogation) | Scene 6 (combat dialogue), Epilogue | Determines leadership style narrative |
| `impressionScore` | `0` | Scenes 3, 4, 5 | Epilogue | Determines Blazer's interest level (0-15) |
| `publicChaos` | `0` | Scenes 4, 5 | Epilogue (optional) | Tracks public disturbance level (0-10) |
| `isRomanticTensionActive` | `false` | Scene 5 (billboard kiss) | Epilogue | Determines if romance narrative is included |

---

## Key Design Decisions [ni jamie]

### Why Word-by-Word Text Display?

Traditional visual novels use text effects to create dramatic pacing. By displaying dialogue word-by-word rather than instantly, the program:
- Gives players time to read and absorb information
- Creates tension during emotional moments
- Makes characters feel more alive and present
- Mimics the experience of professional visual novels

### Why Global Variables Instead of Parameters?

Using global variables allows any scene to reference any decision made earlier without complex parameter passing. This creates a persistent "game state" where Robert's character development is truly cumulative. For example, Scene 6 can check `isMerciful` from Scene 2 without needing to pass it through Scenes 3, 4, and 5.

### Why Both Kiss Options Activate Romance?

In real relationships, romantic tension exists regardless of whether physical intimacy occurs. By setting `isRomanticTensionActive = true` for both choices, the program acknowledges that:
- The kiss creates passionate but complicated tension
- Not kissing creates unresolved chemistry and "what if" tension
- Both paths are valid romantic narratives, just different types

This design choice makes the romance more nuanced than a simple "romance on/off" switch.

---

## How Choices Cascade

### Example: The Mercy Path

**Scene 2:** Player chooses "Pull Him Back"
- `isMerciful = true`

**Scene 6:** Robert faces Toxic
- Check: `if (isMerciful)` → Use compassionate dialogue
- Robert says: "Cause it's over, Shroud" (measured)
- Instead of: "Uh, where the fuck is Shroud?" (aggressive)

**Epilogue:** Final character assessment
- Check: `if (isMerciful)` → Use compassionate leadership narrative
- Output: "Robert chose a path of compassion, showing mercy even to his enemies."

**This demonstrates narrative consistency across 5 scenes from a single decision.**

---

## Limitations

### Text Display Compatibility
- Word-by-word display requires `<thread>` and `<chrono>` libraries (C++11 or later)
- Some older compilers may not support these features
- ASCII box characters work on all terminals; Unicode may cause alignment issues

### Input Handling
- Program assumes valid numerical input after validation
- Does not support mouse or arrow key navigation
- Requires manual Enter key presses between scenes

---

## References

- [Dispatch Episode 1 Walkthrough](https://gam3s.gg/dispatch/guides/dispatch-episode-1-walkthrough/)
- [Dispatch on YouTube](https://www.youtube.com/watch?v=ak78JicnW_E)
- [C++ Documentation: `<thread>`, `<chrono>`, `<sstream>` libraries](https://www.geeksforgeeks.org/cpp/multithreading-in-cpp/)
- [C++ Library - <chrono>](https://www.tutorialspoint.com/cpp_standard_library/cpp_chrono.htm)
- [std::chrono](https://www.reddit.com/r/cpp/comments/e97i6f/i_made_a_cheat_sheet_for_stdchrono_because_i_have/)
- [README.md File](https://www.geeksforgeeks.org/cpp/cpp-global-variables/) 
- [C++ Global Variables](https://www.geeksforgeeks.org/cpp/cpp-global-variables/)

PS. This is not the complete list of references. Other members may not be able to add their sources as this was my choice to add. :))

---
**Flowchart:**
<img width="6035" height="732" alt="image" src="https://github.com/user-attachments/assets/3b8827f0-e86b-4846-a85c-842814d7e4a8" />

**This flowchart shows the story path of an interactive game where you play as Robert Roberson, also known as Mecha Man. It follows six main scenes where your choices shape Robert's personality, his relationships, and the kind of hero he becomes. Each decision you make changes how characters see him and what happens in the end, leading to a final summary that reflects the unique journey you created.**

---
**Jamie Dominique J. Medina**    
Writer, Coder

**Lee Ferrer**  
**Rodge Ravin**  
Coders


---

## License
This project is created for educational purposes as part of a C++ programming course.

---

**DONEZOOO IT'S CHRISTMASTIME 🤑**

