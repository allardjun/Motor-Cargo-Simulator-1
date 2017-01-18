% Wrapper for the draw_movie script which creates a movie of the
% simulation output

%% file juggling

%set the name of the run here
run_name='demo';
localpath=pwd;
%create prefix name with directory
results_prefix=[localpath '/' run_name];

%analysis file path
analysispath='~/project_code/Motor_Freedom/tools/analysis and visualization';

%% Movie setup

%what frames to display
start_frame=1;
frames=200; %number of skip_frames to go, not actual number of frames
%skip_frames=1;
skip_frames=NaN;

%whether or not to save a movie
SaveMPEG=false;
%SaveMPEG='quarter_second_no_force';

%% frame setup

%whether or not to draw force vectors
draw_forces=false;
%whether or not to color code heads and necks
draw_detail=false;

%level of details to display
%1: show time
%2: show step and time
Diagnostics=1;

%title to display
titlestring=sprintf('Demonstration Movie');

%number of points to draw on the surface of the cargo
n_cargo_surf=20;

%initial view angle
%init_view=[-130 30];

%whether or not to draw the target circle for MFP visualizations
%set to 0 for don't draw, 1 for draw
disp_theta_c=0;

%option for choosing what the bounds of the plot are
%{
1: static shaped to cargo set at (0,0,0)
2: outside of all points to be drawn
3: tighter bounds than 2, motor circles may be cut off
4: follow cargo center
%}
plot_box=2;

%% create the movie

run([analysispath '/draw_movie.m'])