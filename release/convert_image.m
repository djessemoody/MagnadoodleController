% Converts and resizes an image to fit the Magna Doodle
%  1. scales to fit within board, preserving aspect ratio
%  2. pads sides with white to match desired size
function output_image = convert_image(input_image, board_height, board_width)
output_image = input_image;

% cast as double (map values 0-255 to 0.0-1.0)
[height width channels] = size(output_image);
output_image = im2uint8(output_image);

% convert to grayscale and verify
channels = size(output_image, 3);
if channels == 3
    output_image = rgb2gray(output_image);
end
channels = size(output_image, 3);
assert(channels == 1);

% rotate if necessary to maximize image size on board
if height > width
    output_image = imrotate(output_image, 90);
    [height width channels] = size(output_image);
end

% calculate ratios for comparison
img_ratio = width / height;
board_ratio = board_width / board_height;

if img_ratio < board_ratio
    % pad left/right with white pixels:
    %  ------------
    %  |  |    |  |
    %  |  |    |  |
    %  |  |    |  |
    %  ------------
    output_image = imresize(output_image, board_height / height);
    [height width] = size(output_image);
    % pad left and right with white
    pad = 255 * ones(height, (board_width - width) / 2);
    output_image = [pad, output_image, pad];
else
    % pad top/bottom with white pixels:
    %  ------------
    %  |----------|
    %  |          |
    %  |----------|
    %  ------------
    output_image = imresize(output_image, board_width / width);
    [height width] = size(output_image);
    % pad top and bottom with white
    pad = 255 * ones((board_height - height) / 2, width);
    output_image = [pad; output_image; pad];
end
[height width] = size(output_image);