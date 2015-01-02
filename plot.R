data<-read.csv(file="timeresolve.csv")

require(ggplot2)
#colnames(data)<-c("vin","vout")
fit<-lm(data$vin~data$vout)
plot<-ggplot(data,aes(vin,vout)) +  geom_line()
plot.line<-geom_abline(intercept = fit$coefficients[1], slope = fit$coefficients[2])
word<-paste("y =",paste(as.numeric(round(fit$coefficients[1],4))),"x + ",paste(as.numeric(round(fit$coefficients[2],4))))
plot.words<-annotate("text", x =2, y = 3, label = word  )

plot+plot.line+plot.words

ggplot(data,aes(time))+geom_line(aes(y=pin2, color="pin2"))+geom_line(aes(y=pin3,color="pin3")) +
                      geom_line(aes(y=pin5,color="pin5")) +geom_line(aes(y=grnd,color="grnd"))
