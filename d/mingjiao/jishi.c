// Code of ShenZhou
// room: /mingjiao/jishi.c

inherit ROOM;

void create()
{
        set("short", "��ʯɽ");
        set("long", @LONG
�����·�ѱ棬������С�ɽ����ʯ�ѻ�����߻򰫣������������
�ߣ�С��Ҳ�缦�ѡ���ɽ�����棬ǿ�糣��ʯ�������������ˣ��ʴ˲�
Ҫͣ�����á�
LONG );

        set("exits", ([
                "northup" : __DIR__"daqing",
                "southdown" : __DIR__"lingjia",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}