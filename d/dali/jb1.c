// Code of ShenZhou
// Room: /dali/jb1.c
// AceP

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��վ�����׽��ߣ�����ɽʯ���������Ρ�룬�����Ķ��ڴ��뽭����ʮ����
�ߣ���ˮ���ǣ�Ҳ�����ͽ���ȥ�����ﲢ���˼������޵�·��
LONG );

	set("exits", ([
		"go"    : __DIR__"jb2",
		"enter" : __DIR__"shishi2",
	]));

	set("cost", 2);
        set("outdoors", "dali");
	setup();
}
