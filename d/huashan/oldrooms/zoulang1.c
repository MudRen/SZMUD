// Code of ShenZhou
// Room: zoulang1.c ����
// qfy July 7, 1996.

inherit ROOM;

void reset();

void create()
{
    set("short", "����");
    set("long", @LONG
���ȶ������������������ϱ��ǻ�ɽ���ż���Ů���ӵ���Ϣ�ң�����
�������ȥ��
LONG
    );

    set("exits", ([
	"east" : __DIR__"liangong1",
	"west" : __DIR__"liangong2",
	"south" : __DIR__"zoulang",
	"north" : __DIR__"buwei1",
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
    setup();
    //replace_program(ROOM);
}
