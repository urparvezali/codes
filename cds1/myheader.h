long sumofnthnumbers(long n){
    if(n==0) return 0;
    return n+sumofnthnumbers(n-1);
}
void printnthnumbers(long n){
    if(n==0) return;
    printnthnumbers(n-1);
    std::cout<<n<<std::endl;
}
void myname(){
    std::cout<<"----Parvez Ali"<<std::endl;
    std::cout<<"Dept. of ICE, PUST"<<std::endl;
}
void fuck(){
    std::cout<<"F U C K"<<std::endl;
}