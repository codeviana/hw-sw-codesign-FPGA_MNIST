# hw-sw-codesign-FPGA_MNIST


The main goal of this project was to design a MNIST classifier using Hardware and Software with the Altera DE2-115 FPGA.
The basic function is:
  1. Frame digit inside B&W square
  2. Capture digit with camera - KEY [2]
  3. Run the classifier - SW[2]
  
## Architecture
  There is a Hardware side and a Software side to the architecture:
  - Hardware components
    - Base project from Altera's TRDB D5M CMOS Camera CD (Intel website)
    - Greyscale box
    - Dual Port RAM
    - VGA selector (between color and B&W)
    - LCD 16x2 Screen

  - Software components
    - Rescaler
    - MNIST classifier from [1]
    
## File navigation
  The three most important files in this project are
    - DE2_115_CAMERA.qpf  (Quartus Project File)
    - de2_115_camera.qsys (Platform Designer/Qsys File)
    - lcd_tryout folders  (Eclipse for NiosII Tools Files)



**All info detailed in HCR_Report.pdf**


### If you have any questions raise an issue and ask away! :)

This project was developed using code from https://github.com/RunTimeError2/CNN_Nios/tree/master/First_Nios [1] // All credits belong to the owner
