function  [ EA ]=error2(Hp)
EA=zeros(1,256);
for a=1:104
    EA(a)=1-abs(Hp(a));
end
for a=105:149
    EA(a)=0;
end
for a=150:156
    EA(a)=-abs(Hp(a));
end
for a=156:194
    EA(a)=abs(Hp(a));
end
for a=194:256
    EA(a)=-abs(Hp(a));
end
end