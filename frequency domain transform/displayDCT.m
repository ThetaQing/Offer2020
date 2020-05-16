% 余弦变换的应用——压缩编码
clear                             %清除工作区间
RGB=imread('D:\Pic\simple\fourier.jpg');   %加载图片
GRAY=rgb2gray(RGB);               %彩色转灰度图
figure,
subplot(221),imshow(GRAY);               %显示灰度图
title('灰度图')
D=dct2(GRAY);                     %进行dct变换
subplot(222),imshow(log(1+abs(D)),[ ]);   %显示变换过程
title('余弦变换图')
colormap(gray(4));colorbar; % 显示色条
D(abs(D)<100)=0;
I=idct2(D)/255;                   %设置限值
subplot(223),imshow(I)                %显示变换后的图
title('变换之后的图')
% error = imsubtract(double(GRAY),I); % 不对
% subplot(224),imshow(error);
% title('误差')