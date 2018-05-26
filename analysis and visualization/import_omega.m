function omega=import_omega(localpath,run_name)
%% Import data from text file.
% Script for importing data from the following text file:
%
%    /Users/Matt/Google Drive/project_data/Motor_Freedom_data/omega_rotation_test/omega_rotation_Omega.txt
%
% To extend the code to different selected data or a different text file,
% generate a function instead of a script.

% Auto-generated by MATLAB on 2016/12/01 18:56:21

%% Initialize variables.
filename = [localpath '/' run_name '_Omega.txt'];
disp(['Importing rotation from ' filename]);
delimiter = ' ';
startRow = 2;

%% Format for each line of text:
%   column1: double (%f)
%	column2: double (%f)
%   column3: double (%f)
%	column4: double (%f)
%   column5: double (%f)
%	column6: double (%f)
% For more information, see the TEXTSCAN documentation.
formatSpec = '%f%f%f%f%f%f%[^\n\r]';

%% Open the text file.
fileID = fopen(filename,'r');

%% Read columns of data according to the format.
% This call is based on the structure of the file used to generate this
% code. If an error occurs for a different file, try regenerating the code
% from the Import Tool.
dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter, 'MultipleDelimsAsOne', true, 'EmptyValue' ,NaN,'HeaderLines' ,startRow-1, 'ReturnOnError', false, 'EndOfLine', '\r\n');

%% Close the text file.
fclose(fileID);

%% Post processing for unimportable data.
% No unimportable data rules were applied during the import, so no post
% processing code is included. To generate code which works for
% unimportable data, select unimportable cells in a file and regenerate the
% script.

%% Allocate imported array to column variable names

omega=struct;

%repeat1 = dataArray{:, 1};
%step1 = dataArray{:, 2};
omega.t_arr = dataArray{:, 3};
omega.vector = [dataArray{:, 4} dataArray{:, 5} dataArray{:, 6}];

%% Clear temporary variables
%clearvars filename delimiter startRow formatSpec fileID dataArray ans;
end