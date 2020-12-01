clear
close all
iptsetpref('ImshowBorder', 'tight')

FontSize=11;
FontName='Arial';

load('CODIGO KEIL\cap2_ejercicio_2_10\y1.dat')
n=0:19;
figure(1);stem(n,y1(n+1),'filled','k')
axis([0,19,0,2.3]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_1[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_10\y2.dat')
figure(2);stem(n,y2(n+1),'filled','k')
axis([0,19,0,2.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_2[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_10\y3.dat')
figure(3);stem(n,y3(n+1),'filled','k')
axis([0,19,0,1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_3[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_10\y4.dat')
figure(4);stem(n,y4(n+1),'filled','k')
axis([0,19,-1.6,1.6]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_4[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_10\y5.dat')
figure(5);stem(n,y5(n+1),'filled','k')
axis([0,19,-4,4.5]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_5[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_10\y6.dat')
figure(6);stem(n,y6(n+1),'filled','k')
axis([-1,18,0,2.3]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_6[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_10\y7.dat')
figure(7);stem(n,y7(n+1),'filled','k')
%axis([0,19,0,550]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_7[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_10\y8.dat')
figure(8);stem(n,y8(n+1),'filled','k')
%axis([0,19,-8.1,4]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y_8[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);



