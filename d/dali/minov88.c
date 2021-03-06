// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "剑川山口");
	set("long", @LONG
这里是苍山北麓的一个乌夷城镇。此地正处山口，两边崇山峻岭
耸立，几乎无路可行，唯有穿此镇可入苍山，因此是从蜀中至大理的
军事要冲，大理国在此修有刁楼箭塔，常年驻军。有官兵在镇口站岗
巡逻，盘察过往行人。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov83",
		"south" : __DIR__"minov89",
		]));

	set("objects", ([
		__DIR__"npc/dalishibing" : 3,
		__DIR__"npc/wujiang" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
