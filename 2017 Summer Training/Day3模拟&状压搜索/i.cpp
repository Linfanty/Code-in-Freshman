#include<stdio.h>
#include<string.h>
#include<memory.h>
// 1 , 2 ,3 , 4, 5 dragon 、ninja、iceman、lion、wolf 
int test,casen;
int M,N,T;//valid need scaned first
int losob[5];//life_of_solider_on_born: dragon、ninja、iceman、lion、wolf
int aosob[5];//attack_of_solider_on_born:dragon 、ninja、iceman、lion、wolf
int rcl,re,lre;//red_command_life,
int bcl,be,lbe;
int rsbs[5]={3,4,5,2,1};//red_solider_born_sequence
int bsbs[5]={4,1,2,3,5};
int ct;//current_time
int rbs,rbn;//red_born_sequenc,r_born_numbers
int bbs,bbn;
int city[22][2];
int ele[22][2],aele[22][2];
int force[22][2],aforce[22][2];
int number[22][2];
int kill[22][2];
int win[22][2];
int flag[22];
int life[22];
int db[22];
int pl[22];
int hpy[22];
int rw,bw;
char nos[5][8]={"dragon","ninja","iceman","lion","wolf"};
char color[2][6]={"red","blue"};
void dt(){//display time
    printf("%03d:%02d ",ct/60,ct%60);
}
void w_zero()
{
    if(rcl>=losob[rsbs[rbs]-1])
    {
        rcl-=losob[rsbs[rbs]-1];
        dt();
        printf("red %s %d born\n",nos[rsbs[rbs]-1],++rbn);
        city[0][0]=rsbs[rbs];
        ele[0][0]=losob[rsbs[rbs]-1];
        force[0][0]=aosob[rsbs[rbs]-1];
        kill[0][0]=0;
        number[0][0]=rbn;
        if(rbs==4) rbs=0;
        else rbs++;
    }
    if(bcl>=losob[bsbs[bbs]-1])
    {
        bcl-=losob[bsbs[bbs]-1];
        dt();
        printf("blue %s %d born\n",nos[bsbs[bbs]-1],++bbn);
        city[N+1][1]=bsbs[bbs];
        ele[N+1][1]=losob[bsbs[bbs]-1];
        force[N+1][1]=aosob[bsbs[bbs]-1];
        kill[N+1][1]=0;
        number[N+1][1]=bbn;
        if(bbs==4) bbs=0;
        else bbs++;
    }
}
void w_one()
{
    int i;
    i=N+1;
    while(i>0)
    {
        city[i][0]=city[i-1][0];
        city[i-1][0]=0;
        if(i==N+1&&city[i][0]>0){
            lbe=be;
            be++;
        }
        ele[i][0]=ele[i-1][0];
        ele[i-1][0]=0;
        force[i][0]=force[i-1][0];
        force[i-1][0]=0;
        number[i][0]=number[i-1][0];
        number[i-1][0]=0;
        kill[i][0]=kill[i-1][0];
        kill[i-1][0]=0;
        if(i%2==0&&city[i][0]==3)
        {
            if(ele[i][0]<=9)
                ele[i][0]=1;
            else
                ele[i][0]-=9;
            force[i][0]+=20;
        }
        i--;
    }
    i=0;

    while(i<=N)
    {
        city[i][1]=city[i+1][1];
        city[i+1][1]=0;
        if(i==0&&city[i][1]>0){
            lre=re;
            re++;
        }
        ele[i][1]=ele[i+1][1];
        ele[i+1][1]=0;
        force[i][1]=force[i+1][1];
        force[i+1][1]=0;
        number[i][1]=number[i+1][1];
        number[i+1][1]=0;
        kill[i][1]=kill[i+1][1];
        kill[i+1][1]=0;
        if((N+1-i)%2==0&&city[i][1]==3)
        {
            if(ele[i][1]<=9)
                ele[i][1]=1;
            else
                ele[i][1]-=9;
            force[i][1]+=20;
        }
        i++;
    }
    if(city[0][1]>0)
    {
        dt();
        printf("blue %s %d reached red headquarter with %d elements and force %d\n",
            nos[city[0][1]-1],number[0][1],ele[0][1],force[0][1]);
    }
    if(re==2)
    {
        dt();
        printf("red headquarter was taken\n");
    }
    i=1;
    while(i<=N)
    {
        if(city[i][0]>0)
        {
            dt();
            printf("red %s %d marched to city %d with %d elements and force %d\n",
                nos[city[i][0]-1],number[i][0],i,ele[i][0],force[i][0]);
        }
        if(city[i][1]>0)
        {
            dt();
            printf("blue %s %d marched to city %d with %d elements and force %d\n",
                nos[city[i][1]-1],number[i][1],i,ele[i][1],force[i][1]);
        }
        i++;
    }
    if(city[N+1][0]>0)
    {
        dt();
        printf("red %s %d reached blue headquarter with %d elements and force %d\n",
            nos[city[N+1][0]-1],number[N+1][0],ele[N+1][0],force[N+1][0]);
    }
    if(be==2)
    {
        dt();
        printf("blue headquarter was taken\n");
    }
        //printf();
}
void w_two()
{
    int i;
    i=1;
    while(i<=N) life[i++]+=10;
}
void dgetlife(int i,int rb)
{
    dt();
    printf("%s %s %d earned %d elements for his headquarter\n",color[rb],nos[city[i][rb]-1],number[i][rb],life[i]);
}
void w_three()
{
    int i;
    i=1;
    while(i<=N)
    {
        if(city[i][0]>0&&city[i][1]==0)
        {
            rcl+=life[i];
            dgetlife(i,0);
            life[i]=0;
        }
        else if(city[i][0]==0&&city[i][1]>0)
        {
            bcl+=life[i];
            dgetlife(i,1);
            life[i]=0;
        }
        i++;
    }
}
void death(int i,int rb)
{
//  dt();
//  printf("%s %s %d was killed int city %d\n",color[rb],nos[city[i][rb]-1],number[i][rb],i);
//  city[i][rb]=0;
    force[i][rb]=0;
    ele[i][rb]=0;
    kill[i][rb]=0;
//  number[i][0]=0;
}
void ddeath(int i ,int rb)
{
    dt();
    printf("%s %s %d was killed in city %d\n",color[rb],nos[city[i][rb]-1],number[i][rb],i);
}
void happy(int i,int rb)
{
    dt();
    printf("%s %s %d yelled in city %d\n",color[rb],nos[city[i][rb]-1],number[i][rb],i);
}
void dreattack(int i,int rb1,int rb2)
{
    dt();
    printf("%s %s %d fought back ",color[rb1],nos[city[i][rb1]-1],number[i][rb1]);
    printf("against %s %s %d in city %d\n",color[rb2],nos[city[i][rb2]-1],number[i][rb2],i);

}
void reattack(int i,int rb1,int rb2)
{
    int dead;
    dead=0;
    if(city[i][rb1]!=2)
    {
        if(ele[i][rb2]<=force[i][rb1]/2){
            if(city[i][rb2]==4){
                pl[i]=ele[i][rb2];
            }
            dead=1;
            if(rb1==0) rw++;
            else bw++;
        }
    }
    if(dead==0&&city[i][rb2]==1)
        hpy[i]=1;
    if(dead==1)
        death(i,rb2);
}
void adattack(int i,int rb1,int rb2)
{
    dt();
    printf("%s %s %d attacked ",color[rb1],nos[city[i][rb1]-1],number[i][rb1]);
    printf("%s %s %d in city %d ",color[rb2],nos[city[i][rb2]-1],number[i][rb2],i);
    printf("with %d elements and force %d\n",aele[i][rb1],aforce[i][rb1]);
}
void attack(int i,int rb1,int rb2)
{
    if(ele[i][rb2]<=force[i][rb1])
    {
        kill[i][rb1]++;
        if(city[i][rb1]==5&&kill[i][rb1]%2==0){
            db[i]=2;
        }
        if(city[i][rb2]==4){
            pl[i]=ele[i][rb2];
        }
        death(i,rb2);
        if(city[i][rb1]==1)
            hpy[i]=1;
        if(rb1==0) rw++;
        else bw++;
    }
    else 
        reattack(i,rb2,rb1);
}
void fight(int i)
{
    if(flag[i]==1)
        attack(i,0,1);
    else if(flag[i]==2)
        attack(i,1,0);
    else{
        if(i%2==1) attack(i,0,1);
        else attack(i,1,0);
    }
}
void getlife(int i,int rb)
{
    if(rb==0)
    {
        if(rcl>=8*rw)
        {
            rcl-=8;
            ele[i][0]+=8;

        }
        dgetlife(i,rb);
        rw--;
    }
    else
    {
        if(bcl>=8)
        {
            bcl-=8;
            ele[i][1]+=8;
        }
        dgetlife(i,rb);
    }
}
void raisflag(int i,int rb)
{
    dt();
    printf("%s flag raised in city %d\n",color[rb],i);
}
void dfour(int i,int rb1,int rb2)
{
    adattack(i,rb1,rb2);
    ele[i][rb2]-=aforce[i][rb1];
    if(ele[i][rb2]<0)
        ele[i][rb2]=0;
    if(ele[i][rb2]==0)
    {
        ele[i][rb1]*=db[i];
        force[i][rb1]*=db[i];
        ele[i][rb1]+=pl[i];
        ddeath(i,rb2);
        if(hpy[i]==1)
            happy(i,rb1);
        getlife(i,rb1);
    }
    else
    {
        if(city[i][rb2]!=2)
        {
            dreattack(i,rb2,rb1);
            ele[i][rb1]-=(aforce[i][rb2]/2);
            if(ele[i][rb1]<0)
                ele[i][rb1]=0;
        }
        if(ele[i][rb1]==0){
            ddeath(i,rb1);
            ele[i][rb2]+=pl[i];
        }
        if(hpy[i]==1)
            happy(i,rb1);
        if(ele[i][rb1]==0)
            getlife(i,rb2);
    }
    if(ele[i][0]>0&&ele[i][1]==0)
    {
        win[i][1]=0;
        win[i][0]++;
        if(flag[i]==2)
            flag[i]=0;
        else if(flag[i]==0&&win[i][0]==2)
        {
            flag[i]=1;
            raisflag(i,0);
        }
    }
    else if(ele[i][0]==0&&ele[i][1]>0)
    {
        win[i][0]=0;
        win[i][1]++;
        if(flag[i]==1)
            flag[i]=0;
        else if(flag[i]==0&&win[i][1]==2)
        {
            flag[i]=2;
            raisflag(i,1);
        }
    }
    else
    {
        win[i][0]=0;
        win[i][1]=0;
    }
}
void w_four()
{
    int i;
    rw=0;
    bw=0;
    i=1;
    while(i<=N)
    {
        db[i]=1;
        pl[i]=0;
        hpy[i]=0;
        if(city[i][0]>0&&city[i][1]>0){
            aele[i][0]=ele[i][0];
            aele[i][1]=ele[i][1];
            aforce[i][1]=force[i][1];
            aforce[i][0]=force[i][0];
            fight(i);
        }
        i++;
    }
    i=1;
    while(i<=N)
    {
        if(city[i][0]>0&&city[i][1]>0)
        {
            if(flag[i]==1)
            {
                dfour(i,0,1);
            }
            else if(flag[i]==2)
            { 
                dfour(i,1,0);
            }
            else
            {
                if(i%2==1) dfour(i,0,1);
                else dfour(i,1,0);
            }
        //  if()
        }
        i++;
    }
    i=1;
    while(i<=N)
    {
        if(ele[i][0]>0&&ele[i][1]==0)
        {
            rcl+=life[i];
            //force[i][1]=0;
            city[i][1]=0;
            number[i][1]=0;
            life[i]=0;
        }
        else if(ele[i][0]==0&&ele[i][1]>0)
        {
            bcl+=life[i];
            city[i][0]=0;
            number[i][0]=0;
            life[i]=0;
        }
        i++;
    }
}
void w_five(){
    dt();
    printf("%d elements in red headquarter\n",rcl);
    dt();
    printf("%d elements in blue headquarter\n",bcl);
}
void wot()//work_on_(the)time
{
    int work;
    work=(ct%60)/10;
    if(work==0)
        w_zero();
    else if(work==1)
        w_one();
    else if(work==2)
        w_two();
    else if(work==3)
        w_three();
    else if(work==4)
        w_four();
    else
        w_five();
}
void output()
{
    printf("Case:%d\n",casen++);
    while(ct<=T)
    {
        wot();
        if(re==2||be==2) break;
        ct+=10;
    }
}
void input()
{
    int i;
    scanf("%d%d%d",&M,&N,&T);
    i=0;
    while(i<5) scanf("%d",&losob[i++]);
    i=0;
    while(i<5) scanf("%d",&aosob[i++]);
}
void init()
{
    ct=0;
    memset(city,0,sizeof(city));
    memset(flag,0,sizeof(flag));
    memset(life,0,sizeof(life));
    memset(ele,0,sizeof(ele));
    memset(force,0,sizeof(force));
    memset(number,0,sizeof(number));
    memset(kill,0,sizeof(kill));
    memset(win,0,sizeof(win));
    rcl=M;
    bcl=M;
    rbs=0;
    rbn=0;
    bbs=0;
    bbn=0;
    re=0;
    lre=0;
    be=0;
    lbe=0;
}
void main()
{
    scanf("%d",&test);
    casen=1;
    while(test--)
    {
        input();
        init();
        output();
    }
}

 

刚提交通过的代码：

 
Problem: 3760       User: huangchang9001
Memory: 156K        Time: 0MS
Language: C         Result: Accepted


 

/*
    This C code is programed to solve the problem 3760 of POJ
    (http://poj.org/problem?id=3760).I had ever submit a first
    accepted C code of the problem on the time 2011/06/25 21:44:50
    But when I continued to study c language deeply, I had a look
    at my C code which I thought ugly and tedious. So I want to 
    edit a graceful and simple C code.
    
    date:  2012/8/23 15:24
    author:huangchang9001
*/
#include<stdio.h>

/*<- predefined area */
// CITY_MAX
#define CM 22
// WARRIOR_SPECIES
#define WAS 5
//STRING_LENGTH
#define SL 10


/* predefined area ->*/

/* */
struct headquarters{
    int element;
    int nxtwr;//next_warrior 
    int NO;
    int taken;
    int start;
    int walk;
    int end;
//  int 
};

struct City{
    int element;
    int wr[2];//warrior
    int hp[2];
    int atk[2];
    int NO[2];
    int stc[2];//step_count
    int kln[2];//kill number;
    int flc[3];//flag_color;
};

enum Warrior{dragon,ninja,iceman,lion,wolf,null,dead};
enum Color{red,blue,none};

struct headquarters hq[2];
struct City city[CM];
/* */

/*<- variable area */

// below is the variable need scan
int M,N,T;
int hp_of_born[WAS];
int atk_of_born[WAS];

// below is the variable used by other function
// ct:current_time which called by the function dt(); 
int ct;
// warrior_to_string
char wtostr[WAS][SL]={"dragon","ninja","iceman","lion","wolf"};
char ctostr[2][SL]={"red","blue"};
//  warriot born of sequence
int wbos[2][WAS]={{iceman,lion,wolf,ninja,dragon},{lion,dragon,ninja,iceman,wolf}}; 

/* variable area ->*/


/*<- function area */

//dt():display_time()
void dt();
//dw():display_warrior();
void dw(int cn,int clr);
//
void dha(int cn,int clr);
//
void dd(int cn,int clr);
//initall function
void init();
void init_city();
void init_headquarter();
// input() function is used to scan the variable
void input();

// output funciton is used to display the outcome
void output();

// time 00 functions
void born();
void born_c(int clr);//clr: color

// time 10 functions
void march();
void march_c(int clr);
void march_o(int i,int clr);

// time 20 functions
void product();

// time 30 functions
void get_element();
void get_ele(int cn,int clr);

// time 40 functions;
void fight();
void attack(int cn);
void reattack(int cn);
void yell(int cn,int clr);

// time 50 functions;
void report();
void report_c(int clr);


/* function area ->*/

void main(){
    int test,casen=1;
//  printf("%d\n",iceman);
    scanf("%d",&test);
    while(test--){
        input();
        init();
//      printf("%d %d\n",hq[red].end,hq[blue].end);
        printf("Case:%d\n",casen++);
        output();
    }
}

void dt(){
    printf("%03d:%d0 ",ct/6,ct%6);
}
void dw(int cn,int clr){
    printf("%s %s %d ",ctostr[clr],wtostr[city[cn].wr[clr]],city[cn].NO[clr]);
}
void dha(int cn,int clr){
    printf("with %d elements and force %d\n",city[cn].hp[clr],city[cn].atk[clr]);
}
void dd(int cn,int clr){
    dt();
    dw(cn,clr);
    printf("was killed in city %d\n",cn);
}
void init(){
    init_city();
    init_headquarter();
}

void init_city(){
    int i=0;
    while(i<=N+1){
        city[i].element=0;
        city[i].wr[red]=null;
        city[i].wr[blue]=null;
        city[i].flc[red]=0;
        city[i].flc[blue]=0;
        city[i].flc[2]=none;
        ////if(i%2==1) city[i].flc[2]=red;
        //else city[i].flc[2]=blue;
        i++;
    }
}

void init_headquarter(){
    hq[red].element=M;
    hq[red].end=N+1;
    hq[red].NO=1;
    hq[red].nxtwr=0;
    hq[red].start=0;
    hq[red].taken=0;
    hq[red].walk=1;
    hq[blue].element=M;
    hq[blue].end=0;
    hq[blue].NO=1;
    hq[blue].nxtwr=0;
    hq[blue].start=N+1;
    hq[blue].taken=0;
    hq[blue].walk=-1;
}

void input(){
    int i;
    scanf("%d%d%d",&M,&N,&T);
    i=0;
    while(i<WAS) scanf("%d",&hp_of_born[i++]);
    i=0;
    while(i<WAS) scanf("%d",&atk_of_born[i++]);
}

void output(){
    T/=10;
    ct=0;
    while(ct<=T){
        int work=ct%6;
        switch(work){
            case 0:born();break;
            case 1:march();break;
            case 2:product();break;
            case 3:get_element();break;
            case 4:fight();break;
            case 5:report();break;
            default:break;
        }
        if(hq[red].taken==2||hq[blue].taken==2) break;
        ct++;
    }
//  over: ct=1;
}
void born(){
    born_c(red);    
    born_c(blue);
}
void born_c(int clr){
    int wr=wbos[clr][hq[clr].nxtwr];
    int start=hq[clr].start;
    if(hq[clr].element>=hp_of_born[wr]){
        hq[clr].element-=hp_of_born[wr];

        city[start].wr[clr]=wr;
        city[start].atk[clr]=atk_of_born[wr];
        city[start].hp[clr]=hp_of_born[wr];
        city[start].NO[clr]=hq[clr].NO;
        city[start].stc[clr]=0;
        city[start].kln[clr]=0;

        dt();
        printf("%s %s %d born\n",ctostr[clr],wtostr[wr],hq[clr].NO);
        if(hq[clr].nxtwr==4) hq[clr].nxtwr=0;
        else hq[clr].nxtwr++;
        hq[clr].NO++;
    }
    else
        city[start].wr[clr]=null;
}

void product(){
    int i=1;
    while(i<=N) city[i++].element+=10;
}

void march(){
    int i;
    march_c(red);
    march_c(blue);
    if(city[0].wr[blue]<null){
        dt();
        dw(0,blue);
        printf("reached %s headquarter ",ctostr[red]);
        dha(0,blue);
        hq[red].taken++;
        city[0].wr[blue]=null;
    }
    if(hq[red].taken==2){
        dt();
        printf("red headquarter was taken\n");
    }
    i=1;
    while(i<=N){
        if(city[i].wr[red]<null){
            march_o(i,red);
        }
        if(city[i].wr[blue]<null){
            march_o(i,blue);
        }
        i++;
    }
    
    if(city[N+1].wr[red]<null){
        dt();
        dw(N+1,red);
        printf("reached %s headquarter ",ctostr[blue]);
        dha(N+1,red);
        hq[blue].taken++;
        city[N+1].wr[red]=null;
    }
    if(hq[blue].taken==2){
        dt();
        printf("blue headquarter was taken\n");
    }
    //if(city[hq[red].end].)
}
void march_c(int clr){
    int start=hq[clr].end;
    int end=hq[clr].start;
    int walk=-hq[clr].walk;
    while(start!=end){
    
        city[start].hp[clr]=city[start+walk].hp[clr];
        city[start].atk[clr]=city[start+walk].atk[clr];
        city[start].NO[clr]=city[start+walk].NO[clr];
        city[start].stc[clr]=city[start+walk].stc[clr]+1;
        city[start].kln[clr]=city[start+walk].kln[clr];
        city[start].wr[clr]=city[start+walk].wr[clr];
        if(city[start].wr[clr]==iceman&&city[start].stc[clr]%2==0){
            if(city[start].hp[clr]>9)
                city[start].hp[clr]-=9;
            else
                city[start].hp[clr]=1;
            city[start].atk[clr]+=20;
            
        }
        start+=walk;
    }
}

void march_o(int i,int clr){
    dt();
    dw(i,clr);
    //printf("%s %s %d ",ctostr[clr],wtostr[city[i].wr[clr]],city[i].NO[clr]);
    printf("marched to city %d with ",i);
    printf("%d elements and force %d\n",city[i].hp[clr],city[i].atk[clr]);
}

void get_element(){
    int i=1;
    while(i<=N){
        if((city[i].wr[red]<null&&city[i].wr[blue]>=null)||
            (city[i].wr[red]>=null&&city[i].wr[blue]<null)){
            int clr=city[i].wr[red]<null?red:blue;
            get_ele(i,clr);
            hq[clr].element+=city[i].element;
            city[i].element=0;
        }
        i++;
    }
}

void get_ele(int cn,int clr){
    dt();
    dw(cn,clr);
    printf("earned %d elements for his headquarter\n",city[cn].element);
}
void fight(){
//  int hpbf[2];//hp_before_fight
//  int wrbf[2];
    int ele[2];
    int clr;
    int rasc=none;
    int i=1;
    ele[red]=0;
    ele[blue]=0;
    while(i<=N){
        if(city[i].wr[red]<null&&city[i].wr[blue]<null){
            if(city[i].flc[2]==none) clr=1-(i%2);
            else clr=city[i].flc[2];
            rasc=none;
            //hpbf[red]=city[i].hp[red];
        //  hpbf[blue]=city[i].hp[blue];
            //wrbf[red]=city[i].wr[red];
            //wrbf[red]=city[i].wr[blue];
            attack(i);
            if(city[i].wr[1-clr]==dead){
                ele[clr]+=city[i].element;
                if(city[i].wr[clr]==dragon) yell(i,clr);
                get_ele(i,clr);
                city[i].element=0;
                city[i].flc[clr]++;
                city[i].flc[1-clr]=0;
                if(city[i].flc[2]==none&&city[i].flc[clr]==2){
                    rasc=clr;
                //  dt();
                //  printf("%s flag raised in city %d\n",ctostr[clr],i);
                    city[i].flc[2]=clr;
                    city[i].flc[clr]=0;
                }
            }
            else{
                reattack(i);
                if(city[i].wr[clr]==dead){
                    ele[1-clr]+=city[i].element;
                    get_ele(i,1-clr);
                    city[i].element=0;
                    city[i].flc[1-clr]++;
                    city[i].flc[clr]=0;
                    if(city[i].flc[1-clr]==2){
                        rasc=1-clr;
                        //dt();
                        //printf("%s flag raised in city %d\n",ctostr[1-clr],i);
                        city[i].flc[1-clr]=0;
                        city[i].flc[2]=1-clr;
                    }
                }
                else{
                    if(city[i].wr[clr]==dragon) yell(i,clr);
                    city[i].flc[red]=0;
                    city[i].flc[blue]=0;
                }
            }
        //  if(city[i].wr[clr]==dragon) yell(i,clr);
        //  if(city[i].wr[blue]==dragon) yell(i,blue);
            if(rasc!=none){
                dt();
                printf("%s flag raised in city %d\n",ctostr[rasc],i);
            }
        }
        i++;
    }
    clr=red;
    while(clr<none){
        i=hq[clr].end-hq[clr].walk;
        while(i!=hq[clr].start){
            if(city[i].wr[1-clr]==dead){
                if(city[i].wr[clr]<null&&hq[clr].element>=8){
                    city[i].hp[clr]+=8;
                    hq[clr].element-=8;
                }
                city[i].wr[1-clr]=null;
            }
            i-=hq[clr].walk;
        }
        clr++;
    }
    hq[red].element+=ele[red];
    hq[blue].element+=ele[blue];
    //hp_before_fight[red]=city[]
}
void attack(int cn){
    int clr;
    if(city[cn].flc[2]==none) clr=1-(cn%2);
    else clr=city[cn].flc[2];
    dt();
    dw(cn,clr);
    printf("attacked ");
    dw(cn,1-clr);
    printf("in city %d ",cn);
    dha(cn,clr);
    city[cn].hp[1-clr]-=city[cn].atk[clr];
    if(city[cn].hp[1-clr]<=0){
        dd(cn,1-clr);
        city[cn].kln[clr]++;
        /*if(city[cn].wr[clr]==dragon){
            dt();
            dw(cn,clr);
            printf("yelled in city %d\n",cn);
        }*/
        if(city[cn].wr[clr]==wolf&&city[cn].kln[clr]%2==0){
            city[cn].hp[clr]<<=1;
            city[cn].atk[clr]<<=1;
        }
        if(city[cn].wr[1-clr]==lion){
            city[cn].hp[clr]+=city[cn].hp[1-clr]+city[cn].atk[clr];
        }
        city[cn].wr[1-clr]=dead;
    }
}
void reattack(int cn){
    int clr;
    if(city[cn].flc[2]==none) clr=cn%2;
    else clr=1-city[cn].flc[2];
    if(city[cn].wr[clr]==ninja) return;
    dt();
    dw(cn,clr);
    printf("fought back against ");
    dw(cn,1-clr);
    printf("in city %d\n",cn);
    city[cn].hp[1-clr]-=city[cn].atk[clr]/2;
    if(city[cn].hp[1-clr]<=0){
        dd(cn,1-clr);   
        //city[cn].kln[clr]++;
        /*if(city[cn].wr[clr]==dragon){
            dt();
            dw(cn,clr);
            printf("yelled in city %d\n",cn);
        }*/
        if(city[cn].wr[1-clr]==lion){
            city[cn].hp[clr]+=city[cn].hp[1-clr]+city[cn].atk[clr]/2;
        }
        city[cn].wr[1-clr]=dead;
    }
    else{
        
    }
}

void yell(int cn,int clr){
    dt();
    dw(cn,clr);
    printf("yelled in city %d\n",cn);
}
void report(){
    report_c(red);
    report_c(blue);
    //printf("%d elements in");
}
void report_c(int clr){
    dt();
    printf("%d elements in %s headquarter\n",hq[clr].element,ctostr[clr]);
}
