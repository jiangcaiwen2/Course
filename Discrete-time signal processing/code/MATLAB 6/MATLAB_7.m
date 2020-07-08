clc;
close all;
clear all;

%% kaiser 窗
[n,Wn,bta,filtype]=kaiserord([0.4*pi 0.58*pi],[1 0],[0.0531 0.085],2*pi);
h=fir1(n,Wn,filtype,kaiser(n+1,bta),'noscale');
[H,w] = freqz(h,1,256);
[EA_1]=error1(H);
subplot(1,2,1);
plot(h);
xlabel('n');ylabel('幅值h[n]');
title('单位脉冲响应h[n]-kaiser');grid on;
subplot(1,2,2);
plot(w/pi,20*log10(abs(H/max(H)))); 
xlabel('归一化频率/\pi'); ylabel('20log_{10}|W(e^{j\omega})| /dB'); 
title('对数幅度响应-kaiser'); grid on;
figure;
plot(w/pi,EA_1);
xlabel('归一化频率/\pi');
title('未加权误差函数-kaiser'); grid on;
 
%% Parks-McClellan
[n,fo,mo,w]=firpmord([0.4*pi 0.58*pi],[1 0],[0.0531 0.085],2*pi);
h_2=firpm(n,fo,mo,w);
[H_2,w] = freqz(h_2,1,256); 
[EA_2]=error2(H_2);
figure;
subplot(1,2,1);
plot(h_2);
xlabel('n');ylabel('幅值h[n]');
title('单位脉冲响应h[n]-Parks-McClellan');grid on;
subplot(1,2,2);
plot(w/pi,20*log10(abs(H_2/max(H_2)))); 
xlabel('归一化频率/\pi'); ylabel('20log_{10}|W(e^{j\omega})| /dB'); 
title('对数幅度响应-Parks-McClellan'); grid on;
figure;
plot(w/pi,EA_2);
xlabel('归一化频率/\pi');
title('未加权误差函数-Parks-McClellan'); grid on;