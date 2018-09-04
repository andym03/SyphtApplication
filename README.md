# SyphtApplication
Application for Sypht Internship.

Completed Problem #1.
Completed under the assumption the difference between "04/07/1984 - 25/12/1984" is 173, 
non inclusive of the start and end dates.

Running the program with 0 arguments enters input mode, whereby dates in the format "DD/MM/YYYY - DD/MM/YYYY" can be entered
endlessly. 
Running the program with a text file path will cause the program to read that text file, expecting dates in the aformentioned format,
seperated by new lines.

Further thoughts on optimisation: 
Counting each day is the least optimal way to complete this problem. Counting should be done in chunks, be they yearly, monthly, and in
partial months. This does change the layout of the algorithm somewhat, but given more time I would definitely implement it this way. 
