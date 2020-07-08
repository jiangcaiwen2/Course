function  [ EA ]=error1(Hk)
EA=zeros(1,256);
for a=1:104
    EA(a)=1-abs(Hk(a));
end
for a=105:150
    EA(a)=0;
end
for a=151:179
    EA(a)=abs(Hk(a));
end
for a=180:209
    EA(a)=-abs(Hk(a));
end
for a=210:241
    EA(a)=abs(Hk(a));
end
for w=242:256
    EA(a)=-abs(Hk(a));
end
end