// Code of ShenZhou
// Summer 9/12/96

inherit ROOM;

void create()
{
        set("short", "�ƺ�");
        set("long", @LONG
�ƺӳ����ຣ��������֮�����ܵ�������ԭ���赲��ת���򶫱�
��ȥ��������������ԭ�Ĺ�������ɳ����������ˮɫ�λƣ��ͱ���Ϊ�ƺӡ�
LONG
        );
        set("exits", ([
		"northeast" : __DIR__"huanghe1",
                "south" :"/d/changan/beimen",
                "west" : __DIR__"huanghe3",
        ]));
	set("cost", 2);
        setup();
        set("outdoors", "huanghe");
        replace_program(ROOM);
}
