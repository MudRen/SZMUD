// Code of ShenZhou
// Jay 10/11/96

inherit ROOM;

void create()
{
        set("short", "�ƺ�");
        set("long", @LONG
�ƺ����ɹŸ�ԭ�ϱ������ʣ���̫��ɽ������������תͷ
���£��γɽ��µķֽ硣
LONG
        );

        set("exits", ([
		"west" : __DIR__"hetao",
		"south" : __DIR__"weifen",
        ]));

	set("outdoors","forest");
	set("cost", 3);
        setup();
	replace_program(ROOM);
}

