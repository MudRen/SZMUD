// Room: /d/chengdu/center.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�񶼹㳡");
	set("long", @LONG
�����ǳɶ��ᶽ��ǰ�㳡���ÿտ��ĵط���ֻ��ϡϡ���伸��û
����ɵ����ˡ���������ᶽ���ˣ��ϱ����ᶽ�֡��㳡��Χ����һ
Ȧ���������������԰���ʯ�㳡����ɹ�ù���ð�̡�
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"west" : __DIR__"xidajie1",
		"south" : __DIR__"nandajie1",
		"north" : __DIR__"tidugate",
	]));
        set("objects", ([
            "/d/city/npc/wujiang" : 2,
        ]));

	setup();
	replace_program(ROOM);
}

