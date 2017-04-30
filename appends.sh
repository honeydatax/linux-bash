printf "" > page1.ps
echo "%PS" >> page1.ps
echo "/Times-Roman findfont" >> page1.ps
echo "16 scalefont" >> page1.ps
echo "setfont" >> page1.ps
echo "newpath" >> page1.ps
echo "10 800 moveto" >> page1.ps
echo "(page 1) show" >> page1.ps

printf "" > page2.ps
echo "%PS" >> page2.ps
echo "/Times-Roman findfont" >> page2.ps
echo "16 scalefont" >> page2.ps
echo "setfont" >> page2.ps
echo "newpath" >> page2.ps
echo "10 800 moveto" >> page2.ps
echo "(page 2) show" >> page2.ps

ps2pdf page1.ps page1.pdf
ps2pdf page2.ps page2.pdf
gs -dNOPAUSE -sDEVICE=pdfwrite -sOUTPUTFILE=book.pdf -dBATCH page1.pdf page2.pdf
xpdf book.pdf &



















