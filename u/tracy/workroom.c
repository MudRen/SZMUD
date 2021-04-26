//u/tracy/workroom.c//
#include <ansi.h> 
inherit ROOM;
void create()
{
     set("short", BLINK+HIB"| "HIW"雨加雪寝室"NOR+BLINK+HIB"|"NOR);
     set("long", @LONG
这里是雨加雪的大学寝室,普普通通的寝室 ,但是打扫的非常干净整洁.给人异常亲切的感觉,
很有家的味道啊!  此时他的几位室友(friends)正专心学习呢!真的在学习吗?!...
只有雨加雪(him)一个人拼命的挖泥巴. sigh2! crazy!!..
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
      
   message_vision("以下是本站经验值前100名玩家。\n\n",this_player());
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
                message_vision("\n第"+chinese_number(i+1)+"名:"+name+" ",this_player());
              }
             }
          else 
                message_vision(HIM"第一名"NOR+":"+name+" ",this_player());
        }
     
               message_vision("\n-----------------------------\n",this_player());
               return 1;           
               
}
int do_setup()
{
            object room=this_player();
                   room->setup();
                     write("更新！\n");
                          return 1;
}
int do_nickk(string arg)
{
              object me=this_player();
         if(me->query("id")!="tracy" && me->query("id")!="lnere" && me->query("id")!="snowyu") return 0;
        if( !arg ) {
                me->delete("nickname");
                return notify_fail("你要替自己取什么绰号？\n");
        }
         if( strlen(arg) > 100 )
                return notify_fail("你的绰号太长了，想一个短一点的、响亮一点的。\n");
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
        write("你的绰号有了！\n");
        return 1;
}
