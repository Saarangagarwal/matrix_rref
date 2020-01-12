#include<iostream>

#ifndef MARMOSET_TESTING
int main();
#endif
void print_matrix(double row1[], double row2[], double row3[]) ;
void get_user_input(double row1[], double row2[], double row3[]) ;
void swap_rows(double rowA[], double rowB[]) ;
void scale_row(double rowA[], double factor) ;
void add_to_row(double rowSrc[], double rowTgt[], double factor) ;
void rref(double row1[], double row2[], double row3[]) ;


#ifndef MARMOSET_TESTING
int main()
{
	double r1[4]{}, r2[4]{}, r3[4]{};

	get_user_input(r1,r2,r3);
	print_matrix(r1,r2,r3);
	rref(r1,r2,r3);

	return 0;
}
#endif

void print_matrix(double row1[], double row2[], double row3[])
{
	std::cout<<std::endl<<"You have entered: ";
	std::cout<<row1[0]<<" "<<row1[1]<<" "<<row1[2]<<" "<<row1[3]<<std::endl;
	std::cout<<row2[0]<<" "<<row2[1]<<" "<<row2[2]<<" "<<row2[3]<<std::endl;
	std::cout<<row3[0]<<" "<<row3[1]<<" "<<row3[2]<<" "<<row3[3]<<std::endl;
}

void get_user_input(double row1[], double row2[], double row3[])
{
	std::cout<<"Row 1: ";
	std::cin>>row1[0]>>row1[1]>>row1[2]>>row1[3];
	std::cout<<"Row 2: ";
	std::cin>>row2[0]>>row2[1]>>row2[2]>>row2[3];
	std::cout<<"Row 3: ";
	std::cin>>row3[0]>>row3[1]>>row3[2]>>row3[3];
}

void swap_rows(double rowA[], double rowB[])
{
	double temp{};
	for(std::size_t i{}; i<4; i++)
	{
		temp=rowA[i];
		rowA[i]=rowB[i];
		rowB[i]=temp;
	}
}

void scale_row(double rowA[], double factor)
{
	for(std::size_t i{}; i<4; i++)
	{
		rowA[i]*=factor;
	}
}

void add_to_row(double rowSrc[], double rowTgt[], double factor)
{
	for(std::size_t i{}; i<4; i++)
	{
		rowTgt[i]=rowTgt[i]+(factor*rowSrc[i]);
	}
}

void rref(double row1[], double row2[], double row3[])
{
	scale_row(row1, (1/row1[0]));
	add_to_row(row1, row2, -row2[0]);
	add_to_row(row1, row3, -row3[0]);

	scale_row(row2, (1/row2[1]));
	add_to_row(row2, row3, -row3[1]);
	add_to_row(row2, row1, -row1[1]);

	scale_row(row3, (1/row3[2]));
	add_to_row(row3, row1, -row1[2]);
	add_to_row(row3, row2, -row2[2]);

	std::cout<<"The RREF form is: "<<std::endl;
	std::cout<<row1[0]<<" "<<row1[1]<<" "<<row1[2]<<" "<<row1[3]<<std::endl;
	std::cout<<row2[0]<<" "<<row2[1]<<" "<<row2[2]<<" "<<row2[3]<<std::endl;
	std::cout<<row3[0]<<" "<<row3[1]<<" "<<row3[2]<<" "<<row3[3]<<std::endl;
}
