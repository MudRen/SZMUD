//Cracked by Roath
// wdroad1.c
// by Ywz yidao1.c

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����ͨ�����ݳǡ�
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
		"southwest" : "/d/shaolin/ruzhou",
		"northeast" : __DIR__"yidao2",
        ]));
	set("cost", 2);

        setup();
        replace_program(ROOM);
}
