// rama@sz
// 04/03/2002
#include <ansi.h>
#include <net/daemons.h>
#define DING "/u/rama/npc/ding"
#define AZI "/u/rama/npc/azi"
#define CYC 12*3600
// #include "/u/rama/include/location.h"
inherit F_DBASE;
int last_update=0;
/*string *dirs = ({
        "/d/city",
        //��Ҫ����ܶ�Ŀ¼
});*/
void init_quest();
void azi();
void check_time();
void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "������");
        CHANNEL_D->do_channel( this_object(), "sys", "xx quest starts��\n");
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
                });

         user= users();
         last_update=time();
         i = random(sizeof(dirs));
         CHANNEL_D->do_channel(ding, "menpai", "��������˾�Ȼ͵�����ɵı�����˭�ܰ���ץ���������������ͣ�");
         CHANNEL_D->do_channel(this_object(), "rumor", "��˵�����ɶ���������");
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
        if( time() - last_update > 60*15)
        {       
                CHANNEL_D->do_channel(ding, "menpai", "����������Ϊ�ҽ��ǣ�û�뵽��Ȼ�ð����Ǹ�С������ң���⣡");            
                
                who=find_living("a zi");
                if(who)
                destruct(who);
                init_quest();
                }
        
                
}
