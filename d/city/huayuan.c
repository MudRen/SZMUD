// Code of ShenZhou
//Jay 2/3/97

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�����Ǻ��ָ��Ļ�԰��Ժ�������˸�ɫ����ľջ����ƾ��ж�ʤ��
����ҩ������֪���׾������°ס�һ��ѩ���������¡��Ͼ���˫���ࡢ
������������̡���������˺졢���������ܽ�ء�����
    Ժ���м�����ɫ�ر��޵Ļƻ�������Ƶ������һ���������
���Ӻ���ɻ����Ǿ��Ǵ����ô����Ľ�Ѯ����
LONG
	);

	set("exits", ([
		"south" : __DIR__"dongxiang",
	]));
	set("objects", ([
		__DIR__"npc/obj/juhua1" : 1,
	]));

	set("cost", 2);
	setup();
}

int valid_leave(object me, string dir)
{
        if (!(me->query_temp("jinboxunhua"))
	&& !wizardp(me)
	&& userp(me) ) {
		me->receive_wound("qi", me->query("qi")+200, "���˽�Ѯ��������");
		return notify_fail("��ͻȻͷ��Ŀ��ˤ���ڵء�\n");
	} 
	return ::valid_leave(me, dir);
}
