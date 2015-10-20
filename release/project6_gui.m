%{

ECE 495 Project 6
12/04/13
Group 13: John Berry, Prateek Diwan, Taylor Etcheson, Jesse Moody,
Scott Winters

%}


function varargout = project6_gui(varargin)
% PROJECT6_GUI MATLAB code for project6_gui.fig
%      PROJECT6_GUI, by itself, creates a new PROJECT6_GUI or raises the existing
%      singleton*.
%
%      H = PROJECT6_GUI returns the handle to a new PROJECT6_GUI or the handle to
%      the existing singleton*.
%
%      PROJECT6_GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PROJECT6_GUI.M with the given input arguments.
%
%      PROJECT6_GUI('Property','Value',...) creates a new PROJECT6_GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before project6_gui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to project6_gui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help project6_gui

% Last Modified by GUIDE v2.5 03-Dec-2013 15:32:27

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @project6_gui_OpeningFcn, ...
                   'gui_OutputFcn',  @project6_gui_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end

% End initialization code - DO NOT EDIT


% --- Outputs from this function are returned to the command line.
function varargout = project6_gui_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% --- Executes just before project6_gui is made visible.
function project6_gui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to project6_gui (see VARARGIN)

% Choose default command line output for project6_gui
handles.output = hObject;
% Update handles structure
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function figure1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

clc; % clear the command window

% global constants
global BOARD_HEIGHT;
global BOARD_WIDTH;
global OFFSET_X;
global OFFSET_Y;
global START_THETA;
global START_RADIUS;
global START_DARK;

% other globals
global my_arduino;
global tg;
global filename;

% initialize parameters
RES = 2.0;  % px/cm
BOARD_HEIGHT_CM = 17;
BOARD_WIDTH_CM = 24;
BOARD_HEIGHT = BOARD_HEIGHT_CM * RES;
BOARD_WIDTH = BOARD_WIDTH_CM * RES;
OFFSET_Y_CM = -10.4;
OFFSET_X_CM = 13;
OFFSET_Y = OFFSET_Y_CM * RES;
OFFSET_X = OFFSET_X_CM * RES;
START_RADIUS = 340;   % upper left corner
START_THETA = 0;      % upper left corner
START_DARK = 0;

% initialize Arduino
delete(instrfind({'Port'},{'COM4'}));
my_arduino = arduino('COM4');
arduino_interface(my_arduino,500);

disp('Move electromagnet to upper left corner of board now and press ENTER....');
pause;

arduino_interface(my_arduino, START_RADIUS);

fprintf('Now loading model....\n');

% load model, connect to xPC, and start running
tg = xpc;
filename = 'project6_model';
load_system(filename);
if strcmp(tg.application, filename)
    tg.load(filename);
else
    rtwbuild(filename);
end
set_param(gcs, 'SimulationCommand', 'connect');
set_param(gcs, 'SimulationCommand', 'start');
tg.start;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% initialize system parameters
set_param('project6_model/Darkness setpoint', 'Value', num2str(START_DARK));
set_param('project6_model/Angle setpoint', 'Value', num2str(START_THETA)); % assumes the emag is at the lower left

fprintf('Opening GUI...\n');


% --- Executes on button press in btn_browse.
% Only performs image processing
function btn_browse_Callback(hObject, eventdata, handles)
% hObject    handle to btn_browse (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Constants
global BOARD_HEIGHT;
global BOARD_WIDTH;

% other globals
global width;
global height;
global draw_image;

% read in bitmap image
[filename, pathname] = uigetfile('*.bmp', 'Pick a bitmap file');
fullpath = fullfile(pathname, filename);
if isequal(filename,0) || isequal(pathname,0)
    disp('User pressed cancel. Terminating.')
    return;
else
    set(handles.txt_path, 'String', filename);
end
input_image = imread(fullpath);
draw_image = input_image;

% prepare new copy of image for drawing
draw_image = convert_image(draw_image, BOARD_HEIGHT, BOARD_WIDTH); % scale to size and pad with zeros
[height width channels] = size(draw_image);

figure;
subplot(1,2,1),subimage(input_image);title('Input image');
subplot(1,2,2),subimage(draw_image);title('Output image');
%figure, imshow(draw_image, 'InitialMagnification', 'fit'), title('Drawing Image');


% --- Executes on button press in btn_start.
function btn_start_Callback(hObject, eventdata, handles)
% hObject    handle to btn_start (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% global constants
global OFFSET_X;
global OFFSET_Y;
global WAIT_DARK;
global WAIT_LIGHT;
global WAIT_THETA;
global WAIT_THETA_SLOW;
global START_DARK;
global STEP_THETA;
global START_THETA;
global START_RADIUS;
% other globals
global width;
global height;
global draw_image;
global my_arduino;
global theta;
global run_flag;

% parameters
STEP_THETA  = 1.0;      % degrees
WAIT_DARK   = 0.2;      % seconds
WAIT_LIGHT  = 0;        % seconds
WAIT_THETA  = 0.25;     % seconds
WAIT_THETA_SLOW = 0.40; % seconds
THRESH_DARK = 0.1;      % volts
MAX_DARK    = 2.0;      % volts

run_flag = 1;

% nested for loop alternates directions every other row:
%     ------->
%     <-------
%     ------->
%     <-------
for y = 1:height
    ltr = mod(y, 2); % 1: left to right motion; 0: right to left
    if ltr
        init = 1;
        step = 1;
        final = width;
    else
        init = width;
        step = -1;
        final = 1;
    end

    for x = init:step:final
        if ~run_flag
            return;
        end
        % calculate position and darkness for drawing at this location
        d1 = imcomplement(draw_image);
        d1 = d1(y,x);
        if d1 < 50  
            d1 = 0;
        elseif d1 < 100
            d1 = .2;
        elseif d1 < 150
            d1 = .3;
        elseif d1 < 200
            d1 = .4;
        else d1 = 1;
        end
        darkness = d1 * MAX_DARK;
        
        [radius, theta] = px_to_loc(y, x, OFFSET_Y, OFFSET_X, height);

        % nothing to draw at this pixel, so skip
        WAIT_TIME = WAIT_DARK;
        WAIT_T = WAIT_THETA;
        if darkness < THRESH_DARK
            WAIT_T = WAIT_LIGHT;
            WAIT_TIME = WAIT_LIGHT;
        end

        set(handles.txt_x, 'String', num2str(x));
        set(handles.txt_y, 'String', num2str(y));
        set(handles.txt_dark, 'String', num2str(darkness));
        %fprintf('x=%d, y=%d, r=%.2f, theta=%.2f draw_image=%.2f\n',x,y,radius,theta,darkness);

        bool_top = y < (height / 2);
        bool_left = x < (width / 2);
        if xor(ltr, xor(bool_top, bool_left))
            arduino_interface(my_arduino, radius); % doesn't return until finished
            set_param('project6_model/Angle setpoint', 'Value', num2str(theta));
            if (y >= 0.8 * height && darkness > THRESH_DARK)
                pause(WAIT_THETA_SLOW);
            else
                pause(WAIT_T);
            end
        else
            set_param('project6_model/Angle setpoint', 'Value', num2str(theta));
            if (y >= 0.8 * height && darkness > THRESH_DARK)
                pause(WAIT_THETA_SLOW);
            else
                pause(WAIT_T);
            end
            arduino_interface(my_arduino, radius);
        end

        set_param('project6_model/Darkness setpoint', 'Value', num2str(darkness));
        pause(WAIT_TIME); % allow time to achieve darkness
        set_param('project6_model/Darkness setpoint', 'Value', num2str(START_DARK)); % avoid drawing too dark at the next location
        pause(WAIT_TIME); % allow time to readjust before continuing
    end
end

% finish up

set_param('project6_model/Darkness setpoint', 'Value', num2str(START_DARK));
pause(WAIT_DARK);

% return home
while abs(theta - START_THETA) > STEP_THETA
    if theta > START_THETA
        theta = theta - STEP_THETA;
    else
        theta = theta + STEP_THETA;
    end
    set_param('project6_model/Angle setpoint', 'Value', num2str(theta));
    pause(WAIT_THETA);
end
theta = START_THETA;
set_param('project6_model/Angle setpoint', 'Value', num2str(theta));

arduino_interface(my_arduino, START_RADIUS);


% --- Executes on button press in btn_stop.
function btn_stop_Callback(hObject, eventdata, handles)
% hObject    handle to btn_stop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB

% global constants
global START_THETA;
global START_RADIUS;
global START_DARK;
global STEP_THETA;
global WAIT_THETA;
global WAIT_DARK;
% other globals
global my_arduino;
global theta;
global run_flag;

% finish up
run_flag = 0;

set_param('project6_model/Darkness setpoint', 'Value', num2str(START_DARK));
pause(WAIT_DARK);
% return home
while abs(theta - START_THETA) > STEP_THETA
    if theta > START_THETA
        theta = theta - STEP_THETA;
    else
        theta = theta + STEP_THETA;
    end
    set_param('project6_model/Angle setpoint', 'Value', num2str(theta));
    pause(WAIT_THETA);
end
theta = START_THETA;
set_param('project6_model/Angle setpoint', 'Value', num2str(theta));

arduino_interface(my_arduino, START_RADIUS);


% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure

% other globals
global my_arduino;
global tg;

delete(my_arduino);

%set_param(gcs,'SimulationCommand','stop');
tg.stop;

% Hint: delete(hObject) closes the figure
delete(hObject);
