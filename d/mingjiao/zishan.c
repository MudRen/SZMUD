// Code of ShenZhou
// room: /mingjiao/zishan.c

inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
������Ƶ�ƽ�����Ϊɽ����ʵֻ��һ��С����ˡ�Ȼ��������ˣ�
�˴���ľ��Ϊ��ï������Ҳ���ź��ĳ��ݣ�ż���ݴ��Ҷ���һЩҰ���
��֮����Ծ��������ɫҰ�����࿪�ţ��������ˡ�
LONG );

        set("exits", ([
                "westdown" : __DIR__"lingjia",
        ]));

	set("objects",([
		__DIR__"obj/xiaohuangshi" : 2,
]));
        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}