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
       add_action("do_nickk", "nickk");
         add_action("do_setup", "setup");
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
                && ob_list[i]->query("combat_exp") >= 75000
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
      
   message_vision("�����Ǳ�վ����ֵǰ100����ҡ�\n\n",this_player());
if (j>100) j=100;
        for( i = 0;i <j; i++) {
             obj=obj_list[i];
             name = obj->query("name")+"("+obj->query("id")+")";
          if ( i > 0 ) {
               exp1=obj_list[i]->query("combat_exp");
               exp2=obj_list[i-1]->query("combat_exp");
             
              if ((int)exp1 == (int)exp2) 
                 message_vision(""+name+" ",this_player());
             else {     
                message_vision("\n��"+chinese_number(i+1)+"��:"+name+" ",this_player());
              }
             }
          else 
                message_vision(HIM"��һ��"NOR+":"+name+" ",this_player());
        }
     
               message_vision("\n-----------------------------\n",this_player());
               return 1;           
               
}
int do_setup()
{
            object room=this_player();
                   room->setup();
                     write("���£�\n");
                          return 1;
}
int do_nickk(string arg)
{
              object me=this_player();
         if(me->query("id")!="tracy" && me->query("id")!="lnere" && me->query("id")!="snowyu") return 0;
        if( !arg ) {
                me->delete("nickname");
                return notify_fail("��Ҫ���Լ�ȡʲô�ºţ�\n");
        }
         if( strlen(arg) > 100 )
                return notify_fail("��Ĵº�̫���ˣ���һ����һ��ġ�����һ��ġ�\n");
        arg = replace_string(arg, "$BLINK$", BLINK);
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        me->set("nickname", arg + NOR);
        write("��Ĵº����ˣ�\n");
        return 1;
}
