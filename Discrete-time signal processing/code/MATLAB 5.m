clc;clear all;
h=rcosine(1,2,'sqrt');

syms z
HZ = tf(h,1,0.01,'Variable','z^-1')%求系统的Z变换
[p z]=pzmap(HZ);                   %求系统极点和零点
Z=z;                               %系统零点
zplane(h,1);
title('系统零极点图')              %系统零极点图

syms w;
Hjw=0;
for i=0:12
    Hjw=Hjw+h(i+1)*exp(-j*w*i);    %定义式直接求H（e^jw）
end
subplot(3,1,1)
ezplot(abs(Hjw));title('系统幅度响应|H(e^j^w)|');xlim([-2*pi 2*pi]);xlabel('频率w');
subplot(3,1,2)
ezplot(angle(Hjw));title('系统相位响应∠H(e^j^ω)');xlim([-2*pi 2*pi]);xlabel('频率w');
subplot(3,1,3)
ezplot(-diff(angle(Hjw),w));title('系统群延迟grdH(e^j^w)');xlim([-2*pi 2*pi]);ylim([5 7]);xlabel('频率w');


    



