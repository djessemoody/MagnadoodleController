function [radius, theta] = px_to_loc(y, x, OFFSET_Y, OFFSET_X, height)
y = y - 1;
x = x - 1;

r1 = sqrt((x - OFFSET_X)^2 + (height - y - OFFSET_Y)^2); % in pixels
t1 = atan2(height - y - OFFSET_Y , x - OFFSET_X) + atan2(height - OFFSET_Y , OFFSET_X) - pi; % in radians

% conversions
top_loc = 410;
bot_loc = 890;
rval = r1 + OFFSET_Y; % convert pixels to SoftPot values
radius = bot_loc - (bot_loc - top_loc) * rval / height;
theta = convang(t1, 'rad', 'deg'); % in degrees