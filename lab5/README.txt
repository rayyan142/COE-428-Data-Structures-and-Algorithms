Rayyan Faisal
501196760
Section 03

In this lab we focused on creating a program that checks if XML files are correctly formatted and turns numbers into an XML heap, 
using stack and heap algorithms. Everything works.

In order to incorporate stand-alone tags with the XML validation, I can modify the tag processing logic to determine the point at which a tag self-closes. 
Tags that end in "/>" will be identified as stand-alone. This tag will not be pushed to the stack or require a matching closing tag because the program will 
recognize it as complete on its own. By making this modification, the balance required to create a valid XML structure is maintained and only tags that require 
matching pairs are added to the stack.