#include <ansi.h>
inherit ROOM;
int do_tan(string);
void create()
{
	set("short", HIG"����"NOR);
	set("long", @LONG
�������������ң�����˳��ط��ż������ţ��������ż����㣬����������
�𡣡�
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
                                         return notify_fail("ʲô��\n"); 
                         if ((int)me->query("qi") < 30 || me->query("jingli") < 30 )
                                         return notify_fail("�㾫�񲻼��޷����ĵ��٣�\n");
                  me->receive_damage("qi", 25);
                  me->receive_damage("jingli", 25);
                 if ( me->query_skill("qinqi-shuhua", 1) < 30 )
                        {
                                message_vision("$N�ڳ�һ�Ź��ݣ����������˼�����ֻ���������������£��������Ǻš�\n", me);
                                me->receive_damage("jing", random(20) );
                                me->receive_damage("qi", random(20) );
                                return 1;
                        }
               if ( me->query_skill("qinqi-shuhua", 1) >100 )
                        {
                                message_vision("$N�ڳ�һ�Ź��ݣ����������˼�����ֻ��������ƽ�ͣ��������������м��⡣\n", me);
                                return 1;
                        }
                me->improve_skill("qinqi-shuhua", (int)me->query_int()/4 + (int)me->query_skill("qinqi-shuhua", 1)/10);
                tell_object(me, "��ڳ�һ�Ź��ݣ����˵��ң�������������ֻ������������������������ࡣ\n");
             
               message_vision("ֻ��" + me->query("name") +
                  "���˴󷢣�����������������ֻ����ʱ�����������Įƽɳ������������\n"
                  "ʱ��С����ˮ�������˼ҡ�������������������������ʱ��������ࡣ\n",
                        environment(me), ({me}) );

                        return 1;
                }

}
