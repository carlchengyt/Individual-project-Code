#include <AFMotor.h>
#include <SPI.h> // This library allows communication with SPI devices
#include <WiFly.h> //include the WiFly experimental library
char msg[128];//variables for reading in the html responses
int letterCount = 0; 
int speed_scale = 0;//from 1-5
int input_mode = 0;
// setting motor names
AF_DCMotor motor1(1); // left front
AF_DCMotor motor2(2); // right front
AF_DCMotor motor3(3); // left back
AF_DCMotor motor4(4); // right back
WiFlyServer server(80);
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);  //Serial communication at 9600 buad for debugging 
  WiFly.begin();//begin WiFly communictaiosn                                                                                                                                 

  Serial.print("IP: ");
  Serial.println(WiFly.ip());  //Prints IP address once associated with the network
                              //If DHCP is on, this IP can change. If static IP is set, it should not.  
  server.begin(); //initialize the server
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFlyClient client = server.available();
  //the flag dataFlag give a notification of where the actual post
  //is once we flag it we can begin recording the message
  int dataFlag = 0;
  int msgIsolator = 0;

  //int inChar; //variable for reading in data from the phone/browser 
  //boolean isParsing = false;// flag for reading in and parsing data

  if (client) {
    // an http request ends with a blank line
    boolean current_line_is_blank = true;
    boolean endOfCode = true;
    char c;

    while (client.connected()) 
    {
      if (client.available()) 
      {
        c = client.read();
        delay(10);
        //Uncomment this line to see the HTTP respone
        Serial.print(c);

        // if we've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so we can send a reply
        if (!client.available()) {
          endOfCode = true;
        } else if (c == '\n') {
          // we're starting a new line
          current_line_is_blank = true;
        } else if (c != '\r') {
          // we've gotten a character on the current line
          current_line_is_blank = false;
          endOfCode = false;
        }

        //this is where the message that the user entered is going so this is where
        //we record it into a char array
        if (msgIsolator == 1) 
        {
          recordMessage(c);
          delay(100);
        }
        
        if ((c == '\n' && current_line_is_blank && !client.available()) || endOfCode) 
        {

          //As soon as the page has been refreshed the letter count is set to zero
          letterCount = 0;

          //Once the page has been refreshed we are no longer on the first run through
          //off the program so we set this to false
          endOfCode = false;

          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          //client.println("Connection: close");

          client.println();

          client.println("<html>");
          client.println("<title>Parallel Parking Control</title>");

          //the form code creates the buttons to click and change the temp/blanketstate 
          client.println("<center>");
          client.println("<form name=\"input\" action=\"\" method=\"post\">");
          client.println("<input type=\"submit\" name=\"%\" value=\"L\" style=\"height:50px; width:150px\" >");
          client.println("</form>");

          client.println("<form name=\"input\" action=\"\" method=\"post\">");
          client.println("<input type=\"submit\" name=\"%\" value=\"R\" style=\"height:50px; width:150px\" >");
          client.println("</form>");

          client.println("<form name=\"input\" action=\"\" method=\"post\">");
          client.println("<input type=\"submit\" name=\"%\" value=\"F\" style=\"height:50px; width:150px\" >");
          client.println("</form>");
          
          client.println("<form name=\"input\" action=\"\" method=\"post\">");
          client.println("<input type=\"submit\" name=\"%\" value=\"B\" style=\"height:50px; width:150px\" >");
          client.println("</form>");
          
          client.println("<form name=\"input\" action=\"\" method=\"post\">");
          client.println("<input type=\"submit\" name=\"%\" value=\"1\" style=\"height:50px; width:150px\" >");
          client.println("</form>");

          client.println("<form name=\"input\" action=\"\" method=\"post\">");
          client.println("<input type=\"submit\" name=\"%\" value=\"2\" style=\"height:50px; width:150px\" >");
          client.println("</form>");

          client.println("<form name=\"input\" action=\"\" method=\"post\">");
          client.println("<input type=\"submit\" name=\"%\" value=\"3\" style=\"height:50px; width:150px\" >");
          client.println("</form>");

          client.println("<form name=\"input\" action=\"\" method=\"post\">");
          client.println("<input type=\"submit\" name=\"%\" value=\"4\" style=\"height:50px; width:150px\" >");
          client.println("</form>");

          client.println("<form name=\"input\" action=\"\" method=\"post\">");
          client.println("<input type=\"submit\" name=\"%\" value=\"5\" style=\"height:50px; width:150px\" >");
          client.println("</form>");

          client.println("</center>");
          client.println("</html>");
          
          delay(500);//delay is very important. It gives the browser time to process requests 
          letterCount = 0;
          checkAction();//go to check action function is a HTML button is pressed. 
          break;
        }

        //Serial.print(c);

        //We detect where the actual post data is in other words what the user entered
        //once we isolate it we can parse it and use it
        if (c =='%')
        {
          dataFlag = 1;
        }
          if (dataFlag == 1)
          {
            //in here goes the user entered data it follows the string "25="
            if (c == '=')
            {
              //trim the fat of the soon to be recorded char so we only get the user entered message
              msgIsolator = 1;
            }
          }
      }
    }

  // give the web browser time to receive the data
  delay(100);//delay is very important 
  client.flush();
  client.stop();
  }
}

///////////////////////////////////////////////////////////////////////

char recordMessage (char incomingMsg)
{
  //letterCount = 0;
  msg[letterCount] = incomingMsg;
  letterCount++;
  delay(100);
}
///////////////////////////////////////////////////////////////////////



void checkAction() 
{ 

  if (msg[0] == 'L' )// Move Left
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor2.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor3.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
        delay(1000);
  }
  //-------------------------------------------------------
  else if (msg[0] == 'R')// Move Right
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor2.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor3.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
        delay(1000);
  }
  //-------------------------------------------------------
  else if (msg[0] == 'F')// Move Forward
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor2.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor3.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
        delay(1000);
  }  
  //-------------------------------------------------------

  else if (msg[0] == 'B')// Move Backward
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor2.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor3.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
        delay(1000);
  }
  //-------------------------------------------------------

  else if (msg[0] == '1')// set speed
  {
    speed_scale = 1
  }
  else if (msg[0] == '2')
  {
    speed_scale = 2
  }
  else if (msg[0] == '3')
  {
    speed_scale = 3
  }
  else if (msg[0] == '4')
  {
    speed_scale = 4
  }
  else if (msg[0] == '5')
  {
    speed_scale = 5
  }
// angled turn needs to be added after testing
}//end checkAction()
