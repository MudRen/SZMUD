// Code of ShenZhou
// Jay 10/11/96

inherit ROOM;

void create()
{
        set("short", "������ԭ");
        set("long", @LONG
�ƺ���һ�����н�������ԭ�п���������СϪ���д�����ɳ
����ƺӣ��γ�ǧ�����֡�����֮���һ���ƽ�ؽ���̨ܫ��
LONG
        );

        set("exits", ([
		"southwest" : __DIR__"huanghe",
		"northeast" : __DIR__"hetao",
        ]));

	set("outdoors", "huanghe");
	set("cost", 3);
        setup();
	replace_program(ROOM);
}

