clear
close all
iptsetpref('ImshowBorder', 'tight')

FontSize=11;
FontName='Arial';

load('CODIGO KEIL\cap2_ejercicio_2_13\y1.dat')
n = 0:9;
figure(1);stem(n,y1(n+1),'filled','k');
axis([0,9,0,10]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_1[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_13\y2.dat')
figure(2);stem(n,y2(n+1),'filled','k');
axis([0,9,0,85]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_2[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_13\y3.dat')
figure(3);stem(n,y3(n+1),'filled','k');
axis([0,9,0,30]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_3[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_13\y4.dat')
figure(4);stem(n,y4(n+1),'filled','k');
axis([0,9,-90,120]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_4[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);