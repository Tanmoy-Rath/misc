### Shows % of NA's per column with column numbers in []

```R
NA_Data <- function( Dataset ){
   colnems <- colnames(Dataset)
   NAS <- sort(sapply(Dataset, function(x) sum(is.na(x))/length(x) )*100, decreasing = TRUE)
   NA_list <- tapply(NAS, as.factor(NAS), function(x) paste0(names(x),"[",match(names(x),colnems),"]"), simplify = FALSE)
   #NA_list <- tapply(NAS, as.factor(NAS), names, simplify = FALSE)
   max_is <- max(sapply(NA_list, length))
   sapply(    NA_list,    function(x)    c(   x,   rep("",max_is - length(x))   )    )
}


> NA_Data(airquality)
     0          4.57516339869281 24.1830065359477
[1,] "Wind[3]"  "Solar.R[2]"     "Ozone[1]"      
[2,] "Temp[4]"  ""               ""              
[3,] "Month[5]" ""               ""              
[4,] "Day[6]"   ""               ""              

# Strange thing about gapminder is, a matrix is returned, not a vector which should have been
> NA_Data(gapminder)
     0             
[1,] "country[1]"  
[2,] "continent[2]"
[3,] "year[3]"     
[4,] "lifeExp[4]"  
[5,] "pop[5]"      
[6,] "gdpPercap[6]"
```
