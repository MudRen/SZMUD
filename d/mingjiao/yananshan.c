// Code of ShenZhou
// room: /mingjiao/yanan.c

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
������ǰ�����Ѿ���������ɽ�������������˾�η������Ҳ��������
��֮�С�ɽ�ƽ��ߣ����������㲻�����˸���ս��̧����ȥ��ֻ������
�޾���ǧɽ���룬��������֪�����˶��ٹ��¡�
LONG );

        set("exits", ([
                "eastup" : __DIR__"lingjia",
//                "west" : __DIR__"???????",
        ]));

	set("objects",([
		__DIR__"obj/xiaohuangshi" : 2,
]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 3);

        setup();
        replace_program(ROOM);
}