// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "Ӣ��¥");
        set("long", @LONG
��¥�����νྻ�����п������κ��ݣ�ʮ���Ǹ��̴�֡�
��ɽ�ش���ͨҪ�أ�����Է����˻��治�١�
LONG
        );
        set("exits", ([
		"north" : __DIR__"street2",
		"up" : __DIR__"yxlou2",
	]));

	set("objects", ([
		__DIR__"npc/feng7" : 1,
	]));
	set("cost",1);
	setup();
        replace_program(ROOM);
}
