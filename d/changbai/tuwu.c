// Code of ShenZhou
// Room: tuwu.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һ���û����ݳɵ�С�ݣ����ڴ�ɨ�ĺܸɾ������ܵ�ǽ���Ϲ�����
���ֹ��ӣ�ǥ�ӣ���ɽ����С���ӵȹ��ߣ������ƺ��ǲɲ����õĹ��ߡ���
������Ļ�������һλ������͵����ˣ��������ź��̴���
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"xiaoxiang",
	]));
        set("objects",([
		__DIR__"npc/batou" : 1,
	]));
        

	setup();
	replace_program(ROOM);
}

