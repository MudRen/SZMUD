//u/tracy/workroom.c//
#include <ansi.h> 
inherit ROOM;
void create()
{
     set("short", BLINK+HIB"| "HIW"���ѩ����"NOR+BLINK+HIB"|"NOR);
     set("long", @LONG
���������ѩ�Ĵ�ѧ����,����ͨͨ������ ,���Ǵ�ɨ�ķǳ��ɾ�����.�����쳣���еĸо�,
���мҵ�ζ����!  ��ʱ���ļ�λ����(friends)��ר��ѧϰ��!�����ѧϰ��?!...
ֻ�����ѩ(him)һ����ƴ���������. sigh2! crazy!!..
LONG );
     set("exits", ([ 
        "cs" : "/d/city/guangchang",
        "power" : "/u/power/workroom",
])); 
     set("valid_startroom", 1);
     set("no_fight", 1);
     set("sleep_room", 1);
     set("no_death", 1);
     setup();
 }
void init()
{          add_action("do_top", "top");
}
int do_top()
{       
       object where, obj,*ob_list,*obj_list;
        string msg, name;
        int i,m,j = 0, exp = 0;
        int exp1,exp2;
        ob_list = users();
        obj_list = users();
          for( i = 0; i < sizeof(ob_list); i++) {
                where = environment(ob_list[i]);
                if(!wizardp(ob_list[i])
                && where
                && strsrch(file_name(where), "/d/") >= 0) {
                        obj_list[j]=ob_list[i];
                        j++;                }
        }
             for( m = 0; m < (j-1); m++) 
               for( i = 0; i < (j-1-m); i++) {
                      exp1 = obj_list[i]->query("combat_exp");
                      exp2 = obj_list[i+1]->query("combat_exp");
                 if ((int)exp1 <= (int)exp2) {
                   obj = obj_list[i];obj_list[i] = obj_list[i+1];obj_list[i+1] = obj;
                 }
               }
      
          message_vision("�����Ǳ�վ��ҵľ���ֵ���ݡ�\n\n",this_player());
      //if (j>=10) j=10;
        for( i = 0;i <j; i++) {
             obj=obj_list[i];
             name = obj->query("name")+"("+obj->query("id")+")";
          if ( i > 0 ) {
               exp1=obj_list[i]->query("combat_exp");
               exp2=obj_list[i-1]->query("combat_exp");
             
              if ((int)exp1 == (int)exp2) 
                 message_vision(""+name+" ",this_player());
              else {                message_vision("\n-----------------------------",this_player());
                message_vision("\n��"+chinese_number(i+1)+"��:"+name+" ",this_player());
              }
             }
          else 
                message_vision(HIM"��һ��"NOR+":"+name+" ",this_player());
        }
     
               message_vision("\n-----------------------------\n",this_player());
               return 1;           
               
}
