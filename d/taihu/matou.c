// Code of ShenZhou
//Kane

inherit FERRY;

void create()
{
	set("short", "��ͷ");
	set("long", @LONG
����һ���ڽ���ˮ�缫��������ͷ���ɴֲڵĴ�����ʯ��ɡ�
�����ƺ���һ�������ׯԺ��
LONG
	);
	 set("exits", ([
		"north" : __DIR__"damen",
		"east" : __DIR__"matou2",
	]));
	set("cost", 2);
	set("outdoors", "taihu");

	set("name", "��");
	set("boat", __DIR__"duchuan");
	set("opposite", __DIR__"taihu");

	setup();
}
