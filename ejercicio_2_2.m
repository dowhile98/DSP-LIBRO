clear
close all
iptsetpref('ImshowBorder', 'tight')

FontSize=11;
FontName='Arial';

load('CODIGO KEIL\cap2_ejercicio_2_2\dat1.dat')
n = 0:3:511;
figure(1);
stem(n,dat1(n+1),'filled','k.');
%axis([0 511 -1.1 1.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('sin1[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

load('CODIGO KEIL\cap2_ejercicio_2_2\dat2.dat')
n = 0:511;
figure(2);stem(n,dat2(n+1),'filled','k.');
%axis([0 511 -1.1 1.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('sin2[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);