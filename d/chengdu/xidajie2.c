// Room: /d/chengdu/xidajie2.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
һ����ʯ�̳ɵĴ��ͨ���ϱ���·���������ﲻ����ֻ�����治
Զ���Ĺ�������һ����ª��̯�ӣ�̯��һ�ǵ������ڷ���ҡ���ţ���
��д�š��������������ȻҲΧ��һ���ˡ��������������ˣ�������
�񶼴����
LONG );

        set("outdoors", "chengdu");

	set("exits", ([
		"east" : __DIR__"xidajie1",
		"west" : __DIR__"daximen",
		"north" : __DIR__"westroad1",
		"south" : __DIR__"westroad2",
	]));
        set("objects", ([
            "/d/taishan/npc/tangzi": 1,
        ]));

	setup();
	replace_program(ROOM);
}

