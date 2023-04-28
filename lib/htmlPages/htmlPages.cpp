#include "htmlPages.h"

String htmlPages::home(){
    String htmlString = "<!DOCTYPE html> \
<html> \
<head> \
  <meta charset=\"UTF-8\"> \
  <title>IoT Device Configuration Instructions</title> \
  <style> \
    h1 { \
      text-align: center; \
    } \
    /* Rest of the CSS styles */ \
  </style> \
</head> \
<body> \
  <h1>IoT Device Configuration Instructions</h1> \
  <h2>Step 1: Connect to Wi-Fi</h2> \
  <p>Connect your device to your Wi-Fi network by following these steps:</p> \
  <ol> \
    <li>Plug in your device and wait for it to power on.</li> \
    <li>Open the Wi-Fi settings on your smartphone or computer.</li> \
    <li>Look for a network called \"[Device Name] Setup\" and connect to it.</li> \
    <li>Once connected, return to the device setup app to continue.</li> \
  </ol> \
  <h2>Step 2: Configure Device Settings</h2> \
  <p>Configure your device settings by following these steps:</p> \
  <ol> \
    <li>Open the device setup app.</li> \
    <li>Follow the on-screen instructions to connect your device to your home Wi-Fi network.</li> \
    <li>Enter any additional information requested by the app (such as your device name or room location).</li> \
    <li>Wait for the app to complete the device configuration process.</li> \
  </ol> \
  <h2>Step 3: Verify Device Connectivity</h2> \
  <p>Verify that your device is connected to your home Wi-Fi network by following these steps:</p> \
  <ol> \
    <li>Open the device setup app.</li> \
    <li>Check the device status to confirm that it is connected to your home Wi-Fi network.</li> \
    <li>If the device is not connected, follow the on-screen instructions to troubleshoot the issue.</li> \
  </ol> \
  <!-- Rest of the HTML code --> \
  <form action=\"/login\">\
  <button type=\"submit\">Next</button>\
    </form>\
</body> \
</html>";
    return htmlString;
}

String htmlPages::login(bool crdentials){
    String htmlPage = "<!DOCTYPE html> \
                <html> \
                <head> \
                <title>Login Page</title> \
                <style> \
                body { \
                background-color: #F5F5F5; \
                font-family: Arial, sans-serif; \
                } \
                h1 { \
                text-align: center; \
                font-size: 36px; \
                margin-top: 50px; \
                margin-bottom: 30px; \
                } \
                form { \
                background-color: #FFFFFF; \
                border: 1px solid #DDDDDD; \
                padding: 20px; \
                max-width: 400px; \
                margin: 0 auto; \
                border-radius: 5px; \
                box-shadow: 0px 0px 10px #DDDDDD; \
                } \
                label { \
                display: block; \
                margin-bottom: 10px; \
                font-weight: bold; \
                } \
                input[type=\"text\"], input[type=\"password\"] { \
                width: 100%; \
                padding: 10px; \
                border: 1px solid #CCCCCC; \
                border-radius: 5px; \
                margin-bottom: 20px; \
                font-size: 16px; \
                box-sizing: border-box; \
                } \
                input[type=\"submit\"] { \
                background-color: #4CAF50; \
                color: #FFFFFF; \
                border: none; \
                padding: 10px 20px; \
                border-radius: 5px; \
                font-size: 16px; \
                cursor: pointer; \
                transition: background-color 0.3s ease; \
                } \
                input[type=\"submit\"]:hover { \
                background-color: #3E8E41; \
                } \
                </style> \
                </head> \
                <body> \
                <h1>Login</h1> \
                <form action=\"/login\" method=\"post\"> \
                <label for=\"username\">Username:</label> \
                <input type=\"text\" id=\"username\" name=\"username\" required> \
                <label for=\"password\">Password:</label> \
                <input type=\"password\" id=\"password\" name=\"password\" required> \
                <input type=\"submit\" value=\"Login\">";
                if(crdentials){
                    htmlPage+="<br><br><label id=\"error_label\" style=\"color:red;\">Invalid credentials</label>";
                }
                
                htmlPage+="</form> \
                </body> \
                </html>";

return htmlPage;

}

String htmlPages::config(){
   String html = "<!DOCTYPE html><html><head><title>Device Setup</title><style>body{background-color:#F5F5F5;font-family:Arial,sans-serif}h1{text-align:center;font-size:36px;margin-top:50px;margin-bottom:30px}form{background-color:#FFFFFF;border:1px solid #DDDDDD;padding:20px;max-width:400px;margin:0 auto;border-radius:5px;box-shadow:0px 0px 10px #DDDDDD}label{display:block;margin-bottom:10px;font-weight:bold}input[type=\"text\"],input[type=\"password\"]{width:100%;padding:10px;border:1px solid #CCCCCC;border-radius:5px;margin-bottom:20px;font-size:16px;box-sizing:border-box}input[type=\"submit\"]{background-color:#4CAF50;color:#FFFFFF;border:none;padding:10px 20px;border-radius:5px;font-size:16px;cursor:pointer;transition:background-color 0.3s ease}input[type=\"submit\"]:hover{background-color:#3E8E41}</style></head><body><h1>Device Setup</h1><form action=\"/config\" method=\"post\"><label for=\"username\">Username:</label><input type=\"text\" id=\"username\" name=\"username\" required><label for=\"user_password\">Password:</label><input type=\"password\" id=\"user_password\" name=\"user_password\" required><label for=\"ssid\">WiFi Network Name:</label><input type=\"text\" id=\"ssid\" name=\"ssid\" required><label for=\"password\">WiFi Password:</label><input type=\"password\" id=\"password\" name=\"password\" required><label for=\"device_name\">Device Name:</label><input type=\"text\" id=\"device_name\" name=\"device_name\" required><label for=\"device_password\">Device Password:</label><input type=\"password\" id=\"device_password\" name=\"device_password\" required><input type=\"submit\" value=\"Save\"></form></body></html>";

    return html;
}