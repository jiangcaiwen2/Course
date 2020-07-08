%��������
N = 64; 
ModuA =[-1,1 ]/sqrt(2); 
hn=[1 0 0 0 0 0 0 0 0.5 0 0 0 0 0 0 0.25];
a = randsrc(N,1,ModuA,12345) + i *randsrc(N,1,ModuA,54321); 
%�����������˲���
Fd=1;Fs=4;hf=rcosine(Fd,Fs);
%���ø��������˲������ϲ���֮��ķ������н����˲�
x=conv(hf,upsample(a,4));

figure;
subplot(1,2,1);stem(real(a));title('ԭ�ź�a[n]��ʵ��');
subplot(1,2,2);stem(imag(a));title('ԭ�ź�a[n]���鲿');
figure;
subplot(1,2,1);stem(real(x));title('�����������˲���x[n]��ʵ��');
subplot(1,2,2);stem(imag(x));title('�����������˲���x[n]���鲿');

%������������a[n]��x[n]��4���²���ֵ
hfoff=fix(length(hf)/2);
dx=downsample(x(hfoff+1:end-hfoff),4);
figure;
subplot(2,1,1);stem(real(a),'mo');hold on;stem(real(dx),'b');
title('a[n]��x[n]��4���²���ֵʵ��');
subplot(2,1,2);stem(imag(a),'mo');hold on;stem(real(dx),'b');
title('a[n]��x[n]��4���²���ֵ�鲿');


h=[1 0 0 0 0 0 0 0 0.5 0 0 0 0 0 0 0 0.25];
y=conv(h,x);
figure;%ϵͳ�������
subplot(2,1,1),stem(real(y));
subplot(2,1,2),stem(imag(y));
Ndft=128;
H=fft(h,Ndft);
Hi=1./H;%��ϵͳ
hi=ifft(Hi,Ndft);%��ϵͳ��λ������Ӧ
figure;
subplot(2,1,1),stem(real(h));
subplot(2,1,2),stem(real(hi));
 
P=50;
hi=hi(1:P);
figure;
stem(real(hi));
yp=[zeros(P-1,1); y];
%����ÿ�ν�ȡ�����г���
Ly=Ndft-P+1;
%����ÿ�ν�ȡ�����г���
R=fix((length(yp)-P+1)/Ly);
%����β�����0�Ա�֤���г���
%���ÿɱ���������ȡ
Lpy=(R+1)*Ly-length(y);
ypp=[yp;zeros(Lpy,1)];
ye=[];
  for hf=0:R
      z=ypp(hf*(Ndft-P+1)+(1:Ndft));
      Z=fft(z,Ndft);
      ZE=Z.*Hi;
      ze=ifft(ZE,Ndft);
      ye=[ye;ze(P:end)];
  end
figure;
subplot(2,1,1),stem(real(ye));
subplot(2,1,2),stem(real(ye));
  
a1=downsample(ye(hfoff+1:end-hfoff-length(h)+1-Lpy),4);
% 
% 
% figure;
% subplot(2,1,1),stem(real(a),'mo');
% hold on; stem(real(a1), 'b.');
% subplot(2,1,2),stem(imag(a),'mo');
% hold on; stem(imag(a1), 'b.');

h=scatterplot(a,1,1,'ro');
hold on;
scatterplot(a1,1,1,'b.',h);
mse=var(a1-a)
figure;
plot(10*log10(mse));
grid on; title('���Ƶľ������vs��ϵͳ������Ӧ����');
xlabel('��ϵͳ������Ӧ����');ylabel('���Ƶľ������');
