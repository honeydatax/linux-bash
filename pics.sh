#!/bin/bash

a=$(zenity --file-selection --title="select a bitmap to convert into jpg")

cjpeg -quality 100 "$a" > "$a.jpg"



























