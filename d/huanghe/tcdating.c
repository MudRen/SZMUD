// Code of ShenZhou
// /d/huanghe/tcdating.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
ת�˸��䣬����ǰͻȻ���������ǵ���һ�����֮�У�ǽ�ϲ�������
��ѣ���ҫ��ͬ���磬����վ�����ֳ�����Ļ��ڡ�����Щ�˶��׺ݵ�
Ŀ���ഥ֮�£��㲻�����˸������
LONG );

        set("exits", ([
		"south" : __DIR__"tctongdao",
        ]));

    	set("cost", 1);

        set("objects", ([
                __DIR__"npc/tc_you" : 1,
                __DIR__"npc/tc_hu" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
