%生成序列
N = 64; 
ModuA =[-1,1 ]/sqrt(2); 
hn=[1 0 0 0 0 0 0 0 0.5 0 0 0 0 0 0 0.25];
a = randsrc(N,1,ModuA,12345) + i *randsrc(N,1,ModuA,54321); 
%生成升余弦滤波器
Fd=1;Fs=4;hf=rcosine(Fd,Fs);
%采用根升余弦滤波器对上采样之后的符号序列进行滤波
x=conv(hf,upsample(a,4));

figure;
subplot(1,2,1);stem(real(a));title('原信号a[n]的实部');
subplot(1,2,2);stem(imag(a));title('原信号a[n]的虚部');
figure;
subplot(1,2,1);stem(real(x));title('经过升余弦滤波后x[n]的实部');
subplot(1,2,2);stem(imag(x));title('经过升余弦滤波后x[n]的虚部');

%画出符号序列a[n]和x[n]的4倍下采样值
hfoff=fix(length(hf)/2);
dx=downsample(x(hfoff+1:end-hfoff),4);
figure;
subplot(2,1,1);stem(real(a),'mo');hold on;stem(real(dx),'b');
title('a[n]和x[n]的4倍下采样值实部');
subplot(2,1,2);stem(imag(a),'mo');hold on;stem(real(dx),'b');
title('a[n]和x[n]的4倍下采样值虚部');


h=[1 0 0 0 0 0 0 0 0.5 0 0 0 0 0 0 0 0.25];
y=conv(h,x);
figure;%系统输出序列
subplot(2,1,1),stem(real(y));
subplot(2,1,2),stem(imag(y));
Ndft=128;
H=fft(h,Ndft);
Hi=1./H;%逆系统
hi=ifft(Hi,Ndft);%逆系统单位脉冲响应
figure;
subplot(2,1,1),stem(real(h));
subplot(2,1,2),stem(real(hi));
 
P=50;
hi=hi(1:P);
figure;
stem(real(hi));
yp=[zeros(P-1,1); y];
%计算每次截取的序列长度
Ly=Ndft-P+1;
%计算每次截取的序列长度
R=fix((length(yp)-P+1)/Ly);
%序列尾部添加0以保证序列长度
%正好可被整数倍截取
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
grid on; title('估计的均方误差vs逆系统脉冲响应长度');
xlabel('逆系统脉冲响应长度');ylabel('估计的均方误差');
