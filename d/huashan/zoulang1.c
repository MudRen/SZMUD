// Code of ShenZhou
// Room: zoulang1.c ����
// qfy July 7, 1996.

inherit ROOM;

void reset();

void create()
{
    set("short", "����");
    set("long", @LONG
����ľ������ȹᴩ���������棬�ϱ�����һ��ƫ�������ܷǳ�������
����֨֨��������������һƬ��͡�
LONG
    );

    set("exits", ([
	"east" : __DIR__"zoulang2",
	"west" : __DIR__"zoulang4",
	"south" : __DIR__"pianting2",
	"north" : __DIR__"houyuan",
    ]));

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
    replace_program(ROOM);
}