// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov26.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǿ�ڲ��Ĵ�����ôЩ����ľ۾�����ôЩ�����ǰ��ĵ�һ֧����
��Ҳ��ɽ���С��ƽԭ����������һƬ��ˮ��������������ط���΢ƫԶЩ����
���൱���ٵİ����������ڸ��������Ϸ��е�·ͨ����������
LONG);
	set("objects", ([
		__DIR__"npc/byshang.c" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov27",
		"southwest" : __DIR__"minov31",
		"southup" : __DIR__"minov30",
		"westup" : __DIR__"minov25",
		]));
	set("area", "������");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
