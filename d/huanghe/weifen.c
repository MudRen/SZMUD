// Code of ShenZhou
// Jay 10/11/96

inherit ROOM;

void create()
{
        set("short", "μ������");
        set("long", @LONG
�ںӺ�μ�ӻ���ƺӣ���������ˮ�ƣ�Ҳ�����˸������ɳ��
����Ӷ��ǽ����������¡�
LONG
        );

        set("exits", ([
		"north" : __DIR__"huanghe2",
		"south" : __DIR__"bank1",
        ]));

	set("outdoors","forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

