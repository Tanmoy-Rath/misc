```R
parts <- c("This is my teststring to explain how substitution with my R Base works",
           "another teststring for My example of gsub and sub",
           "3445 is GReater than 23 - @???!§$",
           "Tom coded 11 Java scrips TO MY 23 Python scripts")

whole <- c("This is my teststring to explain how substitution with my R Base works
           another teststring for My example of gsub and sub
           3445 is GReater than 23 - @???!§$
           Tom coded 11 Java scrips TO MY 23 Python scripts")
           
# a vector of strings
> parts
[1] "This is my teststring to explain how substitution with my R Base works"
[2] "another teststring for My example of gsub and sub"                     
[3] "3445 is GReater than 23 - @???!§$"                                     
[4] "Tom coded 11 Java scrips TO MY 23 Python scripts"                      

# one whole string
> whole
[1] "This is my teststring to explain how substitution with my R Base works\n           another teststring for My example of gsub and sub\n           3445 is GReater than 23 - @???!§$\n           Tom coded 11 Java scrips TO MY 23 Python scripts"
```

grep() works on a **vector of strings**. It returns (with value=TRUE) those strings (as a vector) in the input vector inside which the pattern occurs
Otherwise it returns the input vector indices of the strings, inside which the pattern is found to occur.
