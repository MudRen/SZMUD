#include <ansi.h>
inherit ROOM;
int do_tan(string);
void create()
{
	set("short", HIG"琴室"NOR);
	set("long", @LONG
这里是昆仑琴室，地下顺序地放着几个蒲团，正中烧着几柱香，轻烟袅袅升
起。。
LONG
	);
	set("exits", ([
                "east"  : __DIR__"huayuan1",
	]));

         set("objects",([
"/kungfu/class/kunlun/kfxiansheng.c" :  1,
         
                        ]));

	
set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");

        set("cost", 0);
        setup();
        replace_program(ROOM);
}

	
void init()
{
        add_action("do_tan", "tan");
}

int do_tan(string arg)
{
         {       object me = this_player();
                  
                         if ( !arg || arg != "qin" )
                                         return notify_fail("什么？\n"); 
                         if ((int)me->query("qi") < 30 || me->query("jingli") < 30 )
                                         return notify_fail("你精神不加无法安心弹琴！\n");
                  me->receive_damage("qi", 25);
                  me->receive_damage("jingli", 25);
                 if ( me->query_skill("qinqi-shuhua", 1) < 30 )
                        {
                                message_vision("$N摆出一张古筝，铮铮琮琮弹了几声，只听得曲调杂乱无章，宛如鬼哭狼号。\n", me);
                                me->receive_damage("jing", random(20) );
                                me->receive_damage("qi", random(20) );
                                return 1;
                        }
               if ( me->query_skill("qinqi-shuhua", 1) >100 )
                        {
                                message_vision("$N摆出一张古筝，铮铮琮琮弹了几声，只听得曲调平和，洋洋洒洒，颇有佳意。\n", me);
                                return 1;
                        }
                me->improve_skill("qinqi-shuhua", (int)me->query_int()/4 + (int)me->query_skill("qinqi-shuhua", 1)/10);
                tell_object(me, "你摆出一张古筝，调了调弦，弹了起来，你只觉得连日来烦燥的心情好了许多。\n");
             
               message_vision("只见" + me->query("name") +
                  "雅兴大发，竟弹起曲子来，你只觉得时而金戈铁马、大漠平沙。。。。。。\n"
                  "时而小桥流水、几户人家。。。。。。万般气象，你心情顿时宁静了许多。\n",
                        environment(me), ({me}) );

                        return 1;
                }

}
