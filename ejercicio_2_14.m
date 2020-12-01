clear
close all
iptsetpref('ImshowBorder', 'tight')

FontSize=11;
FontName='Arial';

%% GRAFICA DE LA ENTRADA AL FILTRO
load('CODIGO KEIL\cap2_ejercicio_2_14\x.dat')
n = 0:511;
figure(1);stem(n,x(n+1),'filled','k');
%axis([0,9,0,10]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);

%% GRAFICA DE LA SALIDA
load('CODIGO KEIL\cap2_ejercicio_2_14\y.dat')
n = 0:511;
figure(2);stem(n,y(n+1),'filled','k');
%axis([0,9,0,10]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('y[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);