#Using Indico.io's API Library for Face analysis
import indicoio
indicoio.config.api_key = "b57606da653f10a89fe88740d7a74164"


#Confirming Python file has ran from the bash script
print("Python file is executing")


#Creates a new text file "Test" and inserts the data outputted from the API 
#into the text file as a string
fo = open("Test", "w")
#Calling the images saved in the folder to analyze 
fo.write(str(indicoio.fer("Shyam1.jpg")));
fo.write("\n");
fo.write(str(indicoio.fer("Shyam2.jpg")));
fo.write("\n");
fo.write(str(indicoio.fer("Ostap.jpg")));
fo.write("\n");


