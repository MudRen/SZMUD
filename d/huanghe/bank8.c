// Code of ShenZhou
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "�ƺ��뺣��");
        set("long", @LONG
�ƺ�������ظ�ԭ��������ԭ������ƽԭ���ܳ�һ����Ű��
���������󺣡�
LONG
        );

        set("exits", ([
		"southwest" : __DIR__"bank7",
//		"east" : __DIR__"sea1", // for fun. not serious.
        ]));

	set("outdoors","forest");
    set("tjjob", 3);
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

