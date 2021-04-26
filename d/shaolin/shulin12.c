// Code of ShenZhou
// Room: /d/shaolin/shulin12.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "������");
	set("long", @LONG
����ǰ��Ȼһ�ڣ������У�ֻ������ǰ�󣬵������������
�ص������֡���ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ����
��ɡ��������գ��������ڵ�˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�
һ�Ų���ȥ������β����������ƺ���ʧ�˷�����ûͷ��Ӭ��
�����Ҵ���
LONG
	);
	switch(random(2)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        case 1:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1]));
                break;
	}
	set("exits", ([
		"east" : __DIR__"shulin"+(random(8)+6),
		"south" : __DIR__"shulin"+(random(8)+6),
		"west" : __DIR__"shulin"+(random(8)+6),
		"north" : __DIR__"shulin"+(random(8)+6),
	]));

	set("outdoors", "shaolin");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}


