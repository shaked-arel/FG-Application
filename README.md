# FG-Application

# Brief explanation of the project:

This application allows the user to see flight data on a simulator, and to explore it. 
Flight data includes the speed of the plane, the direction, the height of the plane, and so on.
the flow of the application:
The user loads two data files to the app: 
1) csv file that contains the values of each attribute at each point of time in the flight.
2) xml file that contains the names of all the attributes that the user can check their values during the flight.
After the user loads those files, the app will open a window that:
- Shows the condition of every attribute of the flight in graphs.
- Has a media bar that can run the flight forward, back, restart the flight video, end it and has a lot more features.
- Has a visualization of the flight while it is running.
In this app the user can explore the data of the flight, and find detections.



# Added Features

* MainWindow screen that allows you to upload a csv and xml files that necessary for the flight simulator.
* Main screen that contains joystick and sliders of throttle and rudder, that moves according to the movement of the airplane.
* There are measurements like altimeter, airspeed and heading. Also, the user can see a visualization of the pitch, roll and yaw.  
* There is a list of all the flight attributes, the user can select one of them at a time, and then, three graphs that related to the attribute will show up.
* MediaBar that allows the user variety of actions: change the speed of the video, stop, continue, go back to the beginning etc.  


# Required installation and Preparations

1) [FlightGear](https://www.flightgear.org/) application version 3.6.
2) Move playback_small.xml to C:\Program Files\FlightGear 2020.3.6\data\Protocol.
3) Using the .NET Framework to create a GUI App for FlightGear.
4) Visual Studio 2019 
5) install the plotting library [OxyPlot](https://oxyplot.readthedocs.io/en/latest/getting-started/hello-wpf-xaml.html) for .NET.

# Compiling and Running

Before connecting, run the FlightGear Launcher and go to *Additional Settings* and write: 

--generic=socket,in,10,127.0.0.1,5400,tcp,playback_small
--fdm=null

Offered options to download the application: 
- Use git on the termianl with the command: git clone https://github.com/Noamls123/FG-Application
- Download the zip for this repository.

 After opening the app, a MainWindow will show up. 
 The user needs to load xml and csv files (as you can see in the picture) and then, needs to press **start**.
 
 ![image](https://user-images.githubusercontent.com/73317511/114721566-b6308400-9d41-11eb-870a-721e75846763.png)
 
 # Dll explanation
 if you would like to load a Dll you need to upload a csv file and a dll file.
 To start the min circle dll please upload the file in this path: "\plugins\CsharpCircleDll\CsharpCircleDll\bin\Debug\CsharpCircleDll.dll"
To start the regres dll please upload the file in this path: "\plugins\DllRe\Debug\DllRe.dll"

if we would like to use a new algorithm, we will need to make sure that the Dll implements the IDll interface. it has to have the function getAnomaliesFile that return the name of a txt file that has the list of the anomalies in it. 

note!
We did not manage to finish the part that present the anomalies that comes back from our algorithms,
we had a bug in the timeseries files that we didnt had time to fix.

# UML Chart:

Press [here](https://github.com/Noamls123/FG-Application/blob/main/UML.jpeg) to get the UML of the main classes.


# Code Design and Architechture:

For programming this app, **MVVM** architecture has been used.

This App has three main parts that run it, each part with its own designated responsibilities- View, ViewModel and Model.
The **Model**, which implement the interface IModel, as a client, interacts with The server (the Flight-Gear app) via TCP connection, and send data of csv and xml files.
In addition, the Model notifies the relevant **ViewModel** when it's data changed. Next, the ViewModel process the changed data and notifies the **Views** (all the UserControls which appear on the screen) by using data binding mechanism of wpf. The Views reacts to the changed data accordingly.
Furthermore, When the data of the View changed by the user, it is send a command to the relevant ViewModel, that send a command to the Model which reacts to the changed data accordingly. 

# Explanation Video:
Press [here](https://youtu.be/Y7CUQCnqSNw) to watch our video examples.
# Collaborators
This program was developed by Shaked Arel, Ruth Lofsky, Hadassa Danesh and Noam Sery Levi.

