library (readxl)
library(openxlsx)
aeusp_1_1_ <- read_excel("C:/Users/alumno-b302/Downloads/aeusp (1) (1).xlsx")
View(aeusp_1_1_)

datos <- read.xlsx(file.choose(), sheet="aeusp")

#Sexo
Sexo=datos[ ,3]
Sexo

y=factor(Sexo,levels=c(1,2),labels=c("Masculino", "Femenino"))
head(y) # muestra el panorama de los datos

fi=table(y)
hi = prop.table(fi)
pi= prop.table(fi)*100
tabla = cbind(fi,hi,pi)
tabla

# Grafico de barras
# Frecuencia Absoluta
barplot(fi)
bp=barplot(fi,main = "Aspectos socioeconomicos y culturales",col=c("blue","red"), 
names=c("Masculino","Femenino"),ylim=c(0,max(fi)*1.1))
text(x=bp, y=fi, labels=fi, pos=3)

porcentaje<-c(round(pi, digits = 3))
etiqueta<-c(paste(porcentaje,"%",sep=""))
colores<-c("green","pink")
pie(porcentaje,labels=etiqueta,cloCkwise=TRUE,col=c("green","pink")
,main = "Diagrama circular del Nivel de Estudio de los trabajadores")
legend("bottomright",c("Masculino","Femenino"), cex=0.6,fill=colores)
#puede moverse de ubicación la leyenda



