// Code of ShenZhou
// room: /d/baituo/dushi.c
// Jiuer

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǰ���ɽׯ�������ң����յ��ӳ����������·�������С����
�����ð��յİٶ��衣
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"shechang",
	]));

	set("cost", 2);
	setup();
}
