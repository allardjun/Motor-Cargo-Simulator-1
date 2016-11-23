%% Import data from text file.
% Script for importing data from the following text file:
%
%    /Users/Matt/Google Drive/project_data/Motor_Freedom_data/numerical_tests/anchor_drag.0_Summary.txt
%
% To extend the code to different selected data or a different text file,
% generate a function instead of a script.

% Auto-generated by MATLAB on 2016/10/21 10:54:06

%% Initialize variables.
filename = strcat(results_prefix,'_Summary.txt');
delimiter = ' ';
startRow = 2;

%% Format for each line of text:
%   column1: double (%f)
%	column2: double (%f)
%   column3: double (%f)
%	column4: double (%f)
%   column5: double (%f)
%	column6: double (%f)
%   column7: double (%f)
%	column8: double (%f)
%   column9: double (%f)
%	column10: double (%f)
%   column11: double (%f)
%	column12: double (%f)
% For more information, see the TEXTSCAN documentation.
%formatSpec = '%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%[^\n\r]';

num=10;

piece1=repmat('%f',1,num+3+3*(N(1)+N(2)));
piece2='%[^\n\r]';

formatSpec=strcat(piece1,piece2);

%% Open the text file.
fileID = fopen(filename,'r');

%% Read columns of data according to the format.
% This call is based on the structure of the file used to generate this
% code. If an error occurs for a different file, try regenerating the code
% from the Import Tool.
dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter, 'MultipleDelimsAsOne', true, 'HeaderLines' ,startRow-1, 'ReturnOnError', false, 'EndOfLine', '\r\n');

%% Close the text file.
fclose(fileID);

%% Post processing for unimportable data.
% No unimportable data rules were applied during the import, so no post
% processing code is included. To generate code which works for
% unimportable data, select unimportable cells in a file and regenerate the
% script.

%% Allocate imported array to column variable names
repeat = dataArray{:,1};
step = dataArray{:, 2};
t_arr = dataArray{:, 3};
exit_cond = dataArray{:, 4};
D_anchor = dataArray{:, 5};
eps_0 = dataArray{:, 6};
pi_0 = dataArray{:, 7};
offset = dataArray{:, 8};
R = dataArray{:,9};
theta_c = dataArray{:,10};

center_final = [dataArray{:, num+1} dataArray{:, num+2} dataArray{:, num+3}];
% type0motor0_x = dataArray{:, 10};
% type0motor0_y = dataArray{:, 11};
% type0motor0_z = dataArray{:, 12};

locs_final=cell(2,1);
locs_final{1}=cell(N(1),1);
locs_final{2}=cell(N(2),2);

for m=1:2
    for n=1:N(m)
        if m==1
            column=num+4+(n-1)*3;
        else
            column=num+4+N(1)*3+(n-1)*3;
        end
        locs_final{m}{n}=[dataArray{:,column:column+2}];
    end
end


%% Clear temporary variables
clearvars filename delimiter startRow formatSpec fileID dataArray ans num;