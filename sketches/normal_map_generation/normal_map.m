RGB = imread('normal_input.jpg');
Gray = rgb2gray(RGB);

Diff_X = diff(double(Gray), 1, 2);
Diff_Y = diff(double(Gray), 1, 1);

# pad both matrices since one row/column was lost due to the diff-operation
Diff_X(:, 512) = Diff_X(:, 511);
Diff_Y(512, :) = Diff_Y(511, :);

# strength of normal map effect (x-component has to inverted, because
# difference was taken into other direction)

# TODO: strength should go from 0% (no normal effect) to 100% (complete range
# used)
strength = 5.0;
Diff_X = -strength * Diff_X;
Diff_Y = strength * Diff_Y;

# bring from range -255..255 into range 0..255
# 0 => X/Y = -1.0 (normal)
# 128 => X/Y = 0.0 (normal)
# 255 => X/Y = 1.0 (normal)
Diff_X = (Diff_X + 255.0) / 2.0;
Diff_Y = (Diff_Y + 255.0) / 2.0;

# convert to normal map
Out_RGB = zeros(512, 512, 3);
Out_RGB(:,:,1) = Diff_X;
Out_RGB(:,:,2) = Diff_Y;
Out_RGB(:,:,3) = 255.0;

imwrite(uint8(Out_RGB), 'normal_output.png');
