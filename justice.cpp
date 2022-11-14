#include"runout.h"
#include"creatin.h"

using namespace std;
int main(){
    vector<string> wenjianjia =bianliwenjian("./input");
    for(int k =0;k<wenjianjia.size();k++){
        vector<string> chenxulist =bianliwenjian("./input/"+wenjianjia[k]);
        
        for(int i=0;i<chenxulist.size()-1;i++){
            for(int j= i+1;j<chenxulist.size();j++){
              bool flag=true;
              for(int t=0;t<8;t++){

             
                creatinput("./input/"+wenjianjia[k]+ "/stdin_format.txt");
                if(chenxulist[i].find("cpp")!=string::npos && chenxulist[j].find("cpp")!=string::npos){
                    string caozuo ="g++ "+chenxulist[i];
                    system(caozuo.c_str());
                    system("a.out <input.txt >ouput1.txt");

                    string caozuo2="g++ "+chenxulist[j];
                    system(caozuo2.c_str());
                    system("a.out <input.txt >ouput2.txt");

                    ifstream in1("output1.txt");
                
                    ifstream in2("output2.txt");
                    string temp1="";
                    string temp2="";
                
                    while(in1 >>temp1 ){

                        if(!(in2 >>temp2)){
                           flag=false;
                           break;
                        }
                        else if(in2 >>temp2 && temp1 != temp2){
                            flag=false;
                            break;
                        }
                    }
                    while(in2 >>temp2 ){

                        if(!(in1 >>temp1)){
                           flag=false;
                           break;
                        }
                        else if(in1 >>temp1 && temp1 != temp2){
                            flag=false;
                            break;
                        }
                    }


                }

            
            
              }
            
            
            
            }
        }


    }
}