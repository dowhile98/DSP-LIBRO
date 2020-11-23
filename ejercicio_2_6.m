clear
close all
iptsetpref('ImshowBorder', 'tight')

FontSize=11;
FontName='Arial';

load('CODIGO KEIL\cap2_ejercicio_2_6\s.dat')
n = 0:511;
figure(1);stem(n,s(n+1),'filled','k.');
axis([0 511 -2.1 2.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('s[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);