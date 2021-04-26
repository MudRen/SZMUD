// Code of ShenZhou
// room: /mingjiao/lingjia.c

inherit ROOM;

void create()
{
        set("short", "��٤ɽ");
        set("long", @LONG
��Χ�����ֶ�һ�ԣ���һ�ԣ��������ҡ�����һ��խխ��С·������
�۵���ǰ���죬������������Է�����òȳ��ġ���ϸ�����ܷ���һЩ��
��ķ�㣬ȴ���նӹ���ĺۼ�������ɽ�ƽ�Ϊƽ�������������Ƕ��͡�
LONG );

        set("exits", ([
                "eastup" : __DIR__"zishan",
                "northup" : __DIR__"jishi",
                "westdown" : __DIR__"yananshan",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}