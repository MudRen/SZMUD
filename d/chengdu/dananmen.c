// /d/chengdu/dananmen.c
// By Jpei

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǿ��ǳɶ����ϳ����ˡ��ɶ��ش����У�һ������ս�����ţ����Ժ���
������ʿ�������ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG
	);

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
		"north" : __DIR__"nandajie2",
		"south" : __DIR__"sroad1",
	]));
        set("outdoors", "chengdu");
        set("cost", 1);
	setup();
}

string look_gaoshi()
{
 	return FINGER_D->get_killer() + "\n���ݴ�ʷ\n�����\n";
}

