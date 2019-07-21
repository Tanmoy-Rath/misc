<details>
  <summary><b>Input Details...</b>click to expand!!</summary>

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
</details>

<hr>

### grep()
>- selects those strings in input vector of strings, where a match occurs.

grep() works on a **vector of strings**. It returns (with value=TRUE) those strings (as a vector) in the input vector of strings, inside whom the pattern occurs. Otherwise it returns the input vector indices of the strings, inside whom the pattern is found to occur.

```R
> grep("my", parts, ignore.case=TRUE, value=TRUE)
[1] "This is my teststring to explain how substitution with my R Base works"
[2] "another teststring for My example of gsub and sub"                     
[3] "Tom coded 11 Java scrips TO MY 23 Python scripts"                      

> grep("my", whole, ignore.case=TRUE, value=TRUE)
[1] "This is my teststring to explain how substitution with my R Base works\n           another teststring for My example of gsub and sub\n           3445 is GReater than 23 - @???!§$\n           Tom coded 11 Java scrips TO MY 23 Python scripts"



> grep("my", parts, ignore.case=TRUE)
[1] 1 2 4

> grep("my", whole, ignore.case=TRUE)
[1] 1
```

<hr>

### grepl()
grepl() is same as grep(), i.e. works on a vector of strings, but returns boolean results of patterns found.
Its return length is same as total number of strings in the input vector of strings

```R
> grepl("my", parts, ignore.case=TRUE)
[1]  TRUE  TRUE FALSE  TRUE

> grepl("my", whole, ignore.case=TRUE)
[1] TRUE
```

<hr>

### gsub()
gsub() can work on a vector of strings or just a single string (e.g. a paragraph). It replaces the pattern strings found with the replacement string. Return result type is same as the input vector type. Unmatched strings in input vector are returned as it is.

```R
> gsub("my", "**--**", parts, ignore.case=TRUE)
[1] "This is **--** teststring to explain how substitution with **--** R Base works"
[2] "another teststring for **--** example of gsub and sub"                         
[3] "3445 is GReater than 23 - @???!§$"                                             
[4] "Tom coded 11 Java scrips TO **--** 23 Python scripts"                          

> gsub("my", "**--**", whole, ignore.case=TRUE)
[1] "This is **--** teststring to explain how substitution with **--** R Base works\n           another teststring for **--** example of gsub and sub\n           3445 is GReater than 23 - @???!§$\n           Tom coded 11 Java scrips TO **--** 23 Python scripts"
```

<hr>

### Regular Expressions

|![](https://github.com/Tanmoy-Rath/misc/blob/master/R/UDEMY/misc/regexp1.jpg)|![](https://github.com/Tanmoy-Rath/misc/blob/master/R/UDEMY/misc/regexp2.jpg)|
|---|---|
|- |any character|

tolower() and toupper() are used to change cases
```R
> tolower("Graphs and Histograms")
[1] "graphs and histograms"

> toupper("Graphs and Histograms")
[1] "GRAPHS AND HISTOGRAMS"
```

strsplit() splits the input string based on the given pattern
```R
> # splitting the string in single character values
> strsplit("Graphs and Histograms", NULL)
[[1]]
 [1] "G" "r" "a" "p" "h" "s" " " "a" "n" "d" " " "H" "i" "s" "t" "o" "g" "r" "a" "m" "s"

> # splitting strings after each space
> strsplit("Graphs and Histograms", " ")
[[1]]
[1] "Graphs"     "and"        "Histograms"
```
