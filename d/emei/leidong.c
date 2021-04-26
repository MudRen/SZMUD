// Code of ShenZhou
// /d/emei/leidong.c �׶�ƺ
// Shan: 96/06/22

#include <ansi.h>
inherit ROOM;

void do_say(string);

void create()
{
        set("short", "�׶�ƺ");
	set("long", @LONG
�׶�ƺһ������·���պ��ˣ�·���Ǳ����������ɼ�֣�·���������
�ľ���Ͽ�ȡ����ﳤ���������֣����ɺڰ������Ͻ��������Ա���һ������
�ɴ������ǡ���ʮ���̡�����������µ�ϴ��ء�
LONG
	);
	set("exits", ([
		"southup" : __DIR__"pan84",
		"east" : __DIR__"lenshan1",
		"northdown" : __DIR__"lingyun",
	]));
        set("item_desc", ([
                "����" :
"������ֹ��������������о���Ѹ�磬�������������걩����\n",
		"bei" :
"������ֹ��������������о���Ѹ�磬�������������걩����\n",
])  ) ;

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 2);
	setup();
}

void init()
{
	add_action("do_say", "say");
}

int valid_leave(object me, string dir)
{
        if ((dir == "southup" || dir == "east") && me->query("jingli") >12)
        {
                me->add("jingli",-random(12));
                me->improve_skill("dodge", random(10));
                write("�����ϰ�ʮ���̣���Щ���ˡ�\n");
        }

        else if ((dir == "southup" || dir == "east") && me->query("jingli") <= 10)
        {
                write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

int do_say(string arg)
{
	int level, check;
    	string dir;
        object me = this_player();

   	level = (int)me->query_skill("force",1);
   	check = level*level*level;

	if( !userp(me)) return 0;
	
   	if ( level <= 100  && check < (int)me->query("combat_exp")*10 ) 
		me->improve_skill("force", me->query_con()+random(level));

	tell_object(me, HIR "���˵��һ���֣�ɲ�Ǽ侪��Ѹ�磬�������������걩����\n" NOR);

        message("vision", HIR + me->name()+"��˵��һ���֣�ɲ�Ǽ侪��Ѹ�磬�������������걩����\n"NOR 
	, environment(me), ({me}));
        write(HIR"��һ���ӱ����У�ȫ���顣\n"NOR);

	if (me->query("jing") < level || me->query("qi") < level ) {
		me->set_temp("last_damage_from", "������Ѹ�����");
		if(random(me->query_kar()) == 3) me->die();
		else me->unconcious();
	} else {
		me->receive_damage("jing", random(2*level), "������Ѹ�����");
		me->receive_damage("qi", random(2*level), "������Ѹ�����");
	}

        return 1;

}
