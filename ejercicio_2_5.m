close all
iptsetpref('ImshowBorder', 'tight')

FontSize=11;
FontName='Arial';
%% x1
load('CODIGO KEIL\cap2_ejercicio_2_5\x1.dat')
n = 0:9;
figure(1);stem(n,x1(n+1),'filled','k');
axis([0,9,0,5.7]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x_1[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
%% x2
load('CODIGO KEIL\cap2_ejercicio_2_5\x2.dat')
figure(2);stem(n,x2(n+1),'filled','k');
axis([0,9,0,1.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x_2[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
%% x3
load('CODIGO KEIL\cap2_ejercicio_2_5\x3.dat')
figure(3);stem(n,x3(n+1),'filled','k');
axis([0,9,0,1.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x_3[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
%% x4
load('CODIGO KEIL\cap2_ejercicio_2_5\x4.dat')
figure(4);stem(n,x4(n+1),'filled','k');
axis([0,9,-1.1,1.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x_4[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
%% x5
load('CODIGO KEIL\cap2_ejercicio_2_5\x5.dat')
figure(5);stem(n,x5(n+1),'filled','k');
axis([0,9,-1.6,0.6]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x_5[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);