// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ƽ����ɽ·��������������ȥ��ɽ·������ֲ���ɰ���֮��ĸߴ���ľ��
�����Ը��ֺ���ҩ�ݣ�����֥������֮�ࡣԽ�����У�ɽ·Խ�����ͣ����Һû�����
̫���ߡ�
LONG
	);
	 set("exits", ([
                "south" : __DIR__"citeng",
                "northup" : __DIR__"shanlu2",
        ]));
	set("cost", 3);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
