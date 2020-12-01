clear
close all
iptsetpref('ImshowBorder', 'tight')

FontSize=11;
FontName='Arial';
%% entrada
load('CODIGO KEIL\cap2_ejercicio_2_18\x.dat')
n = 0:2:511;
figure(1);stem(n,x(n+1),'filled','k');
%axis([0 511 -1 1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

%% salida

load('CODIGO KEIL\cap2_ejercicio_2_18\y.dat')
n = 0:2:100;
figure(2);stem(n,y(n+1),'filled','k');
%axis([0 511 -1 1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);