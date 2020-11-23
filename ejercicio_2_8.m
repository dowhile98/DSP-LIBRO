clear
close all
iptsetpref('ImshowBorder', 'tight')

FontSize=11;
FontName='Arial';

load('CODIGO KEIL\cap2_ejercicio_2_8\square.dat')
n = 0:199;
figure(1);stem(n,square(n+1),'filled','k.');
axis([0,200,-2.6,2.6]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('sq[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_8\triangle.dat')
figure(2);stem(n,triangle(n+1),'filled','k.');
axis([0,200,-1.6,1.6]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('tr[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);