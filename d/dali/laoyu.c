// Code of ShenZhou
// Room: /d/newdali/laoyu.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "����");
	set("long", @LONG
������Ϊ����֮�أ�Ȼ�����մ�ల����ҵ�����з��£����������տ���
Ҳ��ֻ�м�����ͷ�ڽ���������������ǽ����ɢɢ�����ż���Կ�ס�
LONG
	);

	set("no_clean_up", 0);
	set("cost", 1);
set("objects", ([
     "/d/dali/npc/yuzu" : 1,
]));


	setup();
}
void init()
{
        object ob = this_player();

        if( (int)ob->query_condition("dali_jail") <= 0 )
        {
                message("vision",
                        HIY "ֻ���η����ſ��һ�죬һ���������ļһﱻ���˽�����\n"NOR,
                        environment(ob), ob);

                tell_object(ob, "����ٺٵ�Ц�ţ���������������������...��\n");

                ob->apply_condition("dali_jail", 60);
        }
}
