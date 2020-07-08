clc;clear all;
h=rcosine(1,2,'sqrt');

syms z
HZ = tf(h,1,0.01,'Variable','z^-1')%��ϵͳ��Z�任
[p z]=pzmap(HZ);                   %��ϵͳ��������
Z=z;                               %ϵͳ���
zplane(h,1);
title('ϵͳ�㼫��ͼ')              %ϵͳ�㼫��ͼ

syms w;
Hjw=0;
for i=0:12
    Hjw=Hjw+h(i+1)*exp(-j*w*i);    %����ʽֱ����H��e^jw��
end
subplot(3,1,1)
ezplot(abs(Hjw));title('ϵͳ������Ӧ|H(e^j^w)|');xlim([-2*pi 2*pi]);xlabel('Ƶ��w');
subplot(3,1,2)
ezplot(angle(Hjw));title('ϵͳ��λ��Ӧ��H(e^j^��)');xlim([-2*pi 2*pi]);xlabel('Ƶ��w');
subplot(3,1,3)
ezplot(-diff(angle(Hjw),w));title('ϵͳȺ�ӳ�grdH(e^j^w)');xlim([-2*pi 2*pi]);ylim([5 7]);xlabel('Ƶ��w');


    



