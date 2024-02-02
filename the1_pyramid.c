#include <stdio.h>
double calculate_pressure_on_block(int row, int column, double block_weight);

double calculate_pressure_on_blockhelper(int row, int column, double block_weight);

double col(int y, int m, double w);
/* TODO: implement your recursive function(s) here */
double calculate_pressure_on_blockhelper(int row, int column, double block_weight)
{
    if (row==0)
        return 0;
    else if (column==0)
        return calculate_pressure_on_blockhelper(row-1, column, block_weight)*0.15+(block_weight/2);
    else if (column==row)
        return calculate_pressure_on_blockhelper(row-1, column-1, block_weight)*0.15+(block_weight/2);
    else
        return (calculate_pressure_on_blockhelper(row-1, column-1, block_weight)*0.15+(block_weight/2))+(calculate_pressure_on_blockhelper(row-1, column, block_weight)*0.15+(block_weight/2));
}

double calculate_pressure_on_block(int row, int column, double block_weight)
{
    if (column<=row)
    {
        col(column,0,block_weight);
        
        return calculate_pressure_on_block(row,column+1,block_weight);
    }
}

double col(int y, int m, double w)
{
    double result;
    if (m<=y)
    {
        result=calculate_pressure_on_blockhelper(y, m, w);
        printf("(%d,%d) %.8lf\n",y,m,result);
        return col(y,m+1,w);
    }
}
int main() {
    
    /* TODO: Implement here */
    int row,weight;
    scanf("%d %d",&row, &weight);
    
    calculate_pressure_on_block(row-1,0,weight);
    
    return 0;
}