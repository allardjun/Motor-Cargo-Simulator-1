//prototypes
void bead_equations();

void bead_equations(){
    switch(total_motors){
        case 0:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*TorqeExt[0];

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*TorqeExt[1];

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*TorqeExt[2];

            break;

        case 1:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmTangential[0][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmTangential[0][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmTangential[0][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] + c[2]*FmTangential[0][1] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] - c[2]*FmTangential[0][0] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] + c[1]*FmTangential[0][0] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            break;

        case 2:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmTangential[0][0] + FmTangential[1][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmTangential[0][1] + FmTangential[1][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmTangential[0][2] + FmTangential[1][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1]) - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0]) + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0]) - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            break;

        case 3:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1]) - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0]) + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0]) - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            break;

        case 4:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1]) - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0]) + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0]) - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            break;

        case 5:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1]) - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0]) + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0]) - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            break;

        case 6:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1]) - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0]) + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0]) - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            break;

        case 7:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1]) - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0]) + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0]) - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            break;

        case 8:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1]) - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0]) + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0]) - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            break;

        case 9:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1]) - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0]) + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0]) - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            break;

        case 10:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1]) - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0]) + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0]) - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            break;

        case 11:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1]) - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0]) + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0]) - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            break;

        case 12:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1]) - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0]) + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0]) - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            break;

        case 13:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1]) - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0]) + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0]) - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            break;

        case 14:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1]) - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0]) + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0]) - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            break;

        case 15:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1]) - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0]) + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0]) - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            break;

        case 16:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1]) - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0]) + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0]) - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            break;

        case 17:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1]) - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0]) + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0]) - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            break;

        case 18:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1]) - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0]) + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0]) - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            break;

        case 19:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmRadial[18][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmRadial[18][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmRadial[18][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2] + FmTangential[18][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2] - a[18][2]*FmTangential[18][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1]) - c[1]*FmTangential[18][2] + a[18][1]*FmTangential[18][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2] + a[18][2]*FmTangential[18][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0]) + c[0]*FmTangential[18][2] - a[18][0]*FmTangential[18][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1] - a[18][1]*FmTangential[18][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0]) - c[0]*FmTangential[18][1] + a[18][0]*FmTangential[18][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            a1[18][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[18][0] + theta[2]*a[18][1] - theta1[2]*a[18][1] - theta[1]*a[18][2] + theta1[1]*a[18][2];

            a1[18][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[18][0] + theta1[2]*a[18][0] + a[18][1] + theta[0]*a[18][2] - theta1[0]*a[18][2];

            a1[18][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[18][0] - theta1[1]*a[18][0] - theta[0]*a[18][1] + theta1[0]*a[18][1] + a[18][2];

            break;

        case 20:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmRadial[18][0] + FmRadial[19][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmRadial[18][1] + FmRadial[19][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmRadial[18][2] + FmRadial[19][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2] + FmTangential[18][2] + FmTangential[19][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2] - a[18][2]*FmTangential[18][1] - c[1]*FmTangential[18][2] + a[18][1]*FmTangential[18][2] - a[19][2]*FmTangential[19][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1]) - c[1]*FmTangential[19][2] + a[19][1]*FmTangential[19][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2] + a[18][2]*FmTangential[18][0] + c[0]*FmTangential[18][2] - a[18][0]*FmTangential[18][2] + a[19][2]*FmTangential[19][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0]) + c[0]*FmTangential[19][2] - a[19][0]*FmTangential[19][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1] - a[18][1]*FmTangential[18][0] - c[0]*FmTangential[18][1] + a[18][0]*FmTangential[18][1] - a[19][1]*FmTangential[19][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0]) - c[0]*FmTangential[19][1] + a[19][0]*FmTangential[19][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            a1[18][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[18][0] + theta[2]*a[18][1] - theta1[2]*a[18][1] - theta[1]*a[18][2] + theta1[1]*a[18][2];

            a1[18][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[18][0] + theta1[2]*a[18][0] + a[18][1] + theta[0]*a[18][2] - theta1[0]*a[18][2];

            a1[18][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[18][0] - theta1[1]*a[18][0] - theta[0]*a[18][1] + theta1[0]*a[18][1] + a[18][2];

            a1[19][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[19][0] + theta[2]*a[19][1] - theta1[2]*a[19][1] - theta[1]*a[19][2] + theta1[1]*a[19][2];

            a1[19][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[19][0] + theta1[2]*a[19][0] + a[19][1] + theta[0]*a[19][2] - theta1[0]*a[19][2];

            a1[19][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[19][0] - theta1[1]*a[19][0] - theta[0]*a[19][1] + theta1[0]*a[19][1] + a[19][2];

            break;

        default:
            printf("Bad value for total_motors\n");
            exit(0);
    }
}
