// Code of ShenZhou
// Room: taogu.c Сľ��
// qfy July 25, 1996.

inherit ROOM;

void reset();

void create()
{
    set("short", "Сľ��");
    set("long", @LONG
һ������򵥵�Сľ�ݡ�������һ����¯��ǽ�Ϲ���һ��������
��������һλ���ߣ�������Ȼ���أ�ȴ���˲��ɵ�����������
LONG
    );

    set("exits", ([
	"out" : __DIR__"xiaojing2",
    ]));

    set("objects", ([
        "/clone/npc/feng" : 1,
    ]));

    set("no_clean_up", 0);

	set("cost", 0);
    setup();
    //replace_program(ROOM);
}
