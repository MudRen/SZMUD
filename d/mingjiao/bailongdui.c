// Code of ShenZhou
// room: /mingjiao/bailongdui.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������������������ɽ��ɽ����Զ��ʱ��������һ���������ԡ���
��������ʿ���Դ˵��˷�ˮ���أ��س��󸻴��֮�ˣ�������������Ӧ�顣
��������ɽ���ڴ����㣬Ĥ��ɽ��Ҳ����������֮����
LONG );

        set("exits", ([
                "westup" : __DIR__"badake",
                "northup" : __DIR__"monan",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}