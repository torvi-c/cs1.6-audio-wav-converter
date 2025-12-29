// --- MADE BY TORVI ---

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Drag and drop WAV files onto this EXE to convert.\n");
        return 1;
    }

    char command[512];
    char outFolder[] = "converted";

    // Create output folder
    system("mkdir converted 2>nul");

    for (int i = 1; i < argc; i++) {
        char *inFile = argv[i];

        char fileName[256];
        const char *slash = strrchr(inFile, '\\');
        strcpy(fileName, slash ? slash + 1 : inFile);

        char outPath[300];
        sprintf(outPath, "%s/%s", outFolder, fileName);

        printf("Converting: %s → %s\n", fileName, outPath);

        sprintf(command,
            "ffmpeg -i \"%s\" -ac 1 -ar 22050 -sample_fmt s16 \"%s\" -y -loglevel quiet",
            inFile, outPath);

        system(command);
    }

    printf("Creating ZIP archive...\n");

    // --- Unix time handling ---
    long unixTime = time(NULL);
    char zipName[64];
    sprintf(zipName, "CA_%ld.zip", unixTime);

    // Create ZIP archive using PowerShell
    sprintf(command,
        "powershell -Command \"Compress-Archive -Path '%s/*' -DestinationPath '%s' -Force\"",
        outFolder, zipName);
    system(command);

    // Remove the converted folder after zipping
    sprintf(command, "rmdir /S /Q \"%s\"", outFolder);
    system(command);

    printf("Done! Output: %s\n", zipName);
    return 0;
}
