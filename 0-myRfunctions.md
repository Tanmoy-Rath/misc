```R
NA_Data <- function( Dataset ){
        colnems <- colnames(Dataset)
        NAS <- sort(sapply(Dataset, function(x) sum(is.na(x))/length(x) )*100, decreasing = TRUE)
        NA_list <- tapply(NAS, as.factor(NAS), function(x) paste0(names(x),"[",match(names(x),colnems),"]"), simplify = FALSE)
        #NA_list <- tapply(NAS, as.factor(NAS), names, simplify = FALSE)
        max_is <- max(sapply(NA_list, length))
        sapply(    NA_list,    function(x)    c(   x,   rep("",max_is - length(x))   )    )
}

```
