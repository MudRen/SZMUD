// /d/chengdu/dadongmen.c
// By Jpei

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ǳɶ��Ķ������ˡ��ɶ��ش����У�һ������ս�����ţ����Ժ���
������ʿ�������ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG
	);

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
		"west" : __DIR__"dongdajie2",
		"east" : __DIR__"eroad1",
		"north" : __DIR__"chenggenlu5",
	]));
        set("outdoors", "chengdu");
        set("cost", 1);
	setup();
}

string look_gaoshi()
{
 	return FINGER_D->get_killer() + "\n���ݴ�ʷ\n�����\n";
}

