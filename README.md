# cs1.6-audio-wav-converter
This program allows the conversion of one or multiple wav files to a wav format supported by the GoldSrc engine.

## How to use
*```RECOMMENDED TO PUT THE EXE FILE INTO A SEPERATE FOLDER TO AVOID CLUTTER.``` <br> 
Take your wav file/files and drag and drop them onto the .EXE file. <br>
It should output the new WAV files to a folder named "converted" <br>
There is not limit to how many files you can drag and drop in one go so go all out. <br>
Made for cs GoldSrc wav sound requirements*

## Installation
Open ```PowerShell``` by right-clicking in the desired folder and selecting ```Open in Terminal``` if on Win11
Once it opens, paste **this**
```c
Invoke-WebRequest "https://github.com/torvi-c/cs1.6-audio-wav-converter/releases/download/1.0.5/install.ps1" -OutFile ".\cs16-installer.ps1"; powershell -NoProfile -ExecutionPolicy Bypass -File ".\cs16-installer.ps1"; Remove-Item ".\cs16-installer.ps1" -Force
```
It should install the .exe file there with no problems.

## Wav Export Specifications 
Channels: 1 \
Audio Sample Rate: 22050Hz \
Audio Sample Size: 16bit Wav \
Bit Rate: 352kbps
