#include <stdio.h>

int main() {
    
    /* TODO: Implement here */
    /*####################################################################################################*/
    /*********assigning_variables**********/
    int n,m,t,i;
    int temp1;
    float sum;
    
    
    float votes[50];
    float curvotes[50];
    char parties[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    float divider[50];
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++){
        divider[i]=1;
    }
    
    for(i=0;i<n;i++){
        scanf("%d",&temp1);
        votes[i]=temp1;
        curvotes[i]=temp1;
    }
    /*********assigning_variables**********/

    /*********************election_loop************************/
    for(t=0;t<m;t++){
        
        /*********max**********/
        int s=0;
        float d=0.0;
        for(i=0;i<n;i++)
        {
            
            if (curvotes[i]>d)
            {
                s=i;
                d=curvotes[s];
            }
            /************equalvotes**************/
            if (curvotes[i]==d && votes[i]>votes[s])
            {
                s=i;
                d=curvotes[s];
            }
            /************equalvotes**************/
        }       
        /*********max*********/
        divider[s]+=1;
        curvotes[s]=votes[s]/divider[s];
    }
    /*********************election_loop************************/

    /***************FOXTV_election_screen**********************/
    for(i=0;i<n;i++){               /*assign_the_chairs*/
        divider[i]-=1;
    }

    
    do
    {
        /*max*/
        int s=0;
        float d=0.0;
        for(i=0;i<n;i++)
        {
            if (divider[i]>d)
            {
                s=i;
                d=divider[s];
            }
        }
        /*max*/

        printf("%c: %d\n",parties[s],(int)divider[s]);
        divider[s]=0;

        /*******sum*******/
        sum=0;
        for(i=0;i<n;i++)
        {
            sum+=divider[i];
        }
        /*******sum*******/
    } while (sum);
    /***************FOXTV_election_screen**********************/
    
    return 0;
}