// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����֮����һ���ͺͺ��ʯ�ڣ������޻��������������ط��γ�ǿ�ҷ��ʯ��
����һ���Ҷ����Ҷ��������ģ��������������ʲô�����ƺ�����Ӱ�ζ���
LONG
	);

         set("exits", ([
                "south" : __DIR__"shucong",
        ]));
        set("objects", ([
                __DIR__"npc/zhou" : 1,
        ]));

	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
