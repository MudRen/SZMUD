// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
�ߵ�������Ʋ��Լ����������֮����Ȼû��ʲô�ߴ���ľ�����̲�����
������һЩ�滨��ݣ�ɢ�������������ķε����㣬���˾���Ϊ֮һ�񡣾Ӹ���
�³�������ȥ�ƺ���һƬСС���� ��
LONG
	);
	 set("exits", ([
                "south" : __DIR__"xiaojing",
                "north" : __DIR__"zhulin",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
