// Code of ShenZhou
// d/emei/valley.c ɽ��
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
��ǰ��Ȼ���ʣ�������һ��Сɽ�ȡ����л��ݴ����������ء�һ��С��
�������۵�ͨ���ľ����֮����
LONG
	);
        set("outdoors", "emei" );

        set("exits", ([
                "east" : __DIR__"valleypath",
        ]));

	set("cost", 3);
	setup();
        replace_program(ROOM);
}

