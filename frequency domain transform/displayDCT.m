% ���ұ任��Ӧ�á���ѹ������
clear                             %�����������
RGB=imread('D:\Pic\simple\fourier.jpg');   %����ͼƬ
GRAY=rgb2gray(RGB);               %��ɫת�Ҷ�ͼ
figure,
subplot(221),imshow(GRAY);               %��ʾ�Ҷ�ͼ
title('�Ҷ�ͼ')
D=dct2(GRAY);                     %����dct�任
subplot(222),imshow(log(1+abs(D)),[ ]);   %��ʾ�任����
title('���ұ任ͼ')
colormap(gray(4));colorbar; % ��ʾɫ��
D(abs(D)<100)=0;
I=idct2(D)/255;                   %������ֵ
subplot(223),imshow(I)                %��ʾ�任���ͼ
title('�任֮���ͼ')
% error = imsubtract(double(GRAY),I); % ����
% subplot(224),imshow(error);
% title('���')