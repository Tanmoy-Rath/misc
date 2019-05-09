https://www.r-bloggers.com/a-quick-primer-on-split-apply-combine-problems/<br/>
https://vita.had.co.nz/papers/plyr.pdf
# Solutions to S-A-C problems (split-apply-combine)

### Technique-1
```R
> s <- split(airquality, airquality$Month)
> sapply(  s, function(x) colMeans(x[,c("Ozone","Solar.R","Wind")])  )
               5         6          7        8        9
Ozone         NA        NA         NA       NA       NA
Solar.R       NA 190.16667 216.483871       NA 167.4333
Wind    11.62258  10.26667   8.941935 8.793548  10.1800

# If you want to remove NAs...
> sapply(  s, function(x) colMeans(x[,c("Ozone","Solar.R","Wind","Temp")],na.rm=TRUE)  )
                5         6          7          8         9
Ozone    23.61538  29.44444  59.115385  59.961538  31.44828
Solar.R 181.29630 190.16667 216.483871 171.857143 167.43333
Wind     11.62258  10.26667   8.941935   8.793548  10.18000
Temp     65.54839  79.10000  83.903226  83.967742  76.90000
```
