// Code of ShenZhou
// room: /mingjiao/monan.c

inherit ROOM;

void create()
{
        set("short", "ĩ��ɽ");
        set("long", @LONG
��ɽλ�����ر�´����������֮�˴ӱ��������˴�������Ϊ�Ѿ�
�������ؾ�ͷ���ʳ�֮Ϊ��ĩ�ϡ�������Ҳ��ɽ��Ρ�룬ȴ��һ����
ŭ�����ľ��ˡ��������ʱ�����洫������ˮ���������һ����ӡ�
LONG );

        set("exits", ([
                "eastdown" : __DIR__"tongtianhe",
                "southdown" : __DIR__"bailongdui",
                "northdown" : __DIR__"tushantai",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}