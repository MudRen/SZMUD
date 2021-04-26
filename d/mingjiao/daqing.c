// Code of ShenZhou
// room: /mingjiao/daqing.c

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
�˴���ľ����ʮ��Ũ�ܣ����ѽ����Ͱ���ֻ��һ�˶�ߣ����Ǹ�ɽ
��������ͷ����ͷ���Ƕ�����������ľ֮�ϣ�������һ��������
��ԶԶ��ȥ����һ��˵�����Ĺ��졣
LONG );

        set("exits", ([
                "southwest" : __DIR__"qingshuigou",
                "eastdown" : __DIR__"luyuhe",
                "southdown" : __DIR__"jishi",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}