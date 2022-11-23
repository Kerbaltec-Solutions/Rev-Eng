<!--
author:   Björn Schnabel

email:    bjoern-uwe.schnabel@tu-freiberg.de

version:  0.0.2

language: en

narrator: English Female

comment:  Documentation for the reverse engeneering program for Arduino Uno

@btn:     <span class="lia-icon"><lia-keep>@0</lia-keep></span>

import:   LiaTemplates/mec2/blob/main/README.md

-->

# Reverse engeneering with Arduino Uno

With this program you can let your Arduino analize logic circuits with up to 18 inputs or outputs

## Useage:

0. Connect your logic circuit to the arduino

1. After uploading the program open the serial console.

2. _(version 2a only)_ The arduino will ask you, if it should treat analog pins as analog

    `Treat analog pins as analog? :`

    + Type "y" or "Y" to treat the pins A0 to A5 (pin 14-19) as analog outputs of the attached circuit and record analog values when they are declared as outputs.

        + You can still declare those pins as inputs if you want to.

    + Type anything else to treat those pins as digital pins

    _(version 3 only)_ The arduino will ask you, if it should display the logic table in hexadecimal

    `Format output as hexadecimal?: `

    + Type "y" or "Y" to show the logic table in hexadecimal

    + Type anything else to display the logic table like normal

3. _(version 2 and higher)_ The Arduino will ask you which pin you want to assign to a cretain input of the attached circuit. You can assign pin 2-19

    `Pin for IC input <input number> :`

    + Type a pin number to assign this pin to the displayed input. Pins cannot be assigned twice.
    + Type "e" or "E" to end the assinging process and continue to assing output pins

4. _(version 2 and higher)_ The Arduino will ask you which pin you want to assign to a cretain output of the attached circuit. You can assign pin 2-19

    `Pin for IC output <output number> :`

    + Type a pin number to assign this pin to the displayed output. Pins cannot be assigned twice.
    + Type "e" or "E" to end the assinging process and continue with the iterating process

5. The Arduino will iterate troug the different combinations of `on`or `off`of the _input pins_ and record the state of the _output pins_.

6. The arduino will display a logic chart showing the states of all _output pins_ for all combinations of _input pins_

## Installation:

Download one of the versions from the branches and upload it to your Arduino using the IDE

## Simulation:

A simulation of the latest version can be found at https://wokwi.com/projects/347380666516636244
