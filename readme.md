This is my Fork of a Fork of WLED. (What?)<br>
WLED is neat. WLED-Audio reactive my Atuline is neat too.<br>
But i'm missing MSGEQE7 support so here i am coding it myself.<br>
At least i try to.<br><br>


## Current Pins: 
audio_reactive.h:

#define pinAnalog A0      //A0 on ESP8266<br>
#define pinReset 5        //GPIO5<br>
#define pinStrobe 4       //GPIO4<br>
<br><br>
feel free to change it for your needs.
<br><br><br><br>
THIS MAY NOT BE MAINTAINED!

<br>


# 👋 Welcome to my project WLED!

A fast and feature-rich implementation of an ESP8266/ESP32 webserver to control NeoPixel (WS2812B, WS2811, SK6812, APA102) LEDs or also SPI based chipsets like the WS2801!

## ⚙️ Features
- Everything from WLED
- MSGEQ7 Support
- Music Reactive Effects from atuline and his community
- EEPROM Saving
- Frequency per Preset

## 💡 Supported light control interfaces
- WLED app for Android and iOS
- JSON and HTTP request APIs
- MQTT
- Blynk IoT
- E1.31
- Hyperion
- UDP realtime
- Alexa voice control (including dimming and color)
- Sync to Philips hue lights
- Adalight (PC ambilight via serial)
- Sync color of multiple WLED devices (UDP notifier)
- Infrared remotes (24-key RGB, receiver required)
- Simple timers/schedules (time from NTP, timezones/DST supported)

## 📲 Quick start guide and documentation

See the [WLED-wiki](https://github.com/Aircoookie/WLED/wiki)!<br>
See the [Music Reactive-wiki from atuline](https://github.com/atuline/WLED/wiki)!

DrZzs has made some excellent video guides:
[Introduction, hardware and installation](https://www.youtube.com/watch?v=tXvtxwK3jRk)
[Settings, tips and tricks](https://www.youtube.com/watch?v=6eCE2BpLaUQ)

If you'd rather read, here is a very [detailed step-by-step beginner tutorial](https://tynick.com/blog/11-03-2019/getting-started-with-wled-on-esp8266/) by tynick!


## ✌️ Other

Licensed under the MIT license
Credits [here](https://github.com/Aircoookie/WLED/wiki/Contributors-&-About)!

Uses Linearicons by Perxis!

Join the Discord server to discuss everything about WLED!
Any Questions? Hit me up @NeariX#4799 on Discord!

<a href="https://discord.gg/KuqP7NE"><img src="https://discordapp.com/api/guilds/473448917040758787/widget.png?style=banner2" width="25%"></a>

Check out the WLED [Discourse forum](https://wled.discourse.group)!
You can also send me mails to [dev.aircoookie@gmail.com](mailto:dev.aircoookie@gmail.com), but please only do so if you want to talk to me privately.
If WLED really brightens up your every day, you can [![](https://img.shields.io/badge/send%20me%20a%20small%20gift-paypal-blue.svg?style=flat-square)](https://paypal.me/aircoookie)


*Disclaimer:*
If you are prone to photo epileptic seizures, it is not recommended that you use this software.
If you still want to try, **DO NOT** use strobe, lightning or noise modes or high effect-speed settings.
As per the MIT license, I assume no liability for any damage to you or any other person or equipment.

