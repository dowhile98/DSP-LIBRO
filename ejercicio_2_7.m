clear
close all
iptsetpref('ImshowBorder', 'tight')

FontSize=11;
FontName='Arial';
%% sin1
load('CODIGO KEIL\cap2_ejercicio_2_7\s1.dat')
n=0:99;
figure(1);stem(n,s1(n+1),'filled','k','Color','g')
axis([0,100,-1.1,1.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('sin1[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
grid on
%% sin2
load('CODIGO KEIL\cap2_ejercicio_2_7\s2.dat')
figure(2);stem(n,s2(n+1),'filled','k','Color','g')
axis([0,100,-1.1,1.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('sin2[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
grid on