// July 31,2000
// Code by April
// /gumu/liangongshi1.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

int do_study(string arg);

void create()
{
	set("short","������");

	set("long",@LONG
��ʯ����״�������أ���խ�Ͽ���Ϊ���Ρ����߰�Բ������ȴ����
����״���Ҷ�ʯ�ڣ�ceiling���Ͽ�������㻨�Ʒ��ţ������������̳ɣ�
�����ǳ�����޹�������������������
LONG);

	set("item_desc",(["ceiling" : "
��ʯ��ԭ��ȫ����ʼ����������������ĵط���
\n"]));

	set("exits",([ 
		"east" : __DIR__"mudao19",
		"southeast" : __DIR__"jianshi1",
		"southwest" : __DIR__"biaoshi1",
		"west" : __DIR__"liangongshi3", 
		"north" : __DIR__"zhangshi1",
		]));

	set("objects", ([ 
		"/kungfu/class/gumu/npc/baiyi1": 1, 
		]) );
                  
	create_door("west", "ľ��", "east", DOOR_CLOSED);
          
	set("cost",1);
	setup();
}

void init()
{
	add_action("do_study", "study");
	add_action("do_study", "du");
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "Ů��" && dir == "west" && !wizardp(me) )
		return notify_fail("������㣬��������������\n");

	if (dir =="west" && me->query("family/family_name")!="��Ĺ��" 
		&& objectp(present("baiyi girl", environment(me))))
			return notify_fail("������Ů���ֵ�ס�����ȥ·���˴����ɽ��أ���ֹ����\n");

	return ::valid_leave(me, dir);
}

int do_study(string arg)
{
	object me = this_player();
	int f1, f2;

	if ( !arg || ( arg != "ceiling" ) ) return 0;

	if (me->is_busy()) return notify_fail("��æ���أ�\n");

	if ( (int)me->query_skill("literate", 1) < 1){
		write("�㲻ʶ�֣���ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}

	f1 = me->query_skill("quanzhen-xinfa", 1);
	f2 = me->query_skill("yunu-xinjing", 1);

	if ((f1 >= 30) || (f2>=30)){
		write("���о��˰���һ������\n");
		write("����Ҫ���������ȫ����ѧ��ֻ��ȥȫ���ˡ�\n");
		return 1;
	}

	if (me->query("jing")<15) {
		write("������ͷ���ۻ����������컨���ϵ��֡�\n");
		return 1;
	}

	me->receive_damage("jing", 10, "����˥�߶���");

	message_vision("$N��ר���ж��컨���ϵ�ȫ���ķ���\n", me);

	me->improve_skill("quanzhen-xinfa", me->query_int()/2);
	write("������컨���ϵ��ľ����ƺ���ȫ����ѧ�����˽⡣\n");

	return 1;
}
