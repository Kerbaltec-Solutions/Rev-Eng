<!--
author:   Björn Schnabel

email:    bjoern-uwe.schnabel@tu-freiberg.de

version:  0.0.1

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
    
    + circuit inputs are on pin 11, 12 and 13
    + circuit outputs are on pin 5 and 7

1. After uploading the program open the serial console.

2. _(version 2 and higher)_ The Arduino will ask you which pin you want to assign to a cretain output of the attached circuit. You can assign pin 2-19

    `Pin for IC output <output number> :`

    + Type a pin number to assign this pin to the displayed output. Pins cannot be assigned twice.
    + Type "e" or "E" to end the assinging process and continue with the iterating process

3. The Arduino will iterate troug the different combinations of `on`or `off`of the _input pins_ and record the state of the _output pins_.

4. The arduino will display a logic chart showing the states of all _output pins_ for all combinations of _input pins_

## Installation:

Download one of the versions from the branches and upload it to your Arduino using the IDE
