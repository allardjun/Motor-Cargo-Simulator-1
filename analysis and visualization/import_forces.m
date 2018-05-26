function forces=import_forces(params,localpath,run_name)
%% Import data from text file.
% Script for importing data from the following text file:
%
%    /Users/Matt/Google Drive/Allard Lab/Motor Freedom Project/src/macrun1
%
% To extend the code to different selected data or a different text file,
% generate a function instead of a script.

% Auto-generated by MATLAB on 2016/04/19 02:12:49

%% Initialize variables.
filename = [localpath '/' run_name '_Forces.txt'];
disp(['Importing forces from ' filename]);
delimiter = ' ';
startRow = 2;

N=params.N;

%% Format string for each line of text:

%need a %f for each column of numbers to read in
%step, time, center x,y,z = 5
%x,y,z for each motor = 3*(N_k+N_d)
piece1=repmat('%f',1,9+6*(N(1)+N(2))+2);
piece2='%[^\n\r]';

formatSpec=strcat(piece1,piece2);

%% Open the text file.
fileID = fopen(filename,'r');

%% Read columns of data according to format string.
% This call is based on the structure of the file used to generate this
% code. If an error occurs for a different file, try regenerating the code
% from the Import Tool.
dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter, 'MultipleDelimsAsOne', true, 'EmptyValue' ,NaN,'HeaderLines' ,startRow-1, 'ReturnOnError', false);

%% Close the text file.
fclose(fileID);

%% Post processing for unimportable data.
% No unimportable data rules were applied during the import, so no post
% processing code is included. To generate code which works for
% unimportable data, select unimportable cells in a file and regenerate the
% script.

%% Allocate imported array to column variable names

forces=struct;

%repeat = dataArray{:, 1};
%step = dataArray{:, 2};
forces.t_arr = dataArray{:, 3};

forces.Fext = [dataArray{:, 4} dataArray{:, 5} dataArray{:, 6}];
forces.Fsteric = [dataArray{:, 7} dataArray{:, 8} dataArray{:, 9}];

forces.Fradial=cell(2,1);
forces.Ftangential=cell(2,1);
for m=1:2
    forces.Fradial{m}=cell(N(m),1);
    forces.Ftangential{m}=cell(N(m),1);
end


%% 

for m=1:2
    for n=1:N(m)
        if m==1
            column=10+(n-1)*6;
        else
            column=10+N(1)*6+(n-1)*6;
        end
        forces.Fradial{m}{n}=[dataArray{:,column:column+2}];
        forces.Ftangential{m}{n}=[dataArray{:,column+3:column+5}];
    end
end

%%

forces.MTdist=[dataArray{:,column+6:column+7}];


%% Clear temporary variables
%clearvars column m n piece1 piece2...
%    filename delimiter startRow formatSpec fileID dataArray ans;
end