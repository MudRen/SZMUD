// Code of ShenZhou
// room: yuanzi.c

inherit ROOM;

void create()
{
        set("short", "Ժ��");
        set("long", @LONG
����һ�������ĵ�Ժ�ӡ�Ժ�������ż��ô�����������������
����ס�����ϲ�ʱ�Ĵ���������У������������ʡ�Ժ�ӵĶ������
���м�����˯����
LONG );

        set("exits", ([
                "east" : __DIR__"xiangfang1",
                "south" : __DIR__"xiangfang2",
		"west" : __DIR__"guangchang",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
