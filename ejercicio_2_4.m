clc
clear
N = 20-1;
iptsetpref('ImshowBorder', 'tight')
FontSize=11;
FontName='Arial';
%% x1
load('CODIGO KEIL\cap2_ejercicio_2_4\x1.dat')
n = 0:1:N;
figure(1);
stem(n,x1(n+1),'filled','k.','LineWidth',1,'Color','b');
axis([0 20 0 1.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x1[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
grid on
%% x2
load('CODIGO KEIL\cap2_ejercicio_2_4\x2.dat')
n = 0:1:N;
figure(2);
stem(n,x2(n+1),'filled','k.','LineWidth',1,'Color','b');
axis([0 20 -0.1 2.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x2[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
grid on
%% x3
load('CODIGO KEIL\cap2_ejercicio_2_4\x3.dat')
n = 0:1:N;
figure(3);
stem(n,x3(n+1),'filled','k.','LineWidth',1,'Color','b');
axis([0 20 -1.1 0]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x3[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
grid on
%% x4
load('CODIGO KEIL\cap2_ejercicio_2_4\x4.dat')
n = 0:1:N;
figure(4);
stem(n,x4(n+1),'filled','k.','LineWidth',1,'Color','b');
axis([0 20 -5.1 3]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x4[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
grid on
%% x5
load('CODIGO KEIL\cap2_ejercicio_2_4\x5.dat')
n = 0:1:N;
figure(5);
stem(n,x5(n+1),'filled','k.','LineWidth',1,'Color','b');
axis([0 20 0 1.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x5[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
grid on
%% x6
load('CODIGO KEIL\cap2_ejercicio_2_4\x6.dat')
n = 0:1:N;
figure(6);
stem(n,x6(n+1),'filled','k.','LineWidth',1,'Color','b');
axis([0 20 0 1.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x6[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
grid on
%% x7
load('CODIGO KEIL\cap2_ejercicio_2_4\x7.dat')
n = 0:1:N;
figure(7);
stem(n,x7(n+1),'filled','k.','LineWidth',1,'Color','b');
axis([0 20 -1 1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x7[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
grid on
%% x8
load('CODIGO KEIL\cap2_ejercicio_2_4\x8.dat')
n = 0:1:N;
figure(8);
stem(n,x8(n+1),'filled','k.','LineWidth',1,'Color','b');
axis([0 20 0 1.1]);
lab=xlabel('n');
set(lab,'FontName',FontName,'FontSize',FontSize);
lab=ylabel('x8[n]');
set(lab,'FontName',FontName,'FontSize',FontSize);
