// Room: /d/hengshan/cuiping1.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�����ڴ���ɽ���ϣ�ʯ�׶��ͣ�����Ŀǰ����ͷ��������ɽ��
�͵��֣���ľ������о��ס�
LONG
	);
	set("exits", ([
		"westup"  : __DIR__"cuiping2",
		"down"    : __DIR__"cuipinggu2",
	]));
	set("cost", 1);
	set("outdoors", "hengshan");
	setup();
        replace_program(ROOM);
}

