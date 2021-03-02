# Need2Pee---Car-Game
A mini Arcade Car Game for the ChipKIT IS1200

This project was made in the course IS1200 Computer Technology.

## Requirements
The task for this project was to create some sort of application using the SPI interface for the ChipKIT Basic I/O shield. 
Requirements was that the user should be able to interact through buttons or other, and navigation through menus with different setting for the application.

## The game
The result was an arcade like game, with a pixel Formula 1 car riding on the highway trying to avoid collisions with cars coming the opposite way.
The speed of the game is increasing as the game progresses.

The screen is divided into four lanes, with all cars taking up an entire lane, both the driver vehicle as well as the opposing vehicles.

There are 3 levels to the game, Easy, Hard and Extreme. In Easy and Hard mode, the car "snaps" to either of the four lanes of the higway. 
This makes it easier for the user to avoid the cars.
In the Extreme level, the driver car can go across the lanes, which makes it much harder for the user to navigate since the opposing vehicles take up so much space. 

## Lessons learned
Since the project was also about the controlling of the hardware, a lot was learned about the structure of a microprocessor and the utilities it presents.
For example the updating of the frames in the game was controlled by an interrupt, and the randomness of the opposing vehicles was taken from the onboard clock.
The project also was great to increase my knowledge of the C programming language.
