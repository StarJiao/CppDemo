int count = 5;
extern void write_extern(int);

int main(){
	write_extern(4);
	count ++;
	write_extern(4);
	return 0;
}
