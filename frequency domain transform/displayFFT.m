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
r=real(FC);          %ͼ��Ƶ��ʵ��
i=imag(FC);          %ͼ��Ƶ���鲿
margin=log(abs(FC));      %ͼ������ף���log������ʾ
phase=log(angle(FC)*180/pi);     %ͼ����λ��
fphase = ifft2(phase);
fmargin = ifft2(margin);
l=log(FC);           
subplot(2,2,1),imshow(f),title('Դͼ��');
subplot(2,2,2),imshow(l,[]),title('ͼ��Ƶ��');
subplot(2,2,3),imshow(fmargin,[]),title('ͼ������׷��任');
subplot(2,2,4),imshow(fphase,[]),title('ͼ����λ�׷��任');
