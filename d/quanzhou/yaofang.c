// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
�����Ǽ�������ҩ��ҩ�ĵط����������з���һֻ��ҩ¯��һ��
С������ͣ�ļ�ҩ���Ļ���ˮ��¯�в�ͣ��ð������ˮ����ɢ��
��ŨŨ��ҩ����
LONG
	);
	set("exits", ([
  "west" : __DIR__"yaopu",
]));
        set("objects", ([
             __DIR__"npc/xiaosi" : 1,
             __DIR__"obj/yaolu" : 1,
        ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

