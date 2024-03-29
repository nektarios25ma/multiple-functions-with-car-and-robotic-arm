# multiple-functions-with-car-and-robotic-arm
link ellak: https://openedtech.ellak.gr/robotics2023/onoma-omadaserevnitestitlos-ergourompotikos-vrachionas-pollaplon-litourgion/

Στα μαθήματα της ρομποτικής-STEM που κάνω στο σχολείο μας, τα παιδιά μου πρότειναν την δημιουργία ενός ρομποτικού βραχίονα σε ρομπότ-αυτοκινητάκι ο οποίος θα ελέγχεται από το κινητό μας τηλέφωνο ή απο κάποιο ασύρματο τηλεχειριστήριο και θα εκτελεί διάφορες εργασίες.
Διάλεξα λοιπόν το παρακάτω kit το οποίο αποτελεί και εργαλείο εκμάθησης STEM, όπου ξεκινώντας από απλές δημιουργίες καταλήγει σε πολύπλοκες και δημιουργικές κατασκευές.
https://wiki.keyestudio.com/KS0520_KEYESTUDIO_4DOF_Mechanical_Robot_Arm_Car_Learning_Kit

Ο «Βαθμός Ελευθερίας» (DoF) όπως σχετίζεται με τους ρομποτικούς βραχίονες, είναι μια ανεξάρτητη άρθρωση που μπορεί να παρέχει ελευθερία κινήσεων στον χειριστή, είτε με περιστροφική είτε με γραμμική κίνηση. 
Κάθε γεωμετρικός άξονας στον οποίο μια άρθρωση μπορεί να περιστραφεί ή να εκτείνεται κατά μήκος υπολογίζεται ως Ενιαίος Βαθμός Ελευθερίας. 

Σε αυτό το έργο βασιστήκαμε σε ένα κιτ εκμάθησης μηχανικού ρομποτικού βραχίονα 4DOF που στηρίζεται σε ένα αυτοκίνητο.
Το συναρμολογήσαμε , μάθαμε από αυτό και δημιουργήσαμε τη δική μας έκδοση  λειτουργίας με κωδικούς MCU και μια εφαρμογή smartphone δικής μας έμπνευσης.

![image](https://github.com/nektarios25ma/multiple-functions-with-car-and-robotic-arm/assets/44388822/2be72c44-2f55-4945-834f-4a1517304bf8)

Ο ρομποτικός βραχίονας έχει 4 βαθμούς ελευθερίας, ελέγχεται από το κινητό μας και το αυτοκίνητο κινείται κατόπιν παραγγελίας μας.
Σχέδιο 3 σε 1: Έξυπνο αυτοκίνητο, μηχανικός βραχίονας. Πολλαπλές λειτουργίες: αποφυγή εμποδίων, παρακολούθηση κ.λπ. 

Ανιχνεύει επίσης το σκοτάδι μέσω ενός αισθητήρα φωτογραφίας και ανάβει αυτόματα τα φώτα.

Το βίντεο που δείχνει την κατασκευή μας έχει ως όνομα το VIDEO_DEMOSTRATION_ARM_ELLAK.mp4 και βρίσκεται σε αυτό το github ή εδώ https://drive.google.com/file/d/1K4BlvJT_M1YCqCxiA833Xw4zHBCchlr_/view?usp=sharing .

Σχεδιάσαμε επίσης τη δική μας εκδοχή ενός ρομποτικού βραχίονα σε τρεις διαστάσεις (3D STL TINKERCAD), τα αρχεία του οποίου δημοσιεύουμε στο GITΗUB: 
https://github.com/nektarios25ma/multiple-functions-with-car-and-robotic-arm/tree/main/3Darm
and we are searching for 3d printer…

Το learning kit προτείνει μια σειρά από κώδικες που αποτελούν και σειρά μαθημάτων ΟΜΩΣ τα παιδιά εφτιαξαν την δική τους εκδοχή 
με όνομα arm1blu.ino στο GITHUB , link: https://github.com/nektarios25ma/multiple-functions-with-car-and-robotic-arm/blob/main/arm1blu.ino

Η παρακάτω εφαρμογή σχεδιάστηκε-προγραμματίστηκε απο τα παιδιά.
MIT APP LINK FOR DOWNLOAD  AND INSTALL TO OUR SMARTPHONE:
https://github.com/nektarios25ma/multiple-functions-with-car-and-robotic-arm/blob/main/BLECAR_ARM1%20(1).aia

O τρόπος συναρμολόγησης δίνεται εδώ στο pdf : 4DF Mechanical Robot Arm Car.pdf με link: 
https://github.com/nektarios25ma/multiple-functions-with-car-and-robotic-arm/blob/main/4DF%20Mechanical%20Robot%20Arm%20Car.pdf

Επίσης η δική τους σειρά μαθημάτων εδώ στο αρχείο : KS0520 4DOF Mechanical Robot Arm Car.pdf με link:
https://github.com/nektarios25ma/multiple-functions-with-car-and-robotic-arm/blob/main/KS0520%204DOF%20Mechanical%20Robot%20Arm%20Car.pdf

Πάνω στο arduino uno κουμπώνει η shield του keyestudio διευκολύνοντας την συνδεσμολογία  όμως προσθέσαμε τον αισθητήρα φωτός και τα led φωτισμού στο GITHB : με όνομα ldr sensor with two lights.png και link  εδώ : https://github.com/nektarios25ma/multiple-functions-with-car-and-robotic-arm/blob/main/ldr%20sensor%20with%20two%20lights.png


ΥΛΙΚΑ:

1)KIT =141,40€


https://www.pc-bonus.gr/paihnidia-kai-eidi-doron/paihnidia/rompotiki/tupos-el-1147.html
ή
https://www.smartfox.gr/product/keyestudio-4dof-mechanical-robot-arm-car-kit-ks0520-gia-arduino/?gclid=CjwKCAiA2rOeBhAsEiwA2Pl7QxWdzSBc3WhdoWsLRBF1P5e84g7JfSP7L91zGnD15fJV_NkV6H_1vBoCV14QAvD_BwE


2)2X 18650 BATTERY =€20

LINK: https://www.cosmoprice.gr/product/72872/epanafortizomeni-mpataria-biomixanikoy-typoy-samsung.html#img2

3)Photoresistor - Light Detection Module for Arduino =€2.23
https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/mcu-and-components/light/photoresistor-light-detection-module-for-arduino/

ΣΥΝΟΛΟ=169 €

ΠΗΓΕΣ:
WIKI: https://en.wikipedia.org/wiki/Degrees_of_freedom_(mechanics)

https://reachrobotics.com/blog/degrees-of-freedom-vs-functions-of-a-robotic-arm/

https://wiki.keyestudio.com/KS0520_KEYESTUDIO_4DOF_Mechanical_Robot_Arm_Car_Learning_Kit
και https://www.data-media.gr/files/KS0520.pdf
