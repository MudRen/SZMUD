// Code of ShenZhou
// room: guangchang.c

inherit ROOM;

void create()
{
        set("short", "�㳡");
        set("long", @LONG
������һ����һ���ʯ���̳ɵĹ㳡���㳡�����ż�����ˣ�һ
������ӥ�����Ʈ�������ʯͷ���ɵ����ˡ��㳡��������������
ӥ�̴�ľۻᶼ��������С�
LONG );

        set("exits", ([
                "west" : __DIR__"lianwuchang",
                "north" : __DIR__"dadian",
		"east" : __DIR__"yuanzi",
		"south" : __DIR__"road1",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
