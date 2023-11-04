# Dash - Marvin
## Contest Challenge

**Objective:** Develop a program that finds the most cost-effective path through a map. Beginning at `M` and ending at `G`, your program must traverse tiles labeled `1` - `9`, paying the corresponding cost with every step. Aim to minimise the total cost of your journey.

### General Guidelines

### General Instructions
- The program must compile using the command `make` in the root directory.
- The compiled executable should be named `marvin` and placed in the root directory during the compilation via the Makefile.
- C is mandatory
- No norm is required
- Usage of external libraries is not allowed. Except for all libraries shipped with the compiler itself (example: #include <stdio.h>).
- Memory leaks are not a concern.
- Be prepared to explain your logic during presentation to ensure originality and authenticity.
- No multithreading

### Traces
During the Dash, you'll receive traces at four intervals, spaced every 2 hours: at the 2nd, 4th, 6th, and 8th hours. These feedback moments are designed to ensure your output is correct. They will check if you:
- Compile your executable the right way.
- Reach the goal.
- Return any unnecessary characters.
- Stay within the maps boundaries.

The traces will be pushed to your repository. (inside the branch `traces` so don't store your code inside there :))

### Input Instructions
- Maps contain lines of uniform length.
- Valid characters include:
  - 'M': starting point (only one per map).
  - 'G': goal (only one per map).
  - '1' - '9': cost tiles.
- The map file is passed as a command-line argument: `./marvin planet.txt`.
- Always expect just one command-line argument (argc == 2).
- The file will always be present and will have read rights.
- The map given will always be valid 
### Output Criteria

- Display the sequence of moves towards the goal:
  - `U`: Up
  - `D`: Down
  - `R`: Right
  - `L`: Left
- The output sequence should conclude with a newline (`\n`).

**Example:**
planet.txt
```
88888
81118
81818
8M8G8
88888
```

Execution:
```
./marvin planet.txt | cat -e
```

Output:
```
UURRDD$
```

- Multiple solutions can be submitted, but only the latest one ending with a newline will be considered.

### Assessment

After 7pm, your submitted programs will be compiled and tested against multiple unique maps. For each map, your program has a fixed amount of seconds to deliver its optimal solution (we will timeout your program afterwards so don't worry about ending your program). Points will be awarded based on the path with the lowest cost, similar to how racers collect points in Mario Kart. After all the challenges are completed, teams will be ranked based on their total points, with the team having the highest score being declared the winner.
If there is a tie it will be broken by a `boomerang foo` team match.

## Open League Challenges
You can also use C++ in the Open League
### Enhanced Input
#### Terrain Modifiers

Along with the standard map, terrain identifiers now enhance gameplay:

```
W8A2
A3E6
```
Here:
- `W`: Water/Ocean
- `A`: Air/Clouds
- `E`: Earth
#### Character Creation
Craft a character resembling the Fallout series, distributing 10 skill points among:
- Water
- Air
- Earth

The maximum allocation for any element is 5 points. Your character's element affinity affects tile costs:
- 0 points => 4
- 1 point => 3
- 2 points => 2.5
- 3 points => 2
- 4 points => 1.5
- 5 points => 1
For instance, with 3 Water points, moving onto a `W4` tile costs 2 * 4 = 8.
### Output Additions

Begin with your character's configuration, followed by the movement sequence.
**Example:**
```
./marvin planet.txt | cat -e
```
Output:
```
541UURRDD$
```

Here, `541` displays the allocated points for Water, Air, and Earth, in this order, respectively.
