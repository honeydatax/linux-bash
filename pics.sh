#!/bin/bash

a=$(zenity --file-selection --title="select a bitmap to convert into jpg" --file-filter="*.bmp")

cjpeg -quality 100 "$a" > "$a.jpg"

xdg-open "$a.jpg" &

























