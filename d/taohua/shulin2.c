// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬ��ͨ���֣��뵺��һ�����ʧ��������ֲ���һ��������һ��С·���
���������������Խ��Խ�ߣ��ƺ�����ɽ�壻��������������ï�ܣ�������̫���ߡ�
LONG
	);
	 set("exits", ([
                "west" : __DIR__"shulin",
                "east" : __DIR__"citeng",
        ]));
	set("cost", 4);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
