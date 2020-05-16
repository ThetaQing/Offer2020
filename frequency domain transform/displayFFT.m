f = imread('D:\Pic\simple\fourier.jpg');
f = rgb2gray(f);
F = fft2(f);

FC = fftshift(F);
S = abs(FC);
S2 = log(1 + abs(FC));
figure();
subplot(121),imshow(S,[]);
title('abs(F)');
subplot(122),imshow(S2,[]);
title('log(1+abs(FC))');
%%
r=real(FC);          %图像频域实部
i=imag(FC);          %图像频域虚部
margin=log(abs(FC));      %图像幅度谱，加log便于显示
phase=log(angle(FC)*180/pi);     %图像相位谱
fphase = ifft2(phase);
fmargin = ifft2(margin);
l=log(FC);           
subplot(2,2,1),imshow(f),title('源图像');
subplot(2,2,2),imshow(l,[]),title('图像频谱');
subplot(2,2,3),imshow(fmargin,[]),title('图像幅度谱反变换');
subplot(2,2,4),imshow(fphase,[]),title('图像相位谱反变换');
