%% Import data from text file.
% Script for importing data from the following text file:
%
%    /Users/Matt/Google Drive/Allard Lab/Motor Freedom Project/src/macrun1
%
% To extend the code to different selected data or a different text file,
% generate a function instead of a script.

% Auto-generated by MATLAB on 2016/04/19 02:12:49

disp('Importing heads')

headimport=struct;

%% Initialize variables.
headimport.filename = [localpath '/' run_name '_Heads.txt'];
headimport.delimiter = ' ';
headimport.startRow = 2;

%% Format string for each line of text:

%need a %f for each column of numbers to read in
%step, time, center x,y,z = 5
%x,y,z for each motor = 3*(N_k+N_d)
headimport.piece1=repmat('%f',1,3+3*(N(1)+N(2))+(N(1)+N(2)));
headimport.piece2='%[^\n\r]';

headimport.formatSpec=strcat(headimport.piece1,headimport.piece2);

%% Open the text file.
headimport.fileID = fopen(headimport.filename,'r');

%% Read columns of data according to format string.
% This call is based on the structure of the file used to generate this
% code. If an error occurs for a different file, try regenerating the code
% from the Import Tool.
headimport.dataArray = textscan(headimport.fileID, headimport.formatSpec, ...
    'Delimiter', headimport.delimiter, 'MultipleDelimsAsOne', true, ...
    'EmptyValue' ,NaN,'HeaderLines' ,headimport.startRow-1, 'ReturnOnError', false);

%% Close the text file.
fclose(headimport.fileID);

%% Post processing for unimportable data.
% No unimportable data rules were applied during the import, so no post
% processing code is included. To generate code which works for
% unimportable data, select unimportable cells in a file and regenerate the
% script.

%% Allocate imported array to column variable names
repeat = headimport.dataArray{:, 1};
step = headimport.dataArray{:, 2};
t_arr = headimport.dataArray{:, 3};

head_rec=cell(2,size(step,1));

last=3+3*(N(1)+N(2))+(N(1)+N(2));

bound{1}=[headimport.dataArray{:,last-(N(1)+N(2))+1:last-N(2)}];
bound{2}=[headimport.dataArray{:,last-N(2)+1:last}];

%%

headimport.temp=cell(2,max(N));

for headimportm=1:2

    for headimportn=1:N(headimportm)

        headimport.ind=4+(headimportm-1)*N(1)*3+(headimportn-1)*3;
        headimport.temp{headimportm,headimportn}=[headimport.dataArray{headimport.ind} ...
            headimport.dataArray{headimport.ind+1} ...
            headimport.dataArray{headimport.ind+2}];

    end

end

%reformat to the shape motor_movie expects
for headimportm=1:2
    headimport.temp2=zeros(N(headimportm),3);
    for headimports=1:size(step,1)
        for headimportn=1:N(headimportm)
            headimport.temp2(headimportn,:)=headimport.temp{headimportm,headimportn}(headimports,:);
        end
        head_rec{headimportm,headimports}=headimport.temp2;
    end
end


%% Clear temporary variables
clearvars headimport headimportm headimportn headimports;
