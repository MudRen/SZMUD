// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "Ӣ��¥");
        set("long", @LONG
��¥�����νྻ�����п������κ��ݣ�ʮ���Ǹ��̴�֡�
������Ը��ɽ��ȫ����
LONG
        );
        set("exits", ([
		"down" : __DIR__"yxlou",
	]));

	set("objects", ([
		__DIR__"npc/pang" : 1,
		__DIR__"npc/shou" : 1,
	]));
	set("cost",1);
	setup();
        replace_program(ROOM);
}
