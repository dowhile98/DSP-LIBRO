clear
close all
iptsetpref('ImshowBorder', 'tight')

FontSize=11;
FontName='Arial';

load('CODIGO KEIL\cap2_ejercicio_2_3\acc_buffer.dat')
n = 0:7:1999;
figure(1);
stem(n,acc_buffer(n+1),'filled','k.','Color','b');
%axis([500,1000,-2100,2100]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('acc\_buffer[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
