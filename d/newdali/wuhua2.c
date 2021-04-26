// Code of ShenZhou
// Room: /d/dali/wuhua2.c

inherit ROOM;

void create()
{
	set("short", "¥��");
	set("long", @LONG
�����ͨ����¥��ӭ��ի����¥�ݣ�¥�ݸ�����ʮ�༶�����������ʺ��ë
ձ��¥������վ��һЩ������ʿ��¥�����ǹ����Ϣ�ĵط���
LONG);
	set("objects", ([
		"kungfu/class/dali/gaoshengtai" : 1,
		__DIR__"npc/weishi4.c" : 3,
        ]));
	set("exits", ([
		"east" : __DIR__"wuhua1.c",
		"up" : __DIR__"wuhua3.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
}
void reset()//make this room no refresh
{
        ::reset();
        set("no_clean_up", 1);
}
