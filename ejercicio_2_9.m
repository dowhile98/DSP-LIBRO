clear
close all
iptsetpref('ImshowBorder', 'tight')

FontSize=11;
FontName='Arial';

load('CODIGO KEIL\cap2_ejercicio_2_9\saw.dat')
n = 0:99;
figure(1);stem(n,saw(n+1),'filled','k.');
axis([0,100,-.7,0.7]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('saw[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);