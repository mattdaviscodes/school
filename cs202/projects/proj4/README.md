# Project 4
Submitted: 2/28/18

### Purpose
This program allows users to input structured rental car and rental
agency data from a [file](HighTechAgency.txt). This file contains
a set number of cars. Each car may contain up to three "high-tech"
addons. These are stored on the Car object in an array of Sensor
objects.

### Design Choices
When reading in car data from the text file, I could find no better
way to handle the 0-3 sensors problem than to iterate over the input
character-by-character. My function first discarded the opening bracket,
then looked at each successive character. If I found whitespace, I
appended a sensor to the car. Once I found the closing bracket, I moved
on. This works, but the code looks terrible. I'm hoping that the
professor will provide a proper solution to this project for our review.

### Problems
Reading the data in was a huge problem for me this time. I wanted to
overload the `>>` operator for all of my classes and only use nested
calls to that function to read in the data. I ended up getting this
to work, but it seemed very clunky to me. While reading in cars, storing
the known variables -- make, model, etc -- was very easy. But when I
got to the bracket-enclosed, whitespace-delimited list of sensors, I
had a much harder time.