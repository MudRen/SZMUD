// Code of ShenZhou
// shanlu3.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "ɽ·");
	set("long", @LONG
��·��֪���ж������������ߣ���Щ�ط����ݱ��˻��ߣ���
Щ�ط���ȫ��ɳ��������·����������������ɽʯ����������·
�����˹�������ġ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"chalu"+(6+random(4)),
		"west" : __DIR__"shanlu4",
	]));
	set("outdoors","xingxiu");
	set("cost", 6);
	setup();
	replace_program(ROOM);
}

