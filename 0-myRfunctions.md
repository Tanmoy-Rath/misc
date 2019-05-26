### Shows % of NA's per column(as column name) with column numbers in [ ]

```R
NA_Data <- function( Dataset ){
   colnems <- colnames(Dataset)
   NAS <- vapply(Dataset, function(x) 100*sum(is.na(x))/length(x), numeric(1))
   NA_list <- tapply(NAS, as.factor(NAS), function(x) paste0(names(x),"[",match(names(x),colnems),"]"), simplify=FALSE)
   max_is <- max(vapply(NA_list, length, numeric(1)))
   as.data.frame(vapply(NA_list, function(x) c(x, rep("",max_is-length(x))), character(max_is)))
}
```
<details>
  <summary><b>Details...</b>click to expand!!</summary>

```R
> NA_Data(airquality)
         0 4.57516339869281 24.1830065359477
1  Wind[3]       Solar.R[2]         Ozone[1]
2  Temp[4]                                  
3 Month[5]                                  
4   Day[6]                                  

> library(gapminder)
# Strange thing about gapminder is, a matrix is returned, not a vector which should have been returned.
# The matrix then gets converted to a data.frame
> NA_Data(gapminder)
             0
1   country[1]
2 continent[2]
3      year[3]
4   lifeExp[4]
5       pop[5]
6 gdpPercap[6]
# My analysis: sapply returns a vector only when returns from list components are of single length.
# If return lengths are > 1, a matrix is returned if all return lengths are same.
# A matrix is returned even if sapply operates only on a single component of a list, as is the case with gapminder.
# Same goes for diamonds dataset

> library(ggplot2)
> data(diamonds)
> NA_Data(diamonds)
            0
1    carat[1]
2      cut[2]
3    color[3]
4  clarity[4]
5    depth[5]
6    table[6]
7    price[7]
8        x[8]
9        y[9]
10      z[10]
```
</details>

<hr>

ufuf
