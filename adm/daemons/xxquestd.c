// rama@sz
// 04/03/2002
#include <ansi.h>
#include <net/daemons.h>
#define DING "/d/quest/xingxiu/npc/ding"
#define AZI "/d/quest/xingxiu/npc/azi"
#define CYC 4*3600
// #include "/u/rama/include/location.h"
inherit F_DBASE;
int last_update=0;
/*string *dirs = ({
        "/d/city",
        //需要增添很多目录
});*/
void init_quest();
void azi();
void check_time();
void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "丁春秋");
        CHANNEL_D->do_channel( this_object(), "sys", "xx quest starts。\n");
        init_quest();
}

void init_quest()
{
        if(time()-last_update >= CYC)
        azi();
        else
        call_out("init_quest",3600);
  
}
void azi()
{
        object me,azi,*user;
        object ding=load_object(DING);

        int i;
        string *dirs;

        dirs = ({"/d/city/","/d/baituo/", "/d/xingxiu/","/d/dali/",
                 "/d/hangzhou/","/d/village/","/d/foshan/","/d/changan/",
                 "/d/quanzhou/","/d/xueshan/","/d/kaifeng/","/d/jueqing/",
                 "/d/forest/","/d/changbai/","/d/emei/","/d/huangshan/",
                 "/d/jiaxing/","/d/hengshan/","/d/huangshan/","/d/dongtinghu/",
                 "/d/taishan/","/d/taihu/","/d/qilian/","/d/taohuacun/","/d/xiangyang/",
                 "/d/zhongnan/",
                });

         user= users();
         last_update=time();
         i = random(sizeof(dirs));
         CHANNEL_D->do_channel(ding, "menpai", "阿紫这贱人居然偷了老仙的宝贝，谁能把他活捉回来，我重重有赏！");
         CHANNEL_D->do_channel(this_object(), "rumor", "听说星宿派丢了至宝。");
         azi=new(AZI);
         azi->random_place(me,dirs,i);
//       azi->set("stay/mark",time());
//      remove_call_out("check_time");
        remove_call_out("check_time");
        call_out("check_time",60*15+random(50));

}
        
void check_time()
{
        object who;
        object ding=load_object(DING);
        if( time() - last_update > 60*30)
        {       
                           
                
                who=find_living("a zi");
                if(who)
                {
                        CHANNEL_D->do_channel(ding, "menpai", "看来无人能为我解忧，没想到居然让阿紫那个小贱人逍遥法外！"); 
                        destruct(who);
                        init_quest();
                }
                else
                init_quest();  
        }
             
}

