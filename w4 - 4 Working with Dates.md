# Working with Dates
#### (d1 <- date())<br/>
### class(d1)<br/>

### (d2 <- Sys.Date())<br/>
### class(d2)<br/>

### format(d2,"%a %d %b %Y")<br/>
### class(format(d2,"%a %d %b %Y"))<br/>

### x <- c("1jan1960","2jan1960","31mar1960","30jul1960")<br/>
### (z <- as.Date(x, "%d%b%Y"))<br/>
### z[1] - z[2]<br/>
### class(z[1] - z[2])<br/>
### as.numeric(z[1] - z[2])<br/>

weekdays(d2)<br/>
months(d2)<br/>
julian(d2)<br/>

library(lubridate)<br/>
ymd("20140108")<br/>
mdy("08/04/2013")<br/>
dmy("03-04-2013")<br/>

ymd_hms("20140108101503")<br/>
ymd_hms("2014-01-08 10:15:03")<br/>
ymd_hms("2014-01-08 10:15:03", tz="Pacific/Auckland")<br/>
?timezone<br/>
Sys.timezone()<br/>
OlsonNames() ## around six hundred names<br/>

http://www.r-statistics.com/2012/03/do-more-with-dates-and-times-in-r-with-lubridate-1-1-0/<br/>
http://cran.r-project.org/web/packages/lubridate/vignettes/lubridate.html<br/>

?POSIXlt
```R
> (d1 <- date())
[1] "Fri May 24 19:15:32 2019"
> class(d1)
[1] "character"

> (d2 <- Sys.Date())
[1] "2019-05-24"
> class(d2)
[1] "Date"

> format(d2,"%a %d %b %Y")
[1] "Fri 24 May 2019"
> class(format(d2,"%a %d %b %Y"))
[1] "character"

> x <- c("1jan1960","2jan1960","31mar1960","30jul1960")
> (z <- as.Date(x, "%d%b%Y"))
[1] "1960-01-01" "1960-01-02" "1960-03-31" "1960-07-30"
> z[1] - z[2]
Time difference of -1 days
> class(z[1] - z[2])
[1] "difftime"
> as.numeric(z[1] - z[2])
[1] -1

> weekdays(d2)
[1] "Friday"
> months(d2)
[1] "May"
> julian(d2)
[1] 18040
attr(,"origin")
[1] "1970-01-01"

> library(lubridate)

Attaching package: ‘lubridate’

The following object is masked from ‘package:base’:

    date

> ymd("20140108")
[1] "2014-01-08"
> mdy("08/04/2013")
[1] "2013-08-04"
> dmy("03-04-2013")
[1] "2013-04-03"

> ymd_hms("20140108101503")
[1] "2014-01-08 10:15:03 UTC"
> ymd_hms("2014-01-08 10:15:03")
[1] "2014-01-08 10:15:03 UTC"
> ymd_hms("2014-01-08 10:15:03", tz="Pacific/Auckland")
[1] "2014-01-08 10:15:03 NZDT"
> ?timezone
> Sys.timezone()
[1] "Pacific/Auckland"
```
